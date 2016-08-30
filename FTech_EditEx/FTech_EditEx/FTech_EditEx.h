
// FTech_EditEx.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFTech_EditExApp:
// See FTech_EditEx.cpp for the implementation of this class
//

class CFTech_EditExApp : public CWinApp
{
public:
	CFTech_EditExApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFTech_EditExApp theApp;