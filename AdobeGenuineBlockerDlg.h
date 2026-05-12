
// AdobeGenuineBlockerDlg.h : header file
//

#pragma once
#include "afxwin.h"

class CAdobeGenuineBlockerDlgAutoProxy;


// CAdobeGenuineBlockerDlg dialog
class CAdobeGenuineBlockerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAdobeGenuineBlockerDlg);
	friend class CAdobeGenuineBlockerDlgAutoProxy;

// Construction
public:
	CAdobeGenuineBlockerDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CAdobeGenuineBlockerDlg();

// Dialog Data
	enum { IDD = IDD_ADOBEGENUINEBLOCKER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	CAdobeGenuineBlockerDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
public:
	bool dialogCompatibility;
	CListBox m_scanList;
	void ScanAndBlock(CString strFolder);
	void ScanAndUnblock(CString strFolder);
	void ScanAndRemove(CString strFolder);
	void ExportListBoxToText(CListBox& listBox, const CString& filePath);
	BOOL ApplyBlockRule(CString strName, CString strPath);
	BOOL ApplyUnblockRule(CString strName, CString strPath);
	BOOL RemoveRule(CString strRuleName);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
};
