
// FTech_EditExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_EditEx.h"
#include "FTech_EditExDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTech_EditExDlg dialog




CFTech_EditExDlg::CFTech_EditExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFTech_EditExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFTech_EditExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_wndEdit);
}

BEGIN_MESSAGE_MAP(CFTech_EditExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CFTech_EditExDlg message handlers

BOOL CFTech_EditExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_wndEdit.SetEnable(false);
	m_wndEdit.SetAlignLeft();				// 글자 정렬
	m_wndEdit.SetSizeText(30);				// 글자 크기
	m_wndEdit.SetStyleTextBold(true);		// 글자 스타일
	m_wndEdit.SetText(L"TEST");				// 글자 설정
	m_wndEdit.SetTextMargins(10,10);		// 글자 옵셋
	m_wndEdit.SetColorText(RGB(255,0,0));	// 글자 색상
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFTech_EditExDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFTech_EditExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

