/*
* Author: Wire
* Date: 09-07-2025
*  
* tiny program which stops the Anki programs,
* kills vic-robot if necessary, and shuts the
* whole robot off.
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libpvictor.h"

bool killrobot = true;

void stop_anki_robot() {
    system("/usr/bin/systemctl stop anki-robot.target");
    killrobot = false;
}

void kill_robot_if_need_be() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    if (killrobot) {
        system("/usr/bin/systemctl kill -s SIGKILL vic-robot.service");
    }
}

int main() {
    // green and bold
    std::cout << "\033[1;32mShutting down in 5 seconds...\033[0m\n";
    std::cout.flush();

    pid_t pid = fork();
    if (pid > 0) {
        return 0;
    }

    // child continues
    setsid();

    pid = fork();
    if (pid > 0) {
        return 0;
    }

    // no more terminal
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    std::thread t(stop_anki_robot);
    std::thread t2(kill_robot_if_need_be);
    t.detach();
    t2.detach();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    body_init();
    shut_body_down();
    return 0;
}
