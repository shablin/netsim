#include "utils.h"
#include "addr.h"
#include <sstream>
#include <vector>
#include "exceptions.h"

namespace net
{
	namespace utils
	{
		std::vector<uint8_t> split_ivp4_addr_str(std::string ipv4_str)
		{
			char ipv4_sprt = '.';
			std::vector<uint8_t> octets;
			std::stringstream ss(ipv4_str);
			std::string token;

			while (std::getline(ss, token, ipv4_sprt))
			{
				int byte = std::stoi(token);
				if (byte < 0 || byte > MAX_IPV4_OCTET_VAL)
					throw net::exception::invalid_ipv4_addr(
						"Invalid IPv4 format: segment out of range"
					);
				octets.push_back(static_cast<uint8_t>(byte));
			}

			if (octets.size() != MAX_IPV4_OCTETS)
				throw net::exception::invalid_ipv4_addr(
					"Invalid IPv4 format: excepted four "
					"numeric octets separated by dots"
				);

			return octets;
		}

		std::vector<std::uint8_t> split_mac_addr_str(std::string str)
		{
			char mac_sprt = ':';
			std::vector<uint8_t> octets;
			std::stringstream ss(str);
			std::string token;

			while (std::getline(ss, token, mac_sprt))
			{
				int byte = std::stoi(token, nullptr, 16);
				if (byte < 0 || byte > MAX_MAC_OCTET_VAL)
					throw net::exception::invalid_mac_addr(
						"Invalid MAC format: segment out of range"
					);
				octets.push_back(static_cast<uint8_t>(byte));
			}

			if (octets.size() != MAX_MAC_OCTETS)
				throw net::exception::invalid_mac_addr(
					"Invalid MAC format: excepted six "
					"hexadecimal octets separated by colons"
				);

			return octets;
		}
	}
}