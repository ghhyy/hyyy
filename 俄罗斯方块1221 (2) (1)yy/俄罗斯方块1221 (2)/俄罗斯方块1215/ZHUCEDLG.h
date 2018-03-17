#if !defined(AFX_ZHUCEDLG_H__80388A65_FB69_4900_A222_6A122761A005__INCLUDED_)
#define AFX_ZHUCEDLG_H__80388A65_FB69_4900_A222_6A122761A005__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZHUCEDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZHUCEDLG dialog

class CZHUCEDLG : public CDialog
{
// Construction
public:
	CZHUCEDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CZHUCEDLG)
	enum { IDD = IDD_DIALOG1 };
	CButton	m_button;
	CString	m_name;
	int		m_age;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZHUCEDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZHUCEDLG)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHUCEDLG_H__80388A65_FB69_4900_A222_6A122761A005__INCLUDED_)
