// 俄罗斯方块1215View.cpp : implementation of the CMy1215View class
//

#include "stdafx.h"
#include "俄罗斯方块1215.h"

#include "俄罗斯方块1215Doc.h"
#include "俄罗斯方块1215View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMy1215View

IMPLEMENT_DYNCREATE(CMy1215View, CView)

BEGIN_MESSAGE_MAP(CMy1215View, CView)
	//{{AFX_MSG_MAP(CMy1215View)
	ON_COMMAND(ID_M_QUICK, OnMQuick)
	ON_COMMAND(ID_M_SLOW, OnMSlow)
	ON_COMMAND(ID_M_MEDIUMEN, OnMMediumen)
	ON_COMMAND(ID_M_START, OnMStart)
	ON_COMMAND(ID_M_STOP, OnMStop)
	ON_COMMAND(ID_M_END, OnMEnd)
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_COMMAND(ID_M_ZHUCE, OnMZhuce)
	ON_COMMAND(ID_SCORE, OnScore)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1215View construction/destruction

CMy1215View::CMy1215View()
{
	// TODO: add construction code here

}

CMy1215View::~CMy1215View()
{
}

BOOL CMy1215View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMy1215View drawing

void CMy1215View::OnDraw(CDC* pDC)
{
	CMy1215Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	int i,j;
	m_pDC=pDC;
	DrawJuXing(BJX2.Bm_x,BJX2.Bm_y,BJX2.Bm_w,BJX2.Bm_h);
	DrawBackground(score);
	for(i=0;i<=m_nJX;i++)
		for(j=0;j<4;j++)
	DrawTuXing(SJX[i].JX[j].m_x,SJX[i].JX[j].m_y,25,25);

		if(score==1200)
		{
			KillTimer(1);
			AfxMessageBox("恭喜通关！");
		}
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMy1215View printing

BOOL CMy1215View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy1215View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy1215View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMy1215View diagnostics

#ifdef _DEBUG
void CMy1215View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1215View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1215Doc* CMy1215View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1215Doc)));
	return (CMy1215Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMy1215View message handlers

void CMy1215View::DrawJuXing(int x, int y, int w, int h)
{
	m_pDC->MoveTo(x,y);
	m_pDC->LineTo(x+w,y);
	m_pDC->LineTo(x+w,y+h);
	m_pDC->LineTo(x,y+h);
	m_pDC->LineTo(x,y);
}

void CMy1215View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	int i;	
	f_x=-2;
	f_y=-2;
	score=0;
	//srand(unsigned(time(0)));////////////////"这个一定要加！！！！！！"

	//Shape=10;
	m_nJX=0;/////////////////////定义图形个数
	m_s=0;
	speed=0;
	TuXing[m_s]=1;
	for(i=0;i<100;i++)
	{
	z[i]=1;
	y[i]=1;
	h[i]=1;
}
	Shape[0]=rand()%16;
	BJX1.Bm_x=200;//游戏最左边
	BJX1.Bm_y=24;
	BJX1.Bm_w=400;//youxi 最右边为600
	BJX1.Bm_h=575;
	BJX2.Bm_x=500;
	BJX2.Bm_y=24;
	BJX2.Bm_w=370;
	BJX2.Bm_h=575;
	KindTuXing(Shape[m_s]);
	// TODO: Add your specialized code here and/or call the base class
	
}





