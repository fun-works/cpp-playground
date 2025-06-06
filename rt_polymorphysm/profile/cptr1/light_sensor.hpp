#ifndef LIGHT_SENSOR_HPP
#define LIGHT_SENSOR_HPP

#include <cstdio>
#include <cstdint>

struct LightSensor {
    float bias = 0;

    void init() {
        bias = 10.0f;
        printf("[LightSensor] Initialized\n");
    }

    bool read(float& out) {
        out = 1000.0f + bias;
        printf("[LightSensor] Read: %.2f\n", out);
        return true;
    }

    void shutdown() {
        printf("[LightSensor] Shutdown\n");
    }

    SensorT to_interface() {
        return SensorT{
            .context = this,
            .init = [](void* ctx) {
                static_cast<LightSensor*>(ctx)->init();
            },
            .read = [](void* ctx, float& out) {
                return static_cast<LightSensor*>(ctx)->read(out);
            },
            .shutdown = [](void* ctx) {
                static_cast<LightSensor*>(ctx)->shutdown();
            }
        };
    }
};

#endif
