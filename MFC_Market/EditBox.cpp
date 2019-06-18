#include "pch.h"
#include "MainFrm.h"
#include "EditBox.h"
#include "resource.h"

IMPLEMENT_DYNCREATE(EditBox, CFormView)

EditBox::EditBox()
	: CFormView(EditBox::IDD)
{

}



void EditBox::AssertValid() const
{
	CFormView::AssertValid();

	// TODO: �ڴ����ר�ô����/����û���
}


void EditBox::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);

	// TODO: �ڴ����ר�ô����/����û���
}
BEGIN_MESSAGE_MAP(EditBox, CFormView)
	ON_BN_CLICKED(IDOK, &EditBox::OnBnClickedOk)
END_MESSAGE_MAP()

void EditBox::OnBnClickedOk()
{
	CString inUsername, inPasswd;
	GetDlgItemText(IDC_EDIT1, inUsername);
	GetDlgItemText(IDC_EDIT2, inPasswd);
	MessageBox(inUsername + inPasswd);
}