void CMy1215View::KindTuXing(int Shape)
{
	int i;
	if(Shape==1)
	{
		for(i=0;i<2;i++)
		{
			SJX[m_nJX].JX[i].m_x=375+i*25;
			SJX[m_nJX].JX[i].m_y=50;
		}
		for(i=2;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_x=375+(i-2)*25;
			SJX[m_nJX].JX[i].m_y=75;
		}
	}//田字形
	if(Shape==2)
	{
		for(i=0;i<2;i++)
		{
			SJX[m_nJX].JX[i].m_x=375+i*25;
			SJX[m_nJX].JX[i].m_y=50;
		}
		for(i=2;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_x=400+(i-2)*25;
			SJX[m_nJX].JX[i].m_y=75;
		}
	}//Z形
	if(Shape==3)
	{
		for(i=0;i<2;i++)
		{
			SJX[m_nJX].JX[i].m_x=400+i*25;
			SJX[m_nJX].JX[i].m_y=50;
		}
		for(i=2;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_x=375+(i-2)*25;
			SJX[m_nJX].JX[i].m_y=75;
		}
	}//反Z形
    if(Shape==4)
	{
		for(i=0;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_x=350+i*25;
			SJX[m_nJX].JX[i].m_y=50;
		}
	}//横”一“形
	if(Shape==5)
	{
		for(i=0;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_x=375;
			SJX[m_nJX].JX[i].m_y=50+i*25;
		}
	}//竖“一”形
	if(Shape==6)
	{
		for(i=0;i<2;i++)
		{
			SJX[m_nJX].JX[i].m_x=375;
			SJX[m_nJX].JX[i].m_y=50+i*25;
		}
		for(i=2;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_x=400;
			SJX[m_nJX].JX[i].m_y=50+(i-1)*25;
		}
	}//反竖“Z”
	if(Shape==7)
	{
		for(i=0;i<2;i++)
		{
			SJX[m_nJX].JX[i].m_x=375;
			SJX[m_nJX].JX[i].m_y=75+i*25;
		}
		for(i=2;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_x=400;
			SJX[m_nJX].JX[i].m_y=50+(i-2)*25;
		}
	}//竖“Z”
	if(Shape==8)
	{
		SJX[m_nJX].JX[0].m_x=375;
		SJX[m_nJX].JX[0].m_y=50;
		for(i=1;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_x=350+i*25;
			SJX[m_nJX].JX[i].m_y=75;
		}
	}//横"L"形
	if(Shape==9)
	{
		SJX[m_nJX].JX[0].m_x=425;
		SJX[m_nJX].JX[0].m_y=50;
		for(i=1;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_x=350+i*25;
			SJX[m_nJX].JX[i].m_y=75;
		}
	}//反向倒L形
    if(Shape==10)
	{
		for(i=0;i<3;i++)
		{
			SJX[m_nJX].JX[i].m_y=50+i*25;
			SJX[m_nJX].JX[i].m_x=375;
		}
		SJX[m_nJX].JX[3].m_x=400;
		SJX[m_nJX].JX[3].m_y=100;
	}//“L”图形
	if(Shape==0)
	{
		for(i=0;i<3;i++)
		{
			SJX[m_nJX].JX[i].m_y=50+i*25;
			SJX[m_nJX].JX[i].m_x=375;
		}
		SJX[m_nJX].JX[3].m_x=400;
		SJX[m_nJX].JX[3].m_y=50;
	}//倒“L”图形
	if(Shape==11)
	{
		for(i=1;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_y=50;
			SJX[m_nJX].JX[i].m_x=350+i*25;
		}
		SJX[m_nJX].JX[0].m_x=375;
		SJX[m_nJX].JX[0].m_y=75;
	}//横竖“L”型
	if(Shape==12)
	{
        for(i=1;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_y=50;
			SJX[m_nJX].JX[i].m_x=350+i*25;
		}
		SJX[m_nJX].JX[0].m_x=425;
		SJX[m_nJX].JX[0].m_y=75;
	}
	if(Shape==13)
	{
		 for(i=1;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_y=75;
			SJX[m_nJX].JX[i].m_x=350+i*25;
		}
		 SJX[m_nJX].JX[0].m_x=400;
		SJX[m_nJX].JX[0].m_y=50;
	}//"T"字型
	if(Shape==14)
	{
         for(i=1;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_y=50;
			SJX[m_nJX].JX[i].m_x=350+i*25;
		}
		 SJX[m_nJX].JX[0].m_x=400;
		SJX[m_nJX].JX[0].m_y=75;
	}//倒“T”型
    if(Shape==15)
	{
        for(i=1;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_y=50+(i-1)*25;
			SJX[m_nJX].JX[i].m_x=400;
		}
		 SJX[m_nJX].JX[0].m_x=425;
		SJX[m_nJX].JX[0].m_y=75;
	}//横“T”
	if(Shape==16)
	{
        for(i=1;i<4;i++)
		{
			SJX[m_nJX].JX[i].m_y=50+(i-1)*25;
			SJX[m_nJX].JX[i].m_x=400;
		}
		 SJX[m_nJX].JX[0].m_x=375;
		SJX[m_nJX].JX[0].m_y=75;
	}
}

