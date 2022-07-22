// HOOK_WG.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "HOOK_WG.h"
#include "WGMainDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CHOOK_WGApp

BEGIN_MESSAGE_MAP(CHOOK_WGApp, CWinApp)
	//{{AFX_MSG_MAP(CHOOK_WGApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHOOK_WGApp construction

CHOOK_WGApp::CHOOK_WGApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CHOOK_WGApp object

CHOOK_WGApp theApp;
CWGMainDlg *pMainDlg = NULL;
BOOL CHOOK_WGApp::InitInstance()
{
	CWinApp::InitInstance();
	
	return TRUE;
}


int CHOOK_WGApp::ExitInstance()
{
	delete pMainDlg;
	pMainDlg = NULL;
	CWinApp::ExitInstance();
	return TRUE;
}
