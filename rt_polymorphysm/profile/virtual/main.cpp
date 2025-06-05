
#include "temp_sensor.hpp"
#include "light_sensor.hpp"

int main() {
    TempSensor ts;

    LightSensor ls;

    ISensor &sensor = ts;
    
    sensor.init(0);

    float temperature = 0;
    if (sensor.read(temperature)) {
        printf("Temperature: %.2f°C\n", temperature);
    }

    sensor.shutdown();

    sensor = ls;
    
    sensor.init(0);

    float light = 0;
    if (sensor.read(light)) {
        printf("Light: %.2f\n", light);
    }

    sensor.shutdown();

    return 0;
}
