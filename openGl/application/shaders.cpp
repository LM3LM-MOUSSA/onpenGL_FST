#include "shaders.h"
#include "Shader Src Expractor .h"
namespace engine {

shaders::shaders(const std::vector<std::string> &shaderSources)
    :
      m_ShProgram(0),
      m_VertexShader(0),
      m_FragmentShader(0)
{
    m_FragmentShaderSource = shaderSources[SHADER_FRAGMENT];
    m_VertexShaderSource = shaderSources[SHADER_VERTEX];
}
shaders::~shaders() 
{
    
    
}
void shaders::Compaile_Shader() 
{
    
    m_ShProgram = glCreateProgram();
    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vSrc = m_VertexShaderSource.c_str();
    glShaderSource(m_VertexShader,1,&vSrc,nullptr);
    glCompileShader(m_VertexShader);
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fSrc = m_FragmentShaderSource.c_str();
    glShaderSource(m_FragmentShader,1,&fSrc,nullptr);
    glCompileShader(m_FragmentShader);


    shader_status VertexShader_status;
    shader_status FragmentShader_status;
    Compaile_status(m_VertexShader, VertexShader_status);
    Compaile_status(m_FragmentShader, FragmentShader_status);


    if (VertexShader_status.SH_compailtStatus == GL_FALSE) {
        std::cout
            << "[ERROR]::Vertex Shader Error: FALAID TO COMPAILE -verfie the src  \n  "
            << "see with the follwing  source code "
            << m_VertexShaderSource
            << std::endl;
        destroy_shader(m_VertexShader);
        return;
    }
    if (FragmentShader_status.SH_compailtStatus == GL_FALSE) {
        std::cout
            << "[ERROR]::Fragment Shader Error: -verfie the src  \n"
            << "see with the follwing  source code "
            << m_FragmentShaderSource
            << std::endl;
        destroy_shader(m_FragmentShader);
        return;
    }

    glAttachShader(m_ShProgram,m_VertexShader);
    glAttachShader(m_ShProgram, m_FragmentShader);
    glLinkProgram(m_ShProgram);
    glValidateProgram(m_ShProgram);

    int linkStatus;
    glGetProgramiv(m_ShProgram, GL_LINK_STATUS, &linkStatus);
    if (linkStatus == GL_FALSE) {
        int length;
        glGetProgramiv(m_ShProgram, GL_INFO_LOG_LENGTH, &length);
        std::string infoLog(length, '\0');
        glGetProgramInfoLog(m_ShProgram, length, &length, &infoLog[0]);
        std::cout << "[ERROR]::Shader Program Linking Failed:\n" << infoLog << std::endl;
        destroy_program();
        return;
    }

    // Clean up individual shaders after successful linking
    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);
    
}
void shaders::Compaile_status(unsigned int shaderID, shader_status& sh_status)
{
    glGetShaderiv(shaderID, GL_SHADER_TYPE, &sh_status.SH_type);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &sh_status.SH_length);
    glGetShaderiv(shaderID, GL_SHADER_SOURCE_LENGTH, &sh_status.SH_srclength);
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &sh_status.SH_compailtStatus);

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
}