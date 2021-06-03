// TemplateParams.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "TemplateParams.h"
#include "afxdialogex.h"


// CTemplateParams 对话框

IMPLEMENT_DYNAMIC(CTemplateParams, CDialogEx)

CTemplateParams::CTemplateParams(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEW_TEMP_PARAMS, pParent)
	, angleStart(_T("-0.39"))
	, angleExtent(_T("0.79"))
	, metric(_T("use_polarity"))
	, typeName(_T(""))
{

}

CTemplateParams::~CTemplateParams()
{
}

void CTemplateParams::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, angleStart);
	DDX_Text(pDX, IDC_EDIT4, angleExtent);
	DDX_Text(pDX, IDC_EDIT5, metric);
	DDX_Text(pDX, IDC_EDIT6, typeName);
}


BEGIN_MESSAGE_MAP(CTemplateParams, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CTemplateParams::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT4, &CTemplateParams::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CTemplateParams::OnEnChangeEdit5)
	ON_BN_CLICKED(IDOK, &CTemplateParams::OnBnClickedOk)
END_MESSAGE_MAP()


// CTemplateParams 消息处理程序


void CTemplateParams::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTemplateParams::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTemplateParams::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CTemplateParams::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
}
