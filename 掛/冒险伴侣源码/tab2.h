#if !defined(AFX_TAB2_H__92F6E1BD_8E35_4156_9802_124D73D6996F__INCLUDED_)
#define AFX_TAB2_H__92F6E1BD_8E35_4156_9802_124D73D6996F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tab2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// tab2 dialog

class tab2 : public CDialog
{
// Construction
public:
	tab2(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(tab2)
	enum { IDD = IDD_DIALOG3 };
	CButton	m_check5;
	CListBox	m_list_filter;
	CListBox	m_list_Data;
	CButton	m_check4;
	CButton	m_check3;
	CButton	m_check2;
	CButton	m_check1;
	UINT	m_edit1;
	UINT	m_edit2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(tab2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(tab2)
	afx_msg void OnDblclkList_data();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnCheck4();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck5();
	afx_msg void OnButton4();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAB2_H__92F6E1BD_8E35_4156_9802_124D73D6996F__INCLUDED_)
