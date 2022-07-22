#include "stdafx.h"
#include "H_IniFile.h"
H_IniFile::~H_IniFile(void) { }

/*
====================================================
�� ������WriteString
�� ���ã���ָ���Ľڵ��е�һ����д��һ���ַ���ֵ��
-------------------------------------------------------------------
- lpSection���ڵ�����
- lpKey������
- lpString��Ҫд����ַ���
- ����ֵ��TRUE��1��/FALSE��0��/ERROR��-1��
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
�� ������WriteInt
�� ���ã���ָ���Ľڵ��е�һ����д��һ��������
-------------------------------------------------------------------
- lpSection���ڵ�����
- lpKey������
- nValue��Ҫд���ֵ����
- ����ֵ��TRUE��1��/FALSE��0��/ERROR��-1��
====================================================
*/
BOOL H_IniFile::WriteInt(TCHAR *lpSection, TCHAR *lpKey, int nValue)
{
	if (!lpSection || !lpKey)
		return FALSE;

	//��intת��ΪTCHAR
	TCHAR szValue[16] = {0};
	wsprintf(szValue, "%d", nValue);

	BOOL bRet = WritePrivateProfileStringA(lpSection, lpKey, szValue, lpszFileName);
	return bRet;
}

/*
====================================================
�� ������WriteDword
�� ���ã���ָ���Ľڵ��е�һ����д��һ��Dword���͵�ֵ��
-------------------------------------------------------------------
- lpSection���ڵ�����
- lpKey������
- dwValue��Ҫд���ֵ
- ����ֵ��TRUE��1��/FALSE��0��/ERROR��-1��
====================================================
*/
BOOL H_IniFile::WriteDword(TCHAR *lpSection, TCHAR *lpKey, DWORD dwValue)
{
	if (!lpSection || !lpKey)
		return FALSE;

	//��DWORDת��ΪTCHAR
	TCHAR szValue[16] = {0};
	wsprintf(szValue, "%X", dwValue);

	BOOL bRet = WritePrivateProfileStringA(lpSection, lpKey, szValue, lpszFileName);
	return bRet;
}

/*
====================================================
�� ������WriteFloat
�� ���ã���ָ���Ľڵ��е�һ����д��һ����������
-------------------------------------------------------------------
- lpSection���ڵ�����
- lpKey������
- flValue��Ҫд���ֵ
- ����ֵ��TRUE��1��/FALSE��0��/ERROR��-1��
====================================================
*/
BOOL H_IniFile::WriteFloat(TCHAR *lpSection, TCHAR *lpKey, float flValue)
{
	if (!lpSection || !lpKey)
		return FALSE;

	//��floatת��ΪTCHAR
	TCHAR szValue[16] = {0};
	wsprintf(szValue, "%0f", flValue);

	BOOL bRet = WritePrivateProfileStringA(lpSection, lpKey, szValue, lpszFileName);
	return bRet;
}

/*
====================================================
�� ������GetString
�� ���ã���ָ���Ľڵ���ĳ�����ַ���ֵ
-------------------------------------------------------------------
- lpSection���ڵ�����
- lpKey������
- lpBuff�����صĻ�����
- pdwSize������������
- ����ֵ��TRUE��1��/FALSE��0��/ERROR��-1��
====================================================
*/
BOOL H_IniFile::GetString(TCHAR *lpSection, TCHAR *lpKey, TCHAR lpBuff[256], DWORD pdwSize)
{
	if (!lpSection || !lpKey)
		return FALSE;

	//�ж��ļ��Ƿ����
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
�� ������GetInt
�� ���ã���ָ���Ľڵ���ĳ��������ֵ
-------------------------------------------------------------------
- lpSection���ڵ�����
- lpKey������
- nDefault��Ĭ��ֵ������ļ�ֵΪ��ʱ���򷵻�Ĭ��ֵ
- ����ֵ��int
====================================================
*/
int H_IniFile::GetInt(TCHAR *lpSection, TCHAR *lpKey, int nDefault = 0)
{
	if (!lpSection || !lpKey )
		return FALSE;

	//�ж��ļ��Ƿ����
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
�� ������GetDword
�� ���ã���ָ���Ľڵ���ĳ����DWORDֵ
-------------------------------------------------------------------
- lpSection���ڵ�����
- lpKey������
- dwDefault��Ĭ��ֵ������ļ�ֵΪ��ʱ���򷵻�Ĭ��ֵ
- ����ֵ��DWORD
====================================================
*/
DWORD H_IniFile::GetDword(TCHAR *lpSection, TCHAR *lpKey, DWORD dwDefault = 0)
{
	if (!lpSection || !lpKey )
		return FALSE;

	//�ж��ļ��Ƿ����
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
�� ������GetFloat
�� ���ã���ָ���Ľڵ���ĳ���ĸ�����
-------------------------------------------------------------------
- lpSection���ڵ�����
- lpKey������
- flDefault��Ĭ��ֵ������ļ�ֵΪ��ʱ���򷵻�Ĭ��ֵ
- ����ֵ��float
====================================================
*/
float H_IniFile::GetFloat(TCHAR *lpSection, TCHAR *lpKey, float flDefault = 0.0)
{
	if (!lpSection || !lpKey )
		return FALSE;

	//�ж��ļ��Ƿ����
	WIN32_FIND_DATAA FindFileData = {0};
	HANDLE hFind;
	hFind = FindFirstFileA(lpszFileName, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
		return flDefault;   //����Ĭ��ֵ
	
	
	//��flDefaultת��ΪTCHAR
	TCHAR szValue[16] = {0};
	TCHAR szReturn[16] = {0};
	wsprintf(szValue, "%s", flDefault);
	
	GetPrivateProfileStringA(lpSection, lpKey, szValue, szReturn, 16, lpszFileName);
	
	float flRetValue = (float)atof(szReturn);
	return flRetValue;
}