#pragma once
#include "vertex_loader.h"
namespace engine {
	class buffer
	{
	public:
		buffer(int t_size_buffer);
		~buffer();
		void create_buffer();
		void bind_buffer(const vector_3& v3, const indexes& indes);
		void unbind_buffer();

	private:
		unsigned int VAO;
		unsigned int VBO;
		unsigned int IBO;
	};

}