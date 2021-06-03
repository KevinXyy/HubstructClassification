// CreateTemplate.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "CreateTemplate.h"
#include "afxdialogex.h"
#include "TemplateParams.h"




// CreateTemplate 对话框

IMPLEMENT_DYNAMIC(CCreateTemplate, CDialogEx)

CCreateTemplate::CCreateTemplate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CREATE_TEMP_DLG, pParent),
	ROICentreRow(L"546"),
	ROICentreCol(L"1012"),
	ROIRadius(L"469")
{
	

}

CCreateTemplate::~CCreateTemplate()
{
}

void CCreateTemplate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, ROIRadius);
	DDX_Text(pDX, IDC_EDIT2, ROICentreRow);
	DDX_Text(pDX, IDC_EDIT4, ROICentreCol);
}


BEGIN_MESSAGE_MAP(CCreateTemplate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCreateTemplate::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CCreateTemplate::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CCreateTemplate::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CCreateTemplate::OnEnChangeEdit4)
	ON_BN_CLICKED(IDOK, &CCreateTemplate::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CCreateTemplate::OnBnClickedButton2)
END_MESSAGE_MAP()


HTuple CCreateTemplate::getModelID() {
	return modelID;
}

char* CCreateTemplate::getTypeName() {
	return typeName;
}
// CreateTemplate 消息处理程序


void CCreateTemplate::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString m_strFilePath = _T("");

	//打开图像文件，获取文件路径名
	LPCTSTR szFilter = _T("JPG(*.jpg)|*.jpg|BMP(*.bmp)|*.bmp|PNG(*.png)|*.png|ALLSUPORTFILE(*.*)|*.*||");
	CFileDialog dlgFileOpenImg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL);
	//打开图像
	if (dlgFileOpenImg.DoModal() == IDOK)
	{
		//读取图像文件名
		m_strFilePath = dlgFileOpenImg.GetPathName();
	}
	else {
		return;
	}

	USES_CONVERSION;
	char* path1 = W2A(m_strFilePath);
	ReadImage(&Image1, path1);
	GetImagePointer1(Image1, &pointer1, &Type1, &m_ImageWidth1, &m_ImageHeight1);
	CWnd* pWnd = GetDlgItem(IDC_STATIC4);
	HWindowID1 = (Hlong)pWnd->m_hWnd;
	pWnd->GetWindowRect(&Rect1);
	SetWindowAttr("background_color", "black");
	
	OpenWindow(0, 0, Rect1.Width() , Rect1.Height(), HWindowID1, "visible", "", &WindowHandle1);
	
	DispObj(Image1, WindowHandle1);
}


void CCreateTemplate::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCreateTemplate::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCreateTemplate::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CCreateTemplate::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//获取ROI的半径及圆心位置
	if (HWindowID1 == -100) {
		MessageBox(L"图像窗口未初始化！");
		return;
	}

	USES_CONVERSION;
	int cr = _ttoi(ROICentreRow);
	int cc = _ttoi(ROICentreCol);
	int r = _ttoi(ROIRadius);
	GenCircle(&ROI, cr, cc, r);/*(int)(W2A(centreRow)), (int)(W2A(centreCol)), (int)(W2A(radius)));*/
	DispObj(Image1, WindowHandle1);
	DispObj(ROI, WindowHandle1);


}


void CCreateTemplate::OnBnClickedButton2()
{
	
	if (HWindowID1 == -100) {
		MessageBox(L"图像窗口未初始化！");
		return;
	}

	if (!ROI.IsInitialized()) {
		MessageBox(L"未建立感兴趣区域。");
		return;
	}
	//将图片处理为灰度图片
	Rgb1ToGray(Image1, &GrayImage);
	//通过感兴趣区域选中图片
	ReduceDomain(GrayImage, ROI, &ReducedImage);
	//打开参数对话框
	CTemplateParams dlg;
	dlg.DoModal();
	angleStart = _ttof(dlg.angleStart);
	angleExtent = _ttof(dlg.angleExtent);
	USES_CONVERSION;
	metric = W2A(dlg.metric);
	//通过参数创建NCC模型
	CreateNccModel(ReducedImage, "auto", angleStart, angleExtent, "auto", metric, &modelID);
	typeName = W2A(dlg.typeName);
	
	CDialogEx::OnOK();

}
