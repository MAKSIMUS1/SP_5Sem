#pragma once

#define OS11_HTAPI_API __declspec(dllexport)

namespace ht
{
	extern "C" OS11_HTAPI_API struct Element   // ������� 
	{
		OS11_HTAPI_API Element();
		OS11_HTAPI_API Element(const void* key, int keyLength);                                             // for get
		OS11_HTAPI_API Element(const void* key, int keyLength, const void* payload, int  payloadLength);    // for insert
		OS11_HTAPI_API Element(const Element* oldElement, const void* newPayload, int  newPayloadLength);   // for update
		const void* key;                 // �������� ����� 
		int         keyLength;           // ������ �����
		const void* payload;             // ������ 
		int         payloadLength;       // ������ ������
	};

	extern "C" OS11_HTAPI_API Element * createGetElement(const void* key, int keyLength);
	extern "C" OS11_HTAPI_API Element * createInsertElement(const void* key, int keyLength, const void* payload, int  payloadLength);

	int getSizeElement(
		int   maxKeyLength,                // ������������ ������ �����
		int   maxPayloadLength);           // ������������ ������ ������
}