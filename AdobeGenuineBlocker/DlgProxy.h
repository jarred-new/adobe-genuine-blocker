
// DlgProxy.h: header file
//

#pragma once

class CAdobeGenuineBlockerDlg;


// CAdobeGenuineBlockerDlgAutoProxy command target

class CAdobeGenuineBlockerDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CAdobeGenuineBlockerDlgAutoProxy)

	CAdobeGenuineBlockerDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CAdobeGenuineBlockerDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~CAdobeGenuineBlockerDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CAdobeGenuineBlockerDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

