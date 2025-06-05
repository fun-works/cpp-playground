#ifndef TEMP_SENSOR_HPP
#define TEMP_SENSOR_HPP

#include <cstdio>
#include <cstdint>

#include "sensor_interface.hpp"

// Concrete temperature sensor class
class TempSensor : public ISensor {
    public:
        void init(uint8_t mode) override {
            printf("[TempSensor] Init with mode: %d\n", mode);
        }
    
        bool read(float & out) override {
            out = 24.7f;
            printf("[TempSensor] Read value: %.2f\n", out);
            return true;
        }
    
        void shutdown() override {
            printf("[TempSensor] Shutdown\n");
        }
    };

#endif
