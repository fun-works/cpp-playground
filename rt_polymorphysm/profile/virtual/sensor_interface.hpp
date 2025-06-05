#ifndef SENSOR_INTERFACE_VIRTUAL_HPP
#define SENSOR_INTERFACE_VIRTUAL_HPP

#include <cstdio>

// Abstract base class for sensors
class ISensor {
public:
    virtual ~ISensor() = default;
    virtual void init(uint8_t mode) = 0;
    virtual bool read(float & value) = 0;
    virtual void shutdown() = 0;
};

#endif // SENSOR_INTERFACE_VIRTUAL_HPP
