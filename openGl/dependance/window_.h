#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
class window_
{
public:
    window_(int width, int height, const char* title);
    ~window_();
    int glfw_window_creation();
private:
    int width = 800;
    int height = 600;
    const char* title = "widow";


};

