#pragma once


// CTemplateParams 对话框

class CTemplateParams : public CDialogEx
{
	DECLARE_DYNAMIC(CTemplateParams)

public:
	CTemplateParams(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTemplateParams();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEW_TEMP_PARAMS};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString angleStart;
	afx_msg void OnEnChangeEdit4();
	CString angleExtent;
	CString metric;
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedOk();
	CString typeName;
};
