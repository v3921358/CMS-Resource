#include "StdAfx.h"
#define WG_HOOK extern "C" __declspec(dllexport)
#include "WG_Exports.h"
#include "HOOK_WG.h"
#include "WGMainDlg.h"
#include "SESDK.h"


HHOOK g_hhook = NULL;



LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	//按F12弹起时呼出窗口
	BOOL bKeyUp = lParam & (1 << 31);
	if (bKeyUp && wParam == VK_F9 && nCode == HC_ACTION) 
	{
		if (pMainDlg == NULL) 
		{
			AFX_MANAGE_STATE(AfxGetStaticModuleState());
			CWnd *pCWnd = CWnd::GetForegroundWindow();
			//当前窗口是否为目标窗口
			char buf[MAX_PATH];
			/*这里可以通过类名或窗体名来查找目标程序，从而判断是否要弹出窗体*/
			//::GetClassName(pCWnd->GetSafeHwnd(), buf, MAX_PATH);
			::GetWindowText(pCWnd->GetSafeHwnd(), buf, MAX_PATH);
			//AfxMessageBox(buf);
			if (lstrcmpi(buf, "MapleStory") == 0) 
			{
				pMainDlg = new CWGMainDlg();
				//创建"呼出窗口"时把目标窗口作为他的父窗口
				pMainDlg->Create(IDD_DIALOG1, pCWnd);
				pMainDlg->ShowWindow(SW_SHOW);
			}
		}
		else 
		{
			//根据当前呼出窗口的状态来显示或隐藏呼出窗口
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
		MessageBox(NULL,"请在选区处使用F9呼出窗体（先别使用功能,完全进入游戏角色后，再开始使用功能）\n\n卡屏或者关闭游戏同学 记得在选区处呼出1次外挂  完全进入游戏人物后再使用功能！.","提示",MB_OK);
		if (g_hhook != NULL)
			return TRUE;
	}	
}

WG_HOOK BOOL WINAPI Uninstall()
{
	return ::UnhookWindowsHookEx(g_hhook);
}
