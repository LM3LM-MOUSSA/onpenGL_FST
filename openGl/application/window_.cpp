#include "window_.h"
#include <iostream>
#include <memory>

int window_::glfw_window_creation() {
    GLFWwindow* window = nullptr;
    std::cout << "starting window creation ";
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }
   
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT); 
        glfwSwapBuffers(window);
        
        glfwPollEvents();

    }
    glfwTerminate();
    return 0;
}
window_::window_(int width, int height, const char* title) 
    :width(width), height(height), title(title) 
{
    std::cout << "Window created with width: " << width << ", height: " << height << ", title: " << title << std::endl;
    
    
}
window_::~window_(){};
