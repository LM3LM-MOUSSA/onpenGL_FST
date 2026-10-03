#pragma once
#include "core_includes.h"
#include <vector>
struct shader_status
{
	int SH_deleltStatus;
	int SH_compailtStatus;
	int SH_length;
	int SH_type;
	int SH_srclength;

	shader_status() : SH_deleltStatus(0), SH_compailtStatus(0), SH_length(0), SH_type(0), SH_srclength(0) {};
};

class shaders
{
public:
	shaders(const std::vector<std::string> &shaderSources);

	~shaders();
	void Compaile_Shader ();
	void  Compaile_status(shader_status& sh_status);
	unsigned int use_program();
	int destroy_shader(unsigned int m_Shader);
	void destroy_program();
private: 
	const char* m_VertexShaderSource;
	const char* m_FragmentShaderSource;
	unsigned int m_ShProgram; 
	unsigned int m_VertexShader; 
	unsigned int m_FragmentShader;

};

struct Default_shader
{
	const std::string vertex_shader_src = R"(
	#version 330 core \n
	layout(location = 0) in vec3 aPos;\n
	void main()\n
	{\n
		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n
	}\n
	)";
	const std::string fragment_shader_src = R"(
	#version 330 core \n
	out vec4 FragColor;\n
	void main()\n
	{\n
		FragColor = vec4(1.0, 0.5, 0.2, 1.0);\n
	}\n
	)";
};