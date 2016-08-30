// SkinEdit.cpp : implementation file
//

#include "stdafx.h"
#include "EditEx.h"


// CEditEx

IMPLEMENT_DYNAMIC(CEditEx, CEdit)

CEditEx::CEditEx()
{
	m_clrText = RGB(255,255,255);
	m_clrBkg = RGB(51,51,51);
	m_clrBorder = RGB(0,0,0);
	m_hBrush = ::CreateSolidBrush(RGB(51,51,51));
	
	m_bBold = false;
	m_nSizeText = 10;
}

CEditEx::~CEditEx()
{
	::DeleteObject(m_hBrush);
}


BEGIN_MESSAGE_MAP(CEditEx, CEdit)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_ERASEBKGND()
	ON_CONTROL_REFLECT(EN_UPDATE, &CEditEx::OnEnUpdate)
	ON_WM_NCPAINT()
END_MESSAGE_MAP()



// CEditEx message handlers

void CEditEx::SetSizeText(int nSize)
{
	CFont font;

	m_nSizeText = nSize;

	int weight = FW_NORMAL;
	m_bBold ? weight = FW_BOLD : weight = FW_NORMAL;

	font.CreateFont(m_nSizeText, 0, 0, 0, weight, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");

	SetFont((CFont*)&font, TRUE);

	font.Detach();
}

void CEditEx::SetStyleTextBold(bool bEnable)
{
	CFont font;

	m_bBold = bEnable;

	int weight = FW_NORMAL;
	m_bBold ? weight = FW_BOLD : weight = FW_NORMAL;

	font.CreateFont(m_nSizeText, 0, 0, 0, weight, FALSE, FALSE, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");

	SetFont((CFont*)&font, TRUE);

	font.Detach();
}

void CEditEx::SetColorBkg(COLORREF clrColor)
{
	::DeleteObject(m_hBrush);

	m_hBrush = ::CreateSolidBrush(clrColor);

	Invalidate();
}

HBRUSH CEditEx::CtlColor(CDC* pDC, UINT nCtlColor)
{
	CRect rect;

	GetClientRect(&rect);

	pDC->SetBkMode(TRANSPARENT);

	pDC->SetTextColor(m_clrText);

	pDC->Rectangle(&rect);

	return m_hBrush;
}

BOOL CEditEx::OnEraseBkgnd(CDC* pDC)
{
	return CEdit::OnEraseBkgnd(pDC);
}

void CEditEx::OnEnUpdate()
{
	RedrawWindow();
}

void CEditEx::OnNcPaint()
{

	CDC* pDC = GetWindowDC( );

	CRect rect;
	GetWindowRect( &rect);
	rect.OffsetRect( -rect.left, -rect.top);

	CBrush brush(m_clrBorder);
	pDC->FrameRect( &rect, &brush);
	ReleaseDC( pDC);

}

