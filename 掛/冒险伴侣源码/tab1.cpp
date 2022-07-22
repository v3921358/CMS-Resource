// tab1.cpp : implementation file
//

#include "stdafx.h"
#include "HOOK_WG.h"
#include "tab1.h"
#include "CRCBypass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// tab1 dialog

VOID SetInt(DWORD dwAddr, INT nValue)
{
	memcpy(&zyzfw, &nValue, 4);
	memcpy(&zgfwy, &nValue, 4);
}

PDWORD ia;


void smemcpy(void *dest, void *src, int len)
{
	ULONG d;
	
	if (VirtualProtect(dest, len, 0x40, &d)) {
		memcpy(dest, src, len);
	}
	return; 
}
ULONG *p;

tab1::tab1(CWnd* pParent /*=NULL*/)
	: CDialog(tab1::IDD, pParent)
{
	//{{AFX_DATA_INIT(tab1)
	m_edit1 = 10;
	m_edit2 = 1100;
	m_edit3 = 600;
	//}}AFX_DATA_INIT
}


void tab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(tab1)
	DDX_Control(pDX, IDC_CHECK45, m_check45);
	DDX_Control(pDX, IDC_CHECK44, m_check44);
	DDX_Control(pDX, IDC_CHECK43, m_check43);
	DDX_Control(pDX, IDC_CHECK42, m_check42);
	DDX_Control(pDX, IDC_CHECK41, m_check41);
	DDX_Control(pDX, IDC_CHECK40, m_check40);
	DDX_Control(pDX, IDC_CHECK39, m_check39);
	DDX_Control(pDX, IDC_CHECK38, m_check38);
	DDX_Control(pDX, IDC_CHECK37, m_check37);
	DDX_Control(pDX, IDC_CHECK36, m_check36);
	DDX_Control(pDX, IDC_CHECK35, m_check35);
	DDX_Control(pDX, IDC_CHECK34, m_check34);
	DDX_Control(pDX, IDC_CHECK33, m_check33);
	DDX_Control(pDX, IDC_CHECK32, m_check32);
	DDX_Control(pDX, IDC_CHECK9, m_check9);
	DDX_Control(pDX, IDC_CHECK8, m_check8);
	DDX_Control(pDX, IDC_CHECK7, m_check7);
	DDX_Control(pDX, IDC_CHECK6, m_check6);
	DDX_Control(pDX, IDC_CHECK5, m_check5);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK31, m_check31);
	DDX_Control(pDX, IDC_CHECK30, m_check30);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK29, m_check29);
	DDX_Control(pDX, IDC_CHECK28, m_check28);
	DDX_Control(pDX, IDC_CHECK27, m_check27);
	DDX_Control(pDX, IDC_CHECK26, m_check26);
	DDX_Control(pDX, IDC_CHECK25, m_check25);
	DDX_Control(pDX, IDC_CHECK24, m_check24);
	DDX_Control(pDX, IDC_CHECK23, m_check23);
	DDX_Control(pDX, IDC_CHECK22, m_check22);
	DDX_Control(pDX, IDC_CHECK21, m_check21);
	DDX_Control(pDX, IDC_CHECK20, m_check20);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK19, m_check19);
	DDX_Control(pDX, IDC_CHECK18, m_check18);
	DDX_Control(pDX, IDC_CHECK17, m_check17);
	DDX_Control(pDX, IDC_CHECK16, m_check16);
	DDX_Control(pDX, IDC_CHECK15, m_check15);
	DDX_Control(pDX, IDC_CHECK14, m_check14);
	DDX_Control(pDX, IDC_CHECK13, m_check13);
	DDX_Control(pDX, IDC_CHECK12, m_check12);
	DDX_Control(pDX, IDC_CHECK11, m_check11);
	DDX_Control(pDX, IDC_CHECK10, m_check10);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(tab1, CDialog)
	//{{AFX_MSG_MAP(tab1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck8)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck9)
	ON_BN_CLICKED(IDC_CHECK10, OnCheck10)
	ON_BN_CLICKED(IDC_CHECK11, OnCheck11)
	ON_BN_CLICKED(IDC_CHECK12, OnCheck12)
	ON_BN_CLICKED(IDC_CHECK13, OnCheck13)
	ON_BN_CLICKED(IDC_CHECK14, OnCheck14)
	ON_BN_CLICKED(IDC_CHECK15, OnCheck15)
	ON_BN_CLICKED(IDC_CHECK16, OnCheck16)
	ON_BN_CLICKED(IDC_CHECK17, OnCheck17)
	ON_BN_CLICKED(IDC_CHECK18, OnCheck18)
	ON_BN_CLICKED(IDC_CHECK19, OnCheck19)
	ON_BN_CLICKED(IDC_CHECK20, OnCheck20)
	ON_BN_CLICKED(IDC_CHECK21, OnCheck21)
	ON_BN_CLICKED(IDC_CHECK22, OnCheck22)
	ON_BN_CLICKED(IDC_CHECK23, OnCheck23)
	ON_BN_CLICKED(IDC_CHECK24, OnCheck24)
	ON_BN_CLICKED(IDC_CHECK25, OnCheck25)
	ON_BN_CLICKED(IDC_CHECK26, OnCheck26)
	ON_BN_CLICKED(IDC_CHECK27, OnCheck27)
	ON_BN_CLICKED(IDC_CHECK28, OnCheck28)
	ON_BN_CLICKED(IDC_CHECK29, OnCheck29)
	ON_BN_CLICKED(IDC_CHECK30, OnCheck30)
	ON_BN_CLICKED(IDC_CHECK31, OnCheck31)
	ON_BN_CLICKED(IDC_CHECK32, OnCheck32)
	ON_BN_CLICKED(IDC_CHECK33, OnCheck33)
	ON_BN_CLICKED(IDC_CHECK34, OnCheck34)
	ON_BN_CLICKED(IDC_CHECK35, OnCheck35)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CHECK36, OnCheck36)
	ON_BN_CLICKED(IDC_CHECK37, OnCheck37)
	ON_BN_CLICKED(IDC_CHECK38, OnCheck38)
	ON_BN_CLICKED(IDC_CHECK39, OnCheck39)
	ON_BN_CLICKED(IDC_CHECK40, OnCheck40)
	ON_BN_CLICKED(IDC_CHECK41, OnCheck41)
	ON_BN_CLICKED(IDC_CHECK42, OnCheck42)
	ON_BN_CLICKED(IDC_CHECK43, OnCheck43)
	ON_BN_CLICKED(IDC_CHECK44, OnCheck44)
	ON_BN_CLICKED(IDC_CHECK45, OnCheck45)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// tab1 message handlers
