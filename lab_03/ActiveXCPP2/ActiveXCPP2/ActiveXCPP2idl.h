

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __ActiveXCPP2idl_h__
#define __ActiveXCPP2idl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DActiveXCPP2_FWD_DEFINED__
#define ___DActiveXCPP2_FWD_DEFINED__
typedef interface _DActiveXCPP2 _DActiveXCPP2;

#endif 	/* ___DActiveXCPP2_FWD_DEFINED__ */


#ifndef ___DActiveXCPP2Events_FWD_DEFINED__
#define ___DActiveXCPP2Events_FWD_DEFINED__
typedef interface _DActiveXCPP2Events _DActiveXCPP2Events;

#endif 	/* ___DActiveXCPP2Events_FWD_DEFINED__ */


#ifndef __ActiveXCPP2_FWD_DEFINED__
#define __ActiveXCPP2_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActiveXCPP2 ActiveXCPP2;
#else
typedef struct ActiveXCPP2 ActiveXCPP2;
#endif /* __cplusplus */

#endif 	/* __ActiveXCPP2_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ActiveXCPP2_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_ActiveXCPP2_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ActiveXCPP2_0000_0000_v0_0_s_ifspec;


#ifndef __ActiveXCPP2Lib_LIBRARY_DEFINED__
#define __ActiveXCPP2Lib_LIBRARY_DEFINED__

/* library ActiveXCPP2Lib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_ActiveXCPP2Lib;

#ifndef ___DActiveXCPP2_DISPINTERFACE_DEFINED__
#define ___DActiveXCPP2_DISPINTERFACE_DEFINED__

/* dispinterface _DActiveXCPP2 */
/* [uuid] */ 


EXTERN_C const IID DIID__DActiveXCPP2;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("292B3356-FB9C-4FB8-9C2E-857113A328E9")
    _DActiveXCPP2 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DActiveXCPP2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DActiveXCPP2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DActiveXCPP2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DActiveXCPP2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DActiveXCPP2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DActiveXCPP2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DActiveXCPP2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DActiveXCPP2 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DActiveXCPP2Vtbl;

    interface _DActiveXCPP2
    {
        CONST_VTBL struct _DActiveXCPP2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DActiveXCPP2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DActiveXCPP2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DActiveXCPP2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DActiveXCPP2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DActiveXCPP2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DActiveXCPP2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DActiveXCPP2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DActiveXCPP2_DISPINTERFACE_DEFINED__ */


#ifndef ___DActiveXCPP2Events_DISPINTERFACE_DEFINED__
#define ___DActiveXCPP2Events_DISPINTERFACE_DEFINED__

/* dispinterface _DActiveXCPP2Events */
/* [uuid] */ 


EXTERN_C const IID DIID__DActiveXCPP2Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B2962934-7A14-4FFB-8463-F822087AE64D")
    _DActiveXCPP2Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DActiveXCPP2EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DActiveXCPP2Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DActiveXCPP2Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DActiveXCPP2Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DActiveXCPP2Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DActiveXCPP2Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DActiveXCPP2Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DActiveXCPP2Events * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DActiveXCPP2EventsVtbl;

    interface _DActiveXCPP2Events
    {
        CONST_VTBL struct _DActiveXCPP2EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DActiveXCPP2Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DActiveXCPP2Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DActiveXCPP2Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DActiveXCPP2Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DActiveXCPP2Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DActiveXCPP2Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DActiveXCPP2Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DActiveXCPP2Events_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActiveXCPP2;

#ifdef __cplusplus

class DECLSPEC_UUID("23A90978-5D84-403E-BBB2-4368738EA438")
ActiveXCPP2;
#endif
#endif /* __ActiveXCPP2Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


