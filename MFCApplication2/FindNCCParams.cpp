// FindNCCParams.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "FindNCCParams.h"
#include "afxdialogex.h"


// CFindNCCParams 对话框

IMPLEMENT_DYNAMIC(CFindNCCParams, CDialogEx)

CFindNCCParams::CFindNCCParams(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIND_NCC_PARAMS, pParent)
	, angleStart(_T("-0.39"))
	, angleExtent(_T("0.79"))
	, minScore(_T("0.5"))
	, maxOverlap(_T("0.5"))
{

}

CFindNCCParams::~CFindNCCParams()
{
}

void CFindNCCParams::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, angleStart);
	DDX_Text(pDX, IDC_EDIT4, angleExtent);
	DDX_Text(pDX, IDC_EDIT5, minScore);
	DDX_Text(pDX, IDC_EDIT6, maxOverlap);
}


BEGIN_MESSAGE_MAP(CFindNCCParams, CDialogEx)
	ON_BN_CLICKED(IDOK, &CFindNCCParams::OnBnClickedOk)
END_MESSAGE_MAP()


// CFindNCCParams 消息处理程序

BOOL CFindNCCParams::OnInitDialog() {
	CDialogEx::OnInitDialog();
	m_font.CreatePointFont(100,_T("宋体"));
	GetDlgItem(IDC_STATIC1)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC2)->SetFont(&m_font); 
	GetDlgItem(IDC_STATIC3)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC4)->SetFont(&m_font);
	return TRUE;
}

void CFindNCCParams::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	if (angleStart.IsEmpty() || angleExtent.IsEmpty() || minScore.IsEmpty() ||
		maxOverlap.IsEmpty()) {
		MessageBox(L"输入不能为空");
		return;
	}
	CDialogEx::OnOK();
	
}
