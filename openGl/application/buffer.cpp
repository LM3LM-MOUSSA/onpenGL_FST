#include "core_includes.h"
#include "buffer.h"
namespace engine{
buffer::buffer(int t_size_buffer) : VAO(0), VBO(0), IBO(0)
{
}

buffer::~buffer() {}

void buffer::create_buffer() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);
}

void buffer::bind_buffer(const vector_3 &v3, const indexes& indes) {
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, v3.size() * sizeof(float), v3.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indes.size() * sizeof(unsigned int), indes.data(), GL_STATIC_DRAW);
}

void buffer::unbind_buffer() {
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

}
