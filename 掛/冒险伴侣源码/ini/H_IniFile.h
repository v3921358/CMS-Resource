/*
====================================================
● 类名：ini文件操作类
● 说明：操作ini文件。
● 作者：泡面 | admin@mafom.com
● 日期：2010/9/22
● 版本：1.4
====================================================
*/
#include <windows.h>
#include <tchar.h>
class H_IniFile
{

public:
	
	H_IniFile(TCHAR *pszFileName)
	{
		RtlZeroMemory(lpszFileName, MAX_PATH);
		lstrcpy(lpszFileName, pszFileName);
	}
	virtual ~H_IniFile(void);

	//写字符串
	BOOL WriteString(TCHAR *lpSection, TCHAR *lpKey, TCHAR *lpString);
	//写整数
	BOOL WriteInt(TCHAR *lpSection, TCHAR *lpKey, int nValue);
	//写DWORD
	BOOL WriteDword(TCHAR *lpSection, TCHAR *lpKey, DWORD dwValue);
	//写单精度浮点数
	BOOL WriteFloat(TCHAR *lpSection, TCHAR *lpKey, float flValue);
	//读取字符串
	BOOL GetString(TCHAR *lpSection, TCHAR *lpKey, TCHAR lpBuff[256], DWORD pdwSize);
	//读取整数
	int GetInt(TCHAR *lpSection, TCHAR *lpKey, int nDefault);
	//读取DWORD
	DWORD GetDword(TCHAR *lpSection, TCHAR *lpKey, DWORD dwDefault);
	//读取浮点数
	float GetFloat(TCHAR *lpSection, TCHAR *lpKey, float flDefault);
private:
	TCHAR lpszFileName[MAX_PATH];
};

