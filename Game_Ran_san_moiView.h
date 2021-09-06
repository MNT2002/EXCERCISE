
// Game_Ran_san_moiView.h : interface of the CGameRansanmoiView class
//
#include"Giaodien.h"
#pragma once


class CGameRansanmoiView : public CView
{
protected: // create from serialization only
	CGameRansanmoiView() noexcept;
	DECLARE_DYNCREATE(CGameRansanmoiView)

// Attributes
public:
	CGameRansanmoiDoc* GetDocument() const;

// Operations
public:
	Giaodien g;
	int kd;

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CGameRansanmoiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	void Batdau();
};

#ifndef _DEBUG  // debug version in Game_Ran_san_moiView.cpp
inline CGameRansanmoiDoc* CGameRansanmoiView::GetDocument() const
   { return reinterpret_cast<CGameRansanmoiDoc*>(m_pDocument); }
#endif

