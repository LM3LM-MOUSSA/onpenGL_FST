#include "render.h"
#include <memory>
int main()
{
	std::unique_ptr<engine::render> render_obj 
		= std::make_unique<engine::render>();
	render_obj->_Drowing();
}