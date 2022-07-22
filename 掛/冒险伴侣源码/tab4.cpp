// tab4.cpp : implementation file
//

#include "stdafx.h"
#include "HOOK_WG.h"
#include "tab4.h"
#include "SESDK.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int i[50];
bool b=true;//Time1 
bool z=true; 
/////////////////////////////////////////////////////////////////////////////
// tab4 dialog


tab4::tab4(CWnd* pParent /*=NULL*/)
	: CDialog(tab4::IDD, pParent)
{
	//{{AFX_DATA_INIT(tab4)
	m_edit1 = 50;
	m_edit2 = 70;
	m_edit3 = 90;
	//}}AFX_DATA_INIT
}


void tab4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(tab4)
	DDX_Control(pDX, IDC_CHECK9, m_check9);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_CHECK8, m_check8);
	DDX_Control(pDX, IDC_EDIT5, m_edit5);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_CHECK6, m_check6);
	DDX_Control(pDX, IDC_CHECK5, m_check5);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(tab4, CDialog)
	//{{AFX_MSG_MAP(tab4)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck8)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck9)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()




/////////////////////////////////////////////////////////////////////////////
// tab4 message handlers

int jt=0;
void sdmemcpy(void *dest, void *src, int len)
{
	ULONG d;
	
	if (VirtualProtect(dest, len, 0x40, &d)) {
		memcpy(dest, src, len);
	}
	return; 
}
ULONG *ja;
ULONG *jb;
ULONG *jc;
ULONG *jd;
ULONG *je;

DWORD rwADD2=0x00d06d44;
DWORD login=0x00d097a8;
DWORD loginint2=0x00d097bc;
DWORD loginint3=0x00d097c0;
DWORD loginint4=0x00d097cc;
HWND hWindow;

void send_key(UINT key)
{
	hWindow = FindWindow("MapleStoryClass", "MapleStory");
	PostMessage(hWindow, 0x100, 0, MapVirtualKey(key, 0) << 16);
	PostMessage(hWindow, 0x101, 0, MapVirtualKey(key, 0) << 16);
}

DWORD key_call=0x009bea30;
void KeyCall(UINT uKeyCodes)
{
	int nVirtualKeyCodes;
	nVirtualKeyCodes = MapVirtualKey(uKeyCodes,0);
	nVirtualKeyCodes = 1 | (nVirtualKeyCodes<<16);
	SE_PROTECT_START();
	_asm
	{
			pushad
			mov ecx,[rwADD2]
			mov ecx,[ecx]
			push nVirtualKeyCodes//键虚拟码
			push uKeyCodes       //键的代码
			call key_call
			popad
	}
	SE_PROTECT_END();
}





void Cn_Login(char* pUser,char* pPassWord)
{
	SE_PROTECT_START();
	__asm
	{
		pushad;
		mov ecx,0x00d097a8;
		mov ecx,dword ptr[ecx];
		mov ecx,dword ptr[ecx + 0xf0];
		push pPassWord;
		push pUser;
		mov eax,0x0060d560;
		call eax;
		popad;
	}
	SE_PROTECT_END();
}

void Cn_SelectService(int iService)
{
	SE_PROTECT_START();
	__asm
	{
		pushad;
		mov esi,0x00d097bc;
		mov esi,dword ptr[esi];
		mov ecx,[esi+0x94];
		mov eax,iService;
		mov [esi+0x1d8],eax;
		push iService; 
		mov eax, 0x00605cc0;
		call eax;
		popad;
	}
	SE_PROTECT_END();
}

void Cn_SelectChannel(int iChannel)
{
	SE_PROTECT_START();
	__asm
	{
		pushad;
		mov esi,0x00d097c0;
		mov esi,dword ptr[esi];
		mov ecx,esi;
		mov eax,iChannel;
		push eax;
		mov eax, 0x0062d760;
		call eax;
		popad;
	}
	SE_PROTECT_END();
}

DWORD mxd_start_call=0x00611330;
void Cn_Start()
{
	SE_PROTECT_START();
	__asm
	{
		pushad;
		mov esi,0x00d097cc;
		mov esi,dword ptr[esi];
		cmp esi,0;
		je ret2;
		mov ecx,esi;
		mov eax,1000;
		push eax;
		call mxd_start_call;
		ret2:
		popad;
	}
	SE_PROTECT_END();
}

