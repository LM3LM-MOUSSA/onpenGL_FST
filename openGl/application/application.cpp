#include "core_includes.h"
#include "window_.h"
#include "shaders.h"

int main() {
	
	shader_status Shaders_STATUS = shader_status();
	Default_shader Df_Shaders = Default_shader();
	std::unique_ptr<window_> window(new window_(800, 600, "Test"));
	std::unique_ptr<buffer> glBuffer(new buffer(1));
	std::unique_ptr<shaders> sheder_VER_FRAG (new shaders(Df_Shaders.vertex_shader_src.c_str(), Df_Shaders.fragment_shader_src.c_str()));
	sheder_VER_FRAG->Compaile_Shader();
	sheder_VER_FRAG->Compaile_status(Shaders_STATUS);
	std::cout << "[INFO]::SHADERS STATUS : \t "
		<< "SH_compailtStatus" << Shaders_STATUS.SH_compailtStatus << "\t "
		<< "SH_length" << Shaders_STATUS.SH_length << "\t " << std::endl;
	window->window_init();
	window->glfw_window_creation(glBuffer.get(), sheder_VER_FRAG.get());
	return 0; 
}