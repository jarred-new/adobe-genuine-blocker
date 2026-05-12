
// AdobeGenuineBlockerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AdobeGenuineBlocker.h"
#include "AdobeGenuineBlockerDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAdobeGenuineBlockerDlg dialog


IMPLEMENT_DYNAMIC(CAdobeGenuineBlockerDlg, CDialogEx);

CAdobeGenuineBlockerDlg::CAdobeGenuineBlockerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAdobeGenuineBlockerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CAdobeGenuineBlockerDlg::~CAdobeGenuineBlockerDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CAdobeGenuineBlockerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_scanList);
}

BEGIN_MESSAGE_MAP(CAdobeGenuineBlockerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CAdobeGenuineBlockerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAdobeGenuineBlockerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAdobeGenuineBlockerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CAdobeGenuineBlockerDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CAdobeGenuineBlockerDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CAdobeGenuineBlockerDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CAdobeGenuineBlockerDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CAdobeGenuineBlockerDlg message handlers

BOOL CAdobeGenuineBlockerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	if (CTaskDialog::IsSupported()) {
		dialogCompatibility = true;
	}
	else {
		dialogCompatibility = false;
	}

	if (dialogCompatibility == false) {
		AfxMessageBox(_T("Runtime Error!\nYour version is not compatible of using TaskDialog.\nThis app will close..."));
		exit(0);
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdobeGenuineBlockerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAdobeGenuineBlockerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		// 1. Always create CPaintDC first to handle the WM_PAINT message correctly
		CPaintDC dc(this);

		// 2. Load your bitmap resource
		CBitmap bmp;
		if (bmp.LoadBitmap(IDB_BITMAP1))
		{
			// 3. Create a memory DC compatible with the screen
			CDC memDC;
			memDC.CreateCompatibleDC(&dc);

			// 4. Select the bitmap into the memory DC
			CBitmap* pOldBmp = memDC.SelectObject(&bmp);

			// 5. Get bitmap dimensions
			BITMAP bm;
			bmp.GetBitmap(&bm);

			// 6. Copy (BitBlt) from memory to the screen DC
			dc.BitBlt(238, 20, bm.bmWidth, bm.bmHeight, &memDC, 0, 0, SRCCOPY);

			// 7. Cleanup: Select the old bitmap back before memDC goes out of scope
			memDC.SelectObject(pOldBmp);
		}
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAdobeGenuineBlockerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CAdobeGenuineBlockerDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CAdobeGenuineBlockerDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CAdobeGenuineBlockerDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CAdobeGenuineBlockerDlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CAdobeGenuineBlockerDlg::ScanAndBlock(CString strFolder)
{
	CFileFind finder;
	CString strWildcard = strFolder + _T("\\*.*");
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		if (finder.IsDots()) continue;

		if (finder.IsDirectory())
		{
			ScanAndBlock(finder.GetFilePath()); // Recursive call
		}
		else
		{
			CString strPath = finder.GetFilePath();
			if (strPath.Right(4).CompareNoCase(_T(".exe")) == 0)
			{
				// 1. Apply the firewall block
				if (ApplyBlockRule(finder.GetFileName(), strPath))
				{
					// 2. Update the ListBox
					CString strEntry;
					strEntry.Format(_T("Blocked: %s"), finder.GetFileName());
					m_scanList.AddString(strEntry);
					UpdateData();
					UpdateWindow();
				}
			}
		}
	}
	finder.Close();
}

BOOL CAdobeGenuineBlockerDlg::ApplyBlockRule(CString strName, CString strPath)
{
	CComPtr<INetFwPolicy2> pNetFwPolicy2;
	CComPtr<INetFwRule> pFwRule;
	CComPtr<INetFwRules> pFwRules;

	if (FAILED(pNetFwPolicy2.CoCreateInstance(CLSID_NetFwPolicy2))) AfxMessageBox(_T("Error 10"));
	if (FAILED(pFwRule.CoCreateInstance(CLSID_NetFwRule))) AfxMessageBox(_T("Error 20"));

	pFwRule->put_Name(strName.AllocSysString());
	pFwRule->put_ApplicationName(strPath.AllocSysString());
	pFwRule->put_Action(NET_FW_ACTION_BLOCK);
	pFwRule->put_Direction(NET_FW_RULE_DIR_OUT);
	pFwRule->put_Enabled(VARIANT_TRUE);
	pFwRule->put_Profiles(NET_FW_PROFILE2_ALL);

	if (SUCCEEDED(pNetFwPolicy2->get_Rules(&pFwRules))) {
		return SUCCEEDED(pFwRules->Add(pFwRule));
	}
	return FALSE;
}


void CAdobeGenuineBlockerDlg::ScanAndUnblock(CString strFolder)
{
	CFileFind finder;
	CString strWildcard = strFolder + _T("\\*.*");
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		if (finder.IsDots()) continue;

		if (finder.IsDirectory())
		{
			ScanAndUnblock(finder.GetFilePath()); // Recursive call
		}
		else
		{
			CString strPath = finder.GetFilePath();
			if (strPath.Right(4).CompareNoCase(_T(".exe")) == 0)
			{
				// 1. Apply the firewall block
				if (ApplyUnblockRule(finder.GetFileName(), strPath))
				{
					// 2. Update the ListBox
					CString strEntry;
					strEntry.Format(_T("Unblocked: %s"), finder.GetFileName());
					m_scanList.AddString(strEntry);
					UpdateData();
					UpdateWindow();
				}
			}
		}
	}
	finder.Close();
}

