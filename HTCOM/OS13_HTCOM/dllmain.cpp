// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "ClassFactory.h"
#include "Registry.h"

HMODULE g_hModule;                                          // Описатель модуля
const WCHAR* FNAME = L"OS13_HTCOM.dll";
const WCHAR* VerInd = L"Smw.CA";
const WCHAR* ProgId = L"Smw.CA.1";

long g_cComponents = 0;		                                // Количество активных компонентов
long g_cServerLocks = 0;                                    // Счетчик блокировок


// {BD5ACDED-52BD-4922-9C05-2ABD3619985F}
static const GUID CLSID_ComponentHT =
{ 0xbd5acded, 0x52bd, 0x4922, { 0x9c, 0x5, 0x2a, 0xbd, 0x36, 0x19, 0x98, 0x5f } };


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        g_hModule = hModule;
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

STDAPI DllCanUnloadNow()
{
	if ((g_cComponents == 0) && (g_cServerLocks == 0))
	{
		return S_OK;
	}
	else
	{
		return S_FALSE;
	}
}

STDAPI DllGetClassObject(const CLSID& clsid,
	const IID& iid,
	void** ppv)
{
	std::cout << "DllGetClassObject:\tСоздать фабрику класса" << std::endl;
	if (clsid != CLSID_ComponentHT)
	{
		return CLASS_E_CLASSNOTAVAILABLE;
	}
	ClassFactory* pFactory = new ClassFactory;
	if (pFactory == NULL)
	{
		return E_OUTOFMEMORY;
	}
	HRESULT hr = pFactory->QueryInterface(iid, ppv);
	pFactory->Release();

	return hr;
}

HRESULT __declspec(dllexport) DllRegisterServer() {
	return RegisterServer(g_hModule, CLSID_ComponentHT, FNAME, VerInd, ProgId);
}

HRESULT __declspec(dllexport) DllUnregisterServer() {
	return UnregisterServer(CLSID_ComponentHT, VerInd, ProgId);
}

STDAPI DllInstall(bool b, PCWSTR s)
{
	return S_OK;
}