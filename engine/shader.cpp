#include "shaders.h"
#include "core_includes.h"

shaders::shaders(const std::string& vertex_src, const std::string& fragment_src){
    
}


shaders::shaders(unsigned int shaderProgram,unsigned int shaderVs):m_shaderProgram(shaderProgram),m_shaderVs(shaderVs)
{
    m_shaderProgram = glCreateProgram();
    m_shaderVs= compileShader(GL_VERTEX_SHADER);

}





shaders::~shaders() {}
unsigned int shaders::compileShader(const std::string& src, unsigned int type_Shader){


}