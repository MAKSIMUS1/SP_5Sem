#pragma warning(disable : 4996)

#include <windows.h>
#include <iostream>

using namespace std;

const wchar_t* getWCC(char* c) {
	wchar_t wc[100];
	string s = string(c) + "_stop"s;
	mbstowcs(wc, s.c_str(), s.size() + 1);
	return wc;
}


int main(int argc, char* argv[])
{
	HANDLE hStopEvent = CreateEvent(NULL,
		TRUE, //FALSE - автоматический сброс; TRUE - ручной
		FALSE,
		getWCC(argv[1]));
	SetEvent(hStopEvent);
}