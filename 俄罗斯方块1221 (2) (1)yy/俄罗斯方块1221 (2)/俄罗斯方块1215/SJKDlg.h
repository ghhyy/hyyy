#if !defined(AFX_SJKDLG_H__11901E18_C88B_4383_9E7E_52B2E09DB476__INCLUDED_)
#define AFX_SJKDLG_H__11901E18_C88B_4383_9E7E_52B2E09DB476__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SJKDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSJKDlg dialog
#include "Ado.h"

class CSJKDlg : public CDialog
{
// Construction
public:
	CSJKDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSJKDlg)
	enum { IDD = IDD_DIALOG2 };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSJKDlg)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSJKDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonShowall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SJKDLG_H__11901E18_C88B_4383_9E7E_52B2E09DB476__INCLUDED_)
