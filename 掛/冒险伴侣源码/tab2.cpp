// tab2.cpp : implementation file
//

#include "stdafx.h"
#include "HOOK_WG.h"
#include "tab2.h"
#include <shlwapi.h>
#include "xmm.h"
#include "SESDK.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#pragma comment(lib, "shlwapi.lib")
#include <shlwapi.h>
#include "ini\H_IniFile.h"
/////////////////////////////////////////////////////////////////////////////
// tab2 dialog
//CString csPath;
DWORD rwjzz=0x00d06d44;
DWORD FallItemFilterAddr=0x005244e9;
DWORD g_uFallGoodsId[255];
DWORD GoodsId;

int nTime[255] = {0};
int nTimeCount = 0;


void ssmemcpy(void *dest, void *src, int len)
{
	ULONG d;
	
	if (VirtualProtect(dest, len, 0x40, &d)) {
		memcpy(dest, src, len);
	}
	return; 
}
ULONG *px;

tab2::tab2(CWnd* pParent /*=NULL*/)
	: CDialog(tab2::IDD, pParent)
{
	//{{AFX_DATA_INIT(tab2)
	m_edit1 = 50;
	m_edit2 = 20;
	//}}AFX_DATA_INIT
}

void tab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(tab2)
	DDX_Control(pDX, IDC_CHECK5, m_check5);
	DDX_Control(pDX, IDC_LIST2, m_list_filter);
	DDX_Control(pDX, IDC_LIST1, m_list_Data);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(tab2, CDialog)
	//{{AFX_MSG_MAP(tab2)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList_data)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void GetDllPath(TCHAR *pszBuf, INT nSize) //检测DLL
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

/////////////////////////////////////////////////////////////////////////////
// tab2 message handlers




DWORD key_call2=0x009bea30;

void KeyCall2(UINT uKeyCodes)
{
	int nVirtualKeyCodes;
	nVirtualKeyCodes = MapVirtualKey(uKeyCodes,0);
	nVirtualKeyCodes = 1 | (nVirtualKeyCodes<<16);
	SE_PROTECT_START();
	_asm
	{
			pushad
			mov ecx,[rwjzz]
			mov ecx,[ecx]
			push nVirtualKeyCodes//键虚拟码
			push uKeyCodes       //键的代码
			call key_call2
			popad
	}
	SE_PROTECT_END();
}

BOOL tab2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CStdioFile  pFile;
	CString csData;
	TCHAR szPath[MAX_PATH];
	
	GetDllPath(szPath, MAX_PATH);
	lstrcat(szPath, _T("\\item.txt"));
	
	if (pFile.Open(szPath, CFile::modeRead) != 0) 
	{
		int index = 0;
		while (pFile.ReadString(csData)) 
		{
			index = m_list_Data.AddString(csData.Mid(8));//物品名称
			m_list_Data.SetItemData(index,StrToInt(csData.Left(7)));//物品ID
		}
		pFile.Close();
	}else
	{
		AfxMessageBox("没有找到过滤文件item.txt,请查看目录内是否缺少，或者重新解压文件.");
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}





void tab2::OnDblclkList_data() 
{
	INT nSel = 0;
	DWORD dwData;
	TCHAR szData[255] = {0};
	INT nIndex;
	TCHAR szTmp[20];
	
	nSel = m_list_Data.GetCurSel();
	//SetDlgItemInt(IDC_EDIT5, m_list_Data.GetItemData(nSel)); 调试用过的
	
	m_list_Data.GetText(nSel, szData);
	dwData = m_list_Data.GetItemData(nSel);
	
	lstrcat(szData, _T(" ID:"));
	wsprintf(szTmp, _T("%d"), dwData);
	lstrcat(szData, szTmp);
	
	nIndex = m_list_filter.InsertString(-1, szData);
	m_list_filter.SetItemData(nIndex, dwData);

for ( int x=0; x< 255; x++){g_uFallGoodsId[x]=0;}
for ( int i=0; i< m_list_filter.GetCount(); i++){g_uFallGoodsId[i]=m_list_filter.GetItemData(i);}

}

