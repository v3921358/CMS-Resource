#if !defined(AFX_WGMAINDLG_H__93CBBB09_0F8C_4B2A_A46B_2B5FC35736D2__INCLUDED_)
#define AFX_WGMAINDLG_H__93CBBB09_0F8C_4B2A_A46B_2B5FC35736D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WGMainDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWGMainDlg dialog
#include "Resource.h"
class CWGMainDlg : public CDialog
{
// Construction
public:
	CWGMainDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWGMainDlg)
	enum { IDD = IDD_DIALOG1 };
	CEdit	m_edit2;
	CEdit	m_edit1;
	CTabCtrl	m_tab;
	CButton	m_check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWGMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWGMainDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WGMAINDLG_H__93CBBB09_0F8C_4B2A_A46B_2B5FC35736D2__INCLUDED_)
