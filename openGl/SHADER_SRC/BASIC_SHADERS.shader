#shader vertex
#version 330 core 
layout (locatino = 0 ) in vec4 postion ;
void main()
{
	gl_Position = postion; 

}
#shader fragment 
#version 330 core 
lyout (locatino = 0 ) out vec4 color ;
void main()
{
color =  vec4(1.0 , 0.0, 0.0 , 1.0 );

}