void CMy1215View::BianHuanTuXing(int Shape)
{
	int i;
     if(Shape-1==0)
	 {
		SJX[m_nJX].JX[1].m_x=SJX[m_nJX].JX[1].m_x+25;
		SJX[m_nJX].JX[1].m_y=SJX[m_nJX].JX[1].m_y-25;
		SJX[m_nJX].JX[2].m_y=SJX[m_nJX].JX[2].m_y-25;
		SJX[m_nJX].JX[3].m_y=SJX[m_nJX].JX[3].m_y+25;
	 }
	 if(Shape-1==1)
	 {
		 for(i=2;i<=3;i++)
			 SJX[m_nJX].JX[i].m_x=SJX[m_nJX].JX[i].m_x+25;
	 }
	 if(Shape-1==2)
	 {
		for(i=2;i<=3;i++)
			 SJX[m_nJX].JX[i].m_x=SJX[m_nJX].JX[i].m_x-50;
	 }
	 if(Shape-1==3)
	 {
		 for(i=0;i<2;i++)
			 SJX[m_nJX].JX[i].m_x=SJX[m_nJX].JX[i].m_x-50;
		 for(i=2;i<=3;i++)
		 {
			 SJX[m_nJX].JX[i].m_y=SJX[m_nJX].JX[i].m_y-25;
			 SJX[m_nJX].JX[i].m_x=SJX[m_nJX].JX[i].m_x+25;
		 }
	 }
	 if(Shape-1==4)
	 {
		 SJX[m_nJX].JX[0].m_x=SJX[m_nJX].JX[0].m_x+25;
		 SJX[m_nJX].JX[0].m_y-=75;
		 for(i=1;i<=3;i++)
		 {
			 SJX[m_nJX].JX[i].m_x=SJX[m_nJX].JX[i].m_x-(i-1)*25;
			 SJX[m_nJX].JX[i].m_y=SJX[m_nJX].JX[i].m_y+i*25-75;
		 }
	 }
     if(Shape-1==5)
	 {
		for(i=2;i<=3;i++)
		{
			SJX[m_nJX].JX[i].m_x=SJX[m_nJX].JX[i].m_x+25;
			SJX[m_nJX].JX[i].m_y=SJX[m_nJX].JX[i].m_y-25;
		}
	 }
	 if(Shape-1==6)
	 {
		 for(i=0;i<2;i++)
			 SJX[m_nJX].JX[i].m_y=SJX[m_nJX].JX[i].m_y+25;
		 for(i=2;i<=3;i++)
			 SJX[m_nJX].JX[i].m_y=SJX[m_nJX].JX[i].m_y-25;
	 }
	 if(Shape-1==7)
	 {
		 SJX[m_nJX].JX[2].m_y=SJX[m_nJX].JX[2].m_y+50;
		 SJX[m_nJX].JX[3].m_x=SJX[m_nJX].JX[3].m_x+25;
		 SJX[m_nJX].JX[3].m_y=SJX[m_nJX].JX[3].m_y+25;
	 }
	 if(Shape-1==8)
	 {
		 SJX[m_nJX].JX[0].m_x=SJX[m_nJX].JX[0].m_x+50;
	 }
	 if(Shape-1==9)
	 {
		 SJX[m_nJX].JX[0].m_x=SJX[m_nJX].JX[0].m_x-50;
		 SJX[m_nJX].JX[2].m_x=SJX[m_nJX].JX[2].m_x-25;
		 SJX[m_nJX].JX[2].m_y=SJX[m_nJX].JX[2].m_y+25;
		 SJX[m_nJX].JX[3].m_x=SJX[m_nJX].JX[3].m_x-25;
		 SJX[m_nJX].JX[3].m_y=SJX[m_nJX].JX[3].m_y+25;
	 }
	 if(Shape-1==10)
	 {
	     SJX[m_nJX].JX[0].m_y+=25;
		 SJX[m_nJX].JX[1].m_y-=25;
		 SJX[m_nJX].JX[2].m_x+=25;
		 SJX[m_nJX].JX[2].m_y-=50;
         SJX[m_nJX].JX[3].m_x+=25;
		 SJX[m_nJX].JX[3].m_y-=50;
	 }
	 if(Shape-1==11)
	 {
		 SJX[m_nJX].JX[0].m_x+=50;
	 }
	 if(Shape-1==12)
	 {
		 SJX[m_nJX].JX[0].m_y-=50;
		 SJX[m_nJX].JX[0].m_x-=25;
	 }
	 if(Shape-1==13)
	 {
         SJX[m_nJX].JX[0].m_y+=50;
	 }
	 if(Shape-1==14)
	 {
		 SJX[m_nJX].JX[1].m_x+=25;
		 SJX[m_nJX].JX[1].m_y-=25;
		 SJX[m_nJX].JX[3].m_x-=25;
		 SJX[m_nJX].JX[3].m_y+=25;
		 SJX[m_nJX].JX[0].m_y-=25;
		 SJX[m_nJX].JX[0].m_x+=25;
	 }
	 if(Shape-1==15)
	 {
		 SJX[m_nJX].JX[0].m_x-=50;
	 }
	 if(Shape-1==-1)
	 {
		SJX[m_nJX].JX[3].m_y=SJX[m_nJX].JX[3].m_y-50;
		SJX[m_nJX].JX[3].m_x+=25;
		for(i=1;i<3;i++)
			SJX[m_nJX].JX[i].m_y+=25;
		SJX[m_nJX].JX[0].m_x+=25;
		SJX[m_nJX].JX[0].m_y-=25;
	 }/////////////////////////////////////////////此处要特别注意是-1不是10;
}

