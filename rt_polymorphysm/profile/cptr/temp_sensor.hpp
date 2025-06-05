#ifndef TEMP_SENSOR_HPP
#define TEMP_SENSOR_HPP

#include <cstdio>
#include <cstdint>

struct TempSensor {
    bool init(uint8_t mode) {
        printf("[TempSensor] Init with mode: %d\n", mode);
        return true;
    }

    bool read(float& value) {
        value = 25.3f;  // Simulated temperature
        printf("[TempSensor] Read value: %.2f\n", value);
        return true;
    }

    void shutdown() {
        printf("[TempSensor] Shutdown\n");
    }
};

#endif
