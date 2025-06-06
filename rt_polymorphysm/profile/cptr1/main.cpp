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
    TempSensor ts;
    LightSensor ls;

    SensorT tsIf = ts.to_interface();
    SensorT lsIf = ls.to_interface();

    printf("\n== Temp Sensor ==\n");
    use_sensor(tsIf);

    printf("\n== Light Sensor ==\n");
    use_sensor(lsIf);

    return 0;
}
