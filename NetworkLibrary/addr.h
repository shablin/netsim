#pragma once
#include <cstdint>
#include <string>

namespace net
{
#define MAX_IPV4_STR_LEN 15
#define MAX_MAC_STR_LEN 17

#define MAX_IPV4_OCTETS 4
#define MAX_MAC_OCTETS 6

#define MAX_IPV4_OCTET_VAL 255

	//struct MacAddress {
	//	uint8_t bytes[6]; // 48 bits (6 bytes)
	//	static MacAddress parse_from_str(std::string mac_str);
	//	std::string conv_to_str() const;
	//	bool operator==(const MacAddress& other) const;
	//	bool operator!=(const MacAddress& other) const;
	//};

	//std::ostream& operator<<(std::ostream& os, const MacAddress& mac);

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