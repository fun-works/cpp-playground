#ifndef LIGHT_SENSOR_HPP
#define LIGHT_SENSOR_HPP

#include <cstdio>
#include <cstdint>
#include "sensor_interface.hpp"

struct LightSensor {
    float bias;
    float value;
};

void light_sensor_init(LightSensor* sensor) {
    sensor->bias = 10.0f;
    printf("[LightSensor] Initialized\n");
}

bool light_sensor_read(LightSensor* sensor, float& out) {
    sensor->value = 1000.0f + sensor->bias;
    out = sensor->value;
    printf("[LightSensor] Read: %.2f\n", out);
    return true;
}

void light_sensor_shutdown(LightSensor* sensor) {
    printf("[LightSensor] Shutdown\n");
}

#endif
