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

int window_::glfw_window_creation(buffer* BUFFER_OBEJECT) 
{
	std::cout << " [INFO]::initializing GLFW " << std::endl;
	if (!glfwInit()) {
		std::cerr << "[ERROR]::Failed to initialize GLFW" << std::endl;
		return -1;
	}
	GLFWwindow* window = nullptr;
	std::cout << "[INFO]::starting window creation " << std::endl;
	window = glfwCreateWindow(width, height, title, NULL, NULL);
	
	if (!window_status( window))
	{
		std::cout <<"[ERROR]::SOME THING WENT WRONG SEE CODE ON LINE 34" << std::endl;
		return -1;
	}
	std::cout << "[INFO]::Window created successfully with width: " 
				<< width << ", height: "
				<< height << ", title: " 
				<< title << std::endl;
	BUFFER_OBEJECT->create_buffer();
	BUFFER_OBEJECT->bind_buffer(v3);
	std::cout << "[INFO]::GLBUFFER CREATED AND BIND SUCCESSFULLY \n [INFO]::STARTING DRAWING" << std::endl;
	while (runnig)
	{   
		input(window);
		draw(window);
		glfwPollEvents();
	}

	BUFFER_OBEJECT->unbind_buffer(v3);
	glfwTerminate();
	std::cout << "[INFO]::WIDOW DISTROY AND GLFW TEMINETED" << std::endl;
	return 0;
}

window_::window_(int width, int height, const char* title) 
	:width(width), height(height), title(title) 
{
	
}
window_::window_(bool toggle )

{
	
}

window_::~window_(){};
int window_::window_status(GLFWwindow* window)
{
	
	if (!window) {
		std::cerr << "[ERROR]::Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return 0;
	}
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK) {
		std::cerr << "[ERROR]::Failed to initialize GLEW" << std::endl;
		glfwDestroyWindow(window);
		glfwTerminate();
		return 0;
	}
	return 1;

}