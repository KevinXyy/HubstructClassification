// ClassDLg.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication2.h"
#include "ClassDLg.h"
#include "afxdialogex.h"


// CClassDLg 对话框

IMPLEMENT_DYNAMIC(CClassDlg, CDialogEx)

CClassDlg::CClassDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLASSDLG, pParent)
{

}

CClassDlg::~CClassDlg()
{
}

void CClassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CClassDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CClassDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


void CClassDlg::setModelIds(HTuple modelIDs) {
	modelIds = modelIDs;
}

void CClassDlg::setTypes(HTuple typess) {
	types = typess;
}
// CClassDLg 消息处理程序


void CClassDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString m_strFilePath = _T("");
	
	//打开图像文件，获取文件路径名
	LPCTSTR szFilter = _T("JPG(*.jpg)|*.jpg|BMP(*.bmp)|*.bmp|PNG(*.png)|*.png|ALLSUPORTFILE(*.*)|*.*||");
	CFileDialog dlgFileOpenImg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST| OFN_ALLOWMULTISELECT, szFilter, NULL);
	//设定最大读取文件数20
	TCHAR* pBuffer = new TCHAR[MAX_PATH * 20];
	dlgFileOpenImg.m_ofn.lpstrFile = pBuffer;
	dlgFileOpenImg.m_ofn.nMaxFile = MAX_PATH * 20;
	dlgFileOpenImg.m_ofn.lpstrFile[0] = '\0';
	if (dlgFileOpenImg.DoModal() == IDOK)
	{
		//读取图像文件名
		POSITION posFile = dlgFileOpenImg.GetStartPosition();
		//打开参数对话框
		CFindNCCParams dlg;
		if (dlg.DoModal() == IDOK) {

			HTuple angleStart = _ttof(dlg.angleStart);
			HTuple angleExtent = _ttof(dlg.angleExtent);
			HTuple minScore = _ttof(dlg.minScore);
			HTuple maxOverlap = _ttof(dlg.maxOverlap);

			while (posFile != NULL) {
				m_strFilePath = dlgFileOpenImg.GetNextPathName(posFile);
				USES_CONVERSION;

				ReadImage(&Image, m_strFilePath.GetBuffer());
				Rgb1ToGray(Image, &GrayImage);

				FindNccModels(GrayImage, modelIds, angleStart, angleExtent, minScore, 1, maxOverlap, "true", 0, &Row,
					&Column, &Angle, &Score, &Model);
				if (Model.Length() == 0) {
					MessageBox(L"没有找到结果");
				}
				else{
					char Message1[70];
				snprintf(Message1, 70, "这张图片是类型 %s，它的分数是：%f 。", types[(int)Model].S().Text(), (float)Score);
				MessageBox(A2W(Message1));
				}

			}
		}
		else {
			return;
		}
		
		
	}
	else {
		return;
	}

	

	
}
