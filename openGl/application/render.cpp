#include "render.h"
#include "core_includes.h"
#include "window_.h"
#include "shaders.h"
#include "Shader Src Expractor .h"

namespace engine
{
static vector_3  v3 = {
	-0.5f, -0.5f, 
	 0.5f, -0.5f, 
	 0.5f,  0.5f, 
	-0.5f,  0.5f  
};
static indexes indeses_obj = {
	0, 1, 2,
	2, 3, 0
};
struct rgb_CHANNELS {
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;
};

render::render()
{
	const std::vector<std::string> shaderSources = LoadShaders
	(
		"openGl/SHADER_SRC/BASIC_SHADERS.shader"
	);
	std::cout
		<< "[INFO]::SHADERS SRC : \t "
		<< "VERTEX SHADER SRC : \n" << shaderSources[SHADER_VERTEX] << "\n"
		<< "FRAGMENT SHADER SRC : \n" << shaderSources[SHADER_FRAGMENT] << "\n"
		<< std::endl;
	m_window_obj = std::make_unique<window_>(800, 600, "OpenGL Window");
	m_runnig = m_window_obj->window_init();
	m_window = m_window_obj->Get_Window();
	m_BUFFER_OBEJ = std::make_unique<buffer>(1);
	m_BUFFER_OBEJ->create_buffer();
	m_BUFFER_OBEJ->bind_buffer(v3, indeses_obj);
	std::cout << "[INFO]::GLBUFFER CREATED AND BIND SUCCESSFULLY \n" << std::endl;
	m_SHADER_OBJ = std::make_unique<shaders>(shaderSources);
	m_SHADER_OBJ->Compaile_Shader();
	std::cout << "[INFO]::SHADERS COMPILED SUCCESSFULLY" << std::endl;

}

render::~render()
{

}




void render::_Drowing()
{
	

	glUseProgram(m_SHADER_OBJ->use_program());
	int location = glGetUniformLocation(m_SHADER_OBJ->use_program(), "u_Color");
	if (location == -1)
	{
		std::cout << "[ERROR]::Failed to get uniform location for u_Color" << std::endl;
		return;
	}
	else
		std::cout << "[INFO]::Uniform location for u_Color: \t "
		<< "in the following location on the prog :"
		<< location
		<< location << std::endl;
	static float  increment = 0.04f;
	static rgb_CHANNELS rgb_channels = { 1.0f, 0.0f, 0.0f };

	glUniform4f(location, rgb_channels.r, rgb_channels.g,rgb_channels.b, 1.0f);
	while (m_runnig)
	{	
		if (glfwWindowShouldClose(m_window))
		{
			m_runnig = false;
		}
		glClear(GL_COLOR_BUFFER_BIT);
		glUniform4f(location, rgb_channels.r, rgb_channels.g, rgb_channels.b, 1.0f);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		if (rgb_channels.r > 1.0f && rgb_channels.g > 1.0f && rgb_channels.b > 1.0f)
		{
			increment = -0.04f;

		}
		else if (rgb_channels.r < 0.0f && rgb_channels.g < 0.0f && rgb_channels.b < 0.0f)
		{
			increment = 0.04f;
		}
			rgb_channels.r += increment;
			rgb_channels.g += increment;
			rgb_channels.b += increment;
		
		glfwSwapBuffers(m_window);
		glfwPollEvents();

	}
	m_BUFFER_OBEJ->unbind_buffer();

	
	
	
}
void render::create_openGL_RENDER_SCEEN()
{
	
}
}
