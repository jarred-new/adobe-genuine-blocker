
// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "AdobeGenuineBlocker.h"
#include "DlgProxy.h"
#include "AdobeGenuineBlockerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAdobeGenuineBlockerDlgAutoProxy

IMPLEMENT_DYNCREATE(CAdobeGenuineBlockerDlgAutoProxy, CCmdTarget)

CAdobeGenuineBlockerDlgAutoProxy::CAdobeGenuineBlockerDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CAdobeGenuineBlockerDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CAdobeGenuineBlockerDlg)))
		{
			m_pDialog = reinterpret_cast<CAdobeGenuineBlockerDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CAdobeGenuineBlockerDlgAutoProxy::~CAdobeGenuineBlockerDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CAdobeGenuineBlockerDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CAdobeGenuineBlockerDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAdobeGenuineBlockerDlgAutoProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_IAdobeGenuineBlocker to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {DC39ACE9-4272-4A02-A822-74729093D3A4}
static const IID IID_IAdobeGenuineBlocker =
{ 0xDC39ACE9, 0x4272, 0x4A02, { 0xA8, 0x22, 0x74, 0x72, 0x90, 0x93, 0xD3, 0xA4 } };

BEGIN_INTERFACE_MAP(CAdobeGenuineBlockerDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CAdobeGenuineBlockerDlgAutoProxy, IID_IAdobeGenuineBlocker, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {AEF598F4-CF74-42BC-B0BE-30582654088F}
IMPLEMENT_OLECREATE2(CAdobeGenuineBlockerDlgAutoProxy, "AdobeGenuineBlocker.Application", 0xaef598f4, 0xcf74, 0x42bc, 0xb0, 0xbe, 0x30, 0x58, 0x26, 0x54, 0x8, 0x8f)


// CAdobeGenuineBlockerDlgAutoProxy message handlers
