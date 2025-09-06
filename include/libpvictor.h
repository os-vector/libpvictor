#ifndef __LIBPVICTOR_H
#define __LIBPVICTOR_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct IMUData {
    float gx;
    float gy;
    float gz;
    float ax;
    float ay;
    float az;
} IMUData;

typedef struct {
    int32_t pos;
    int32_t dlt;
    uint32_t tm;
} spine_motor_status_t;

typedef struct {
    uint32_t seq;
    uint16_t status;
    uint8_t i2c_device_fault;
    uint8_t i2c_fault_item;
    spine_motor_status_t motors[4];
    uint16_t cliff_sensor[4];
    int16_t battery_voltage;
    int16_t charger_voltage;
    int16_t body_temp;
    uint16_t battery_flags;
    uint16_t __reserved1;
    uint8_t prox_sigma_mm;
    uint16_t prox_raw_range_mm;
    uint16_t prox_signal_rate_mcps;
    uint16_t prox_ambient;
    uint16_t prox_SPAD_count;
    uint16_t prox_sample_count;
    uint32_t prox_calibration_result;
    uint16_t touch_sensor;
    uint16_t buttton_state;
    uint32_t mic_indices;
    uint16_t button_inputs;
    uint8_t __reserved2[26];
    uint16_t mic_data[320];
} spine_dataframe_t;

// IMU (gyroscope+accelerometer)
int imu_init();
IMUData getIMUData();

// Body (sensors, motors, LEDs, mics)
int body_init();
void body_close();
spine_dataframe_t body_read();
// Cuts power, be prepared
void shut_body_down();
void body_update(uint32_t seq, int16_t* motors_data, uint32_t* leds_data);

// LCD Screen
void screen_init();
// 1.0: 184x96 RGB565
// 2.0: 160x80 RGB565
void set_pixels(uint16_t *pixels);
// Is Vector 2.0? This is set after init
bool is_midas();

#ifdef __cplusplus
}
#endif

#endif // __LIBPVICTOR_H
