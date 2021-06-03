#pragma once
#include "HalconCpp.h"
#include "FindNCCParams.h"
using namespace HalconCpp;

// CClassDLg 对话框

class CClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CClassDlg)

public:
	CClassDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CClassDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLASSDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();

protected:
	HObject Image, GrayImage;
	HTuple Row, Column, Angle, Score, Model, modelIds, types;
	

public:
	void setModelIds(HTuple modelIds);
	void setTypes(HTuple typess);

};
