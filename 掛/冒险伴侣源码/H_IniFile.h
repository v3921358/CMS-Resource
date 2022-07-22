/*
====================================================
�� ������ini�ļ�������
�� ˵��������ini�ļ���
�� ���ߣ����� | admin@mafom.com
�� ���ڣ�2010/9/22
�� �汾��1.4
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

	//д�ַ���
	BOOL WriteString(TCHAR *lpSection, TCHAR *lpKey, TCHAR *lpString);
	//д����
	BOOL WriteInt(TCHAR *lpSection, TCHAR *lpKey, int nValue);
	//дDWORD
	BOOL WriteDword(TCHAR *lpSection, TCHAR *lpKey, DWORD dwValue);
	//д�����ȸ�����
	BOOL WriteFloat(TCHAR *lpSection, TCHAR *lpKey, float flValue);
	//��ȡ�ַ���
	BOOL GetString(TCHAR *lpSection, TCHAR *lpKey, TCHAR lpBuff[256], DWORD pdwSize);
	//��ȡ����
	int GetInt(TCHAR *lpSection, TCHAR *lpKey, int nDefault);
	//��ȡDWORD
	DWORD GetDword(TCHAR *lpSection, TCHAR *lpKey, DWORD dwDefault);
	//��ȡ������
	float GetFloat(TCHAR *lpSection, TCHAR *lpKey, float flDefault);
private:
	TCHAR lpszFileName[MAX_PATH];
};