void tab2::OnButton1() 
{
	CString csFindData;
	INT		nIndex;
	GetDlgItemText(IDC_EDIT3,csFindData);
	nIndex = m_list_Data.FindString(0, csFindData);
	m_list_Data.SetCurSel(nIndex);
	
}




void tab2::OnButton2() 
{
	// TODO: Add your control notification handler code here
	int Index;
	Index=m_list_filter.GetCurSel();
	m_list_filter.DeleteString(Index);	 
	Index=m_list_filter.GetCurSel();
  for ( int x=0; x< 255; x++){g_uFallGoodsId[x]=0;}
for ( int i=0; i< m_list_filter.GetCount(); ++i){g_uFallGoodsId[i]=m_list_filter.GetItemData(i);}


}


#define JumpCall(frm, to) (int)(((int)to - (int)frm) - 5)

void MakeMemoryWritable( long ulAddress,  long ulSize)
{
	MEMORY_BASIC_INFORMATION* mbi = new MEMORY_BASIC_INFORMATION;
	VirtualQuery((void*)ulAddress, mbi, ulSize);
	if (mbi->Protect != PAGE_EXECUTE_READWRITE)
	{
		unsigned long* ulProtect = new unsigned long;
		VirtualProtect((void*)ulAddress, ulSize, PAGE_EXECUTE_READWRITE, ulProtect);
		delete ulProtect;
	}
	delete mbi;
}

bool Jump( long ulAddress, void* Function,  long ulNops = 0 )
{
	__try
	{
		MakeMemoryWritable(ulAddress, 5 + ulNops);
		*(unsigned char*)ulAddress = 0xE9;
		*(unsigned long*)(ulAddress + 1) = JumpCall(ulAddress, Function);
		memset((void*)(ulAddress + 5), 0x90, ulNops);
		return true;
	}
	__except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}

void __declspec(naked) FallItemFilter()
{
	__asm
	{
		
			mov [GoodsId],ecx //丢一个物品就会显示那个最后丢的ID
			push ebx
			push esi
			mov esi, offset g_uFallGoodsId
			sub esi,4
			mov ebx,ecx
			Filter:
			add esi,4
			cmp [esi],0
			je End0
			cmp [esi],ebx
			je End1
			jmp Filter
			End1:
			mov ecx,0
			End0:
			pop esi
			pop ebx
			mov [edi+0x34],ecx
			movzx ecx,word ptr [esi+0x0C]
			push [0x005244f0]
			ret
	}
}


void tab2::OnCheck4() 
{
	if(m_check4.GetCheck() == BST_CHECKED)
	{
		Jump(FallItemFilterAddr,FallItemFilter,2);
	}else{
		BYTE mxdysp[7]={0x89,0x4F,0x34,0x0F,0xB7,0x4E,0x0C};
		memcpy((PWORD)FallItemFilterAddr,mxdysp,7);
	}
}

