#ifndef SENSOR_INTERFACE_HPP
#define SENSOR_INTERFACE_HPP

#include <cstdint>

struct SensorT {
    using InitFn = void (*)();
    using ReadFn = bool (*)(float&);
    using ShutdownFn = void (*)();

    InitFn init;
    ReadFn read;
    ShutdownFn shutdown;

    // Create from Impl + Policy adapter
    template<typename Impl, typename Policy>
    static SensorT create(Impl& impl) {
        struct Adapter {
            Impl& sensor;

            explicit Adapter(Impl& sensor) : sensor(sensor) {}

            void init() {
                Policy::init(sensor);
            }

            bool read(float& out) {
                return Policy::read(sensor, out);
            }

            void shutdown() {
                Policy::shutdown(sensor);
            }
        };

        static Adapter adapter(impl);
        return SensorT{
            []() { adapter.init(); },
            [](float& out) { return adapter.read(out); },
            []() { adapter.shutdown(); }
        };
    }
};

#endif // SENSOR_INTERFACE_HPP
