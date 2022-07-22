// HOOK_WG.h : main header file for the HOOK_WG DLL
//

#if !defined(AFX_HOOK_WG_H__16DE2EF8_0B0E_4DC1_AB23_9740CE236849__INCLUDED_)
#define AFX_HOOK_WG_H__16DE2EF8_0B0E_4DC1_AB23_9740CE236849__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "WGMainDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CHOOK_WGApp
// See HOOK_WG.cpp for the implementation of this class
//


class CHOOK_WGApp : public CWinApp
{
public:
	CHOOK_WGApp();
	BOOL InitInstance()	;
	int ExitInstance();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHOOK_WGApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CHOOK_WGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
extern CHOOK_WGApp theApp;
extern CWGMainDlg *pMainDlg ;


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOOK_WG_H__16DE2EF8_0B0E_4DC1_AB23_9740CE236849__INCLUDED_)
