#include "shaders.h"

shaders::shaders(const char* Vertex_SH, const char* Fragment_SH)
    :
      m_ShProgram(0),
      m_VertexShader(0),
      m_FragmentShader(0)
{
    m_FragmentShaderSource = Fragment_SH;
    m_VertexShaderSource = Vertex_SH;
}
shaders::~shaders() 
{
    
    
}
void shaders::Compaile_Shader() 
{
    
    m_ShProgram = glCreateProgram();
    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_VertexShader,1,&m_VertexShaderSource,nullptr);
    glCompileShader(m_VertexShader);
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_FragmentShader,1,&m_FragmentShaderSource,nullptr);
    glCompileShader(m_FragmentShader);


    shader_status VertexShader_status;
    shader_status FragmentShader_status;
    Compaile_status(VertexShader_status);
    Compaile_status(FragmentShader_status);


    if (VertexShader_status.SH_compailtStatus == GL_FALSE) {
        std::cout
            << "[ERROR]::Vertex Shader Error: FALAID TO COMPAILE -verfie the src  \n  "
            << std::endl;
        destroy_shader(m_VertexShader);
        return;
    }
    if (FragmentShader_status.SH_compailtStatus == GL_FALSE) {
        std::cout
            << "[ERROR]::Fragment Shader Error: -verfie the src  \n"
            << std::endl;
        destroy_shader(m_FragmentShader);
        return;
    }
    glAttachShader(m_ShProgram,m_VertexShader);
    glAttachShader(m_ShProgram, m_FragmentShader);
    glLinkProgram(m_ShProgram);
    glValidateProgram(m_ShProgram);
   

    
    
}
void shaders::Compaile_status(shader_status& sh_status)
{
    ;
    glGetShaderiv(m_VertexShader, GL_SHADER_TYPE, &sh_status.SH_type);
    glGetShaderiv(m_VertexShader, GL_INFO_LOG_LENGTH, &sh_status.SH_length);
    glGetShaderiv(m_VertexShader, GL_SHADER_SOURCE_LENGTH, &sh_status.SH_srclength);
    glGetShaderiv(m_VertexShader, GL_COMPILE_STATUS, &sh_status.SH_compailtStatus);

}

int shaders::destroy_shader(unsigned int m_Shadertype)
{
    if (m_Shadertype == m_VertexShader)
    {
        glDeleteShader(m_VertexShader);
        return 1;
    }
    else if (m_Shadertype == m_FragmentShader)
    {
        glDeleteShader(m_FragmentShader);
        return 1; 
    }
    
        return 0; 
}
void shaders::destroy_program() 
{
    glDeleteProgram(m_ShProgram);
}
unsigned int shaders::use_program() 
{
    return m_ShProgram;
}
