#include <iostream>
#include "blackcomb/base/Window.h"
#include "blackcomb/misc/Coords.h"

using namespace renderer;

Window::Window(const char* name) : Window::Window(DefaultWidth, DefaultHeight, name) {}

Window::Window(int width, int height, const char* name) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    handle = glfwCreateWindow(width, height, name, nullptr, nullptr);
    if (handle == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return;
    }
}

/**
 * Make this window the current OpenGL context.
 */
void Window::makeContextCurrent() {
    glfwMakeContextCurrent(handle);
}

/**
 * Change input settings for this window.
 */
void Window::setInputMode(int mode, int value) {
    glfwSetInputMode(handle, mode, value);
}

/**
 * Inform GLFW whether or not the window should be closed.
 */
void Window::setShouldClose(bool shouldClose) {
    glfwSetWindowShouldClose(handle, shouldClose);
}

/**
 * @return Whether or not the window should be closed.
 */
bool Window::shouldClose() {
    return (GLboolean)glfwWindowShouldClose(handle);
}

/**
 * Get whether a key is pressed or released.
 *
 * @return GLFW_PRESS or GLFW_RELEASE
 */
int Window::getKey(int key) {
    return glfwGetKey(handle, key);
}

/**
 * Get whether a mouse button is pressed or released.
 *
 * @return GLFW_PRESS or GLFW_RELEASE
 */
int Window::getMouseButton(int button) {
    return glfwGetMouseButton(handle, button);
}

/**
 * @return The pointer to the GLFWwindow this Window is responsible for.
 */
GLFWwindow* Window::getHandle() {
    return handle;
}

/**
 * @return The window's width and height.
 */
Point2i Window::getDims() {
    int width, height;
    glfwGetWindowSize(handle, &width, &height);
    return {width, height};
}

/**
 * Sets the GLFW framebuffer size callback.
 * @param fbSizeCallback A function with the signature `void framebufferSizeCallback(GLFWwindow *window, int width, int height)`.
 */
void Window::setFramebufferSizeCallback(GLFWframebuffersizefun fbSizeCallback) {
    glfwSetFramebufferSizeCallback(handle, fbSizeCallback);
}

/**
 * Sets the window title.
 */
void Window::setWindowTitle(const std::string& title) {
    glfwSetWindowTitle(handle, title.c_str());
}