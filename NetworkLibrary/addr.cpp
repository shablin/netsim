#include "addr.h"  
#include <string>  
#include <iostream>  
#include <vector>  
#include <sstream>
#include "exceptions.h"
#include "utils.h"

namespace net
{
	namespace core
	{

		/*
		* 
		* ipv4_addr methods
		*
		*/

		ipv4_addr ipv4_addr::parse_from_str(std::string ip_str)
		{
			auto octets = net::utils::split_ivp4_addr_str(ip_str);
			ipv4_addr ipv4{};
			std::copy(octets.begin(), octets.end(), ipv4.bytes);

			return ipv4;
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
			return	os << static_cast<int>(ip.bytes[0]) << "."
					<< static_cast<int>(ip.bytes[1]) << "."
					<< static_cast<int>(ip.bytes[2]) << "."
					<< static_cast<int>(ip.bytes[3]);
		}

		std::istream& operator>>(std::istream& is, ipv4_addr& ip)
		{
			std::string ip_str;
			is >> ip_str;

			if (ip_str.length() > IPV4_MAX_STR_LEN ||
				std::count(ip_str.begin(), ip_str.end(), '.') !=
				IPV4_MAX_SEPARATORS)
			{
				throw net::exception::invalid_ipv4_addr(
					"Invalid IPv4 address: maximum "
					"allowed length is 15 chars"
				);
			}

			ip = ipv4_addr::parse_from_str(ip_str);
			return is;
		}

		/*
		* 
		* mac_addr methods
		*
		*/

		mac_addr mac_addr::parse_from_str(std::string mac_str)
		{
			auto octets = net::utils::split_mac_addr_str(mac_str);
			mac_addr mac{};
			std::copy(octets.begin(), octets.end(), mac.bytes);
		
			return mac;
		}

		std::string mac_addr::conv_to_str(mac_addr mac) const
		{
			return	std::to_string(mac.bytes[0]) + ":" +
					std::to_string(mac.bytes[1]) + ":" +
					std::to_string(mac.bytes[2]) + ":" +
					std::to_string(mac.bytes[3]) + ":" +
					std::to_string(mac.bytes[4]) + ":" +
					std::to_string(mac.bytes[5]);
		}

		std::ostream& operator<<(std::ostream& os, const mac_addr& mac)
		{
			return	os << std::hex 
					<< static_cast<int>(mac.bytes[0]) << ":"
					<< static_cast<int>(mac.bytes[1]) << ":"
					<< static_cast<int>(mac.bytes[2]) << ":"
					<< static_cast<int>(mac.bytes[3]) << ":"
					<< static_cast<int>(mac.bytes[4]) << ":"
					<< static_cast<int>(mac.bytes[5])
					<< std::dec;
		}

		std::istream& operator>>(std::istream& is, mac_addr& mac)
		{
			std::string mac_str;
			is >> mac_str;

			if (mac_str.length() > MAC_MAX_STR_LEN ||
				std::count(mac_str.begin(), mac_str.end(), ':') !=
				MAC_MAX_SEPARATORS)
			{
				throw net::exception::invalid_mac_addr(
					"Invalid MAC address: maximum "
					"allowed length is 17 chars"
				);
			}

			mac = mac_addr::parse_from_str(mac_str);
			return is;
		}
	}
}