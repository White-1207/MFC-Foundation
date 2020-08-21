
// SampleDialogDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SampleDialog.h"
#include "SampleDialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSampleDialogDlg 对话框



CSampleDialogDlg::CSampleDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SAMPLEDIALOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSampleDialogDlg::DoDataExchange(CDataExchange* pDX)  
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_butButton1);  //---JP--DDX_Control宏指定了ID为IDC_BUTTON1的控件与类成员变量m_butButton1之间
											//---JP--的映射关系
}

BEGIN_MESSAGE_MAP(CSampleDialogDlg, CDialogEx)	//---JP--BEGIN_MESSAGE_MAP的第一个参数为此类，第二个参数为此类的父类
											//---JP--在BEGIN_MESSAGE_MAP与END_MESSAGE_MAP之间添加消息与消息响应函数
											//---JP--之间的映射关系

	ON_WM_PAINT()								//---JP--ON_WM_PAINT是响应WM_PAINT消息的宏，默认消息响应函数为OnPaint函数
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSampleDialogDlg::OnClickedButton1)  //---JP--此处将ID为IDC_BUTTON1的控件的单击消息与OnClickedButton1函数绑定
															  //---JP--BN_CLICKED会有操作系统发送给Dialog窗口，由窗口的消息处理函数OnClickedButton1进行处理
END_MESSAGE_MAP()


// CSampleDialogDlg 消息处理程序

BOOL CSampleDialogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSampleDialogDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSampleDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSampleDialogDlg::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	SendMessage(WM_CLOSE, 0, 0);
}
