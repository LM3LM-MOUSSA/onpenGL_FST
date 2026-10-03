#pragma once
#include <string>


class shader {
public:
	shader(const std::string& vertex_src, const std::string& fragment_src);
    shader(unsigned int shaderProgram,unsigned int shaderVs);
    ~shader();
    unsigned int compileShader(const std::string& src, unsigned int type_Shader);
private:

    unsigned int m_shaderProgram ;
    unsigned int m_shaderVs;






};


