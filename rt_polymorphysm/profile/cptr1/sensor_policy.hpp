#ifndef SENSOR_POLICY_HPP
#define SENSOR_POLICY_HPP

template <typename Sensor>
struct SensorPolicy {
    static void init(Sensor& sensor) {
        sensor.init(1); // example mode
    }

    static bool read(Sensor& sensor, float& out) {
        return sensor.read(out);
    }

    static void shutdown(Sensor& sensor) {
        sensor.shutdown();
    }
};

#endif
