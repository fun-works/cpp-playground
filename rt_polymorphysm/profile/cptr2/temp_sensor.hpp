#ifndef TEMP_SENSOR_HPP
#define TEMP_SENSOR_HPP

#include <cstdio>
#include <cstdint>
#include "sensor_interface.hpp"

struct TempSensor {
    uint8_t mode;
    float value;
};

void temp_sensor_init(TempSensor* sensor) {
    sensor->mode = 0;
    printf("[TempSensor] Init with mode: %d\n", sensor->mode);
}

bool temp_sensor_read(TempSensor* sensor, float& out) {
    sensor->value = 25.0f;
    out = sensor->value;
    printf("[TempSensor] Read value: %.2f\n", out);
    return true;
}

void temp_sensor_shutdown(TempSensor* sensor) {
    printf("[TempSensor] Shutdown\n");
}

#endif
