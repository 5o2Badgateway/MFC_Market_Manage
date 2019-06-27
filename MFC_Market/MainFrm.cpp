﻿
// MainFrm.cpp: CMainFrame 类的实现
//

#include "pch.h"
#include "framework.h"
#include "MFC_Market.h"
#include "Goods.h"
#include "SelectBox.h"
#include "LoginView.h"
#include "LogoutView.h"
#include "GoodsManageView.h"
#include "PurchaseView.h"
#include "MainFrm.h"
#include "Receipt_Refund.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_MESSAGE(EDIT_LOGIN, OnEditChanges)
	ON_MESSAGE(EDIT_LOGOUT,OnEditChanges)
	ON_MESSAGE(EDIT_USERS_MANAGEMENT, OnEditChanges)
	ON_MESSAGE(EDIT_GOODS_MANAGEMENT, OnEditChanges)
	ON_MESSAGE(EDIT_PURCHASE, OnEditChanges)
	ON_MESSAGE(EDIT_RECEIPT_REFUNDS, OnEditChanges)
	ON_COMMAND_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnApplicationLook)
	ON_UPDATE_COMMAND_UI_RANGE(ID_VIEW_APPLOOK_WIN_2000, ID_VIEW_APPLOOK_WINDOWS_7, &CMainFrame::OnUpdateApplicationLook)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame() noexcept
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	MoveWindow(0, 0, 800, 600);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	//主标题和图标
	SetClassLong(m_hWnd, -14, 311);
	SetTitle(TEXT("MFC_Market_Management"));

	

	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnApplicationLook(UINT id)
{
	CWaitCursor wait;

	theApp.m_nAppLook = id;

	switch (theApp.m_nAppLook)
	{
	case ID_VIEW_APPLOOK_WIN_2000:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManager));
		break;

	case ID_VIEW_APPLOOK_OFF_XP:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOfficeXP));
		break;

	case ID_VIEW_APPLOOK_WIN_XP:
		CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
		break;

	case ID_VIEW_APPLOOK_OFF_2003:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2003));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2005:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2005));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_VS_2008:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerVS2008));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	case ID_VIEW_APPLOOK_WINDOWS_7:
		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows7));
		CDockingManager::SetDockingMode(DT_SMART);
		break;

	default:
		switch (theApp.m_nAppLook)
		{
		case ID_VIEW_APPLOOK_OFF_2007_BLUE:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_LunaBlue);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_BLACK:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_ObsidianBlack);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_SILVER:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
			break;

		case ID_VIEW_APPLOOK_OFF_2007_AQUA:
			CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Aqua);
			break;
		}

		CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
		CDockingManager::SetDockingMode(DT_SMART);
	}
	RedrawWindow(nullptr, nullptr, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);

}

void CMainFrame::OnUpdateApplicationLook(CCmdUI* pCmdUI)
{
	pCmdUI->SetRadio(theApp.m_nAppLook == pCmdUI->m_nID);
}



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	windowSplitter.CreateStatic(this, 1, 2);
	windowSplitter.CreateView(0, 0, RUNTIME_CLASS(SelectBox),CSize(300,600),pContext);
	windowSplitter.CreateView(0, 1, RUNTIME_CLASS(LoginView), CSize(500, 600), pContext);
	return TRUE;
}

LRESULT CMainFrame::OnEditChanges(WPARAM message, LPARAM lparam)
{
	switch (message) {
	case EDIT_LOGIN: {
		cContext.m_pNewViewClass = RUNTIME_CLASS(LoginView);
		cContext.m_pCurrentFrame = this;
		cContext.m_pLastView = (CFormView*)windowSplitter.GetPane(0, 1);
		windowSplitter.DeleteView(0, 1);
		windowSplitter.CreateView(0, 1, RUNTIME_CLASS(LoginView), CSize(500, 600), &cContext);
		LoginView* newView = (LoginView*)windowSplitter.GetPane(0, 1);
		windowSplitter.RecalcLayout();
		newView->OnInitialUpdate();
		windowSplitter.SetActivePane(0, 1);
	}
					 break;
	case EDIT_LOGOUT: {
		cContext.m_pNewViewClass = RUNTIME_CLASS(LogoutView);
		cContext.m_pCurrentFrame = this;
		cContext.m_pLastView = (CFormView*)windowSplitter.GetPane(0, 1);
		windowSplitter.DeleteView(0, 1);
		windowSplitter.CreateView(0, 1, RUNTIME_CLASS(LogoutView), CSize(500, 600), &cContext);
		LogoutView* newView = (LogoutView*)windowSplitter.GetPane(0, 1);
		windowSplitter.RecalcLayout();
		newView->OnInitialUpdate();
		windowSplitter.SetActivePane(0, 1);
	}
		break;
	case EDIT_GOODS_MANAGEMENT: {
		cContext.m_pNewViewClass = RUNTIME_CLASS(GoodsManageView);
		cContext.m_pCurrentFrame = this;
		cContext.m_pLastView = (CFormView*)windowSplitter.GetPane(0, 1);
		windowSplitter.DeleteView(0, 1);
		windowSplitter.CreateView(0, 1, RUNTIME_CLASS(GoodsManageView), CSize(500, 600), &cContext);
		GoodsManageView* newView = (GoodsManageView*)windowSplitter.GetPane(0, 1);
		windowSplitter.RecalcLayout();
		newView->OnInitialUpdate();
		windowSplitter.SetActivePane(0, 1);
	}
		break;
	case EDIT_USERS_MANAGEMENT:
		break;
	case EDIT_PURCHASE: {
		cContext.m_pNewViewClass = RUNTIME_CLASS(PurchaseView);
		cContext.m_pCurrentFrame = this;
		cContext.m_pLastView = (CFormView*)windowSplitter.GetPane(0, 1);
		windowSplitter.DeleteView(0, 1);
		windowSplitter.CreateView(0, 1, RUNTIME_CLASS(PurchaseView), CSize(500, 600), &cContext);
		PurchaseView* newView = (PurchaseView*)windowSplitter.GetPane(0, 1);
		windowSplitter.RecalcLayout();
		newView->OnInitialUpdate();
		windowSplitter.SetActivePane(0, 1);
	}
						break;
		break;
	case EDIT_RECEIPT_REFUNDS: {
		cContext.m_pNewViewClass = RUNTIME_CLASS(Receipt_Refund);
		cContext.m_pCurrentFrame = this;
		cContext.m_pLastView = (CFormView*)windowSplitter.GetPane(0, 1);
		windowSplitter.DeleteView(0, 1);
		windowSplitter.CreateView(0, 1, RUNTIME_CLASS(Receipt_Refund), CSize(500, 600), &cContext);
		Receipt_Refund* newView = (Receipt_Refund*)windowSplitter.GetPane(0, 1);
		windowSplitter.RecalcLayout();
		newView->OnInitialUpdate();
		windowSplitter.SetActivePane(0, 1);
	}
							   break;
	default:
		break;
	}
	return 0;
}
