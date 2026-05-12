

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Feb 25 20:28:00 2026
 */
/* Compiler settings for AdobeGenuineBlocker.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __AdobeGenuineBlocker_h_h__
#define __AdobeGenuineBlocker_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAdobeGenuineBlocker_FWD_DEFINED__
#define __IAdobeGenuineBlocker_FWD_DEFINED__
typedef interface IAdobeGenuineBlocker IAdobeGenuineBlocker;

#endif 	/* __IAdobeGenuineBlocker_FWD_DEFINED__ */


#ifndef __AdobeGenuineBlocker_FWD_DEFINED__
#define __AdobeGenuineBlocker_FWD_DEFINED__

#ifdef __cplusplus
typedef class AdobeGenuineBlocker AdobeGenuineBlocker;
#else
typedef struct AdobeGenuineBlocker AdobeGenuineBlocker;
#endif /* __cplusplus */

#endif 	/* __AdobeGenuineBlocker_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __AdobeGenuineBlocker_LIBRARY_DEFINED__
#define __AdobeGenuineBlocker_LIBRARY_DEFINED__

/* library AdobeGenuineBlocker */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_AdobeGenuineBlocker;

#ifndef __IAdobeGenuineBlocker_DISPINTERFACE_DEFINED__
#define __IAdobeGenuineBlocker_DISPINTERFACE_DEFINED__

/* dispinterface IAdobeGenuineBlocker */
/* [uuid] */ 


EXTERN_C const IID DIID_IAdobeGenuineBlocker;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DC39ACE9-4272-4A02-A822-74729093D3A4")
    IAdobeGenuineBlocker : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAdobeGenuineBlockerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAdobeGenuineBlocker * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAdobeGenuineBlocker * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAdobeGenuineBlocker * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAdobeGenuineBlocker * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAdobeGenuineBlocker * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAdobeGenuineBlocker * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAdobeGenuineBlocker * This,
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
    } IAdobeGenuineBlockerVtbl;

    interface IAdobeGenuineBlocker
    {
        CONST_VTBL struct IAdobeGenuineBlockerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAdobeGenuineBlocker_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAdobeGenuineBlocker_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAdobeGenuineBlocker_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAdobeGenuineBlocker_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAdobeGenuineBlocker_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAdobeGenuineBlocker_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAdobeGenuineBlocker_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAdobeGenuineBlocker_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AdobeGenuineBlocker;

#ifdef __cplusplus

class DECLSPEC_UUID("AEF598F4-CF74-42BC-B0BE-30582654088F")
AdobeGenuineBlocker;
#endif
#endif /* __AdobeGenuineBlocker_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


