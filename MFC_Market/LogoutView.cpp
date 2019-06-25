#include "pch.h"
#include "LogoutView.h"

// LogoutView

using namespace std;

IMPLEMENT_DYNCREATE(LogoutView, CFormView)

LogoutView::LogoutView()
	: CFormView(LogoutView::IDD)
{

}BEGIN_MESSAGE_MAP(LogoutView, CFormView)
ON_BN_CLICKED(IDOK, &LogoutView::OnBnClickedOk)
ON_BN_CLICKED(IDOK2, &LogoutView::OnBnClickedOk2)
END_MESSAGE_MAP()


void LogoutView::OnBnClickedOk()//�˳���½
{
	char title[65] = "\0";
	GetWindowTextA(AfxGetMainWnd()->GetSafeHwnd(), LPSTR(title), 64);
	string strTitle = title;
	if (strTitle == "δ��½ - MFC_Market_Management" || strTitle == "δ��½")
	{
		MessageBox(TEXT("���ȵ�½��"),TEXT("ERROR!"), MB_ICONEXCLAMATION);
		return;
	}
	SetWindowTextA(AfxGetMainWnd()->GetSafeHwnd(), "δ��½");
	MessageBox(TEXT("�ǳ��ɹ���"));
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void LogoutView::OnBnClickedOk2()//�޸�����
{
	char title[65] = "\0";
	GetWindowTextA(AfxGetMainWnd()->GetSafeHwnd(), LPSTR(title), 64);
	string strTitle = title;
	if (strTitle == "δ��½ - MFC_Market_Management" || strTitle == "δ��½")
	{
		MessageBox(TEXT("���ȵ�½��"), TEXT("ERROR!"), MB_ICONEXCLAMATION);
		return;
	}
	CString Username;/*
	Username = CStringA(strTitle.c_str());
	int begin = Username.Find(TEXT("��"));
	int end = Username.Find(TEXT(" ["));
	Username = Username.Mid(begin+1, end);*/
	string tmp=strTitle.substr(strTitle.find("��")+2, strTitle.find("["));
	
	CString passwd1, passwd2;
	GetDlgItemText(IDC_EDIT3, passwd1);
	GetDlgItemText(IDC_EDIT4, passwd2);
	if (passwd1.Compare(passwd2))
	{
		MessageBox(TEXT("�����������벻ͬ��"), TEXT("ERROR!"), MB_ICONEXCLAMATION);
		return;
	}
	UsersList currentList;
	currentList.ReadFile();
	list<ACCESS>::iterator it = currentList.Find(Username);
	SetDlgItemText(IDC_EDIT3, TEXT(""));
	SetDlgItemText(IDC_EDIT4, TEXT(""));
	MessageBox(TEXT("�����޸ĳɹ���"));
}
