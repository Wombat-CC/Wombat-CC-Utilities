#include "../include/Wombat-CC/Utilities.hpp"

#include <cstdlib>
#include <iostream>
#include <thread>
#include <kipr/wombat.h>

/**
 * @file Utilities.cpp
 * @brief Implementation of Wombat-CC Utilities helpers.
 */

namespace Wombat_CC
{

    /**
     * @brief Default constructor.
     */
    Utilities::Utilities(/* args */)
    {
    }

    /**
     * @brief Launches the push-button kill monitor in a detached thread.
     *
     * Thread behavior:
     * - Polls the onboard push button every 10 ms.
     * - If pressed, immediately stops motors and disables servos.
     * - Terminates the process with exit code 0.
     *
     * @note Testing only. Do not enable this during competition runs.
     */
    void Utilities::ActivateKillSwitch()
    {
        std::thread([]()
                    {
		while (true)
		{
			if (push_button() == 1)
			{
				std::cout << "Kill button pressed. Stopping motors and servos." << std::endl;

				ao();
				disable_servos();

				std::exit(0);
			}

			msleep(10);
		} })
            .detach();
    }

    /**
     * @brief Waits for a light-triggered start condition.
     * @param min Calibrated low-end sensor reading.
     * @param max Calibrated high-end sensor reading.
     * @param light_port Analog port used for light detection.
     */
    void Utilities::wait_for_light(int min, int max, int light_port)
    {
        std::cout << "Waiting for light..." << std::endl;
        while (analog(light_port) > (max + min) / 2)
        {
            msleep(10);
        }
        std::cout << "Light detected!" << std::endl;
    }

    /**
     * @brief Default destructor.
     */
    Utilities::~Utilities()
    {
    }

} // namespace Wombat_CC
