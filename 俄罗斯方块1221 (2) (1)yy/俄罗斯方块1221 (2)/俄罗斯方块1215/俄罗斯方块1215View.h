// 俄罗斯方块1215View.h : interface of the CMy1215View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1215VIEW_H__301C0250_25B6_4930_A701_26790BC64A82__INCLUDED_)
#define AFX_1215VIEW_H__301C0250_25B6_4930_A701_26790BC64A82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ZHUCEDLG.h"
#include "SJKDlg.h"

struct BJuXing
{
    int Bm_x;
	int Bm_y;
	int Bm_h;
	int Bm_w;
};///////////画背景两个矩形
struct JuXing
{
	int m_x;
	int m_y;
	int m_w;
	int m_h;
};////

struct SJuXing
{
    struct JuXing JX[4];
};////

class CMy1215View : public CView
{
protected: // create from serialization only
	CMy1215View();
	DECLARE_DYNCREATE(CMy1215View)

// Attributes
public:
	CMy1215Doc* GetDocument();

// Operations
public:
     CDC *m_pDC;
    struct BJuXing BJX1,BJX2;//背景的两个矩形
	CBrush *xbrush;//画刷给背景弄青色
	float score;//记录分数

	struct SJuXing SJX[100];//画多个图形
	int m_nJX;//记录图形个数
	int m_s;//记录第n个图形形状
	int speed;
	int Shape[100];//形状
	int f_x;//f_x==-1时向左，f_x==0时向右
	int f_y;//f_y==-1时向下加速，f_y=0时变换图形
	int TuXing[100];//判断是否碰底
	int z[100];//判断是否能想左
	int y[100];//判断是否能向右
	int h[100];
	CString name;
	int age;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1215View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void CollisionDelect();
	void DrawBackground(int score);
	void Delete(int i);
	void XiaoChu();
	void GameOver();
	void Collision();
	void Dead();
	void DrawTuXing(int x,int y,int w,int h);
	void BianHuanTuXing(int Shape);
	void KindTuXing(int Shape);
	void DrawJuXing(int x,int y,int w,int h);
	virtual ~CMy1215View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1215View)
	afx_msg void OnMQuick();
	afx_msg void OnMSlow();
	afx_msg void OnMMediumen();
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnMEnd();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMZhuce();
	afx_msg void OnScore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 俄罗斯方块1215View.cpp
inline CMy1215Doc* CMy1215View::GetDocument()
   { return (CMy1215Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1215VIEW_H__301C0250_25B6_4930_A701_26790BC64A82__INCLUDED_)
