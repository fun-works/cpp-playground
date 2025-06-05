#ifndef LIGHT_SENSOR_HPP
#define LIGHT_SENSOR_HPP

#include <cstdio>
#include <cstdint>

struct LightSensor {
    bool init(uint8_t mode) {
        printf("[LightSensor] Init with mode: %d\n", mode);
        return true;
    }

    bool read(float& value) {
        value = 25.3f;  // Simulated light intensity
        printf("[LightSensor] Read value: %.2f\n", value);
        return true;
    }

    void shutdown() {
        printf("[LightSensor] Shutdown\n");
    }
};

#endif
