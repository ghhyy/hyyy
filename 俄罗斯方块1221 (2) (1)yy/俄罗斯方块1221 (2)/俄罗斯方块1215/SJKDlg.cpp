// SJKDlg.cpp : implementation file
//

#include "stdafx.h"
#include "俄罗斯方块1215.h"
#include "SJKDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSJKDlg dialog


CSJKDlg::CSJKDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSJKDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSJKDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSJKDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSJKDlg)
	DDX_Control(pDX, IDC_LIST4, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSJKDlg, CDialog)
	//{{AFX_MSG_MAP(CSJKDlg)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SHOWALL, OnButtonShowall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSJKDlg message handlers

BOOL CSJKDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int nColum = -1;
	m_list.InsertColumn(++nColum,"序列",LVCFMT_CENTER,100,0);//60表示宽度，LVCFMT_LEFT表示左对齐
	m_list.InsertColumn(++nColum,"用户名",LVCFMT_CENTER,126,1);
	m_list.InsertColumn(++nColum,"分数",LVCFMT_CENTER,60,1);
	m_list.InsertColumn(++nColum,"年龄",LVCFMT_CENTER,60,1);
    //以下用于设置列表控件的显示风格
	m_list.ModifyStyle(0,LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP);

	m_list.SetTextColor(RGB(255,0,0)); //显示字体的颜色
	DWORD dwStyle = m_list.GetStyle();
	dwStyle |= LVS_EX_GRIDLINES |LVS_EX_FULLROWSELECT|LVS_SHOWSELALWAYS ;
	m_list.SetExtendedStyle(dwStyle);
	m_list.SetBkColor(RGB(240,247,233)); //选中此列时的颜色
	m_list.SetTextBkColor(RGB(240,247,233));
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSJKDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	int i=0;
	CAdo m_Ado;
	m_Ado.OnInitADOConn(".\\CAdo\\分数.mdb");
	CString sql;
	if(AfxMessageBox("是否确认删除",MB_OKCANCEL|MB_ICONQUESTION)==IDCANCEL)
		return;
	for(i=0;i<m_list.GetItemCount();i++)
	{
		if(m_list.GetCheck(i))
		{
			sql.Format("delete * from 分数表 where sid=%s",m_list.GetItemText(i,0));
			m_Ado.ExecuteSQL(sql);
		}
	}
	m_Ado.ExitConnect();
	UpdateData(false);
	OnButtonShowall();
}

int CSJKDlg::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class

	return CDialog::DoModal();
}

void CSJKDlg::OnButtonShowall() 
{
	// TODO: Add your control notification handler code here
	int  nItem= -1;
	CAdo m_Ado;
	m_Ado.OnInitADOConn(".\\CAdo\\分数.mdb");
	CString name,sql,score,num,age;
	sql.Format("select * from 分数表");
	m_Ado.GetRecordSet(sql);
	m_list.DeleteAllItems(); //删除列表框的现有记录

	while(!m_Ado.m_pRecordset->adoEOF)
	{
		nItem++;
		age=m_Ado.GetCollect("sage");
		num=m_Ado.GetCollect("sid");
    	name=m_Ado.GetCollect("sname");
    	score=m_Ado.GetCollect("sscore");
		m_list.InsertItem(nItem,num);
		m_list.SetItemText(nItem,1,name);
		m_list.SetItemText(nItem,2,score);
		m_list.SetItemText(nItem,3,age);
    	m_Ado.m_pRecordset->MoveNext();
	}
	m_Ado.ExitConnect();
	UpdateData(false);
}
