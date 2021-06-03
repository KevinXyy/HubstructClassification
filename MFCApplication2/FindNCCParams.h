#pragma once


// CFindNCCParams 对话框

class CFindNCCParams : public CDialogEx
{
	DECLARE_DYNAMIC(CFindNCCParams)

public:
	CFindNCCParams(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CFindNCCParams();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIND_NCC_PARAMS};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	CFont m_font;
	

	DECLARE_MESSAGE_MAP()
public:
	
	CString angleStart;
	CString angleExtent;
	CString minScore;
	CString maxOverlap;
	
	afx_msg void OnBnClickedOk();
};
