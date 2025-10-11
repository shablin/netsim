#pragma once
#include <string>
#include <vector>

namespace net
{
	namespace utils
	{
		std::vector<uint8_t> split_ivp4_addr_str(std::string ipv4_str);
		std::vector<uint8_t> split_mac_addr_str(std::string mac_str);
	}
}