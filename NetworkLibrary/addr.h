#pragma once
#include <cstdint>
#include <string>

namespace net
{
	namespace core
	{
#define MAX_IPV4_STR_LEN 15
#define MAX_MAC_STR_LEN 17

#define MAX_IPV4_OCTETS 4
#define MAX_MAC_OCTETS 6

#define MAX_IPV4_OCTET_VAL 255
#define MAX_MAC_OCTET_VAL 0xFF

		struct mac_addr {
			uint8_t bytes[MAX_MAC_OCTETS]; // 48 bits (6 bytes)
			static mac_addr parse_from_str(std::string mac_str);
			std::string conv_to_str(mac_addr mac) const;
			// bool operator==(const MacAddress& other) const;
			// bool operator!=(const MacAddress& other) const;
		};

		std::ostream& operator<<(std::ostream& os, const mac_addr& mac);
		std::istream& operator>>(std::istream& is, mac_addr& mac);

		struct ipv4_addr
		{
			uint8_t bytes[MAX_IPV4_OCTETS]; // 32 bits (4 bytes)
			static ipv4_addr parse_from_str(std::string ipv4_str);
			std::string conv_to_str(ipv4_addr ip) const;
			// bool operator==(const IPv4& other) const;
			// bool operator!=(const IPv4& other) const;
		};

		std::ostream& operator<<(std::ostream& os, const ipv4_addr& ip);
		std::istream& operator>>(std::istream& is, ipv4_addr& ip);
	}
}