WNDPROC g_fnWndProc ;
LRESULT CALLBACK NewWndProc(          HWND hwnd,
							UINT uMsg,
							WPARAM wParam,
							LPARAM lParam
							);

BOOL tab1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	g_fnWndProc = (WNDPROC)SetWindowLong (this->m_hWnd, GWL_WNDPROC, (LONG)NewWndProc);  //注册热键
	
	if(!RegisterHotKey(this->m_hWnd,1,NULL,VK_F10))
	{
		MessageBox("热键F10注册失败","提示",0);
	}
	if(!RegisterHotKey(this->m_hWnd,2,NULL,VK_F8))
	{
		MessageBox("热键F8注册失败","提示",0);
	}
	if(!RegisterHotKey(this->m_hWnd,3,NULL,VK_F7))
	{
		MessageBox("热键F7注册失败","提示",0);
	}

	CreateThread(NULL,NULL,(LPTHREAD_START_ROUTINE)CRCBypass,NULL,NULL,NULL); //启动PASS CRC
   
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}




LRESULT CALLBACK NewWndProc(          HWND hwnd,
							UINT uMsg,
							WPARAM wParam,
							LPARAM lParam
							)
{
	if ( uMsg != WM_HOTKEY )
	{
		return CallWindowProc (g_fnWndProc, hwnd, uMsg, wParam, lParam);
	} 
	else
	{
		::SetForegroundWindow(hwnd);
		switch (wParam)
		{
		case 1:
			SendDlgItemMessage (hwnd, IDC_CHECK25, BM_CLICK, 0, 0);
			break;
		case 2:
			SendDlgItemMessage (hwnd, IDC_CHECK26, BM_CLICK, 0, 0);
			break;
		case 3:
			SendDlgItemMessage (hwnd, IDC_CHECK39, BM_CLICK, 0, 0);
			break;
			
		default:
			break;
		}
		HWND hMaple;
		hMaple = ::FindWindow(TEXT("MapleStoryClass"),TEXT("MapleStory"));
		
		::SetForegroundWindow(hMaple);
		return 0;
	}
}


