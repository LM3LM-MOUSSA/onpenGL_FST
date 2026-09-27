#pragma once
#include "core_includes.h"
class shaders
{
public:
	shaders(const char& Vertex_SH , const char& Fragment_SH);
	~shaders();
	unsigned int Compaile_Shader ();
private: 
	const char* m_VertexShaderSource;
	const char* m_FragmentShaderSource;
	unsigned int m_ShProgram; 
	unsigned int m_VertexShader; 
	unsigned int m_FragmentShader;

};

