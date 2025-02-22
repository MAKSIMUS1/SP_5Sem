#pragma once

#include "../../File_mapping/OS10_HTAPI/pch.h"
#include "../../File_mapping/OS10_HTAPI/HT.h"

// {379F801C-93E1-46AD-BC44-03454B0B41A5}
static const GUID IID_IHT =
{ 0x379f801c, 0x93e1, 0x46ad, { 0xbc, 0x44, 0x3, 0x45, 0x4b, 0xb, 0x41, 0xa5 } };

interface IHT : IUnknown {
    STDMETHOD(create(ht::HtHandle** htHandle, int capacity, int secSnapshotInterval, int maxKeyLength, int maxPayloadLength, const wchar_t* fileName)) PURE;
    STDMETHOD(open(ht::HtHandle** htHandle, const wchar_t* fileName, bool isMapFile = false)) PURE;
    STDMETHOD(snap(BOOL& rc, ht::HtHandle* htHandle)) PURE;
    STDMETHOD(close(BOOL& rc, ht::HtHandle* htHandle)) PURE;
    STDMETHOD(insert(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* element)) PURE;
    STDMETHOD(removeOne(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* element)) PURE;
    STDMETHOD(get(ht::Element** rcElement, ht::HtHandle* htHandle, const ht::Element* element)) PURE;
    STDMETHOD(update(BOOL& rc, ht::HtHandle* htHandle, const ht::Element* oldElement, const void* newPayload, int newPayloadLength)) PURE;
    STDMETHOD(getLastError(const char** lastError, ht::HtHandle* htHandle)) PURE;
    STDMETHOD(print(const ht::Element* element)) PURE;
};

// {7A4A0540-1F90-462E-9405-9F2BB2AC25D2}
static const GUID IID_IElement =
{ 0x7a4a0540, 0x1f90, 0x462e, { 0x94, 0x5, 0x9f, 0x2b, 0xb2, 0xac, 0x25, 0xd2 } };

 
interface IElement : IUnknown {
    STDMETHOD(createGetElement(ht::Element** getElement, const void* key, int keyLength)) PURE;
    STDMETHOD(createInsertElement(ht::Element** newElement, const void* key, int keyLength, const void* payload, int  payloadLength)) PURE;
    STDMETHOD(createUpdateElement(ht::Element** updateElement, const ht::Element* oldElement, const void* newPayload, int  newPayloadLength)) PURE;
};