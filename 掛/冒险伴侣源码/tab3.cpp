// tab3.cpp : implementation file
//

#include "stdafx.h"
#include "HOOK_WG.h"
#include "tab3.h"
#include "SESDK.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int nTimes[255] = {0};
int nTimesCount = 0;
CString csPath;
#include <shlwapi.h>
#include "ini\H_IniFile.h"
#pragma comment(lib, "shlwapi.lib")
int j[255] = {0};
bool c=true;
/////////////////////////////////////////////////////////////////////////////
// tab3 dialog
int s=0;
DWORD MyKey=0;

tab3::tab3(CWnd* pParent /*=NULL*/)
	: CDialog(tab3::IDD, pParent)
{
	//{{AFX_DATA_INIT(tab3)
	m_msg1 = _T("此线有人.来人请让让!");
	m_edit2 = 1000;
	m_msg2 = _T("");
	m_msg3 = _T("");
	m_msg4 = _T("");
	m_edit_key_s = _T("");
	m_edit_key_ms = _T("");
	//}}AFX_DATA_INIT
}

LPARAM GetKeylParam(UINT uKey, UINT uFlag);
VOID VirtualPressKey (UINT uKey);

void sememcpy(void *dest, void *src, int len)
{
	ULONG d;
	
	if (VirtualProtect(dest, len, 0x40, &d)) {
		memcpy(dest, src, len);
	}
	return; 
}
ULONG *jz;


void tab3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(tab3)
	DDX_Control(pDX, IDC_COMBO1, m_combo_key);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_LIST3, m_list_key);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Text(pDX, IDC_EDIT1, m_msg1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT4, m_msg2);
	DDX_Text(pDX, IDC_EDIT5, m_msg3);
	DDX_Text(pDX, IDC_EDIT6, m_msg4);
	DDX_Text(pDX, IDC_EDIT3, m_edit_key_s);
	DDX_Text(pDX, IDC_EDIT7, m_edit_key_ms);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(tab3, CDialog)
	//{{AFX_MSG_MAP(tab3)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton_del)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton_clear)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton_save)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton_load)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// tab3 message handlers



void GetDllPath2(TCHAR *pszBuf, INT nSize)
{
	TCHAR szDllPath[MAX_PATH] = {0};
	HMODULE hDll = GetModuleHandle(_T("Partner.dll"));
	GetModuleFileName(hDll, szDllPath, MAX_PATH);
	PathRemoveFileSpec(szDllPath);
	if ( lstrlen(szDllPath) <= nSize )
	{
		lstrcpy(pszBuf, szDllPath);
	}
}

LPARAM GetKeylParam2(UINT uKey, UINT uFlag)
{
	INT nFirstbyte, nScanCode, nThirdbyte;
	LPARAM lParam;
	if ( WM_KEYDOWN == uFlag )
	{
		nFirstbyte = 0;
	} 
	else
	{
		nFirstbyte = 192;
	}
	nScanCode = MapVirtualKey (uKey, 0);
	
	nThirdbyte = 1;
	lParam = nFirstbyte;
	nScanCode <<=16;
	lParam |= nScanCode;
	nThirdbyte <<= 24;
	lParam |= nThirdbyte;
	return lParam;
}


VOID VirtualPressKey (UINT uKey)
{
	HWND hWndMp = FindWindow(_T("MapleStoryClass"), _T("MapleStory"));
	if ( !hWndMp )
	{
		MessageBox(NULL, _T("取窗口句柄失败"), _T("调试"), MB_OK);
	}
	PostMessage(hWndMp, WM_KEYDOWN, uKey, GetKeylParam2(uKey, WM_KEYDOWN));
}



DWORD rwADD=0x00d06d44;

