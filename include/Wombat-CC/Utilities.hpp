#ifndef WOMBAT_CC_Utilities_HPP
#define WOMBAT_CC_Utilities_HPP

/**
 * @file Utilities.hpp
 * @brief Utility helpers for common Wombat bot startup and safety tasks.
 */

namespace Wombat_CC
{

    /**
     * @class Utilities
     * @brief Static helper methods intended for testing workflows.
     *
     * The Utilities library currently provides:
     * - A background kill-switch listener via the robot push button.
     * - A simple wait-for-light start helper.
     */
    class Utilities
    {
    private:
        /* data */
    public:
        /**
         * @brief Constructs a Utilities object.
         *
         * This class primarily exposes static helpers, so construction is
         * optional for normal use.
         */
        Utilities(/* args */);

        /**
         * @brief Starts a detached background thread that watches the push button.
         *
         * When the push button is pressed, all motors and servos are disabled and
         * the process exits immediately.
         *
         * @note Testing only. Do not enable this during competition runs.
         */
        static void autokill();

        /**
         * @brief Blocks until the light sensor sees a value below threshold.
         *
         * The threshold is calculated as the midpoint between min and max.
         * The method polls until analog(light_port) is less than or equal to
         * that midpoint.
         *
         * @param min Calibrated low-end sensor reading.
         * @param max Calibrated high-end sensor reading.
         * @param light_port Analog port connected to the light sensor.
         *
         * @note Testing only. Do not use this helper during competition runs.
         */
        static void wait_for_light(int min, int max, int light_port);

        /**
         * @brief Destroys a Utilities object.
         */
        ~Utilities();
    };

} // namespace Wombat_CC

#endif // WOMBAT_CC_Utilities_HPP