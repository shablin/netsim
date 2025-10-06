#pragma once
#include <exception>

namespace net
{
	namespace exception
	{

		class generic_exception : public std::exception
		{
		private:
			const char* msg;
		public:
			generic_exception(const char* _msg) noexcept
				: msg(_msg) {
			}

			const char* what() const noexcept override
			{
				return msg;
			}
		};

		class invalid_ipv4_addr : public generic_exception
		{
		public:
			invalid_ipv4_addr(const char* _msg) noexcept
				: generic_exception(_msg) {
			};
		};

		class invalid_mac_addr : public generic_exception
		{
		public:
			invalid_mac_addr(const char* _msg) noexcept
				: generic_exception(_msg) {
			};
		};
	}
};