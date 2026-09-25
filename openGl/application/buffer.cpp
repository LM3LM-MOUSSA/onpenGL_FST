#include "core_includes.h"
#include "buffer.h"

buffer::buffer(int t_size_buffer) : VBO(t_size_buffer) {}

buffer::~buffer() {}

void buffer::create_buffer() {
	glGenBuffers(1, &VBO);
}

void buffer::bind_buffer(vector_3 &v3) {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(v3), &v3, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);
}

void buffer::unbind_buffer(vector_3 &v3) {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	(void)v3;
}