int suoling=0;
int jiasu3=50;
int pdao[10] = {0};
int jixieshi=1932016;


DWORD GetChong()
{
	DWORD *BaseAddr = (DWORD *)rwjz;
	if(BaseAddr==NULL)return 0;
	BaseAddr=(DWORD *)BaseAddr[0];
	if(BaseAddr==NULL)return 0;
	BaseAddr = (DWORD *)BaseAddr[0x2c40];
	if(BaseAddr==NULL)return 0;
	BaseAddr = (DWORD *)BaseAddr[0x4];
	if(BaseAddr==NULL)return 0;
	BaseAddr = (DWORD *)BaseAddr[0x90];
	return BaseAddr[0x0194];
	
}

void tab1::OnTimer(UINT nIDEvent) 
{
	switch(nIDEvent)
	{
    case(1)://停止呼吸
		smemcpy(&p, (void *)(PWORD)rwjz, 4);
		smemcpy((UCHAR *)p + 0x0478, &suoling, 4);
		break;
	case(2)://无线挂花
		smemcpy(&p, (void *)(PWORD)rwjz, 4);
		smemcpy((UCHAR *)p + 0x00003af0, &suoling, 4);
		break;
	case(3)://超级捡物
		smemcpy(&p, (void *)0x00cbf3e0, 4);
		smemcpy((UCHAR *)p + 0x2098, &suoling, 4);
		break;
	case(4)://攻击加速
		smemcpy(&p, (void *)(PWORD)rwjz, 4);
		smemcpy((UCHAR *)p + 0x0480, &suoling, 4);
		break;
	case(6)://机械可移动
		smemcpy(&p, (void *)(PWORD)rwjz, 4);
		smemcpy((UCHAR *)p + 0x00003a14, &suoling, 4);
		break;
	case(8)://新宠物吸
		smemcpy(&p, (void *)(PWORD)rwjz, 4);
		if(p>0)
		{
		xunhuangongneng();
		}
		break;
	case(9):
		smemcpy(&p, (void *)(PWORD)rwjz, 4);
		if(p>0)
		{
		DUxy();
		ZDjianwu();
		}
		break;
	case(10):
		smemcpy(&p, (void *)(PWORD)rwjz, 4);
		if(p>0)
		{
			GetChong();
		}
		break;
	case(11)://机械师变身
		smemcpy(&p, (void *)(PWORD)rwjz, 4);
		smemcpy((UCHAR *)p + 0x00000434, &jixieshi, 4);
		break;
	case(12):
		xxxxkg=1;
		SetTimer(12,500,NULL);
		KillTimer(11);
		break;
	case(13):
		xxxxkg=1;
		SetTimer(11,500,NULL);
		KillTimer(12);
	case(111):
		//DLL检测
		if (NULL == ::OpenEvent(EVENT_ALL_ACCESS,FALSE, _T("11asdsadhhjuy44151---1000/2.5*2041-100+0.008")))
		{
			ExitThread(0);
		}
		break;

	default:			
	break;
	
	CDialog::OnTimer(nIDEvent);
}
}

void tab1::OnCheck1() 
{
	if (m_check1.GetCheck()==1)
	{
		Jump(wudi_add,wudi_Start,1);
	}
	else
	{
		BYTE wudi_end[6]={0x0f,0x85,0xfc,0x1e,0,0};
		memcpy((PWORD)wudi_add,&wudi_end,6);
	}
	
}


void tab1::OnCheck2() 
{
	if (m_check2.GetCheck()==1)
	{
		Jump(wudi58S_add,wudi58S_Start,2);
	}
	else
	{
		BYTE wudi58S_end[7]={0x33,0xD2,0xB9,0x64,0,0,0};
		memcpy((PWORD)wudi58S_add,&wudi58S_end,7);
	}
	
}

