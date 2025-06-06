#include "temp_sensor.hpp"
#include "light_sensor.hpp"

void use_sensor(SensorT& sensor, void* sensor_instance) {
    sensor.init(sensor_instance);
    float value;
    if (sensor.read(sensor_instance, value)) {
        printf("-> Value: %.2f\n", value);
    }
    sensor.shutdown(sensor_instance);
}

// ======= Main =======
int main() {
    TempSensor ts;
    LightSensor ls;

    SensorT tsIf = { 
        (void (*)(void*))temp_sensor_init, 
        (bool (*)(void*, float&))temp_sensor_read, 
        (void (*)(void*))temp_sensor_shutdown 
    };

    SensorT lsIf = { 
        (void (*)(void*))light_sensor_init, 
        (bool (*)(void*, float&))light_sensor_read, 
        (void (*)(void*))light_sensor_shutdown 
    };

    printf("\n== Temp Sensor ==\n");
    use_sensor(tsIf, &ts);

    printf("\n== Light Sensor ==\n");
    use_sensor(lsIf, &ls);

    return 0;
}
