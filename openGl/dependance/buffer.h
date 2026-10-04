#pragma once
#include "vertex_loader.h"
class buffer
{
public:
	buffer(int t_size_buffer);
	~buffer();
	void create_buffer();
	void bind_buffer(float vertices[]);
	void unbind_buffer();
	
private:
	unsigned int VBO ;
	unsigned int VAO;
	 
};