BOOL tab4::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_edit4.SetWindowText("游戏账号");
	m_edit5.SetWindowText("游戏密码");


	m_combo2.InsertString(0,_T("1线"));
	m_combo2.InsertString(1,_T("2线"));
	m_combo2.InsertString(2,_T("3线"));
	m_combo2.InsertString(3,_T("4线"));
	m_combo2.InsertString(4,_T("5线"));
	m_combo2.InsertString(5,_T("6线"));
	m_combo2.InsertString(6,_T("7线"));
	m_combo2.InsertString(7,_T("8线"));
	m_combo2.InsertString(8,_T("9线"));
	m_combo2.InsertString(9,_T("10线"));
	
	
	m_combo2.SetCurSel(0);




//	CheckDlgButton(IDC_RADIO1, BST_CHECKED);
	CheckDlgButton(IDC_RADIO6, BST_CHECKED);



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void tab4::OnTimer(UINT nIDEvent) 
{
	switch(nIDEvent)
	{
	case(1):
	{
		sdmemcpy(&ja, (void *)(PWORD)rwADD2, 4);
		if(ja>0)
			{
			
			if (BST_CHECKED == IsDlgButtonChecked(IDC_RADIO6) )
			{
				KeyCall('A');
			}
			else if(BST_CHECKED == IsDlgButtonChecked( IDC_RADIO7))
			{
				send_key('A');
		   }
		}
		  break;
	}
	case(2):
	{
		sdmemcpy(&ja, (void *)(PWORD)rwADD2, 4);
		if(ja>0)
			{
		if (i[1]==i[2])
		{
			i[2]=i[2]+1;
		}
		if (i[1]==i[3])
		{
			i[3]=i[3]+1;
		}
		if (i[2]==i[3])
		{
			i[3]=i[3]+1;
		}
		if (i[1]!=0)
		{
			i[1]=i[1]-1;
		}else
		{

		  KillTimer(1);b=false;
		  KeyCall('X');
		  i[1]=m_edit1/2;
		}

		if (i[2]!=0)
		{
			i[2]=i[2]-1;
			}else
			{
				KillTimer(1);b=false;
				KeyCall('C');
				i[2]=m_edit2/2;
		}
			if (i[3]!=0)
			{
				i[3]=i[3]-1;
			}else
			{
				KillTimer(1);b=false;
				KeyCall('V');
				i[3]=m_edit3/2;
			}
		}
			break;
	}
	case(3):
	{
		sdmemcpy(&ja, (void *)(PWORD)rwADD2, 4);
		if(ja>0)
			{
		if (i[3]!=0)
		{
			if(b==false)
			{
				SetTimer(1,130,NULL);
				b=true;
			}
		}
		else
		{
			KillTimer(1);
			b=false;
		}
		if (i[2]!=0)
		{
			if(b==false)
			{
				SetTimer(1,130,NULL);
				b=true;
			}
		}
		else
		{
			KillTimer(1);
			b=false;
		}
		if (i[1]!=0)
		{
			if(b==false)
			{
				SetTimer(1,130,NULL);
				b=true;
			}
		}
		else
		{
			KillTimer(1);
			b=false;
		}

		}
		break;

	}
	case(4):
		{
			sdmemcpy(&ja, (void *)(PWORD)rwADD2, 4);
			if(ja<=0)
			{
				MessageBeep(0);
			}
			break;
		}
	case(5):
		{
			if(*((DWORD*)(((char *)((DWORD *)(*(DWORD*)0x00d02840)))+0x00003e9c))>0)
			{
				MessageBeep(0);
			}
			break;
		}
	case(6):
		{
			sdmemcpy(&ja, (void *)(PWORD)rwADD2, 4);
			if(ja<=0)
			{
				system("shutdown -s -t 1");
			}
			break;
		}
	case(7):
		{
			if(*((DWORD*)(((char *)((DWORD *)(*(DWORD*)0x00d02840)))+0x00003e9c))>0)
			{
				system("shutdown -s -t 1");

			}
			break;
		}
	case(8):
		{
			if(*((DWORD*)(((char *)((DWORD *)(*(DWORD*)0x00d02840)))+0x00003e9c))>0)
			{
				system("shutdown -s -t 1");
				
			}
			break;
		}
	case(10):
		{
			sdmemcpy(&ja, (void *)(PWORD)rwADD2, 4);
			sdmemcpy(&jb, (void *)(PWORD)login, 4);
			sdmemcpy(&jc, (void *)(PWORD)loginint2, 4);
			sdmemcpy(&jd, (void *)(PWORD)loginint3, 4);
			sdmemcpy(&je, (void *)(PWORD)loginint4, 4);
	

			if(ja==0 &&jb!=0)
			{	
				UpdateData(true);
				CString User;
				m_edit4.GetWindowText(User);
				char *zhanghao = User.GetBuffer(User.GetLength() + 1);
				UpdateData(true);
				CString PassWord;
				m_edit5.GetWindowText(PassWord);
				char *mima = PassWord.GetBuffer(PassWord.GetLength() + 1);
				Cn_Login(zhanghao,mima);

			}

		   if(ja==0 &&jb==0&&jc!=0)
		   {
				UpdateData(true);
				CString Service;
				CString ServiceI;
				m_combo1.GetWindowText(ServiceI);
				int xService=m_combo1.FindStringExact(-1,_T(ServiceI));
				Service.Format(_T("%d"),xService);
				int fuwuqi=atoi(Service);
				Cn_SelectService(fuwuqi);
		   }

		   if(ja==0 &&jb==0)
		   {
			   SetTimer(11,1000,NULL);
			   KillTimer(12);

		   }
			break;
		}
		case(11):
			{
				sdmemcpy(&ja, (void *)(PWORD)rwADD2, 4);
				sdmemcpy(&jb, (void *)(PWORD)login, 4);
				if(ja==0 &&jb==0)
				{
					UpdateData(true);
					CString Channel;
					CString ChannelI;
					m_combo2.GetWindowText(ChannelI);
					int xChannel=m_combo2.FindStringExact(-1,_T(ChannelI));
					Channel.Format(_T("%d"),xChannel);
					int pindao=atoi(Channel);
					Cn_SelectChannel(pindao);

					SetTimer(12,1000,NULL);
					KillTimer(11);
				}
			
				break;
			}
		case(12):
			{
				sdmemcpy(&ja, (void *)(PWORD)rwADD2, 4);
				sdmemcpy(&jb, (void *)(PWORD)login, 4);
				sdmemcpy(&jc, (void *)(PWORD)loginint2, 4);
				sdmemcpy(&jd, (void *)(PWORD)loginint3, 4);
				sdmemcpy(&je, (void *)(PWORD)loginint4, 4);
				if(ja==0 &&jb==0&&jc==0&&jd!=0&&je!=0)
				{
					SetTimer(10,2000,NULL);
					KillTimer(12);
				}else
				{
					if(ja==0 &&jb==0&&jc==0&&jd==0&&je!=0)
					{
						Cn_Start();
					}
					
				}
				if(ja==0 &&jb==0&&jc==0&&jd!=0&&je!=0)
				{
					KillTimer(12);
				}
				break;
			}
		default:
		break;

		}

		CDialog::OnTimer(nIDEvent);
}



