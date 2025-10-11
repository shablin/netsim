#include <iostream>
#include "addr.h"

int main()
{
	net::core::ipv4_addr ip;
	net::core::mac_addr mac;

	std::cout << "Enter IPv4: "; std::cin >> ip;
	std::cout << "Entered IPv4: " << ip << std::endl;

	std::cout << "Enter MAC: "; std::cin >> mac;
	std::cout << "Entered MAC: " << mac << std::endl;
}