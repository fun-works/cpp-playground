#ifndef SENSOR_INTERFACE_HPP
#define SENSOR_INTERFACE_HPP

#include <cstdint>

struct SensorT {
    void* context;

    void (*init)(void* ctx);
    bool (*read)(void* ctx, float& out);
    void (*shutdown)(void* ctx);
};

#endif // SENSOR_INTERFACE_HPP
