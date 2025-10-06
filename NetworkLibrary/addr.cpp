#include "addr.h"  
#include <string>  
#include <iostream>  
#include <vector>  
#include <sstream>

namespace net
{
	ipv4_addr ipv4_addr::parse_from_str(std::string ip_str)
	{  
		std::vector<std::string> octets;
		std::stringstream ss(ip_str);
		std::string item;
	
		while (std::getline(ss, item, '.')) {
			octets.push_back(item);
		}

		ipv4_addr ip{};
		for (size_t i = 0; i < octets.size(); i++) {  
			int byte = std::stoi(octets[i]);  
			if (byte < 0 || byte > 255) {  
				throw std::invalid_argument("Invalid IPv4 address");  
			}  
			ip.bytes[i] = static_cast<uint8_t>(byte);  
		} 

		return ip;
	}

	std::string ipv4_addr::conv_to_str(ipv4_addr ip) const
	{
		return	std::to_string(ip.bytes[0]) + "." +
				std::to_string(ip.bytes[1]) + "." +
				std::to_string(ip.bytes[2]) + "." +
				std::to_string(ip.bytes[3]);
	}

	std::ostream& operator<<(std::ostream& os, const ipv4_addr& ip)
	{
		os << static_cast<int>(ip.bytes[0]) << "."
			<< static_cast<int>(ip.bytes[1]) << "."
			<< static_cast<int>(ip.bytes[2]) << "."
			<< static_cast<int>(ip.bytes[3]);
		return os;
	}

	std::istream& operator>>(std::istream& is, ipv4_addr& ip)
	{
		std::string ip_str;
		is >> ip_str;
		ip = ipv4_addr::parse_from_str(ip_str);
		return is;
	}
}