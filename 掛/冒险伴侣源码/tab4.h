#if !defined(AFX_TAB4_H__90A67427_778A_49E5_8B27_E281AFCE58CC__INCLUDED_)
#define AFX_TAB4_H__90A67427_778A_49E5_8B27_E281AFCE58CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tab4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// tab4 dialog

class tab4 : public CDialog
{
// Construction
public:
	tab4(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(tab4)
	enum { IDD = IDD_DIALOG5 };
	CButton	m_check9;
	CComboBox	m_combo2;
	CComboBox	m_combo1;
	CButton	m_check8;
	CEdit	m_edit5;
	CEdit	m_edit4;
	CButton	m_check6;
	CButton	m_check5;
	CButton	m_check4;
	CButton	m_check3;
	CButton	m_check2;
	CButton	m_check1;
	UINT	m_edit1;
	UINT	m_edit2;
	UINT	m_edit3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(tab4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(tab4)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnCheck6();
	afx_msg void OnCheck8();
	afx_msg void OnButton1();
	afx_msg void OnCheck9();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAB4_H__90A67427_778A_49E5_8B27_E281AFCE58CC__INCLUDED_)
