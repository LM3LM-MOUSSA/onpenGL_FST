#include "core_includes.h"
#include "window_.h"
#include "buffer.h"
#include "shaders.h"
namespace engine {
GLFWwindow* window_::Get_Window()
{
		return m_window;
}
int window_::window_init()
{
	std::cout << " [INFO]::initializing GLFW " << std::endl;
	if (!glfwInit()) {
		std::cerr << "[ERROR]::Failed to initialize GLFW" << std::endl;
		return 0;
	}
	
	std::cout << "[INFO]::starting window creation " << std::endl;
	m_window =glfwCreateWindow(width, height, title, NULL, NULL);
	if (!m_window) {
		std::cerr << "[ERROR]::Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return 0;
	}
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);
	if (glewInit() != GLEW_OK) {
		std::cerr << "[ERROR]::Failed to initialize GLEW" << std::endl;
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return 0;
	}
	
	std::cout << "[INFO]::Window created and initialised successfully with width: "
		<< width << ", height: "
		<< height << ", title: "
		<< title << std::endl;
	return 1;
}

window_::window_(int width, int height, const char* title) 
	:width(width), height(height), title(title) ,m_window(nullptr)
{
	
}


window_::~window_()
{
	glfwTerminate();
	std::cout << "[INFO]::WIDOW DISTROY AND GLFW TEMINETED" << std::endl;
};
int window_::window_status()
{
	
	return 1;

}
}
