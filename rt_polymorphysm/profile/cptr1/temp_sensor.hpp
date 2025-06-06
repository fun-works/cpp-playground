#ifndef TEMP_SENSOR_HPP
#define TEMP_SENSOR_HPP

#include <cstdio>
#include <cstdint>
#include "sensor_interface.hpp"

struct TempSensor {
    void init(uint8_t mode) {
        printf("[TempSensor] Init with mode: %d\n", mode);
    }

    bool read(float& out) {
        out = 25.0f;
        printf("[TempSensor] Read value: %.2f\n", out);
        return true;
    }

    void shutdown() {
        printf("[TempSensor] Shutdown\n");
    }

    SensorT to_interface() {
        return {
            this,
            [](void* ctx) { static_cast<TempSensor*>(ctx)->init(0); },
            [](void* ctx, float& out) { return static_cast<TempSensor*>(ctx)->read(out); },
            [](void* ctx) { static_cast<TempSensor*>(ctx)->shutdown(); }
        };
    }
};

#endif
