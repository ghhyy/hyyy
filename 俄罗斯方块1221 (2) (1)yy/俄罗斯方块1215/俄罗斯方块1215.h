// 俄罗斯方块1215.h : main header file for the 俄罗斯方块1215 application
//

#if !defined(AFX_1215_H__2ABA285D_99BE_4108_8333_650FB4F46F89__INCLUDED_)
#define AFX_1215_H__2ABA285D_99BE_4108_8333_650FB4F46F89__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1215App:
// See 俄罗斯方块1215.cpp for the implementation of this class
//

class CMy1215App : public CWinApp
{
public:
	CMy1215App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1215App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy1215App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1215_H__2ABA285D_99BE_4108_8333_650FB4F46F89__INCLUDED_)
