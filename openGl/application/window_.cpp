#include "core_includes.h"
#include "window_.h"
#include "buffer.h"
vector_3 v3 = vector_3();
bool runnig = true;
void window_::input(GLFWwindow *window) {

	if (glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		runnig = false;
	}
}

void window_::draw(GLFWwindow* window) {
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glfwSwapBuffers(window);
}

int window_::glfw_window_creation() {
	GLFWwindow* window = nullptr;
	std::cout << "starting window creation " << std::endl;
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
		std::cerr << "Failed to initialize GLEW" << std::endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		return -1;
	}

	std::unique_ptr<buffer> vbo(new buffer(1));
	vbo->create_buffer();
	vbo->bind_buffer(v3);

	while (runnig)
	{   
		input(window);
		draw(window);
		glfwPollEvents();
	}

	vbo->unbind_buffer(v3);
	glfwTerminate();
	return 0;
}

window_::window_(int width, int height, const char* title) 
	:width(width), height(height), title(title) 
{
	std::cout << "Window created with width: " << width << ", height: " << height << ", title: " << title << std::endl;
}

window_::~window_(){};