void tab4::OnCheck1() 
{
	if(m_check1.GetCheck()==1)
	{
		UpdateData();
		i[1] = m_edit1;
		i[2] = m_edit2;
		i[3] = m_edit3;
		SetTimer(3,5,NULL);
		SetTimer(2,1000,NULL);
		SetTimer(1,130,NULL);
		b=true;
	}else{
		KillTimer(3);
		KillTimer(2);
		KillTimer(1);
	}
}

void tab4::OnCheck2() 
{
	if(m_check2.GetCheck()==1)
	{
		SetTimer(4,500,NULL);
	}else{
		KillTimer(4);
	}
}

void tab4::OnCheck3() 
{
	if(m_check3.GetCheck()==1)
	{
		SetTimer(5,500,NULL);
	}else{
		KillTimer(5);
	}
}
void tab4::OnCheck4() 
{
	if(m_check4.GetCheck()==1)
	{
		SetTimer(6,500,NULL);
	}else{
		KillTimer(6);
	}
}

void tab4::OnCheck5() 
{
	if(m_check5.GetCheck()==1)
	{
		SetTimer(7,500,NULL);
	}else{
		KillTimer(7);
	}
}

void tab4::OnCheck6() 
{
	if(m_check6.GetCheck()==1)
	{
		SetTimer(8,500,NULL);
	}else{
		KillTimer(8);
	}
}

