#pragma once
#include "addr.h"

namespace net
{
	namespace core
	{
		class device
		{
		private:
			uint8_t hardware_id;
			std::string name;
			mac_addr mac;
			ipv4_addr ipv4;
			// TODO: add vector of ports
		public:
			virtual ~device() = default;
			ipv4_addr get_ipv4() const { return ipv4; }
			void set_ipv4(const ipv4_addr& ip) { ipv4 = ip; }
			mac_addr get_mac() const { return mac; }
			void set_mac(const mac_addr& m) { mac = m; }
			std::string get_name() const { return name; }
			void set_name(const std::string& n) { name = n; }
			uint8_t get_hardware_id() const { return hardware_id; }
			void set_hardware_id(uint8_t id) { hardware_id = id; }

			virtual void recv();
			virtual void send();
		};
	}
}