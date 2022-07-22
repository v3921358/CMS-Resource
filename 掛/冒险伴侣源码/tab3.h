#if !defined(AFX_TAB3_H__AFD3AFD7_3AE5_456A_AF9D_2AE3D49ADD1C__INCLUDED_)
#define AFX_TAB3_H__AFD3AFD7_3AE5_456A_AF9D_2AE3D49ADD1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tab3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// tab3 dialog

class tab3 : public CDialog
{
// Construction
public:
	tab3(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(tab3)
	enum { IDD = IDD_DIALOG4 };
	CComboBox	m_combo_key;
	CButton	m_check2;
	CListBox	m_list_key;
	CButton	m_check1;
	CString	m_msg1;
	UINT	m_edit2;
	CString	m_msg2;
	CString	m_msg3;
	CString	m_msg4;
	CString	m_edit_key_s;
	CString	m_edit_key_ms;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(tab3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(tab3)
	afx_msg void OnCheck1();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCheck2();
	afx_msg void OnButton2();
	afx_msg void OnButton_del();
	afx_msg void OnButton_clear();
	afx_msg void OnButton_save();
	afx_msg void OnButton_load();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAB3_H__AFD3AFD7_3AE5_456A_AF9D_2AE3D49ADD1C__INCLUDED_)
