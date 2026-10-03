#include "core_includes.h"
#include "window_.h"
#include "shaders.h"
#include <vector>
#include "Shader Src Expractor .h"

int main() {
	
	const std::vector<std::string> shaderSources = LoadShaders
	(
		"openGl/SHADER_SRC/BASIC_SHADERS.shader"
	);
	std::cout
		<< "[INFO]::SHADERS SRC : \t "
		<< "VERTEX SHADER SRC : \n" << shaderSources[SHADER_VERTEX] << "\n"
		<< "FRAGMENT SHADER SRC : \n" << shaderSources[SHADER_FRAGMENT] << "\n"
		<< std::endl;
	shader_status Shaders_STATUS = shader_status();
	
	std::unique_ptr<window_> window(new window_(800, 600, "Test"));
	std::unique_ptr<buffer> glBuffer(new buffer(1));
	std::unique_ptr<shaders> sheder_VER_FRAG (new shaders(shaderSources));
	window->window_init();
	sheder_VER_FRAG->Compaile_Shader();
	sheder_VER_FRAG->Compaile_status(Shaders_STATUS);
	std::cout << "[INFO]::SHADERS STATUS : \t "
		<< "SH_compailtStatus" << Shaders_STATUS.SH_compailtStatus << "\t "
		<< "SH_length" << Shaders_STATUS.SH_length << "\t " << std::endl;
	window->glfw_window_creation(glBuffer.get(), sheder_VER_FRAG.get());
	return 0; 
}
