#pragma once
#include "core_includes.h"
#include "buffer.h"
#include "shaders.h"
#include "window_.h"
namespace engine {
	class render
	{
	public:
		render();
		~render();
		void input();
		void _Drowing();
		void create_openGL_RENDER_SCEEN();
	private:
		bool m_runnig;
		GLFWwindow * m_window;
		std::unique_ptr<window_> m_window_obj;
		std::unique_ptr<buffer> m_BUFFER_OBEJ ;
		std::unique_ptr<shaders> m_SHADER_OBJ ;
	};

	enum API
	{
		OPENGL,
		DIRECTX,
		VULKAN

	};
}
