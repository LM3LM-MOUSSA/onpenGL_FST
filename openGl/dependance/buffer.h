#pragma once
#include "vortex_loader.h"
class buffer
{
public :
	buffer(int t_size_buffer);
	~buffer();
	void create_buffer();
	void bind_buffer(vector_3 &v3);
	void unbind_buffer(vector_3 &v3);
	
private:
	unsigned int VBO ;
};

