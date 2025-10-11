#pragma once
#include <cstdint>
#include <string>

namespace net
{
	namespace core
	{
		constexpr auto IPV4_MAX_STR_LEN = 15;
		constexpr auto IPV4_MAX_OCTETS = 4;
		constexpr auto IPV4_MAX_OCTET_VAL = 255;
		constexpr auto IPV4_MAX_SEPARATORS = 3;

		constexpr auto MAC_MAX_STR_LEN = 17;
		constexpr auto MAC_MAX_OCTETS = 6;
		constexpr auto MAC_MAX_OCTET_VAL = 0xFF;
		constexpr auto MAC_MAX_SEPARATORS = 5;

		struct mac_addr {
			uint8_t bytes[MAC_MAX_OCTETS]; // 48 bits (6 bytes)
			static mac_addr parse_from_str(std::string mac_str);
			std::string conv_to_str(mac_addr mac) const;
			// bool operator==(const mac_addr& other) const;
			// bool operator!=(const mac_addr& other) const;
		};

		std::ostream& operator<<(std::ostream& os, const mac_addr& mac);
		std::istream& operator>>(std::istream& is, mac_addr& mac);

		struct ipv4_addr
		{
			uint8_t bytes[IPV4_MAX_OCTETS]; // 32 bits (4 bytes)
			static ipv4_addr parse_from_str(std::string ipv4_str);
			std::string conv_to_str(ipv4_addr ip) const;
			// bool operator==(const IPv4& other) const;
			// bool operator!=(const IPv4& other) const;
		};

		std::ostream& operator<<(std::ostream& os, const ipv4_addr& ip);
		std::istream& operator>>(std::istream& is, ipv4_addr& ip);
	}
}