void tab1::OnCheck3() 
{
	int IsRectEmptyAddr = NULL;
	PWORD wlwd = (PWORD)0x00d0c6a4; 
	
	if(m_check3.GetCheck()==1)
	{
		DWORD ICS_wlwdaddr = (DWORD)ICS_wlwd;
		memcpy(wlwd,&ICS_wlwdaddr,4);
		
	}else
	{
		HMODULE API_MXD = ::GetModuleHandle("user32.dll");
		IsRectEmptyAddr = (DWORD)::GetProcAddress(API_MXD,"IsRectEmpty");
		memcpy(wlwd,&IsRectEmptyAddr,4);
		
	}
}

void tab1::OnCheck4() 
{
	if (m_check4.GetCheck()==1)
	{
		BYTE fengjie_Start[1]={0x75};
		memcpy((PWORD)fengjie_add,&fengjie_Start,1);
	}
	else
	{
		BYTE fengjie_end[1]={0x74};
		memcpy((PWORD)fengjie_add,&fengjie_end,1);
	}
	
}

void tab1::OnCheck5() 
{
	if (m_check5.GetCheck()==1)
	{
		Jump(benguai_add,gwbmg_Start,1);
	}
	else
	{
		BYTE gwbmg_end[6]={0x0F,0x85,0xdc,0,0,0};
		memcpy((PWORD)benguai_add,&gwbmg_end,6);
	}
	
}

void tab1::OnCheck6() 
{
	if (m_check6.GetCheck()==1)
	{
		Jump(benguai_add,cjbg_Start,1);
	}
	else
	{
		BYTE gwbmg_end[6]={0x0F,0x85,0xdc,0,0,0};
		memcpy((PWORD)benguai_add,&gwbmg_end,6);
	}
	
}

void tab1::OnCheck7() 
{
	if (m_check7.GetCheck()==1)
	{
		Jump(guaiwuJT_add,guaiwuJT_Start,0);
	}
	else
	{
		BYTE gwJT_end[5]={0xE8,0xca,0x4c,0xCb,0xFF};
		memcpy((PWORD)guaiwuJT_add,&gwJT_end,5);
	}
	
}

void tab1::OnCheck8() 
{
	if (m_check8.GetCheck()==1)
	{
		Jump(jf_add,jufeng,1);
		m_check12.EnableWindow(false);
	}
	else
	{
		BYTE jf_end[6]={0x8b,0x6c,0x24,0x60,0x6a,0x14};
		memcpy((PWORD)jf_add,&jf_end,6);
		m_check12.EnableWindow(true);

	}
	
}

void tab1::OnCheck9() 
{
	if (m_check9.GetCheck()==1)
	{
	Jump(dandansuxian_add,dandansuxian,2);
	}
	else
	{
		BYTE dandansuxian_end[7]={0x83,0xBE,0xfc,0x03,0,0,0};
		memcpy((PWORD)dandansuxian_add,&dandansuxian_end,7);
	}
	
}

void tab1::OnCheck10() 
{
	if (m_check10.GetCheck()==1)
	{
		sgcspdkg=0;
		Jump(sgxg_add,sgxg2,1);
		Jump(gwdz_add,gwdz,0);
		
	}
	else
	{
		sgcspdkg=1;
		Jump(sgxg_add,sgxgzctz2,1);
		BYTE gwdz_end[5]={0xE8,0x4E,0x60,0x36,0};
		memcpy((PWORD)gwdz_add,&gwdz_end,5);
	}
	
}

void tab1::OnCheck11() 
{
	if (m_check11.GetCheck()==1)
	{
//		Jump(qzyqpgj_add,qzyqpgj,1);
	//	Jump(gwdz_add,gwdz,0);
		
	}
	else
	{
//		BYTE qzyqpgj_end[6]={0x56,0x57,0x8B,0x7C,0x24,0x0C};
//		memcpy((PWORD)qzyqpgj_add,&qzyqpgj_end,6);
//	/	BYTE gwdz_end[5]={0xE8,0x4E,0x60,0x36,0};
//		memcpy((PWORD)gwdz_add,&gwdz_end,5);
	}
	
}

