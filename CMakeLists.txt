cmake_minimum_required(VERSION 3.10)

project(libpvictor VERSION 0.1 LANGUAGES C CXX)

add_compile_options(-Wno-narrowing)
add_compile_options(-Wno-int-to-pointer-cast)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC_CPP "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB SRC_LIB_CPP "${PROJECT_SOURCE_DIR}/src/libs/*.cpp")
file(GLOB SRC_LIB_C "${PROJECT_SOURCE_DIR}/src/libs/*.c")

set(SOURCES ${SRC_CPP} ${SRC_LIB_CPP} ${SRC_LIB_C})

add_library(pvictor SHARED ${SOURCES})

target_link_libraries(pvictor atomic)

# examples

add_executable(voff ${PROJECT_SOURCE_DIR}/examples/voff/voff.cpp)
target_link_libraries(voff pvictor)

install(TARGETS pvictor
        LIBRARY DESTINATION lib)

install(TARGETS voff
        DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)