__declspec(naked) void sd_msg(DWORD ll)
{
	SE_PROTECT_START();
	__asm
	{
			push ebp
			mov ebp,esp
			sub esp,0x08
			mov eax,0x00D01A84
			push ebx
			mov dword ptr[ebp-0x08],eax
			push esi
			mov dword ptr[eax],0x00D01A98
			mov eax,[ebp+0x08]
			push edi
			mov dword ptr[ebp-0x04],0x00545df0
			_emit 0x89
			_emit 0x05
			_emit 0x94
			_emit 0x1a
			_emit 0xd0
			_emit 0x00
			pushad
			mov edi,0x00000000
			mov ebx,0x00000000
			mov eax,[ebp-0x08]
			push ebx
			mov dword ptr[ebp+0x08],eax
			push eax
			call dword ptr [ebp-0x04]
			popad
			pop edi
			pop esi
			pop ebx
			mov esp,ebp
			pop ebp
			ret
	}
	SE_PROTECT_END();
}

DWORD SendKeyCall=0x009bea30;

void CallSendKey(int nSendKey)
{
		int nKey = (MapVirtualKey(nSendKey,0)<<16)|1;
	_asm
	{
			pushad
			push nKey
			mov ecx,[rwADD]
			mov ecx,[ecx]
			push nSendKey
			call [SendKeyCall]
			popad
	}
}


HWND hWindow2;

void send_key2(UINT key)
{
	hWindow2 = FindWindow("MapleStoryClass", "MapleStory");
	PostMessage(hWindow2, 0x100, 0, MapVirtualKey(key, 0) << 16);
	PostMessage(hWindow2, 0x101, 0, MapVirtualKey(key, 0) << 16);
}

BOOL tab3::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	for (INT i='B'; i<='Z'; ++i)
	{
		TCHAR szStr[50] = {0};
		szStr[0] = i;
		lstrcat(szStr, _T("键"));
		m_combo_key.InsertString(-1, szStr);
		m_combo_key.SetCurSel(0);

	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void tab3::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case(1):
		{
			sememcpy(&jz, (void *)(PWORD)rwADD, 4);
			if(jz>0)
			{
			CallSendKey('A');
			}
			break;
		}
	case(2):
		{
			sememcpy(&jz, (void *)(PWORD)rwADD, 4);
			if(jz>0)
			{

			for (int i=0; i<m_list_key.GetCount(); ++i)
			{
				if(j[i+1]>0)
				{
					j[i+1]=j[i+1]-1000;
				}else
				{
					KillTimer(1);c=false;
					CallSendKey(m_list_key.GetItemData(i));
					j[i+1]=nTimes[i];
				}
			}

			}
			break;
		}
	case(3):
		{
			sememcpy(&jz, (void *)(PWORD)rwADD, 4);
			if(jz>0)
			{
			for (int i=0; i<m_list_key.GetCount(); ++i)
			{
				if(j[i+1]>0)
				{
					if(c==false)
					{
						SetTimer(1,130,NULL);
						c=true;
					}
				}else
				{
					KillTimer(1);
					c=false;
				}
			}


			}
			break;
		}

	case(4):
		{
			sememcpy(&jz, (void *)(PWORD)rwADD, 4);
			if(jz>0)
			{
			if (s==0)
			{
				UpdateData(true);
				int ll=m_msg1.GetLength()+1;
				memcpy((VOID *)0x00D01A98,m_msg1.GetBuffer(ll),ll);
				sd_msg(ll);
				s++;
			}
			else if (s==1)
			{
				UpdateData(true);
				int ll1=m_msg2.GetLength()+1;
				memcpy((VOID *)0x00D01A98,m_msg2.GetBuffer(ll1),ll1);
				sd_msg(ll1);
				s++;
			}
			else if (s==2)
			{
				UpdateData(true);
				int ll2=m_msg2.GetLength()+1;
				memcpy((VOID *)0x00D01A98,m_msg3.GetBuffer(ll2),ll2);
				sd_msg(ll2);
				s++;
			}
			else if (s==3)
			{
				UpdateData(true);
				int ll3=m_msg2.GetLength()+1;
				memcpy((VOID *)0x00D01A98,m_msg4.GetBuffer(ll3),ll3);
				sd_msg(ll3);
				s=0;
			}
			}
		}
		break;
	default:
		break;
	}
	
	CDialog::OnTimer(nIDEvent);
}


