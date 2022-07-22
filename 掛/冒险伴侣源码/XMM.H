#include "windows.h"

DWORD RWHP;//HP值
DWORD RWMP;//MP值
DWORD GetGamePes(PDWORD addr,DWORD zhizhen) //获取HPMP初始值
{
	DWORD baseaddr;
	//PDWORD  addr=(DWORD*)0x00caa250;
	memcpy(&baseaddr,addr,4);
	if(baseaddr==NULL) return -1;//错误处理
	addr=(DWORD*)(baseaddr+zhizhen);
	memcpy(&baseaddr,addr,4);
	if(baseaddr==NULL) return -1;//错误处理
	addr=(DWORD*)(baseaddr+0x40);
	memcpy(&baseaddr,addr,4);
	addr=(DWORD*)(baseaddr+0x24);
	memcpy(&baseaddr,addr,4);
	addr=(DWORD*)(baseaddr+0x18);
	memcpy(&baseaddr,addr,4);
	addr=(DWORD*)(baseaddr+0x24);
	memcpy(&baseaddr,addr,4);
	addr=(DWORD*)(baseaddr+0x1c);
	memcpy(&baseaddr,addr,4);
	return baseaddr;
}
VOID GetGamePesW(PDWORD addr,DWORD zhizhen)//获取HPMP百分比
{
	RWHP = GetGamePes(addr,zhizhen);
	RWMP = GetGamePes(addr,zhizhen+0x18);
        if(RWHP != -1)
		RWHP = 100-(165-RWHP)*100/137;
        if(RWMP != -1)
		RWMP = 100-(334-RWMP)*100/137;
}



char* GetGameID(PDWORD addr,DWORD zhizhen)//获取帐号或名字 
{
	char str[20];
	DWORD baseaddr;
	memcpy(&baseaddr,addr,4);
	if(baseaddr==NULL) return NULL;//错误处理
	addr=(DWORD*)(baseaddr+zhizhen);
	memcpy(&baseaddr,addr,4);
	addr=(DWORD*)(baseaddr+0x0);
	memcpy(&str,addr,4);
	return str;
}