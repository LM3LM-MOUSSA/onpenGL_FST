#pragma once
#include "core_includes.h"


#define WIDTH 800
#define HEIGHT 600
#define TITLE "window"
class window_
{
public:
    window_(int width, int height, const char* title);
    ~window_();
    int glfw_window_creation();
    void input(GLFWwindow* window);
    void draw(GLFWwindow* window);
private:
    int width = WIDTH;
    int height = HEIGHT;
    const char* title = TITLE;


};