void tab3::OnCheck1() 
{
	if(m_check1.GetCheck()==1)
	{
		s=0;
		UpdateData(true);
		SetTimer(4,m_edit2,NULL);
	}else{
		KillTimer(4);
	}
}




void tab3::OnCheck2() 
{
	if(m_check2.GetCheck()==BST_CHECKED)
	{
		for (int i=0; i<m_list_key.GetCount(); ++i)
		{
			j[i+1]=nTimes[i];
		}
		SetTimer(3,5,NULL);
		SetTimer(2,1000,NULL);
		SetTimer(1,130,NULL);
		c=true;
	}else
	{
		KillTimer(3);
		KillTimer(2);
		KillTimer(1);
	}
}

void tab3::OnButton2() 
{
	// TODO: Add your control notification handler code here

	UpdateData();
	TCHAR cComboCur = m_combo_key.GetCurSel();
	CString s;
	
	if ( cComboCur < 25 ) //A-Z
	{
		cComboCur += 'B';
		if( m_edit_key_s != "" )
		{
			s = s + m_edit_key_s + _T("秒");
			
		}
		if ( m_edit_key_ms != "")
		{
			s = s + m_edit_key_ms + _T("毫秒");
		}
		s = s + _T("-") + cComboCur + _T("键");
		
		INT nIndex = m_list_key.InsertString(-1, s);
		if ( nIndex != LB_ERR && nIndex != LB_ERRSPACE )
		{
			m_list_key.SetItemData(nIndex, cComboCur); //保存按键虚拟键码
			
			nTimes[nTimesCount++] = atoi(m_edit_key_s)*1000+ atoi(m_edit_key_ms);
		}
	}
	
}

void tab3::OnButton_del() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_list_key.GetCurSel();
	m_list_key.DeleteString(nIndex);
	for ( int i=nIndex; i< 255 && nTimes[i] != 0 ; ++i )
	{
		nTimes[i] = nTimes[i++];
	}
}

void tab3::OnButton_clear() 
{
	// TODO: Add your control notification handler code here
	m_list_key.ResetContent();
	RtlZeroMemory(nTimes, 255 * 4);
	nTimesCount = 0;
}

void tab3::OnButton_save() 
{
	// TODO: Add your control notification handler code here
	TCHAR szIniPath[MAX_PATH] = {0};
	TCHAR szSection[100] = {0};
	
	GetDllPath2(szIniPath, MAX_PATH);
	lstrcat(szIniPath, _T("\\key.ini"));
	
	H_IniFile ini(szIniPath);
	
	for ( int i=0; i<m_list_key.GetCount(); ++i)
	{
		m_list_key.GetText(i, szSection);
		ini.WriteInt(szSection, "VirtualKey", m_list_key.GetItemData(i));
		ini.WriteInt(szSection, "Times", nTimes[i]);
	}
}

void tab3::OnButton_load() 
{
	// TODO: Add your control notification handler code here
	TCHAR szPath[MAX_PATH];
	TCHAR szBuf[32767]  = {0};
	TCHAR *p = szBuf; //p来操作 安全
	INT nIndex;
	
	GetDllPath2(szPath, MAX_PATH);
	lstrcat(szPath, _T("\\key.ini"));
	
	GetPrivateProfileString  (NULL, NULL, NULL, szBuf, 32767, szPath);//读所有节点到缓冲区
	
	nTimesCount = 0;
	RtlZeroMemory(nTimes, sizeof(int)*255);
	m_list_key.ResetContent();
	
	while ( lstrlen(p) != 0 ) //后面有无小结
	{
		nIndex = m_list_key.InsertString(-1, p);
		
		nTimes[nTimesCount++] = GetPrivateProfileInt(p, _T("Times"), 0, szPath);//读时间
		m_list_key.SetItemData(nIndex, //读虚拟键码
			GetPrivateProfileInt(szBuf, _T("VirtualKey"), 0, szPath));
		
		p += (lstrlen(p) + 1);//往后移动到下一个小节
	}
}
