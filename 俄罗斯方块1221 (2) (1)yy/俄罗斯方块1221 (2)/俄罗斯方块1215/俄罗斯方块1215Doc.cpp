// 俄罗斯方块1215Doc.cpp : implementation of the CMy1215Doc class
//

#include "stdafx.h"
#include "俄罗斯方块1215.h"

#include "俄罗斯方块1215Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1215Doc

IMPLEMENT_DYNCREATE(CMy1215Doc, CDocument)

BEGIN_MESSAGE_MAP(CMy1215Doc, CDocument)
	//{{AFX_MSG_MAP(CMy1215Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1215Doc construction/destruction

CMy1215Doc::CMy1215Doc()
{
	// TODO: add one-time construction code here

}

CMy1215Doc::~CMy1215Doc()
{
}

BOOL CMy1215Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMy1215Doc serialization

void CMy1215Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMy1215Doc diagnostics

#ifdef _DEBUG
void CMy1215Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy1215Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1215Doc commands
