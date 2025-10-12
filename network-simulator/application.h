#pragma once
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "menu.h"

namespace net::simulator::cli
{
	class application
	{
	public:
		application();
		void run();
	private:
		ftxui::ScreenInteractive screen_;
		MainMenu main_menu_;
	};
}