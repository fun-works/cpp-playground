#ifndef LIGHT_SENSOR_HPP
#define LIGHT_SENSOR_HPP

#include <cstdio>
#include <cstdint>

#include "sensor_interface.hpp"

// Concrete light sensor class
class LightSensor : public ISensor {
    public:

        void init(uint8_t mode) override {
            printf("[LightSensor] Init with mode: %d\n", mode);
        }
    
        bool read(float & value) override {
            value = 350.0f;
            printf("[TempSensor] Read value: %.2f\n", value);
            return true;
        }
    
        void shutdown() override {
            printf("[LightSensor] Power Off\n");
        }
    };

#endif