BOOL CAdobeGenuineBlockerDlg::ApplyUnblockRule(CString strName, CString strPath)
{
	CComPtr<INetFwPolicy2> pNetFwPolicy2;
	CComPtr<INetFwRule> pFwRule;
	CComPtr<INetFwRules> pFwRules;

	if (FAILED(pNetFwPolicy2.CoCreateInstance(CLSID_NetFwPolicy2))) AfxMessageBox(_T("Error 12"));
	if (FAILED(pFwRule.CoCreateInstance(CLSID_NetFwRule))) AfxMessageBox(_T("Error 22"));

	pFwRule->put_Name(strName.AllocSysString());
	pFwRule->put_ApplicationName(strPath.AllocSysString());
	pFwRule->put_Action(NET_FW_ACTION_ALLOW);
	pFwRule->put_Direction(NET_FW_RULE_DIR_OUT);
	pFwRule->put_Enabled(VARIANT_TRUE);
	pFwRule->put_Profiles(NET_FW_PROFILE2_ALL);

	if (SUCCEEDED(pNetFwPolicy2->get_Rules(&pFwRules))) {
		return SUCCEEDED(pFwRules->Add(pFwRule));
	}
	return FALSE;
}

void CAdobeGenuineBlockerDlg::ScanAndRemove(CString strFolder)
{
	CFileFind finder;
	CString strWildcard = strFolder + _T("\\*.*");
	BOOL bWorking = finder.FindFile(strWildcard);

	while (bWorking)
	{
		bWorking = finder.FindNextFile();
		if (finder.IsDots()) continue;

		if (finder.IsDirectory())
		{
			ScanAndRemove(finder.GetFilePath());
		}
		else if (finder.GetFilePath().Right(4).CompareNoCase(_T(".exe")) == 0)
		{
			if (RemoveRule(finder.GetFileName()))
			{
				CString strMsg;
				strMsg.Format(_T("Removed: %s"), finder.GetFileName());
				m_scanList.AddString(strMsg);
				UpdateData();
				UpdateWindow();
			}
		}
	}
	finder.Close();
}

BOOL CAdobeGenuineBlockerDlg::RemoveRule(CString strRuleName)
{
	CComPtr<INetFwPolicy2> pNetFwPolicy2;
	CComPtr<INetFwRules> pFwRules;

	if (FAILED(pNetFwPolicy2.CoCreateInstance(CLSID_NetFwPolicy2))) AfxMessageBox(_T("Error 13"));

	if (SUCCEEDED(pNetFwPolicy2->get_Rules(&pFwRules)))
	{
		// Remove takes the Name string we assigned during creation
		HRESULT hr = pFwRules->Remove(strRuleName.AllocSysString());
		return SUCCEEDED(hr);
	}
	return FALSE;
}

void CAdobeGenuineBlockerDlg::OnBnClickedButton1()
{
	// Block Now Button
	MessageBeep(MB_ICONWARNING);
	CTaskDialog taskDialog(_T("It is your choice...\nClick yes to start blocking Adobe Genuine now.\nClick no to not continue."), _T("Are you sure to perform this?"), _T("Be Careful!!!"), TDCBF_YES_BUTTON | TDCBF_NO_BUTTON);
	taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2)));

	INT_PTR result = taskDialog.DoModal();
	if (result == IDYES) {
		CTime currentTime = CTime::GetCurrentTime();
		CString strTime = currentTime.Format("%Y-%m-%d %H:%M:%S");
		m_scanList.AddString(_T("Block: ") + strTime);
		UpdateData();
		UpdateWindow();

		bool errorCheck;
		try {
			ScanAndBlock(_T("C:\\Program Files\\Adobe"));
			ScanAndBlock(_T("C:\\Program Files (x86)\\Adobe"));

			ScanAndRemove(_T("C:\\Program Files\\Adobe\\Adobe Creative Cloud"));
			ScanAndRemove(_T("C:\\Program Files\\Adobe\\Adobe Creative Cloud Experience"));

			ScanAndRemove(_T("C:\\Program Files (x86)\\Adobe\\Adobe Creative Cloud"));
			ScanAndRemove(_T("C:\\Program Files (x86)\\Adobe\\Adobe Creative Cloud Experience"));
			errorCheck = false;
		}
		catch (CException* e) {
			errorCheck = true;
		}
		if (errorCheck == true) {
			MessageBeep(MB_ICONHAND);
			CTaskDialog taskDialog(_T("This means that your Adobe apps are not existed in your drive..."), _T("Blocked unsuccessfully!"), _T("Failed! :("), TDCBF_OK_BUTTON);
			taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON3)));

			INT_PTR result = taskDialog.DoModal();
			if (result == IDOK) {

			}
		}
		else {
			MessageBeep(MB_ICONINFORMATION);
			CTaskDialog taskDialog(_T("Please restart all your Adobe apps (e.g Photoshop, Illustrator, Premiere Pro) to make effect."), _T("Adobe Genuine is now blocked successfully"), _T("Done!"), TDCBF_OK_BUTTON);
			taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1)));
			taskDialog.SetFooterText(_T("Note: if it dosen't work and keeps popping up, it means the you need to disable antivirus to stop it."));

			INT_PTR result = taskDialog.DoModal();
			if (result == IDOK) {

			}
		}
	}
}


