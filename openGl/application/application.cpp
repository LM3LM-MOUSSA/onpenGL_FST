#include "core_includes.h"
#include"window_.h"

int main() {
	std::unique_ptr<window_> window(new window_(800,600,"Test"));
	std::unique_ptr<buffer> glBuffer(new buffer(1));
	window->glfw_window_creation(glBuffer.get());
	

	return 0; 
}