void CMy1215View::OnMQuick() 
{
	// TODO: Add your command handler code here
	speed=10;
}

void CMy1215View::OnMSlow() 
{
	// TODO: Add your command handler code here
	speed=-5;
}

void CMy1215View::OnMMediumen() 
{
	// TODO: Add your command handler code here
	speed=0;
}

void CMy1215View::OnMStart() 
{
	// TODO: Add your command handler code here
	SetTimer(1,10,NULL);
}

void CMy1215View::OnMStop() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}

void CMy1215View::OnMEnd() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	CAdo m_Ado;
	CString sql;
	m_Ado.OnInitADOConn(".\\CAdo\\分数.mdb");
	UpdateData(true);
	sql.Format("insert into 分数表(sname,sscore,sage) values('%s',%d,%d)",name,score,age);
	m_Ado.ExecuteSQL(sql);
	m_Ado.ExitConnect();
	AfxMessageBox("结束!");
	OnInitialUpdate();
}

void CMy1215View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int i,j,k;
	SJX[m_nJX].JX[0].m_y+=10+speed;
	SJX[m_nJX].JX[1].m_y+=10+speed;
	SJX[m_nJX].JX[2].m_y+=10+speed;
	SJX[m_nJX].JX[3].m_y+=10+speed;
	Sleep(200);//控制向下速度
	Invalidate(true);
	Collision();
	CollisionDelect();//解除左右移动暂停
	XiaoChu();
	GameOver();
	///////////判断图形是否碰到左右两壁
	for(i=0;i<4;i++)
		if(SJX[m_nJX].JX[i].m_x<=200)
		{
			y[m_s]=0;
			k=200-SJX[m_nJX].JX[i].m_x;
			for(j=0;j<4;j++)
				SJX[m_nJX].JX[j].m_x=SJX[m_nJX].JX[j].m_x+k;
		}
		for(i=0;i<4;i++)
			if(SJX[m_nJX].JX[i].m_x>=575)
			{
				z[m_s]=0;
				k=SJX[m_nJX].JX[i].m_x-575;
				for(j=0;j<4;j++)
					SJX[m_nJX].JX[j].m_x=SJX[m_nJX].JX[j].m_x-k;
			}
			//判断是否碰到底边
			for(i=0;i<4;i++)
			{
				if(SJX[m_nJX].JX[i].m_y>500)
				{
					speed=5;
                 if(SJX[m_nJX].JX[i].m_y>575)
				{
					f_y=-2;
					k=SJX[m_nJX].JX[i].m_y-575;
					for(j=0;j<4;j++)
						SJX[m_nJX].JX[j].m_y=SJX[m_nJX].JX[j].m_y-k;
					f_x=-2;
					TuXing[m_s]=0;////////////////使图形无法移动
					m_nJX++;
					m_s++;
					Shape[m_nJX]=rand()%11;
					KindTuXing(Shape[m_nJX]);
					
					//DrawTuXing();
					
				}
				}
			}
			CView::OnTimer(nIDEvent);
}