void CAdobeGenuineBlockerDlg::OnBnClickedButton2()
{
	// Unblock Now Button
	MessageBeep(MB_ICONWARNING);
	CTaskDialog taskDialog(_T("It is your choice...\nClick yes to start unblock now.\nClick no to not continue."), _T("Are you sure to perform this?"), _T("Be Careful!!!"), TDCBF_YES_BUTTON | TDCBF_NO_BUTTON);
	taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2)));

	INT_PTR result = taskDialog.DoModal();
	if (result == IDYES) {
		CTime currentTime = CTime::GetCurrentTime();
		CString strTime = currentTime.Format("%Y-%m-%d %H:%M:%S");
		m_scanList.AddString(_T("Unblock: ") + strTime);
		UpdateData();
		UpdateWindow();

		bool errorCheck;
		try {
			ScanAndUnblock(_T("C:\\Program Files\\Adobe"));
			ScanAndUnblock(_T("C:\\Program Files (x86)\\Adobe"));

			ScanAndRemove(_T("C:\\Program Files\\Adobe\\Adobe Creative Cloud"));
			ScanAndRemove(_T("C:\\Program Files\\Adobe\\Adobe Creative Cloud Experience"));

			ScanAndRemove(_T("C:\\Program Files (x86)\\Adobe\\Adobe Creative Cloud"));
			ScanAndRemove(_T("C:\\Program Files (x86)\\Adobe\\Adobe Creative Cloud Experience"));
			errorCheck = false;
		}
		catch (CException* e) {
			errorCheck = true;
		}
		if (errorCheck == true) {
			MessageBeep(MB_ICONHAND);
			CTaskDialog taskDialog(_T("This means that your Adobe apps are not existed in your drive..."), _T("Unblocked unsuccessfully!"), _T("Failed! :("), TDCBF_OK_BUTTON);
			taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON3)));

			INT_PTR result = taskDialog.DoModal();
			if (result == IDOK) {

			}
		}
		else {
			MessageBeep(MB_ICONINFORMATION);
			CTaskDialog taskDialog(_T("Please restart all your Adobe apps (e.g Photoshop, Illustrator, Premiere Pro) to make effect."), _T("Adobe Genuine is now unblocked successfully"), _T("Done!"), TDCBF_OK_BUTTON);
			taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1)));

			INT_PTR result = taskDialog.DoModal();
			if (result == IDOK) {

			}
		}
	}
}


void CAdobeGenuineBlockerDlg::OnBnClickedButton3()
{
	// Clean Rules Button
	MessageBeep(MB_ICONWARNING);
	CTaskDialog taskDialog(_T("It is your choice...\nClick yes to clean/remove firewall rules now.\nClick no to not continue."), _T("Are you sure to perform this?"), _T("Be Careful!!!"), TDCBF_YES_BUTTON | TDCBF_NO_BUTTON);
	taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2)));

	INT_PTR result = taskDialog.DoModal();
	if (result == IDYES) {
		CTime currentTime = CTime::GetCurrentTime();
		CString strTime = currentTime.Format("%Y-%m-%d %H:%M:%S");
		m_scanList.AddString(_T("Remove Rules: ") + strTime);
		UpdateData();
		UpdateWindow();

		bool errorCheck;
		try {
			ScanAndRemove(_T("C:\\Program Files\\Adobe"));
			ScanAndRemove(_T("C:\\Program Files (x86)\\Adobe"));
			errorCheck = false;
		}
		catch (CException* e) {
			errorCheck = true;
		}
		if (errorCheck == true) {
			MessageBeep(MB_ICONHAND);
			CTaskDialog taskDialog(_T("This means that your Adobe apps are not existed in your drive..."), _T("Removed unsuccessfully!"), _T("Failed! :("), TDCBF_OK_BUTTON);
			taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON3)));

			INT_PTR result = taskDialog.DoModal();
			if (result == IDOK) {

			}
		}
		else {
			MessageBeep(MB_ICONINFORMATION);
			CTaskDialog taskDialog(_T("Please restart all your Adobe apps (e.g Photoshop, Illustrator, Premiere Pro) to make effect."), _T("All rules are now removed successfully!"), _T("Done!"), TDCBF_OK_BUTTON);
			taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1)));

			INT_PTR result = taskDialog.DoModal();
			if (result == IDOK) {

			}
		}
	}
}


