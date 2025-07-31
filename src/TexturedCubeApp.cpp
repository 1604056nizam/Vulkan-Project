#define GLFW_INCLUDE_VULKAN

#include "TexturedCubeApp.hpp"
#include <iostream>
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIHGT = 600;


void TexturedCubeApp::run() {
	initWindow();
	initVulkan();
	mainLoop();
	cleanUp();
}

void TexturedCubeApp::initWindow() {
	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	this->window = glfwCreateWindow(WIDTH, HEIHGT, "VULKAN WINDOW", nullptr, nullptr);

	std::cout << "Window initialized (placeholder)" << std::endl;
}

void TexturedCubeApp::initVulkan() {
	std::cout << "Vulkan initialized (placeholder)" << std::endl;
}

void TexturedCubeApp::mainLoop() {
	std::cout << "Running main loop (placeholder)" << std::endl;

	while (!glfwWindowShouldClose(this->window)) {
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

}

void TexturedCubeApp::cleanUp() {
	std::cout << "Cleaning up (placeholder)" << std::endl;
}
