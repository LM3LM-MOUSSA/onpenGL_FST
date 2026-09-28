#pragma once
#include "core_includes.h"
#include "buffer.h"


#define WIDTH 800
#define HEIGHT 600
#define TITLE "window"
class window_
{
public:
    window_(int width, int height, const char* title);
    window_(bool toggle);
    ~window_();
    int create_window_full();
    int glfw_window_creation(buffer* BUFFER_OBEJECT);
    void input(GLFWwindow* window);
    void draw(GLFWwindow* window);
    int window_status(GLFWwindow* window);
private:
    int width = WIDTH;
    int height = HEIGHT;
    const char* title = TITLE;


};

