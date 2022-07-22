#include "StdAfx.h"
#define WG_HOOK extern "C" __declspec(dllexport)
#include "WG_Exports.h"
#include "HOOK_WG.h"
#include "WGMainDlg.h"
#include "SESDK.h"


HHOOK g_hhook = NULL;



LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	//��F12����ʱ��������
	BOOL bKeyUp = lParam & (1 << 31);
	if (bKeyUp && wParam == VK_F9 && nCode == HC_ACTION) 
	{
		if (pMainDlg == NULL) 
		{
			AFX_MANAGE_STATE(AfxGetStaticModuleState());
			CWnd *pCWnd = CWnd::GetForegroundWindow();
			//��ǰ�����Ƿ�ΪĿ�괰��
			char buf[MAX_PATH];
			/*�������ͨ������������������Ŀ����򣬴Ӷ��ж��Ƿ�Ҫ��������*/
			//::GetClassName(pCWnd->GetSafeHwnd(), buf, MAX_PATH);
			::GetWindowText(pCWnd->GetSafeHwnd(), buf, MAX_PATH);
			//AfxMessageBox(buf);
			if (lstrcmpi(buf, "MapleStory") == 0) 
			{
				pMainDlg = new CWGMainDlg();
				//����"��������"ʱ��Ŀ�괰����Ϊ���ĸ�����
				pMainDlg->Create(IDD_DIALOG1, pCWnd);
				pMainDlg->ShowWindow(SW_SHOW);
			}
		}
		else 
		{
			//���ݵ�ǰ�������ڵ�״̬����ʾ�����غ�������
			pMainDlg->ShowWindow(pMainDlg->IsWindowVisible() ? SW_HIDE : SW_SHOW);
		}
	}
	return ::CallNextHookEx(g_hhook, nCode, wParam ,lParam);
} 

WG_HOOK BOOL WINAPI Install()
{
	
	if (g_hhook == NULL) 
	{
		g_hhook = ::SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, theApp.m_hInstance, 0);
		MessageBox(NULL,"����ѡ����ʹ��F9�������壨�ȱ�ʹ�ù���,��ȫ������Ϸ��ɫ���ٿ�ʼʹ�ù��ܣ�\n\n�������߹ر���Ϸͬѧ �ǵ���ѡ��������1�����  ��ȫ������Ϸ�������ʹ�ù��ܣ�.","��ʾ",MB_OK);
		if (g_hhook != NULL)
			return TRUE;
	}	
}

WG_HOOK BOOL WINAPI Uninstall()
{
	return ::UnhookWindowsHookEx(g_hhook);
}
