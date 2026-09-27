#include "shaders.h"

shaders::shaders(const char& Vertex_SH, const char& Fragment_SH)
    :
      m_ShProgram(0),
      m_VertexShader(0),
      m_FragmentShader(0)
{
    m_FragmentShaderSource = &Fragment_SH;
    m_VertexShaderSource = &Vertex_SH;
}
shaders::~shaders() 
{
    
}
unsigned int Compaile_Shader() 
{

}
