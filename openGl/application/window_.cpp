#include "core_includes.h"
#include "window_.h"
#include "buffer.h"
#include "shaders.h"
vector_3 v3 = vector_3();
bool runnig = true;
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
void window_::input() {

	if (!glfwWindowShouldClose(m_window))
	{
		glfwPollEvents();
		
	}
	else {
		runnig = false;
	}
}

void window_::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glfwSwapBuffers(m_window);
}

int window_::glfw_window_creation(buffer* BUFFER_OBEJ , shaders* CHADER_OBJ) 
{
	BUFFER_OBEJ->create_buffer();
	BUFFER_OBEJ->bind_buffer(v3);
	std::cout << "[INFO]::GLBUFFER CREATED AND BIND SUCCESSFULLY \n [INFO]::STARTING DRAWING" << std::endl;
	glUseProgram(CHADER_OBJ->use_program());
	while (runnig)
	{   
		input();
		draw();
	}

	BUFFER_OBEJ->unbind_buffer(v3);
	glfwTerminate();
	std::cout << "[INFO]::WIDOW DISTROY AND GLFW TEMINETED" << std::endl;
	return 0;
}

window_::window_(int width, int height, const char* title) 
	:width(width), height(height), title(title) ,m_window(nullptr)
{
	
}


window_::~window_(){};
int window_::window_status()
{
	
	return 1;

}