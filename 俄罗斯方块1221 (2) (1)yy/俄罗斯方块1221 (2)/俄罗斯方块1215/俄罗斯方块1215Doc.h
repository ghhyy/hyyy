// ¶íÂÞË¹·½¿é1215Doc.h : interface of the CMy1215Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1215DOC_H__D1B2D7E8_BE8B_497D_8881_ACD64D413B55__INCLUDED_)
#define AFX_1215DOC_H__D1B2D7E8_BE8B_497D_8881_ACD64D413B55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1215Doc : public CDocument
{
protected: // create from serialization only
	CMy1215Doc();
	DECLARE_DYNCREATE(CMy1215Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1215Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1215Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1215Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1215DOC_H__D1B2D7E8_BE8B_497D_8881_ACD64D413B55__INCLUDED_)
