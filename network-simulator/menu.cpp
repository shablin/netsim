#include "menu.h"
#include <ftxui/component/component.hpp>
#include <ftxui/dom/elements.hpp>

namespace net::simulator::cli
{
	MainMenu::MainMenu() :
		items_({ "Devices", "Network Manager", "Exit" }), selected_idx_(0)
	{
		menu_ = ftxui::Menu(&items_, &selected_idx_);
	}

	ftxui::Component MainMenu::get_component()
	{
		return ftxui::Renderer(menu_, [this]
			{
				return ftxui::vbox(
					{
						ftxui::text("NetSim - Networking Simulation Tool by @shablin (v1.0.0)") | ftxui::bold | ftxui::center,
						ftxui::separator(),
						menu_->Render(),
					}) | ftxui::border | ftxui::center;
			});
	}

	int MainMenu::get_selected_idx() const
	{
		return selected_idx_;
	}
}