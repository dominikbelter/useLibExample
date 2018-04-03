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
        std::unique_ptr<Robot> robotLabMate;
        robotLabMate.reset(new LabMate());

        // create Messor II robot
        std::unique_ptr<Robot> robotMessorII;
        robotMessorII.reset(new MessorII());

        // new configuration of the MessorII robot
        std::vector<double> newConf {0.1, 0.2, 0.3, 0.1, 0.2, 0.3, 0.1, 0.2, 0.3, 0.1, 0.2, 0.3, 0.1, 0.2, 0.3, 0.1, 0.2, 0.3,};
        robotMessorII->move2conf(newConf);

        // new configuration of the LabMate robot
        std::vector<double> newConfLabMate {1.1, 1.2, 1.3};
        robotLabMate->move2conf(newConfLabMate);

        getchar();
    }
	catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}
