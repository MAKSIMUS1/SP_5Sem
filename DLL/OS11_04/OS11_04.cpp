﻿#include <string>
#include <sstream>
#include "../OS11_HTAPI/pch.h"
#include "../OS11_HTAPI/HT.h"

using namespace std;

wchar_t* getWC(const char* c);
string intToString(int number);
int charToInt(char* str);
string incrementPayload(char* str);

int main(int argc, char* argv[])
{
	try
	{
		HMODULE hmdll = LoadLibrary(L"OS11_HTAPI.dll");
		if (!hmdll)
			throw "-- LoadLibrary failed";
		cout << "-- LoadLibrary success" << endl;

		auto open = (ht::HtHandle * (*)(const wchar_t*, bool)) GetProcAddress(hmdll, "open");
		auto get = (ht::Element * (*)(ht::HtHandle*, const ht::Element*)) GetProcAddress(hmdll, "get");
		auto update = (BOOL(*)(ht::HtHandle *, const ht::Element*, const void*, int)) GetProcAddress(hmdll, "update");
		auto createGetElement = (ht::Element * (*)(const void*, int)) GetProcAddress(hmdll, "createGetElement");

		ht::HtHandle* ht = open(getWC(argv[1]), true);
		if (ht)
			cout << "-- open: success" << endl;
		else
			throw "-- open: error";

		while (true) {
			int numberKey = rand() % 50;
			string key = intToString(numberKey);
			cout << key << endl;

			ht::Element* element = get(ht, createGetElement(key.c_str(), key.length() + 1));
			if (element)
			{
				cout << "-- get: success" << endl;
				string newPayload = incrementPayload((char*)element->payload);

				if (update(ht, element, newPayload.c_str(), newPayload.length() + 1))
					cout << "-- update: success" << endl;
				else
					cout << "-- update: error" << endl;
			}
			else
				cout << "-- get: error" << endl;

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

int charToInt(char* str)
{
	stringstream convert;
	convert << str;
	int num;
	convert >> num;

	return num;
}

string incrementPayload(char* str)
{
	int oldNumberPayload = charToInt(str);
	int newNumberPayload = oldNumberPayload + 1;
	string newPayload = intToString(newNumberPayload);

	return newPayload;
}
wchar_t* getWC(const char* c)
{
	wchar_t* wc = new wchar_t[strlen(c) + 1];
	mbstowcs(wc, c, strlen(c) + 1);

	return wc;
}