void tab1::OnCheck12() 
{
	if (m_check12.GetCheck()==1)
	{
		Jump(jf2_add,jufeng2,1);
		m_check8.EnableWindow(false);
		
	}
	else
	{
		BYTE jf_end2[6]={0x8b,0x90,0x34,0x10,0,0};
		memcpy((PWORD)jf2_add,&jf_end2,6);
		m_check8.EnableWindow(true);
	}
	
}

void tab1::OnCheck13() 
{
	if (m_check13.GetCheck()==1)
	{
		Jump(guaibuxianshang_add,guaibuxianshang,0);
	}
	else
	{
		BYTE guaibuxianshang_end[5]={0xE8,0x58,0xDA,0xFF,0xFF};
		memcpy((PWORD)guaibuxianshang_add,&guaibuxianshang_end,5);
	}
	
}

void tab1::OnCheck14() 
{
	if(m_check14.GetCheck()==1)
	{
		SetTimer(1,500,NULL);
	}else{
		KillTimer(1);
	}
}

void tab1::OnCheck15() 
{
	if(m_check15.GetCheck()==1)
	{
		SetTimer(2,500,NULL);
	}else{
		KillTimer(2);
	}
}

void tab1::OnCheck16() 
{
	if (m_check16.GetCheck()==1)
	{
		Jump(gjbt_add,CSX,0);
	}
	else
	{
		Jump(gjbt_add,CSXReturn,0);
	}
	
}

void tab1::OnCheck17() 
{
	if (m_check17.GetCheck()==1)
	{
		Jump(cl_add,chuli,0);
	}
	else
	{
		BYTE cl_end[5]={0x83,0xF8,0x1E,0x7E,0x08};
		memcpy((PWORD)cl_add,&cl_end,5);
	}
	
}

void tab1::OnCheck18() 
{
	if(m_check18.GetCheck()==1)
	{
		SetTimer(3,500,NULL);
	}else{
		KillTimer(3);
	}
}

void tab1::OnCheck19() 
{
	if (m_check19.GetCheck()==1)
	{
		Jump(wupinsuxian_add,wupinsuxian,3);
	}
	else
	{
		BYTE wupinsuxian_end[8]={0x83,0xC4,0x10,0xE9,0xee,0xba,0x5a,0};
		memcpy((PWORD)wupinsuxian_add,&wupinsuxian_end,8);
	}
	
}

void tab1::OnCheck20() 
{
	if (m_check20.GetCheck()==1)
	{
		Jump(zddx1_add,zddx1,1);
		Jump(zddx2_add,zddx2,0);
	}
	else
	{
		BYTE zddx1_end[6]={0x0f,0x84,0x73,0x02,0,0};
		memcpy((PWORD)zddx1_add,&zddx1_end,6);
		Sleep(100);
		BYTE zddx2_end[5]={0xe8,0xa7,0x04,0xdc,0xff};
		memcpy((PWORD)zddx2_add,&zddx2_end,5);
	}
	
}

void tab1::OnCheck21() 
{
	if (m_check21.GetCheck()==1)
	{
		Jump(gwbt_add,btgaaaa,0);
	}
	else
	{
		BYTE gwbt_end[5]={0xE8,0x80,0x24,0xFE,0xFF};
		memcpy((PWORD)gwbt_add,&gwbt_end,5);
	}
	
}

void tab1::OnCheck22() 
{
/*	if (m_check22.GetCheck()==1)
	{
		Jump(wupin_add,wplp,1);
		Jump(shubiaofei_add,cwsbf,0);
		sbfkg=0;
		cxkg=1;
		
	}
	else
	{
		BYTE wupin_end[6]={0x8B,0x46,0x04,0x8D,0x3C,0x90};
		memcpy((PWORD)wupin_add,&wupin_end,6);
		cxkg=0;
		BYTE shubiaofei_end[5]={0x89,0x07,0x8b,0x5d,0x14};
		memcpy((PWORD)shubiaofei_add,&shubiaofei_end,5);
	}
	*/
}

