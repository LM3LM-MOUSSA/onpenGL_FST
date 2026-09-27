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
unsigned int shaders::Compaile_Shader(int destroy) 
{
    m_ShProgram = glCreateProgram();
    // ymkn yssir errure kybda m_FragmentShaderSource much meyoufech b nulltreminter {\0}
    m_VertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_VertexShader,1,&m_FragmentShaderSource,nullptr);
    glCompileShader(m_VertexShader);
    m_FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_FragmentShader,1,&m_FragmentShaderSource,nullptr);
    glCompileShader(m_FragmentShader);
    // check status b func shaders::Compaile_status//
    glAttachShader(m_ShProgram,m_VertexShader);
    glAttachShader(m_ShProgram, m_FragmentShader);
    glLinkProgram(m_ShProgram);
    glValidateProgram(m_ShProgram);
    if (destroy == 1) 
    {
        destroy_shader();
    }

    return m_ShProgram;
    
}
 std::string shaders::Compaile_status(unsigned int m_type) 
{
    int status = 0;
    glGetShaderiv(m_type, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE)
    {
        int length = 0;
        glGetShaderiv(m_type, GL_INFO_LOG_LENGTH, &length);
        
        std::string errorLog(length, ' ');
        errorlog = std::string(m_type);
        glGetShaderInfoLog(m_type, length, nullptr, &errorLog[1]);
        return  errorLog;

    }
    return "NULL";
   
}

void shaders::destroy_shader() 
{
    glDeleteShader(m_VertexShader);
    glDeleteShader(m_FragmentShader);
   
}
void shaders::destroy_program() 
{
    glDeleteProgram(m_ShProgram);
}