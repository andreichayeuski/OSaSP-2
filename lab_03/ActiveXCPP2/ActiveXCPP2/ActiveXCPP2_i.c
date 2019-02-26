

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for ActiveXCPP2.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_ActiveXCPP2Lib,0x780A93DF,0xE56F,0x40E3,0x84,0x3F,0x29,0x87,0x10,0xFC,0x66,0x19);


MIDL_DEFINE_GUID(IID, DIID__DActiveXCPP2,0x292B3356,0xFB9C,0x4FB8,0x9C,0x2E,0x85,0x71,0x13,0xA3,0x28,0xE9);


MIDL_DEFINE_GUID(IID, DIID__DActiveXCPP2Events,0xB2962934,0x7A14,0x4FFB,0x84,0x63,0xF8,0x22,0x08,0x7A,0xE6,0x4D);


MIDL_DEFINE_GUID(CLSID, CLSID_ActiveXCPP2,0x23A90978,0x5D84,0x403E,0xBB,0xB2,0x43,0x68,0x73,0x8E,0xA4,0x38);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



