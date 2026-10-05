#shader vertex
#version 330 core 
layout (location = 0 ) in vec4 postion ;
void main()
{
	vec4 newPosition = postion;
   
	gl_Position = newPosition; 

}
#shader fragment 
#version 330 core 
layout (location = 0 ) out vec4 color ;
void main()
{
color =  vec4(0.3 , 0.2, 0.1 , 1.0 );

}