void tab4::OnCheck8() 
{
	if(m_check8.GetCheck()==1)
	{
		SetTimer(10,10000,NULL);
	}else{
		KillTimer(10);
	}


	

}

void tab4::OnButton1() 
{
	if (BST_CHECKED == IsDlgButtonChecked(IDC_RADIO1) )
	{
		
		m_combo1.ResetContent();
		
		m_combo1.InsertString(0,_T("蓝蜗牛"));
		m_combo1.InsertString(1,_T("蘑菇仔"));
		m_combo1.InsertString(2,_T("绿水灵"));
		m_combo1.InsertString(3,_T("漂漂猪"));
		m_combo1.InsertString(4,_T("小青蛇"));
		m_combo1.InsertString(5,_T("红螃蟹"));
		m_combo1.InsertString(6,_T("大海龟"));
		m_combo1.InsertString(7,_T("章鱼怪"));
		m_combo1.InsertString(8,_T("顽皮猴"));
		m_combo1.InsertString(9,_T("星精灵"));
		m_combo1.InsertString(10,_T("胖企鹅"));
		m_combo1.InsertString(11,_T("白雪人"));
		m_combo1.InsertString(12,_T("石头人"));
		m_combo1.InsertString(13,_T("紫色猫"));
		m_combo1.InsertString(14,_T("大灰狼"));
		m_combo1.InsertString(15,_T("小白兔"));
		m_combo1.InsertString(16,_T("喷火龙"));
		m_combo1.InsertString(17,_T("火野猪"));
		m_combo1.InsertString(18,_T("青鳄鱼"));
		m_combo1.InsertString(19,_T("花蘑菇"));
		
		m_combo1.SetCurSel(0);
		
		
		   }


				if (BST_CHECKED == IsDlgButtonChecked(IDC_RADIO2) )
				{
					
					m_combo1.ResetContent();
					
					m_combo1.InsertString(0,_T("祖母绿"));
					m_combo1.InsertString(1,_T("黑水晶"));
					m_combo1.InsertString(2,_T("水晶钻"));
					m_combo1.InsertString(3,_T("黄水晶"));
					m_combo1.InsertString(4,_T("蓝水晶"));
					m_combo1.InsertString(5,_T("紫水晶"));
					m_combo1.InsertString(6,_T("海蓝石"));
					m_combo1.InsertString(7,_T("蛋白石"));
					m_combo1.InsertString(8,_T("石榴石"));
					m_combo1.InsertString(9,_T("月石"));
					m_combo1.InsertString(10,_T("星石"));
					m_combo1.InsertString(11,_T("黄金矿"));
					m_combo1.InsertString(12,_T("黑珍珠"));
					m_combo1.InsertString(13,_T("猫眼石"));
					
					m_combo1.SetCurSel(0);
					
					
				}
				if (BST_CHECKED == IsDlgButtonChecked(IDC_RADIO3) )
				{
					
					m_combo1.ResetContent();
					
					m_combo1.InsertString(0,_T("玛丽亚"));
					m_combo1.InsertString(1,_T("阿勒斯"));
					m_combo1.InsertString(2,_T("薇薇安"));
					m_combo1.InsertString(3,_T("月妙"));
					
					m_combo1.SetCurSel(0);
					
					
				}
				if (BST_CHECKED == IsDlgButtonChecked(IDC_RADIO4) )
				{
					
					m_combo1.ResetContent();
					
					m_combo1.InsertString(0,_T("七星剑"));	
					
					m_combo1.SetCurSel(0);
					
					
				}
				if (BST_CHECKED == IsDlgButtonChecked(IDC_RADIO5) )
				{
					
					m_combo1.ResetContent();
					
					m_combo1.InsertString(0,_T("明珠港"));
					m_combo1.InsertString(1,_T("童话村"));
					m_combo1.InsertString(2,_T("玩具城"));
					m_combo1.InsertString(3,_T("里恩"));
					m_combo1.InsertString(4,_T("飞花院"));
					m_combo1.InsertString(5,_T("埃德尔"));
					m_combo1.InsertString(6,_T("斯坦"));
					
					
					m_combo1.SetCurSel(0);
					
					
				} 
	
}


void tab4::OnCheck9() 
{


}