void CAdobeGenuineBlockerDlg::OnBnClickedButton4()
{
	// Open Firewall Button
	system("WF.msc");
}


void CAdobeGenuineBlockerDlg::OnBnClickedButton5()
{
	// Delete Button
	MessageBeep(MB_ICONWARNING);
	CTaskDialog taskDialog(_T("It is your choice...\nClick yes to delete AGS now.\nClick no to not continue."), _T("Are you sure to perform this?"), _T("Be Careful!!!"), TDCBF_YES_BUTTON | TDCBF_NO_BUTTON);
	taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2)));

	INT_PTR result = taskDialog.DoModal();
	if (result == IDYES) {
		bool errorCheck;
		try
		{
			CFile::Remove(_T("C:\\Program Files (x86)\\Common Files\\Adobe\\AdobeGCClient"));
			errorCheck = false;
		}
		catch (CFileException* e) {
			errorCheck = true;
		}

		if (errorCheck == true) {
			MessageBeep(MB_ICONHAND);
			CTaskDialog taskDialog(_T("This means that AGS is deleted or not existed in your drive..."), _T("AGS is not removed successfully!"), _T("Failed! :("), TDCBF_OK_BUTTON);
			taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON3)));

			INT_PTR result = taskDialog.DoModal();
			if (result == IDOK) {

			}
		}
		else {
			MessageBeep(MB_ICONINFORMATION);
			CTaskDialog taskDialog(_T("Please restart all your Adobe apps (e.g Photoshop, Illustrator, Premiere Pro) to make effect."), _T("AGS is removed successfully!"), _T("Done!"), TDCBF_OK_BUTTON);
			taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1)));

			INT_PTR result = taskDialog.DoModal();
			if (result == IDOK) {

			}
		}
	}
}


void CAdobeGenuineBlockerDlg::OnBnClickedButton6()
{
	m_scanList.ResetContent();
	UpdateData();
	UpdateWindow();
}

void CAdobeGenuineBlockerDlg::ExportListBoxToText(CListBox& listBox, const CString& filePath)
{
	CStdioFile file;
	CFileException fileException;

	// Attempt to open the file for writing (create a new file or overwrite existing)
	if (!file.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeText, &fileException))
	{
		// Handle file open error, e.g., display an error message
		TCHAR szError[1024];
		fileException.GetErrorMessage(szError, sizeof(szError) / sizeof(TCHAR));
		AfxMessageBox(szError);
		return;
	}

	// Get the total number of items in the listbox
	int nItems = listBox.GetCount();
	CString sItem;

	// Loop through each item
	for (int i = 0; i < nItems; i++)
	{
		// Get the text of the current item
		listBox.GetText(i, sItem);

		// Write the item string to the file
		// Add a newline character to separate each item in the text file
		file.WriteString(sItem + _T("\n"));
	}

	// Close the file
	file.Close();
}

void CAdobeGenuineBlockerDlg::OnBnClickedButton7()
{
	CFileDialog fileDlg(FALSE, _T("txt"), _T("export.txt"), OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY,
		_T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"), this);

	if (fileDlg.DoModal() == IDOK)
	{
		CString sFilePath = fileDlg.GetPathName();
		// Assuming m_myListBox is the CListBox member variable associated with your listbox control
		ExportListBoxToText(m_scanList, sFilePath); // 6-7 baby!!!

		MessageBeep(MB_ICONINFORMATION);
		CTaskDialog taskDialog(_T("Now you can email reyesgavinjarred@gmail.com for feedbacks."), _T("Console Log exported successfully!"), _T("Done!"), TDCBF_OK_BUTTON);
		
		taskDialog.SetMainIcon((HICON)LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1)));
		taskDialog.SetVerificationCheckboxText(_T("When click OK, open exported log"));

		INT_PTR result = taskDialog.DoModal();
		if (result == IDOK) {
			if (taskDialog.GetVerificationCheckboxState() == TRUE) {	
				ShellExecute(NULL, _T("edit"), fileDlg.GetPathName(), NULL, NULL, SW_SHOWNORMAL);
			}
		}
	}
}
