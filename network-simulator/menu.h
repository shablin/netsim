#pragma once
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/elements.hpp>

namespace net::simulator::cli
{
	class MainMenu
	{
	public:
		MainMenu();
		ftxui::Component get_component();
		int get_selected_idx() const;
	private:
		std::vector<std::string> items_;
		int selected_idx_;
		ftxui::Component menu_;
	};
}