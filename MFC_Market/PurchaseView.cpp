#include "pch.h"
#include "PurchaseView.h"

// PurchaseView

using namespace std;

IMPLEMENT_DYNCREATE(PurchaseView, CFormView)

PurchaseView::PurchaseView()
	: CFormView(PurchaseView::IDD)
{

}

BEGIN_MESSAGE_MAP(PurchaseView, CFormView)
	ON_BN_CLICKED(IDC_FILTER_BUTTON, &PurchaseView::OnBnClickedFilterButton)
	ON_BN_CLICKED(IDC_SORT_BUTTON, &PurchaseView::OnBnClickedSortButton)
	ON_NOTIFY(UDN_DELTAPOS, IDC_TOCART_SPIN, &PurchaseView::OnDeltaposTocartSpin)
	ON_BN_CLICKED(IDC_TOCART_BUTTON, &PurchaseView::OnBnClickedTocartButton)
	ON_BN_CLICKED(IDC_DELETE_BUTTON, &PurchaseView::OnBnClickedDeleteButton)
	ON_NOTIFY(UDN_DELTAPOS, IDC_INCART_SPIN, &PurchaseView::OnDeltaposIncartSpin)
	ON_BN_CLICKED(IDC_INCART_BUTTON, &PurchaseView::OnBnClickedIncartButton)
	ON_BN_CLICKED(IDC_BUY_BUTTO, &PurchaseView::OnBnClickedBuyButto)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_GOODS_LIST, &PurchaseView::OnLvnItemchangedGoodsList)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_CART_LIST, &PurchaseView::OnLvnItemchangedCartList)
END_MESSAGE_MAP()


void PurchaseView::OnBnClickedFilterButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void PurchaseView::OnBnClickedSortButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void PurchaseView::OnDeltaposTocartSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void PurchaseView::OnBnClickedTocartButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void PurchaseView::OnBnClickedDeleteButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void PurchaseView::OnDeltaposIncartSpin(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void PurchaseView::OnBnClickedIncartButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void PurchaseView::OnBnClickedBuyButto()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void PurchaseView::OnLvnItemchangedGoodsList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void PurchaseView::OnLvnItemchangedCartList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
