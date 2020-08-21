
// SampleDialogDlg.h: 头文件
//

#pragma once


// CSampleDialogDlg 对话框
class CSampleDialogDlg : public CDialogEx
{
// 构造
public:
	CSampleDialogDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
//#ifdef AFX_DESIGN_TIME                     //--JP---这个宏我一般会删除掉，因为有些时候要通过IDD引用IDD_SAMPLEDIALOG_DIALOG
										//---JP--时，由于#ifdefine存在导致失败
	enum { IDD = IDD_SAMPLEDIALOG_DIALOG }; //---JP--指定了CSampleDialog类与ID为IDD_SAMPLEDIALOG_DIALOG绑定
//#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持 //---JP--在此函数的.cpp实现里将类成员变量与Dialog资源中的控件绑定


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();				//---JP--在Dialog所有的资源加载完毕后，即将要显示的时候，所做的工作在此函数里实现
	afx_msg void OnPaint();					//---JP--响应WM_PAINT消息的消息响应函数
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()						//---JP--如果要映射消息与消息响应函数的话，需要在类体里添加这个宏
public:
	CButton m_butButton1;
	afx_msg void OnClickedButton1();
};
