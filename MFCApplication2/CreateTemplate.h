#pragma once
#include "HalconCpp.h"
using namespace HalconCpp;
// CreateTemplate 对话框

class CCreateTemplate : public CDialogEx
{
	DECLARE_DYNAMIC(CCreateTemplate)

public:
	CCreateTemplate(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCreateTemplate();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CREATE_TEMP_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();

	CString ROIRadius;
	
	afx_msg void OnEnChangeEdit4();
	CString ROICentreRow;
	CString ROICentreCol;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
	

protected:
	HTuple m_ImageWidth1, m_ImageHeight1, Type1, WindowHandle1, pointer1, HWindowID1 = -100;
	HTuple angleStart, angleExtent, metric, modelID;
	HObject  Image1, ROI, GrayImage, ReducedImage;
	CRect Rect1;
	char* typeName;

public:
	HTuple getModelID();
	char* getTypeName();
	
};