int jiasu1=0;
int xx1xz=1;
void tab2::OnTimer(UINT nIDEvent) 
{
	switch(nIDEvent)
	{
	case(1):
		ssmemcpy(&px, (void *)(PWORD)rwjzz, 4);
		if(px>0)
		{
			UpdateData();
			GetGamePesW((DWORD*)0x00d07070,0x1658);
			if(RWHP<=m_edit1)
			{
				KeyCall2(33);
			}
		}
		break;
	case(2):
		ssmemcpy(&px, (void *)(PWORD)rwjzz, 4);
		if(px>0)
		{
			UpdateData();
			GetGamePesW((DWORD*)0x00d07070,0x1658);
			if(RWMP<=m_edit2)
			{
				KeyCall2(34);
			}
		}
		 break;
	case(3):
		{
		ssmemcpy(&px, (void *)(PWORD)rwjzz, 4);
		if(px>0)
		{
			UpdateData();
			DWORD *BaseAddr=(DWORD *)rwjzz;
			if(BaseAddr==NULL)return;
			BaseAddr = (DWORD *)BaseAddr[0];
			if(BaseAddr==NULL)return;
			BaseAddr = (DWORD *)BaseAddr[0x2c40/4];
			if(BaseAddr==NULL)return;
			BaseAddr = (DWORD *)BaseAddr[0x4/4];
			if(BaseAddr==NULL)return;
			if(BaseAddr[0xAC/4] !=0 && BaseAddr[0xAC/4]<=60){ KeyCall2(35); }

			}
			return;
	}
	case(4):
		if(*((DWORD*)(((char *)((DWORD *)(*(DWORD*)0x00d06d3c)))+0x18))>0)
		{
			ssmemcpy(&px, (void *)0x00d02840, 4);
			ssmemcpy((UCHAR *)px + 0x0000385c, &xx1xz, 4);
		}else{
			ssmemcpy(&px, (void *)0x00d02840, 4);
			ssmemcpy((UCHAR *)px + 0x0000385c, &jiasu1, 4);
		}
		break;
		default:
		break;
	CDialog::OnTimer(nIDEvent);
	}
}

void tab2::OnCheck1() 
{
	if(m_check1.GetCheck()==1)
	{
		SetTimer(1,1000,NULL);
	}else
	{
		KillTimer(1);
	}	
}

void tab2::OnCheck2() 
{
	if(m_check2.GetCheck()==1)
	{
		SetTimer(2,1000,NULL);
	}else
	{
		KillTimer(2);
	}	
}

void tab2::OnCheck3() 
{
	if(m_check3.GetCheck()==1)
	{
		SetTimer(3,10000,NULL);
	}else{
		KillTimer(3);
	}
}

void tab2::OnCheck5() 
{
	if(m_check5.GetCheck()==1)
	{
		SetTimer(4,500,NULL);
	}else{
		KillTimer(4);
		ssmemcpy(&px, (void *)0x00d02840, 4);
		ssmemcpy((UCHAR *)px + 0x0000385c, &jiasu1, 4);
	}
}

void tab2::OnButton4() //保存物品ID
{

	//system("del C:\\item.ini"); 
	TCHAR szIniPath[MAX_PATH] = {0};
	TCHAR szSection[32767] = {0};
	
	GetDllPath(szIniPath, MAX_PATH);
	lstrcat(szIniPath, _T("\\item.ini"));
	
	H_IniFile ini(szIniPath);
	
	for ( int i=0; i<m_list_filter.GetCount(); ++i)
	{
		m_list_filter.GetText(i, szSection);
		ini.WriteInt(szSection, "item", m_list_filter.GetItemData(i));
	}
}

void tab2::OnButton6() //加载物品ID
{
	TCHAR szPath[MAX_PATH];
	TCHAR szBuf[32767]  = {0};
	TCHAR *p = szBuf;
	INT nIndex;
	CString pstr;
	for ( int x=0; x< 255; x++){g_uFallGoodsId[x]=0;}
	
	GetDllPath(szPath, MAX_PATH);
	lstrcat(szPath, _T("\\item.ini"));
	
	GetPrivateProfileString  (NULL, NULL, NULL, szBuf, 32767, szPath);
	
	nTimeCount = 0;
	RtlZeroMemory(nTime, sizeof(int)*255);
	m_list_filter.ResetContent();
	int i = 0;
	while ( lstrlen(p) != 0 )
	{
		nIndex = m_list_filter.InsertString(-1, p);
			GetPrivateProfileInt(szBuf, _T("item"), 0, szPath);
		pstr = p;
		g_uFallGoodsId[i] = StrToInt(pstr.Right(7));
		i++;
		
		p += (lstrlen(p) + 1);
	}
}
int items[255] = {0};
int itemsCount = 0;

void tab2::OnButton7() 
{
	m_list_filter.ResetContent();
	RtlZeroMemory(items, 255 * 4);
	itemsCount = 0;
}
