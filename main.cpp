/** @file main.cpp
 *
 * This example shows how to use external 'Robot' library
 *
 * @author Dominik Belter
 */

#include "Robot/LabMate.h"
#include "Robot/MessorII.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    try {
        using namespace tutorial;

        // create LabMate robot
        std::unique_ptr<Robot> robotLabMate = std::make_unique<LabMate>();

        // create Messor II robot
        std::unique_ptr<Robot> robotMessorII = std::make_unique<MessorII>();

        // new configuration of the MessorII robot
        robotMessorII->move2conf(
        {0.1, 0.2, 0.3, 0.1, 0.2, 0.3,
         0.1, 0.2, 0.3, 0.1, 0.2, 0.3,
         0.1, 0.2, 0.3, 0.1, 0.2, 0.3});

        // new configuration of the LabMate robot
        robotLabMate->move2conf({1.1, 1.2});

        getchar();
    }
	catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}
