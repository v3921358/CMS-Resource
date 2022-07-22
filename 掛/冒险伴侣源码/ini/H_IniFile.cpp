#include "stdafx.h"
#include "H_IniFile.h"
H_IniFile::~H_IniFile(void) { }

/*
====================================================
● 函数：WriteString
● 作用：向指定的节点中的一个键写入一个字符串值。
-------------------------------------------------------------------
- lpSection：节点名称
- lpKey：键名
- lpString：要写入的字符串
- 返回值：TRUE（1）/FALSE（0）/ERROR（-1）
====================================================
*/

BOOL H_IniFile::WriteString(TCHAR *lpSection, TCHAR *lpKey, TCHAR *lpString)
{
	if (!lpSection || !lpKey)
		return FALSE;

	BOOL bRet = WritePrivateProfileStringA(lpSection, lpKey, lpString, lpszFileName);
	return bRet;
}

/*
====================================================
● 函数：WriteInt
● 作用：向指定的节点中的一个键写入一个整数。
-------------------------------------------------------------------
- lpSection：节点名称
- lpKey：键名
- nValue：要写入的值（）
- 返回值：TRUE（1）/FALSE（0）/ERROR（-1）
====================================================
*/
BOOL H_IniFile::WriteInt(TCHAR *lpSection, TCHAR *lpKey, int nValue)
{
	if (!lpSection || !lpKey)
		return FALSE;

	//把int转换为TCHAR
	TCHAR szValue[16] = {0};
	wsprintf(szValue, "%d", nValue);

	BOOL bRet = WritePrivateProfileStringA(lpSection, lpKey, szValue, lpszFileName);
	return bRet;
}

/*
====================================================
● 函数：WriteDword
● 作用：向指定的节点中的一个键写入一个Dword类型的值。
-------------------------------------------------------------------
- lpSection：节点名称
- lpKey：键名
- dwValue：要写入的值
- 返回值：TRUE（1）/FALSE（0）/ERROR（-1）
====================================================
*/
BOOL H_IniFile::WriteDword(TCHAR *lpSection, TCHAR *lpKey, DWORD dwValue)
{
	if (!lpSection || !lpKey)
		return FALSE;

	//把DWORD转换为TCHAR
	TCHAR szValue[16] = {0};
	wsprintf(szValue, "%X", dwValue);

	BOOL bRet = WritePrivateProfileStringA(lpSection, lpKey, szValue, lpszFileName);
	return bRet;
}

/*
====================================================
● 函数：WriteFloat
● 作用：向指定的节点中的一个键写入一个浮点数。
-------------------------------------------------------------------
- lpSection：节点名称
- lpKey：键名
- flValue：要写入的值
- 返回值：TRUE（1）/FALSE（0）/ERROR（-1）
====================================================
*/
BOOL H_IniFile::WriteFloat(TCHAR *lpSection, TCHAR *lpKey, float flValue)
{
	if (!lpSection || !lpKey)
		return FALSE;

	//把float转换为TCHAR
	TCHAR szValue[16] = {0};
	wsprintf(szValue, "%0f", flValue);

	BOOL bRet = WritePrivateProfileStringA(lpSection, lpKey, szValue, lpszFileName);
	return bRet;
}

/*
====================================================
● 函数：GetString
● 作用：从指定的节点中某键的字符串值
-------------------------------------------------------------------
- lpSection：节点名称
- lpKey：键名
- lpBuff：返回的缓冲区
- pdwSize：缓冲区长度
- 返回值：TRUE（1）/FALSE（0）/ERROR（-1）
====================================================
*/
BOOL H_IniFile::GetString(TCHAR *lpSection, TCHAR *lpKey, TCHAR lpBuff[256], DWORD pdwSize)
{
	if (!lpSection || !lpKey)
		return FALSE;

	//判断文件是否存在
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind;
	hFind = FindFirstFileA(lpszFileName, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
		return FALSE;

	pdwSize = GetPrivateProfileStringA(lpSection, lpKey, "", lpBuff, pdwSize, lpszFileName);
	return TRUE;
}

/*
====================================================
● 函数：GetInt
● 作用：从指定的节点中某键的整数值
-------------------------------------------------------------------
- lpSection：节点名称
- lpKey：键名
- nDefault：默认值。如果的键值为空时，则返回默认值
- 返回值：int
====================================================
*/
int H_IniFile::GetInt(TCHAR *lpSection, TCHAR *lpKey, int nDefault = 0)
{
	if (!lpSection || !lpKey )
		return FALSE;

	//判断文件是否存在
	WIN32_FIND_DATAA FindFileData = {0};
	HANDLE hFind;
	hFind = FindFirstFileA(lpszFileName, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
		return nDefault; 

	int nRetValue =GetPrivateProfileIntA(lpSection, lpKey, nDefault, lpszFileName);
	return nRetValue;
}

/*
====================================================
● 函数：GetDword
● 作用：从指定的节点中某键的DWORD值
-------------------------------------------------------------------
- lpSection：节点名称
- lpKey：键名
- dwDefault：默认值。如果的键值为空时，则返回默认值
- 返回值：DWORD
====================================================
*/
DWORD H_IniFile::GetDword(TCHAR *lpSection, TCHAR *lpKey, DWORD dwDefault = 0)
{
	if (!lpSection || !lpKey )
		return FALSE;

	//判断文件是否存在
	WIN32_FIND_DATAA FindFileData = {0};
	HANDLE hFind;
	hFind = FindFirstFileA(lpszFileName, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
		return dwDefault; 

	DWORD dwRetValue = GetPrivateProfileIntA(lpSection, lpKey, dwDefault, lpszFileName);
	return dwRetValue;
}

/*
====================================================
● 函数：GetFloat
● 作用：从指定的节点中某键的浮点数
-------------------------------------------------------------------
- lpSection：节点名称
- lpKey：键名
- flDefault：默认值。如果的键值为空时，则返回默认值
- 返回值：float
====================================================
*/
float H_IniFile::GetFloat(TCHAR *lpSection, TCHAR *lpKey, float flDefault = 0.0)
{
	if (!lpSection || !lpKey )
		return FALSE;

	//判断文件是否存在
	WIN32_FIND_DATAA FindFileData = {0};
	HANDLE hFind;
	hFind = FindFirstFileA(lpszFileName, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
		return flDefault;   //返回默认值
	
	
	//把flDefault转换为TCHAR
	TCHAR szValue[16] = {0};
	TCHAR szReturn[16] = {0};
	wsprintf(szValue, "%s", flDefault);
	
	GetPrivateProfileStringA(lpSection, lpKey, szValue, szReturn, 16, lpszFileName);
	
	float flRetValue = (float)atof(szReturn);
	return flRetValue;
}