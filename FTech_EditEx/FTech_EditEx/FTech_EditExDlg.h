
// FTech_EditExDlg.h : header file
//

#pragma once
#include "include\EditEx.h"

// CFTech_EditExDlg dialog
class CFTech_EditExDlg : public CDialogEx
{
// Construction
public:
	CFTech_EditExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FTECH_EDITEX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEditEx m_wndEdit;
};
