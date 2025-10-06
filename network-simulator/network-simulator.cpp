#include <iostream>
#include "addr.h"

int main()
{
	net::ipv4_addr ip;
	std::cout << "Enter IPv4: "; std::cin >> ip;
	std::cout << "Entered IPv4: " << ip << std::endl;
}