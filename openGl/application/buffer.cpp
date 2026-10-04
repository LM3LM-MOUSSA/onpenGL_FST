#include "core_includes.h"
#include "buffer.h"

buffer::buffer(int t_size_buffer) : VBO(t_size_buffer) 
{
	VAO = 0;
	

	



}

buffer::~buffer() {}

void buffer::create_buffer() {
	// Creat a Vertex Buffer Obj VBO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
}

 void buffer::bind_buffer(float vertices[]) {
	//
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(
		GL_ARRAY_BUFFER, 
		sizeof(vertices),
		vertices,
		GL_STATIC_DRAW
	);
	
	glVertexAttribPointer(
		0, 3,
		GL_FLOAT, 
		GL_FALSE, 
		0, 
		(void*)0
	);
	glEnableVertexAttribArray(0);
}

void buffer::unbind_buffer() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}


