#include "sensor_interface.hpp"
#include "sensor_policy.hpp"
#include "temp_sensor_policy.hpp"
#include "light_sensor_policy.hpp"
#include "temp_sensor.hpp"
#include "light_sensor.hpp"

int main() {
    TempSensor ts;
    auto temp_sensor = SensorT::create<TempSensor, TempSensorPolicy>(ts);

    LightSensor ls;
    auto light_sensor = SensorT::create<LightSensor, LightSensorPolicy>(ls);

    SensorT &sensor = temp_sensor;
    
    sensor.init();

    float temperature = 0;
    if (sensor.read(temperature)) {
        printf("Temperature: %.2f°C\n", temperature);
    }

    sensor.shutdown();

    sensor = light_sensor;
    
    sensor.init();

    float light = 0;
    if (sensor.read(light)) {
        printf("Light: %.2f\n", light);
    }

    sensor.shutdown();

    return 0;
}
