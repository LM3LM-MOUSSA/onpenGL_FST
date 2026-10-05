#pragma once
#include "core_includes.h"
#include "buffer.h"
#include "shaders.h"

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
    int window_init();
    int glfw_window_creation(buffer* BUFFER_OBEJ_0,  shaders* CHADER_OBJ);
    void input();
    void draw();
    int window_status();
private:
    GLFWwindow* m_window;
    int width = WIDTH;
    int height = HEIGHT;
    const char* title = TITLE;


};

