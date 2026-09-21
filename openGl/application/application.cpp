#include "GL/glew.h"
#include "window_.h"

int main() {
	std::unique_ptr<window_> window(new window_(800,600,"Test"));
	std::cout<<window->glfw_window_creation();
	return 0; 
}