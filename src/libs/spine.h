#ifndef __SPINE_H
#define __SPINE_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libpvictor.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DEBUG_SPINE 0

int spine_init();
int inline spine_send_frame(int handle, uint16_t frame_type, void* frame_data, uint16_t frame_size);
int spine_request_version(int handle);
int spine_mode_change(int handle);
int spine_shutdown(int handle);
int spine_set_led(int handle, uint32_t* led_data);
int spine_update(int handle, uint32_t seq, uint32_t flags, int16_t* motors_data, uint32_t* leds_data);
int spine_read(int handle);
int spine_parse_frame();


extern uint16_t parsed_frame_type;
extern uint16_t parsed_frame_size;
extern uint8_t parsed_frame_data[768];


#ifdef __cplusplus
}
#endif


#endif
