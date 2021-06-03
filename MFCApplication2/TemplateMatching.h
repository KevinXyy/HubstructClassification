#pragma once
#include "ClassDlg.h"

// TemplateMatching 对话框

class TemplateMatching : public CDialogEx
{
	DECLARE_DYNAMIC(TemplateMatching)

public:
	TemplateMatching(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TemplateMatching();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEMP_MATCH_DLG};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	int numOfTypes = 0;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	HTuple modelIds, types;
};
