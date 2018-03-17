// ZHUCEDLG.cpp : implementation file
//

#include "stdafx.h"
#include "俄罗斯方块1215.h"
#include "ZHUCEDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZHUCEDLG dialog


CZHUCEDLG::CZHUCEDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CZHUCEDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZHUCEDLG)
	m_name = _T("");
	m_age = 0;
	//}}AFX_DATA_INIT
}


void CZHUCEDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZHUCEDLG)
	DDX_Control(pDX, IDC_BUTTON1, m_button);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_age);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZHUCEDLG, CDialog)
	//{{AFX_MSG_MAP(CZHUCEDLG)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZHUCEDLG message handlers

void CZHUCEDLG::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();///////////////////////////使对话框退出
}
