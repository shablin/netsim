#include "application.h"
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

namespace net::simulator::cli
{
	application::application() :
		screen_(ftxui::ScreenInteractive::Fullscreen()) { }

	void application::run()
	{
		auto main_component = main_menu_.get_component();
		screen_.Loop(main_component);
	}
}