#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <optional>
#include <set>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <array>
#include "TexturedCubeApp.hpp"

int main() {
	/*try {
		initWindow();
		createInstance();
		createSurface();
		pickPhysicalDevice();
		createLogicalDevice();
		mainLoop();
		cleanup();
	}
	catch (const std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;*/
	TexturedCubeApp app;

	
	try {
		TexturedCubeApp app;
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	system("pause"); 
	return 0;
	


}