void CMy1215View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	int i;
	if(TuXing)
	{
		switch(nChar)
		{
		case 37:
			if(y[m_s]==1)
			{
				f_x=-1;
				SJX[m_nJX].JX[0].m_x-=25;
				SJX[m_nJX].JX[1].m_x-=25; 
				SJX[m_nJX].JX[2].m_x-=25; 
				SJX[m_nJX].JX[3].m_x-=25;
				f_x=-2;
				z[m_s]=1;
				h[m_s]=1;
			}
			//Sleep(10);
			break;
		case 38:
			if(h[m_s]==1)
			{
			f_y=-1;
			if(f_y==-1)
			{
			Shape[m_s]=(Shape[m_s]+1)%17;
			BianHuanTuXing(Shape[m_s]);
			}
			f_y=-2;
			}
			break;
		case 39:
			if(z[m_s]==1)
			{
				f_x=0;
				SJX[m_nJX].JX[0].m_x+=25;
				SJX[m_nJX].JX[1].m_x+=25; 
				SJX[m_nJX].JX[2].m_x+=25; 
				SJX[m_nJX].JX[3].m_x+=25;
				//	Sleep(10);
				f_x=-2;
                y[m_s]=1;
				h[m_s]=1;
			}
			break;
		case 40:f_y=0;
			speed+=10;
			f_y=-2;
			//Sleep(10);
			break;
		}
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CMy1215View::OnMZhuce() 
{
	// TODO: Add your command handler code here
	CZHUCEDLG dlg;
	dlg.DoModal();
    name=dlg.m_name;///////????????
    age=dlg.m_age;
}

void CMy1215View::DrawTuXing(int x, int y, int w, int h)
{
	CBrush brush1(RGB(rand()%255,rand()%255,128));
	xbrush=m_pDC->SelectObject(&brush1);
	m_pDC->SelectObject(brush1);
	m_pDC->Rectangle(x,y,x+w,y+h);
}


void CMy1215View::Dead()
{
	KillTimer(1);
	CAdo m_Ado;
	CString sql;
	m_Ado.OnInitADOConn(".\\CAdo\\分数.mdb");
	UpdateData(true);
	sql.Format("insert into 分数表(sname,sscore,sage) values('%s',%d,%d)",name,score,age);
	m_Ado.ExecuteSQL(sql);
	m_Ado.ExitConnect();
	AfxMessageBox("GameOver!");
	OnInitialUpdate();
}



void CMy1215View::Collision()
{
	int i,j,k,b,f,c=0;
	for(i=0;i<4;i++)
		for(j=0;j<m_nJX;j++)
			for(k=0;k<4;k++)
			{
				if(SJX[j].JX[k].m_y-SJX[m_nJX].JX[i].m_y<=50&&SJX[m_nJX].JX[i].m_y>50)
				{
					speed=0;
					if(SJX[j].JX[k].m_x-25==SJX[m_nJX].JX[i].m_x&&(SJX[m_nJX].JX[i].m_y-SJX[j].JX[k].m_y<25&&SJX[m_nJX].JX[i].m_y-SJX[j].JX[k].m_y>-25))
					{
						z[m_s]=0;
					}
					if(SJX[j].JX[k].m_x+25==SJX[m_nJX].JX[i].m_x&&(SJX[m_nJX].JX[i].m_y-SJX[j].JX[k].m_y<25&&SJX[m_nJX].JX[i].m_y-SJX[j].JX[k].m_y>-25))
					{
						y[m_s]=0;
					}
					if(SJX[j].JX[k].m_x==SJX[m_nJX].JX[i].m_x&&SJX[j].JX[k].m_y-25<=SJX[m_nJX].JX[i].m_y&&SJX[j].JX[k].m_y-SJX[m_nJX].JX[i].m_y>0)
					{
						f_y=-2;  
						TuXing[m_s]=0;
						b=SJX[m_nJX].JX[i].m_y-SJX[j].JX[k].m_y+25;
						for(j=0;j<4;j++)
							SJX[m_nJX].JX[j].m_y=SJX[m_nJX].JX[j].m_y-b;
						m_nJX++;
						m_s++;
						speed=0;
						Shape[m_nJX]=rand()%11;
						KindTuXing(Shape[m_nJX]);
						break;
					}
				}
				
			}
}

void CMy1215View::GameOver()
{
     int i,j,min=700;
	 for(j=0;j<m_nJX;j++)
	 for(i=0;i<4;i++)
	 if(SJX[j].JX[i].m_y<min)
		min=SJX[j].JX[i].m_y;
	 if(min<=50)
		 Dead();

}

void CMy1215View::XiaoChu()
{
	int i,j,k;
	int l[23];
	for(i=0;i<23;i++)
		l[i]=0;
	for(i=0;i<m_nJX;i++)
		for(j=0;j<4;j++)
		{
			if(SJX[i].JX[j].m_y==575)
                l[0]++;
			if(SJX[i].JX[j].m_y==550)
				l[1]++;
			if(SJX[i].JX[j].m_y==525)
                l[2]++;
			if(SJX[i].JX[j].m_y==500)
				l[3]++;
			if(SJX[i].JX[j].m_y==475)
				l[4]++;
			if(SJX[i].JX[j].m_y==450)
				l[5]++;
			if(SJX[i].JX[j].m_y==425)
				l[6]++;
			if(SJX[i].JX[j].m_y==400)
				l[7]++;
			if(SJX[i].JX[j].m_y==375)
				l[8]++;
			if(SJX[i].JX[j].m_y==350)
				l[9]++;
			if(SJX[i].JX[j].m_y==325)
				l[10]++;
			if(SJX[i].JX[j].m_y==300)
				l[11]++;
			if(SJX[i].JX[j].m_y==275)
				l[12]++;
			if(SJX[i].JX[j].m_y==250)
				l[13]++;
			if(SJX[i].JX[j].m_y==225)
                l[14]++;
			if(SJX[i].JX[j].m_y==200)
                l[15]++;
			if(SJX[i].JX[j].m_y==175)
				l[16]++;
			if(SJX[i].JX[j].m_y==150)
				l[17]++;
			if(SJX[i].JX[j].m_y==125)
				l[18]++;
			if(SJX[i].JX[j].m_y==100)
				l[19]++;
			if(SJX[i].JX[j].m_y==75)
				l[20]++;
			if(SJX[i].JX[j].m_y==50)
				l[21]++;
		}
		for(i=0;i<22;i++)
			if(l[i]>=16)
			{
				score+=5;
				Delete(i);
			}
}

void CMy1215View::Delete(int i)
{
     int m,j,k;
	 m=(21-i)*25+50;
     for(j=0;j<m_nJX;j++)
		 for(k=0;k<4;k++)
			 if(SJX[j].JX[k].m_y==m&&SJX[j].JX[k].m_y<m+25)
			 {
                SJX[j].JX[k].m_y+=500;
			 }
      for(j=0;j<m_nJX;j++)
		 for(k=0;k<4;k++)
		 {
			 if(SJX[j].JX[k].m_y<m)
				 SJX[j].JX[k].m_y+=25;
		 }
}

void CMy1215View::DrawBackground(int score)
{
     CBrush brush1(RGB(0,128,128));
	 COLORREF brush2(RGB(255,0,255)),brush3(RGB(0,0,255));
	 COLORREF crPre;
	 xbrush=m_pDC->SelectObject(&brush1);
	 m_pDC->SelectObject(brush1);
	 m_pDC->Rectangle(BJX1.Bm_x,BJX1.Bm_y,BJX1.Bm_x+BJX1.Bm_w,BJX1.Bm_h+BJX1.Bm_y);//给背景设绿色
	 CString str;
	 str.Format("成绩:%d",score);
	 crPre=m_pDC->SetTextColor(brush2);
	 m_pDC->SetTextColor(brush2);
	 m_pDC->TextOut(650,100,str);//给成绩设红色
	 crPre=m_pDC->SetTextColor(brush3);
	 m_pDC->SetTextColor(brush3);
	 m_pDC->TextOut(650,200,"按上键： 变换形状");
	 m_pDC->TextOut(650,250,"按下键： 加速");
	 m_pDC->TextOut(650,300,"按左键： 左移");
	 m_pDC->TextOut(650,350,"按右键： 右移");
}

void CMy1215View::OnScore() 
{
	// TODO: Add your command handler code here
	CSJKDlg dlg;
	dlg.DoModal();
}

void CMy1215View::CollisionDelect()
{
	int i,j,k;
	int sunz=0,suny=0;
     for(i=0;i<4;i++)
		for(j=0;j<m_nJX;j++)
			for(k=0;k<4;k++)
			{
			   if(z[m_s]==0)
			   {
				   if(SJX[j].JX[k].m_x-25==SJX[m_nJX].JX[i].m_x&&(SJX[m_nJX].JX[i].m_y-SJX[j].JX[k].m_y<25&&SJX[m_nJX].JX[i].m_y-SJX[j].JX[k].m_y>-25))
				        sunz++;	   
			   }
			   if(y[m_s]==0)
				   {
				   if(SJX[j].JX[k].m_x+25==SJX[m_nJX].JX[i].m_x&&(SJX[m_nJX].JX[i].m_y-SJX[j].JX[k].m_y<25&&SJX[m_nJX].JX[i].m_y-SJX[j].JX[k].m_y>-25))
				        suny++;	   
			   }
			}
			if(sunz==0)
			{
				z[m_s]=1;
				h[m_s]=1;
			}
			if(suny==0)
			{
				y[m_s]=1;
				h[m_s]=1;
			}

}
