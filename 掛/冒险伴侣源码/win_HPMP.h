#include "windows.h"



char* GetGameID(PDWORD addr,DWORD zhizhen)//��ȡ�ʺŻ����� 
{
	char str[20];
	DWORD baseaddr;
	memcpy(&baseaddr,addr,4);
	if(baseaddr==NULL) return NULL;//������
	addr=(DWORD*)(baseaddr+zhizhen);
	memcpy(&baseaddr,addr,4);
	addr=(DWORD*)(baseaddr+0x0);
	memcpy(&str,addr,4);
	return str;
}