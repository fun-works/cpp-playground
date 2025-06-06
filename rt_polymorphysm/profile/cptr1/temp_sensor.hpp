#ifndef TEMP_SENSOR_HPP
#define TEMP_SENSOR_HPP

#include <cstdio>
#include <cstdint>

struct TempSensor {
    float offset = 0;

    void init() {
        offset = 1.0f;
        printf("[TempSensor] Initialized\n");
    }

    bool read(float& out) {
        out = 25.0f + offset;
        printf("[TempSensor] Read: %.2f\n", out);
        return true;
    }

    void shutdown() {
        printf("[TempSensor] Shutdown\n");
    }

    SensorT to_interface() {
        return SensorT{
            .context = this,
            .init = [](void* ctx) {
                static_cast<TempSensor*>(ctx)->init();
            },
            .read = [](void* ctx, float& out) {
                return static_cast<TempSensor*>(ctx)->read(out);
            },
            .shutdown = [](void* ctx) {
                static_cast<TempSensor*>(ctx)->shutdown();
            }
        };
    }
};

#endif
