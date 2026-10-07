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
	while (m_runnig)
	{	
		if (glfwWindowShouldClose(m_window))
		{
			m_runnig = false;
		}
		glClear(GL_COLOR_BUFFER_BIT);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		glfwSwapBuffers(m_window);
		glfwPollEvents();

	}
	m_BUFFER_OBEJ->unbind_buffer();

	
	
	
}
void render::create_openGL_RENDER_SCEEN()
{
	
}
}