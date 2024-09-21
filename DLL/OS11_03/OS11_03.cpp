#ifdef _WIN64
#pragma comment(lib, "../x64/Debug/OS11_HTAPI.lib")
#else
#pragma comment(lib, "../Debug/OS11_HTAPI.lib")
#endif

#include <string>
#include <sstream>
#include "../OS11_HTAPI/pch.h"
#include "../OS11_HTAPI/HT.h"

using namespace std;

wchar_t* getWC(const char* c);
string intToString(int number);

int main(int argc, char* argv[])
{
	try
	{
		ht::HtHandle* ht = ht::open(getWC(argv[1]), true);
		if (ht)
			cout << "-- open: success" << endl;
		else
			throw "-- open: error";

		while (true) {
			int numberKey = rand() % 50;
			string key = intToString(numberKey);
			cout << key << endl;

			ht::Element* element = new ht::Element(key.c_str(), key.length() + 1);
			if (ht::removeOne(ht, element))
				cout << "-- remove: success" << endl;
			else
				cout << "-- remove: error" << endl;

			delete element;

			Sleep(1000);
		}
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

string intToString(int number)
{
	stringstream convert;
	convert << number;

	return convert.str();
}

wchar_t* getWC(const char* c)
{
	wchar_t* wc = new wchar_t[strlen(c) + 1];
	mbstowcs(wc, c, strlen(c) + 1);

	return wc;
}