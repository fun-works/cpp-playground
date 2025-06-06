#include "sensor_interface.hpp"
#include "sensor_policy.hpp"
#include "temp_sensor_policy.hpp"
#include "light_sensor_policy.hpp"
#include "temp_sensor.hpp"
#include "light_sensor.hpp"

void use_sensor(SensorT& sensor) {
    sensor.init(sensor.context);
    float value;
    if (sensor.read(sensor.context, value)) {
        printf("-> Value: %.2f\n", value);
    }
    sensor.shutdown(sensor.context);
}

// ======= Main =======
int main() {
    TemperatureSensor temp;
    PressureSensor pressure;

    SensorT tempIf = temp.to_interface();
    SensorT pressureIf = pressure.to_interface();

    printf("\n== Temperature Sensor ==\n");
    use_sensor(tempIf);

    printf("\n== Pressure Sensor ==\n");
    use_sensor(pressureIf);

    return 0;
}
