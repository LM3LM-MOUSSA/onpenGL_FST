#pragma once
#include "core_includes.h"
#include "buffer.h"
#include "shaders.h"
namespace engine{
#define WIDTH 800
#define HEIGHT 600
#define TITLE "window"
class window_
{
public:
    window_(int width, int height, const char* title);

    ~window_();

    int window_init();

    GLFWwindow* Get_Window();
   
    int window_status();
private:
    GLFWwindow* m_window;
    int width = WIDTH;
    int height = HEIGHT;
    const char* title = TITLE;


};

}