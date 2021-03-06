// PX2Serial.hpp

#ifndef PX2SERIAL_HPP
#define PX2SERIAL_HPP

#include "PX2UnityPre.hpp"
#ifdef WIN32
#include <windows.h>
#endif

namespace PX2
{

	class PX2_ENGINE_ITEM Serial
	{
#ifdef WIN32
	private:
		HANDLE hcom;
		DWORD mask;
		COMMTIMEOUTS ctmo;
		OVERLAPPED o;
		COMMPROP cmp;
#endif

	public:
		char flag_opened;
		char comport[16];
		int baudrate;

		bool Init(const std::string &comport_in, int baudrate);
		bool Close();

		void Clear();
		
		int Send(const char *buf_ptr, int size);
		int Receive(char *buf_ptr, int size);
		bool Receive2(char *buf_ptr, int size);

		int Send(const std::string &buffer);
		int Receive(std::string &buffer);
		bool Receive2(std::string &buffer);

	};

}

#endif