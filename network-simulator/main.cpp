#include <iostream>
#include "addr.h"

int main() {
	net::core::ipv4_addr ipv4;
	net::core::mac_addr mac;

	std::cout << "Enter IPv4: "; std::cin >> ipv4;
	std::cout << "IPv4: " << ipv4 << std::endl;

	std::cout << "Enter MAC: "; std::cin >> mac;
	std::cout << "MAC: " << mac << std::endl;
}