void tab1::OnCheck23() 
{
	if (m_check23.GetCheck()==1)
	{
		Jump(zsbqj_add,zsbqj,5);
		
	}
	else
	{
		BYTE zsbqj_end[10]={0xC7,0x86,0x78,0x3A,0,0,0x1,0,0,0};
		memcpy((PWORD)zsbqj_add,&zsbqj_end,10);
	}
	
}

void tab1::OnCheck24() 
{
	if (m_check24.GetCheck()==1)
	{
		Jump(BOSS_add,BOSS,1);
		
	}
	else
	{
		BYTE BOSS_end[6]={0x0f,0x87,0x96,0x04,0,0};
		memcpy((PWORD)BOSS_add,&BOSS_end,6);
	}
	
}

void tab1::OnCheck25() 
{
	if (m_check25.GetCheck()==1)
	{
		Jump(shubiao_add,cssbf,0);
		
	}
	else
	{
		BYTE shubiaofei_end[5]={0x89,0x07,0x8b,0x5d,0x14};
		memcpy((PWORD)shubiao_add,&shubiaofei_end,5);
	}
	
}

void tab1::OnCheck26() 
{
	if (m_check26.GetCheck()==1)
	{
		Jump(SSshubiao_add,ssbf,0);
	}
	else
	{
		BYTE SSshubiao_end[5]={0xe8,0xab,0xaa,0x0a,0};
		memcpy((PWORD)SSshubiao_add,&SSshubiao_end,5);
	}
	
}


void tab1::OnCheck27() 
{
		int IntersectRectAddr = NULL;
		PWORD qpgj = (PWORD)0x00d0c6a0;
		
		
		if(m_check27.GetCheck()==1)
		{
			
			Jump(lz_add,lz,0);
			Sleep(100);
			DWORD ICS_qpgjaddr = (DWORD)ICS_qpgj;
			memcpy(qpgj,&ICS_qpgjaddr,4);
			
		}else
		{
			
			BYTE lz_end[5]={0x5,0xe8,0x03,0,0};
			memcpy((PWORD)lz_add,&lz_end,5);
			Sleep(100);
			HMODULE API_MXD = ::GetModuleHandle("user32.dll");
			IntersectRectAddr = (DWORD)::GetProcAddress(API_MXD,"IntersectRect");
			memcpy(qpgj,&IntersectRectAddr,4);
			
			
		}
	}
//////////////////////////////////////////////////
void tab1::OnCheck28() 
{
	if (m_check28.GetCheck()==1)
	{
		Jump(wyc_add,jfwyc,0);
		
	}
	else
	{
		BYTE wwyc_end[5]={0xa1,0xc0,0x73,0xd0,0};
		memcpy((PWORD)wyc_add,&wwyc_end,5);
		
	}
	
}

void tab1::OnCheck29() 
{
	int GetFocusAddr = NULL;
	PWORD znzyz = (PWORD)0x00d0c6d8; 
	
	if(m_check29.GetCheck()==1)
	{
		SetTimer(2,500,NULL);
		DWORD my1=0;
		DWORD my2=0;
		DWORD my3=0;		
		DWORD gjcs=0x50;		//时间		
		DWORD kai=1;            //开关		
		DWORD fwei=0xa;         //范围
		
		
		memcpy(&zyzcspdkg,&my1,4);
		memcpy(&zyzpdfw,&my2,4);
		memcpy(&zyypdkg,&my3,4);
        memcpy(&zyzgjcs,&gjcs,4);	
		memcpy(&zyzkg,&kai,4);	
		memcpy(&zyzfw,&fwei,4);
		
		
		DWORD ICS_zngjbtaddr = (DWORD)ICS_zngjbt;
		memcpy(znzyz,&ICS_zngjbtaddr,4);

	m_check30.EnableWindow(false);
		
	}else
	{
		KillTimer(2);
		DWORD my1=0;
		DWORD my2=0;
		DWORD my3=0;
		memcpy(&zyzcspdkg,&my1,4);
		memcpy(&zyzpdfw,&my2,4);
		memcpy(&zyypdkg,&my3,4);
		HMODULE API_MXD = ::GetModuleHandle("user32.dll");
		GetFocusAddr = (DWORD)::GetProcAddress(API_MXD,"GetFocus");
		memcpy(znzyz,&GetFocusAddr,4);
		m_check30.EnableWindow(true);

	}
}

