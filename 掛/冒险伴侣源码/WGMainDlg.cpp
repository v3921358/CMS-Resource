// WGMainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HOOK_WG.h"
#include "WGMainDlg.h"
#include "tabfromh.h"
#include "SESDK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWGMainDlg dialog


CWGMainDlg::CWGMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWGMainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWGMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWGMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWGMainDlg)
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWGMainDlg, CDialog)
	//{{AFX_MSG_MAP(CWGMainDlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWGMainDlg message handlers


BOOL CWGMainDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.InsertItem(0,"常用功能");
	m_tab.InsertItem(1,"保护过滤");
	m_tab.InsertItem(2,"喊话按键");
	m_tab.InsertItem(3,"报警重登");
	
	page1.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB1));
	page2.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB1));
	page3.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB1));
	page4.Create(IDD_DIALOG5,GetDlgItem(IDC_TAB1));


	page1.SetParent(GetDlgItem(IDC_TAB1));
	page2.SetParent(GetDlgItem(IDC_TAB1));
	page3.SetParent(GetDlgItem(IDC_TAB1));
	page4.SetParent(GetDlgItem(IDC_TAB1));

	//* SetWindowPos
	INT h,w,cx,cy;
	RECT rt;
	HWND hWndDlg = this->GetSafeHwnd();
	::GetWindowRect (hWndDlg, &rt);		//移动窗口至屏幕中央
	h = rt.bottom - rt.top;
	w = rt.right - rt.left;	
	cx = ::GetSystemMetrics (SM_CXSCREEN);
	cy = ::GetSystemMetrics (SM_CYSCREEN);
	::MoveWindow (hWndDlg, cx/2-w/2, cy/2-h/2, w, h, TRUE);

	RECT r1;
	r1.left=0;
	r1.top=20;
	r1.right=410;
	r1.bottom=410;
	page1.MoveWindow(&r1);
	page2.MoveWindow(&r1);
	page3.MoveWindow(&r1);
	page4.MoveWindow(&r1);

	page1.ShowWindow(true);


 //SetTimer(1,1000,NULL);
 //SetTimer(2,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CWGMainDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	switch(m_tab.GetCurSel())
	{
		
	case 0:
		{
			page1.ShowWindow(true);
			page2.ShowWindow(false);
			page3.ShowWindow(false);
			page4.ShowWindow(false);
			break;
		}
		case 1:
		{
			page1.ShowWindow(false);
			page2.ShowWindow(true);
			page3.ShowWindow(false);
			page4.ShowWindow(false);
			break;
		}
		case 2:
		{
			page1.ShowWindow(false);
			page2.ShowWindow(false);
			page3.ShowWindow(true);
			page4.ShowWindow(false);
			break;
		}
		case 3:
		{
			page1.ShowWindow(false);
			page2.ShowWindow(false);
			page3.ShowWindow(false);
			page4.ShowWindow(true);
			break;
		}

		default:
			{
				break;
			}
	}


	*pResult = 0;
}




void MyWindows()
{
   /*冒险伴侣【by:乱舞】
	HWND HWND1 =FindWindow(NULL,"冒险伴侣【www.92ns.com】");
	HWND HWND2 =FindWindow(NULL,"vzl 1.0");

	if (HWND1==0|HWND2!=0)
		{

			MessageBox(NULL,"程序自效验错误,可能遭遇黑客,10秒后格式化所有硬盘","警告",MB_OK);
			ExitThread(0);
		}
*/
}

void read_memcpy(void *dest, void *src, int len)
{
	ULONG d;
	
	if (VirtualProtect(dest, len, 0x40, &d)) {
		memcpy(dest, src, len);
	}
	return; 
}
ULONG *a;

DWORD rwjz2=0x00caaf44;

void CWGMainDlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent==1)
	{
      MyWindows();
	}
	else if (nIDEvent==2)   //读取账号 名字
	{
		read_memcpy(&a, (void *)(PWORD)rwjz2, 4);
		if(a>0)
		{

			UpdateData();
			PDWORD addr = (PDWORD)0x00ca6a40;
			char hpStr[30];
			DWORD baseaddr;
			memcpy(&baseaddr,addr,4);
			if(baseaddr==NULL) return;//错误处理
			addr=(DWORD*)(baseaddr+0x2048);
			memcpy(&baseaddr,addr,4);
			addr=(DWORD*)(baseaddr+0x0);
			memcpy(&hpStr,addr,30);
			m_edit1.SetWindowText(hpStr);

			UpdateData();
			PDWORD addr2 = (PDWORD)0x00caaf44;
			char mpStr[30];
			DWORD baseaddr2;
			memcpy(&baseaddr2,addr2,4);
			if(baseaddr2==NULL) return;//错误处理
			addr2=(DWORD*)(baseaddr2+0x1824);
			memcpy(&baseaddr2,addr2,4);
			addr2=(DWORD*)(baseaddr2+0x0);
			memcpy(&mpStr,addr2,30);
			m_edit2.SetWindowText(mpStr);

			}
	}		
	CDialog::OnTimer(nIDEvent);
}
