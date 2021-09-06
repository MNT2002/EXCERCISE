
// Game_Ran_san_moiView.cpp : implementation of the CGameRansanmoiView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Game_Ran_san_moi.h"
#endif

#include "Game_Ran_san_moiDoc.h"
#include "Game_Ran_san_moiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGameRansanmoiView

IMPLEMENT_DYNCREATE(CGameRansanmoiView, CView)

BEGIN_MESSAGE_MAP(CGameRansanmoiView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CGameRansanmoiView construction/destruction

CGameRansanmoiView::CGameRansanmoiView() noexcept
{
	// TODO: add construction code here
	g = Giaodien();
	kd = 0;
}

CGameRansanmoiView::~CGameRansanmoiView()
{
}

BOOL CGameRansanmoiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGameRansanmoiView drawing

void CGameRansanmoiView::OnDraw(CDC* /*pDC*/)
{
	CGameRansanmoiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pdc(this);

	g.vehinh(&pdc);

	// TODO: add draw code for native data here
}

void CGameRansanmoiView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGameRansanmoiView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGameRansanmoiView diagnostics

#ifdef _DEBUG
void CGameRansanmoiView::AssertValid() const
{
	CView::AssertValid();
}

void CGameRansanmoiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGameRansanmoiDoc* CGameRansanmoiView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGameRansanmoiDoc)));
	return (CGameRansanmoiDoc*)m_pDocument;
}
#endif //_DEBUG


// CGameRansanmoiView message handlers


void CGameRansanmoiView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	int a= g.dinhhuong;
	
	if (nChar == 38 && a!=40 ) //&& "a!=40"Them dieu kien nay de ran ko quay dau duoc
	{
		g.huongdi = 38;
		return;
	}
	if (nChar == 37 && a!=39 )
	{
		g.huongdi = 37;
		return;
	}
	if (nChar == 40 && a!=38 )
	{
		g.huongdi = 40;
		return;
	}
	if (nChar == 39 &&a!=37 )
	{
		g.huongdi = 39;
		return;
	}
	if (nChar == 32) //ban phim space
	{
		if (g.dk == 0)
			Batdau();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CGameRansanmoiView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
UINT capnhathinh(LPVOID pParam)
{
	int ran = 0;
	CGameRansanmoiView* cview = (CGameRansanmoiView*)pParam;
	CClientDC pdc(cview);
	cview->g.capnhathinh(&pdc);
	return 0;
}
UINT randichuyen(LPVOID pParam)
{
	int ran = 0;
	CGameRansanmoiView* cview = (CGameRansanmoiView*)pParam;
	cview->g.dichuyen();
	return 0;
}
void CGameRansanmoiView::Batdau()
{
	// TODO: Add your implementation code here.
	g.thietlap();
	g.batdau();
	AfxBeginThread(capnhathinh, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	AfxBeginThread(randichuyen, this, THREAD_PRIORITY_HIGHEST, 0, 0, NULL);
}