void tab1::OnCheck30() 
{
	
	int GetFocusAddr = NULL;
	PWORD znzyz = (PWORD)0x00d0c6d8; 
	
	if(m_check30.GetCheck()==1)
	{
		DWORD my1=0;
		DWORD my2=0;
		DWORD my3=0;		
		DWORD gjcs=0;  //时间		
		DWORD kai=1;           //开关		
		DWORD fwei=0;        //范围
		
		
		
		
		memcpy(&zyzcspdkg,&my1,4);
		memcpy(&zyzpdfw,&my2,4);
		memcpy(&zyypdkg,&my3,4);
        memcpy(&zyzgjcs,&gjcs,4);	
		memcpy(&zyzkg,&kai,4);	
		SetInt(zyzfw, GetDlgItemInt(IDC_EDIT1));
		
		
		DWORD ICS_zngjbtaddr = (DWORD)ICS_zngjbt;
		memcpy(znzyz,&ICS_zngjbtaddr,4);
		m_check29.EnableWindow(false);
		
	}else
	{
		DWORD my1=0;
		DWORD my2=0;
		DWORD my3=0;
		memcpy(&zyzcspdkg,&my1,4);
		memcpy(&zyzpdfw,&my2,4);
		memcpy(&zyypdkg,&my3,4);
		HMODULE API_MXD = ::GetModuleHandle("user32.dll");
		GetFocusAddr = (DWORD)::GetProcAddress(API_MXD,"GetFocus");
		memcpy(znzyz,&GetFocusAddr,4);
		m_check29.EnableWindow(true);
		
	}
}

void tab1::OnCheck31() 
{
	if(m_check31.GetCheck()==1)
	{
		SetTimer(4,m_edit2,NULL);
	}else{
		KillTimer(4);
	}
}

void tab1::OnCheck32() 
{
	if (m_check32.GetCheck()==1)
	{
		Jump(jxswyc_add,jxswyc,1);
	}
	else
	{
		BYTE jxswyc_end[6]={0x0f,0x8f,0x12,02,0,0};
		memcpy((PWORD)jxswyc_add,&jxswyc_end,6);
	}
	
}

void tab1::OnCheck33() 
{
	if (m_check33.GetCheck()==1)
	{
		Jump(xinqp_add,xinquanping,0);
	}
	else
	{
		BYTE xinqp_end[5]={0xe8,0x4e,0x60,0x36,0};
		memcpy((PWORD)xinqp_add,&xinqp_end,5);
	}
	
}


void tab1::OnCheck34() 
{
	if (m_check34.GetCheck()==1)
	{
		Jump(lz_add,lz,0);
		Jump(jxswyc_add,jxswyc,1);
		SetTimer(6,1000,NULL);
	}
	else
	{
		BYTE lz_end[5]={0x5,0xe8,0x03,0,0};
		memcpy((PWORD)lz_add,&lz_end,5);
		BYTE jxswyc_end[6]={0x0f,0x8f,0x12,02,0,0};
		memcpy((PWORD)jxswyc_add,&jxswyc_end,6);
		KillTimer(6);
	}
	
}

void tab1::OnCheck35() 
{
	if (m_check35.GetCheck()==1)
	{
		Jump(screen_add,screen,0);
		Jump(getxy_add,getxy,1);
	}
	else
	{
		BYTE screen_end[5]={0xe8,0x80,0xe2,0xf6,0xff};
		memcpy((PWORD)screen_add,&screen_end,5);
		BYTE getxy_end[6]={0x39,0xab,0x94,0x02,0,0};
		memcpy((PWORD)getxy_add,&getxy_end,6);
	}
	
}

