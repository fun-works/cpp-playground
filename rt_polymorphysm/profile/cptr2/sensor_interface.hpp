#ifndef SENSOR_INTERFACE_HPP
#define SENSOR_INTERFACE_HPP

#include <cstdint>

struct SensorT {
    void (*init)(void* sensor_instance);
    bool (*read)(void* sensor_instance, float& out);
    void (*shutdown)(void* sensor_instance);
};

#endif // SENSOR_INTERFACE_HPP
