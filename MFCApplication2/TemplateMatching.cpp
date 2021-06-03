// TemplateMatching.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "TemplateMatching.h"
#include "afxdialogex.h"
#include "CreateTemplate.h"


// TemplateMatching 对话框

IMPLEMENT_DYNAMIC(TemplateMatching, CDialogEx)

TemplateMatching::TemplateMatching(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEMP_MATCH_DLG, pParent)
{

}

TemplateMatching::~TemplateMatching()
{
}

void TemplateMatching::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TemplateMatching, CDialogEx)
	ON_BN_CLICKED(IDOK, &TemplateMatching::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &TemplateMatching::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &TemplateMatching::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &TemplateMatching::OnBnClickedButton3)
END_MESSAGE_MAP()


// TemplateMatching 消息处理程序


void TemplateMatching::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void TemplateMatching::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void TemplateMatching::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CCreateTemplate dlg;
	dlg.DoModal();
	modelIds = modelIds.TupleConcat(dlg.getModelID());
	
	types = types.TupleConcat(dlg.getTypeName());
	numOfTypes += 1;
	std::cout << "\n\n\n\n\n";
	//弹出新对话框，输入对应的模板参数
}


void TemplateMatching::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CClassDlg dlg;
	//选中图片进行分类处理
	dlg.setModelIds(modelIds);
	dlg.setTypes(types);
	dlg.DoModal();
}