HBRUSH tab1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)   //颜色
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(pWnd->GetDlgCtrlID()== IDC_CHECK2)
	{
		pDC->SetTextColor(RGB(244,0,0)); 
	}
	if(pWnd->GetDlgCtrlID()== IDC_CHECK5)
	{
		pDC->SetTextColor(RGB(244,0,0)); 
	}
	if(pWnd->GetDlgCtrlID()== IDC_CHECK16)
	{
		pDC->SetTextColor(RGB(244,0,0)); 
	}
	if(pWnd->GetDlgCtrlID()== IDC_CHECK39)
	{
		pDC->SetTextColor(RGB(244,0,0)); 
	}
	if(pWnd->GetDlgCtrlID()== IDC_CHECK20)
	{
		pDC->SetTextColor(RGB(244,0,0)); 
	}
	if(pWnd->GetDlgCtrlID()== IDC_CHECK41)
	{
		pDC->SetTextColor(RGB(244,0,0)); 
	}
	
	return hbr;
}

void tab1::OnCheck36() 
{
	if (m_check36.GetCheck()==1)
	{
		Jump(wyc_add,wyc,0);		
	}
	else
	{
		BYTE wwyc_end[5]={0xa1,0xc0,0x73,0xd0,0};
		memcpy((PWORD)wyc_add,&wwyc_end,5);
	}
	
}


void tab1::OnCheck37() //````````````````````````````````````````
{
	if (m_check37.GetCheck()==1)
	{
		Jump(zswyc_add,zswyc,0);		
	}
	else
	{
		BYTE zswyc_end[5]={0x8B,0x54,0x24,0x28,0x8B};
		memcpy((PWORD)zswyc_add,&zswyc_end,5);
	}
	
}

void tab1::OnCheck38() 
{
/*	if (m_check38.GetCheck()==1)
	{
		Jump(gwgs_add,gwgs,0);		
	}
	else
	{
		BYTE gwgs_end[5]={0xdc,0x6c,0x24,0x48,0x83};
		memcpy((PWORD)gwgs_add,&gwgs_end,5);
	}
*/	
}

void tab1::OnCheck39() 
{
	if (m_check39.GetCheck()==1)
	{
		SetInt(zgfwy, GetDlgItemInt(IDC_EDIT3));
		xgkg=1;
		Jump(xg_add,mynewxiguai,1);
		Jump(gwbt_add,btgaaaa,0);
		//SetTimer(13,500,NULL);
	}
	else
	{
		xgkg=0;
		BYTE xg_end[6]={0x39,0xab,0x94,0x02,0,0};
		memcpy((PWORD)xg_add,&xg_end,6);
		BYTE gwbt_end[5]={0xE8,0x80,0x24,0xFE,0xFF};
		memcpy((PWORD)gwbt_add,&gwbt_end,5);
	//	KillTimer(12);
	//	KillTimer(13);
	}
	
}


void tab1::OnCheck40() 
{
	if (m_check40.GetCheck()==1)
	{
		Jump(xinqp_add,xinquanping,0);
	}
	else
	{
		BYTE xinqp_end[5]={0xe8,0x4e,0x60,0x36,0};
		memcpy((PWORD)xinqp_add,&xinqp_end,5);
	}
	
}

void tab1::OnCheck41() 
{
	if (m_check41.GetCheck()==1)
	{
		Jump(chongxi_add,chongxi,1);
		SetTimer(8,300,NULL);
	}
	else
	{
		Jump(chongxi_add,chongxi_end,1);
		KillTimer(8);
	}
	
}
void tab1::OnCheck42() 
{
/*	if (m_check42.GetCheck()==1)
	{
		Jump(gljinbi_add,gljinbi,1);
	}
	else
	{
		BYTE gljinbi_end[6]={0x89,0x46,0x14,0x89,0x57,0x30};
		memcpy((PWORD)gljinbi_add,&gljinbi_end,6);
	}
*/	
}

void tab1::OnCheck43() 
{
	if (m_check43.GetCheck()==1)
	{
		SetTimer(9,300,NULL);
	}
	else
	{
		KillTimer(9);
	}
	
}

void tab1::OnCheck44() 
{


	if(m_check44.GetCheck()==1)
	{
		SetTimer(10,300,NULL);
	
		
	}else
	{
		KillTimer(10);
	}
}

void tab1::OnCheck45() 
{
	if (m_check45.GetCheck()==1)
	{
		SetTimer(11,500,NULL);
	}else{
		KillTimer(11);
	}
	
}
