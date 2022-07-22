#define JumpCall(frm, to) (int)(((int)to - (int)frm) - 5)
#include <Windows.h>
//#include <dll.h>
#include "SESDK.h"
DWORD MsCr1 = 0x00AE828F,MSCRC_JMP1 = MsCr1+5;
DWORD MsCr2 = 0x00D5D6CB,MSCRC_JMP2 = 0x00D50195;
INT HSdll_EIP,HSdll_CRC_EIP,HSdll_JMP;
LPVOID buf,buf_bak;
PDWORD i;
//======================================================================================
void MakeMemoryWritable(unsigned long ulAddress, unsigned long ulSize)
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
//======================================================================================
bool Jump(unsigned long ulAddress, void* Function, unsigned long ulNops)
{
   __try
   {
      MakeMemoryWritable(ulAddress, 5 + ulNops);
      *(unsigned char*)ulAddress = 0xE9;
      *(unsigned long*)(ulAddress + 1) = JumpCall(ulAddress, Function);
      memset((void*)(ulAddress + 5),0x90, ulNops);
      return true;
   }
   __except (EXCEPTION_EXECUTE_HANDLER) { return false; }
}



//======================================================================================
void __declspec(naked) MSCRC1()
{

		__asm
	{
		push eax
			lea eax,[ecx]
			cmp eax,0x00401000
			jb End
			cmp eax,0x00B41000
			ja End
			push ebx
			mov ebx,buf
			add ecx,ebx
			sub ecx,0x00401000
			pop ebx
End:
		pop eax
			mov dl,[ecx]
			add dl,01
			JMP MSCRC_JMP1
	}

}
//======================================================================================
void __declspec(naked) MSCRC2()
{

		__asm
	{
		cmp edx,0x00401000
			jb hookret
			cmp edx,0x00C20000
			ja hookret
			push ebx
			mov ebx,buf
			sub edx,0x00401000
			add edx,ebx
			pop ebx
hookret:
		push [edx]
			JMP MSCRC_JMP2
	}

}
//===================================================================================
void __declspec(naked) HSCRC()
{
SE_PROTECT_START();
		__asm
	{
		mov eax,[HSdll_CRC_EIP]
			cmp [esp],eax
			jne HS_readret
			mov eax,edi
			cmp eax,0x00C27001
			jnl HS_readret
			cmp eax,0x00400FFF
			jle HS_readret
			sub eax,0x00401000
			push esi
			mov esi,buf       //把内存指针传入esi
			mov buf_bak,esi   //buf_bak得到buf的值
			add eax,buf_bak   //加上偏移，得出ebp+$8的目标地址
			mov edi,eax
			pop esi
HS_readret:
		JMP HSdll_JMP
	}
		SE_PROTECT_END();

}
//======================================================================================

DWORD GetValue(CONST LPDWORD lpdwBase, CONST INT iOffset)
{
	__try { return *(LPDWORD)((LPBYTE)lpdwBase + iOffset); }
	__except (EXCEPTION_EXECUTE_HANDLER) { return NULL; }
}


HWND FindProcessWindow()
{
	return HWND(GetValue((LPDWORD)GetModuleHandle("mss32.dll"),0x8E5EC)); //取冒险岛窗口句柄
}

void CRCBypass()
{
	SE_PROTECT_START();
	{
		SIZE_T CRCsize = 0xA07010;//0x77F000
		SIZE_T Newsize = 0x401000;
		MakeMemoryWritable(Newsize,CRCsize);
		buf = VirtualAlloc(NULL,CRCsize,MEM_COMMIT,PAGE_EXECUTE_READWRITE);
		CopyMemory(buf,(LPVOID)Newsize,CRCsize);
		Jump(MsCr1,MSCRC1,0);
		Jump(MsCr2,MSCRC2,2);
		HSdll_EIP = (int)GetModuleHandle("ehsvc.dll") + 0xC31AC;
		HSdll_CRC_EIP = (int)GetModuleHandle("ehsvc.dll") + 0x21328;
		MakeMemoryWritable(HSdll_EIP,4);
		HSdll_JMP=*(PDWORD)HSdll_EIP;
		*(PDWORD)HSdll_EIP=(int)HSCRC;
	}
	SetWindowTextA(FindProcessWindow(),"MapleStory");
	SE_PROTECT_END();
}

DWORD wudi_add=0x009aeeb4;     //完全无敌
DWORD wudi58S_add=0x009afa6c;  //58秒无敌
DWORD fengjie_add=0x00686f02;  //凤姐定怪
DWORD benguai_add=0x006863cb;  //苯怪
DWORD guaiwuJT_add=0x009b53f1; //怪物击退
DWORD shubiao_add=0x00a1e525;  //鼠标飞
DWORD SSshubiao_add=0x00a1e520;//SS鼠标飞
DWORD gjbt_add=0x00a1e4b8;     //攻击不停
DWORD cl_add=0x009adae3;       //畜力秒放
DWORD wyc_add=0x009e76c0;      //冒险时间
DWORD qzyqpgj_add=0x00464350;  //全职业全屏攻击
DWORD gwbt_add=0x00686bbb;     //怪物不退
DWORD sgxg_add=0x00a21130;     //生怪吸怪
DWORD screen_add=0x004c040b;   //读取坐标
DWORD getxy_add=0x006816a6;    //移动XY
DWORD lz_add=0x009bae87;       //连撞
DWORD wupinsuxian_add=0x0051d4da;//物品速显
DWORD dandansuxian_add=0x0067a0fa;//蛋蛋显
DWORD guaibuxianshang_add=0x00686bc3;//怪物不显示伤
DWORD zsbqj_add=0x00989069;    //战神攻击不前进
DWORD zddx1_add=0x009bfb46;    //掉血1
DWORD zddx2_add=0x009bfc34;    //掉血2
DWORD rwjz=0x00d06d44;         //人物基址
DWORD qbjz=0x00d06d38;         //墙壁基址
DWORD sjjz=0x00d073c0;         //冒险时间
DWORD dtjz=0x00d073dc;         //地图基址
DWORD sbjz=0x00d071c4;         //鼠标基址
DWORD jxswyc_add=0x009c4ab5;   //机械重机枪
DWORD gwdz_add=0x0068166d;     //怪物暂停
DWORD zswyc_add=0x009CDF05;    //战神无延迟
DWORD xg_add=0x006816a6;       //吸怪
DWORD jf_add=0x00a7f2f6;       //飓风
DWORD jf2_add=0x0098b33e;      //飓风2
DWORD BOSS_add=0x0067d859;     //直接打主体
DWORD chongxi_add=0x0051f73c;  //新宠物吸
DWORD xinqp_add=0x0068166d;    //新全屏
DWORD QPjianwu_add=0x0051F4E7; //人物捡取物品
__cdecl ksf();
__cdecl Return();
__cdecl CSXReturn();
__cdecl ksgg();
__cdecl qplf();
__cdecl zngjbt();


DWORD zyzgjcs,zyzcspdkg,zyzpdfw,zyypdkg,zyzkg, rwpddz,zyzpdx,zyzdqx;
DWORD zyzfw=NULL;
DWORD xiguaiX=0x200d0,xiguaiY=0x200d4,xiguaiCALL=0X00A1A320,xxxxkg=0,xgkg=0,zgfwy=NULL;
__declspec(naked) __cdecl mynewxiguai()
{
	SE_PROTECT_START();
	_asm{
	
			cmp [rwjz],0
			je zctz
			cmp [xgkg],0
			je zctz
			cmp [xgkg],1
			je dingdian
			cmp [xgkg],2
			je xiguai
			jmp zctz
			dingdian:
			pushad
			mov ecx,[dtjz]
			mov ecx,[ecx]
			mov eax,[ecx+0x00000b0c]
			mov [xiguaiX],eax
			mov eax,[ecx+0x00000b10]
			mov [xiguaiY],eax
			popad
			mov [xgkg],2
			jmp zctz
			xiguai:
			cmp dword ptr [eax+0x000002e8],01
			je kszgfwx
			cmp dword ptr [eax+0x000002e8],03
			je ksxg
			cmp dword ptr [eax+0x000002e8],04
			je ksxg
			jmp zctz
			kszgfwx:
			push edx
			mov edx,[xiguaiY]
			add edx,[zgfwy]
			cmp [eax+0x00000280],edx
			pop edx
			jg zctz
			push edx
			mov edx,[xiguaiY]
			sub edx,[zgfwy]
			cmp [eax+0x00000280],edx
			pop edx
			jl zctz
			jmp ksxg
			ksxg:
			pushad
			push 0
			push 0
			push 0
			push 0
			push [xiguaiY]
			push [xiguaiX]
			push 1
			mov ecx,eax
			mov esi,eax
			mov [eax+0x000002e8],6
			call xiguaiCALL
			popad
			zctz:
			cmp [ebx+0x00000294],ebp
			push 0x006816A6+6
			ret

	}
	SE_PROTECT_END();
}





__declspec(naked) __cdecl gwdz()
{
	_asm{
			push 0x006830ae
			ret
	}
}


__declspec(naked) __cdecl BOSS()
{
	_asm{
		push 0x0067dcf5
			ret
	}
}

__declspec(naked) __cdecl guaibuxianshang()
{
	_asm{
			push 0x00686bc8
			ret
	}
}
__declspec(naked) __cdecl wupinsuxian()
{
	_asm{
			push 0x0051d527
			ret
	}
}
__declspec(naked) __cdecl dandansuxian()
{
	_asm{
			push 0x0067a107
			ret
	}
}



__declspec(naked) __cdecl chuli()
{
	_asm{
			mov eax,0x500000
			mov ebp,eax
			push 0x009adaea
			ret
	}
}


__declspec(naked) __cdecl jufeng2()
{
	__asm
	{
		push 0x009bd377
			ret
	}
}

__declspec(naked) __cdecl CSX()
{
	__asm
	{
			push eax  
			mov eax,[rwjz]
			mov eax,[eax]
			mov eax,[eax+0x00003ae0]    
			cmp eax,0x32    
			pop eax  
			jg CSXReturn  
			push eax  
			mov eax,[rwjz]
			mov eax,[eax]
			mov eax,[eax+0x00003af0]  
			cmp eax,0x32  
			pop eax   
			jg CSXReturn   

			push eax  
			mov eax,[rwjz]
			mov eax,[eax]
			mov eax,[eax+0x000017d0]
			cmp esi,eax  
			pop eax  
			jne CSXReturn  
			add eax,0x10   
			jmp CSXReturn   
			
			
	}
}


__declspec(naked) __cdecl CSXReturn()
{
	_asm{
			 mov [ebx], eax   
			 mov edi,[ebp+0x10]  
			 push 0x00a1e4bd
		     ret
	}
}

//---------------------------------------------------------------------------------------
__declspec(naked) __cdecl zswyc()
{
	SE_PROTECT_START();
	_asm{
			push 0x009CDE91
			ret
	}
	SE_PROTECT_END();
}

DWORD zskg=1,zsADD=0x00989073;
__declspec(naked) __cdecl zsbqj()
{
	_asm{
		cmp dword ptr [zskg],01
		jne zsgjbqjzctz
		mov byte ptr [esi+0x00003a78],00000000
		jmp zsADD
		zsgjbqjzctz:
		mov byte ptr [esi+0x00003a78],00000001
		jmp zsADD
	}
}



DWORD screen_CALL=0x0042e690;
DWORD screen_X=0x200d0;
DWORD screen_Y=0x200d4;
__declspec(naked) __cdecl screen()
{
	SE_PROTECT_START();
	_asm{
			call screen_CALL
			mov edi,[screen_X]
			mov ecx,[screen_Y]
			push 0x004C040B+0x10
			ret
	}
	SE_PROTECT_END();
}


__declspec(naked) __cdecl getxy()
{
	SE_PROTECT_START();
	_asm{
			push ebx
			mov ebx,[eax+0x0000027c] //x``````````````````````
			mov [screen_X],ebx
			mov ebx,[eax+0x00000280] //y````````````````
			sub ebx,0x79
			mov [screen_Y],ebx
			pop ebx
			cmp [ebx+0x00000294],ebp
			push 0x006816a6+6
			ret

	}
	SE_PROTECT_END();
}


__declspec(naked) ICS_wlwd()//ICS物理无敌
{
	__asm
	{
		cmp dword ptr [esp],0x00688859
		jne IsRectEmptyADD
		mov dword ptr [esp],offset ksgg
		IsRectEmptyADD:
		jmp dword ptr [IsRectEmpty]
	}
}




__declspec(naked) __cdecl ksgg()
{
	__asm
	{
		push 0x0068885d
			ret
	}
}


int wycsj,wycms=0x6;

__declspec(naked) __cdecl wyc()
{
	__asm
	{
			mov eax,[sjjz]  //时间
			mov eax,[eax]
			mov eax,[eax+0x1c]
			mov edx,[wycms]
			add [wycsj],edx
			mov eax,[wycsj]
			ret
	}
}


__declspec(naked) __cdecl wudi_Start()
{
	__asm
	{
			push 0x009b0db6
			ret
	}
}


__declspec(naked) __cdecl ICS_zngjbt()//ICS智能攻击不停
{
	_asm
	{
		cmp dword ptr [esp],0x00a29db5
		jne GetFocusADD
		mov dword ptr [esp],offset zngjbt
		GetFocusADD:
		jmp dword ptr [GetFocus]
	}
}




__declspec(naked) __cdecl zngjbt()
{
	SE_PROTECT_START();
	_asm
	{
			cmp [zyzkg],0
			je zyzzctz
			cmp [rwjz],0
			je zyzzctz
			cmp [zyzcspdkg],0
			jne zyzjxtz
			mov eax,dtjz
			mov eax,[eax]
			mov eax,[eax+0x00000b0c]
			mov [zyzpdx],eax
			mov eax,[rwjz]
			mov eax,[eax]
			mov eax,[eax+0x47c]
			mov [rwpddz],eax
			mov [zyzcspdkg],1
			jmp zyzzctz
			zyzjxtz:
			cmp [rwpddz],0x2
			je xzyzyz
			cmp [rwpddz],0x4
			je xzyzyz
			cmp [rwpddz],0x6
			je xzyzyz
			cmp [rwpddz],0x8
			je xzyzyz
			cmp [rwpddz],0xa
			je xzyzyz
			cmp [rwpddz],0x14
			je xzyzyz
			cmp [rwpddz],0x3
			je xyyzyz
			cmp [rwpddz],0x5
			je xyyzyz
			cmp [rwpddz],0x7
			je xyyzyz
			cmp [rwpddz],0x9
			je xyyzyz
			cmp [rwpddz],0xb
			je xyyzyz
			cmp [rwpddz],0x15
			je xyyzyz
			jmp zyymspd
			zyymspd:
			cmp [zyypdkg],1
			je zyzyz
			cmp [zyypdkg],2
			je yyzyz
			jmp zyzzctz
			zyzyz:
			add [zyzpdfw],1
			mov eax,[zyzfw]
			cmp [zyzpdfw],eax
			jle zuozou
			push edx
			mov edx,[zyzfw]
			imul eax,edx,2
			pop edx
			cmp [zyzpdfw],eax
			jle youzou
			cmp [zyzpdfw],eax
			jle zuozou
			mov eax,[rwjz]
			mov eax,[eax]
			mov eax,[eax+0x00003ae0]
			cmp eax,[zyzgjcs]
			jl zyzzctz
			push edx
			mov edx,dtjz
			mov edx,[edx]
			mov edx,[edx+0x00000b0c]
			cmp [zyzpdx],edx
			pop edx
			mov dword ptr[zyzpdfw],0xfffffffe
			jl zuozou
			mov dword ptr[zyzpdfw],0x00000002
			push eax
			mov eax,dtjz
			mov eax,[eax]
			mov eax,[eax+0x00000b0c]
			mov [zyzdqx],eax
			sub eax,[zyzpdx]
			cmp eax,[zyzfw]
			pop eax
			jnl zuozou
			push eax
			mov eax,[zyzpdx]
			sub eax,[zyzdqx]
			cmp eax,[zyzfw]
			pop eax
			jnl youzou
			jmp zyzzctz
			yyzyz:
			add [zyzpdfw],1
			mov eax,[zyzfw]
			cmp eax,[zyzpdfw]
			jnl youzou
			push edx
			mov edx,[zyzfw]
			imul eax,edx,2
			pop edx
			cmp eax,[zyzpdfw]
			jnl zuozou
			mov eax,[rwjz]
			mov eax,[eax]
			mov eax,[eax+0x00003ae0]
			cmp eax,[zyzgjcs]
			jl zyzzctz
			push edx
			mov edx,dtjz
			mov edx,[edx]
			mov edx,[edx+0x00000b0c]
			cmp [zyzpdx],edx
			pop edx
			mov dword ptr [zyzpdfw],0xfffffffe
			jg zuozou
			mov dword ptr [zyzpdfw],0x00000002
			push eax
			mov eax,dtjz
			mov eax,[eax]
			mov eax,[eax+0x00000b0c]
			mov [zyzdqx],eax
			sub eax,[zyzpdx]
			cmp eax,[zyzfw]
			pop eax
			jnl zuozou
			push eax
			mov eax,[zyzpdx]
			sub eax,[zyzdqx]
			cmp eax,[zyzfw]
			pop eax
			jnl youzou
			jmp zyzzctz
			zuozou:
			mov dword ptr [esp+0x24],0xffffffff
			jmp zyzzctz
			youzou:
			mov dword ptr [esp+0x24],0x1
			jmp zyzzctz
			zyzzctz:
			push eax
			mov eax,[rwjz]
			mov eax,[eax]
			mov eax,[eax+0x00003ae0]
			cmp eax,[zyzgjcs]
			pop eax
			lea edi,[ebx+0x00000088]
			jl 0x00a29e3b
			push 0x00a29db5
			ret
			xzyzyz:
			mov [zyypdkg],1
			jmp zyymspd
			xyyzyz:
			mov [zyypdkg],2
			jmp zyymspd
	}
	SE_PROTECT_END();
}





__declspec(naked) __cdecl wudi58S_Start()
{
	__asm
	{
		lea ecx,[esi+0x00002c1c]
		push 0xFFFF1988
		push 0x009b03ba
		ret
	}
}



__declspec(naked) __cdecl gwbmg_Start()
{
	__asm
	{
		push 0x006864ad
			ret
	}
}


__declspec(naked) __cdecl cjbg_Start()
{
	__asm
	{
		push 0x00686e45
			ret
	}
}



__declspec(naked) __cdecl guaiwuJT_Start()
{
	__asm
	{
			push 0x009b5445
			ret
	}
}



DWORD x,y,xsv=0x00ac8fd0;

__declspec(naked) __cdecl ssbf() 
{
	__asm{
			call xsv
			push edx
			push ecx
			mov edx,rwjz
			mov edx,[edx]
			push eax
			mov eax,sbjz
			mov eax,[eax]
			mov eax,[eax+0x978]
			mov eax,[eax+0x90]
			mov [y],eax
			mov eax,sbjz
			mov eax,[eax]
			mov eax,[eax+0x978]
			mov eax,[eax+0x8c]
			mov [x],eax
			pop eax
			jmp ksf
	}
}

__declspec(naked) __cdecl ksf()
{
	SE_PROTECT_START();
	__asm
	{	
			mov ecx,[x]
			mov [edx+0x00003a5c],ecx
			mov ecx,[y]
			mov [edx+0x00003a60],ecx
			mov [edx+0x00003a54],1
			pop ecx
			pop edx
			mov [edi],eax
			mov ebx,[ebp+0x14]
			push 0x00a1e52a
			ret
	}
	SE_PROTECT_END();
}





__declspec(naked) __cdecl cssbf()
{
	
	__asm
	{
			mov ebx,[rwjz]
			mov ebx,[ebx]
			mov ebx,[ebx+0x000017d0]   //PID
			cmp esi,ebx
			jne RetMSRush
			mov eax,[sbjz]
			mov eax,[eax]
			mov eax,[eax+0x978]
			mov ebx,[eax+0x8c]
			mov eax,[eax+0x90]
			mov [edi-4],ebx
			RetMSRush:
			mov [edi],eax
			mov ebx,[ebp+0x14]
			push 0x00a1e52a
			ret
	}
	
}


DWORD tgbt=1;
__declspec(naked) __cdecl btgaaaa()
{
	__asm
	{	
		mov eax,[tgbt]
		push 0x00686bc0
		ret
	}
}

DWORD zddxdds=0x009bfb4c;
__declspec(naked) __cdecl zddx1()
{
	__asm
	{	
			jmp zddxdds
	}
}

__declspec(naked) __cdecl zddx2()
{
	__asm
	{	
		mov eax,1
		push 0x009bfc39
		ret
	}
}






	__declspec(naked) __cdecl jufeng()
	{
		__asm
		{
				push 0x00a7f564
				ret
		}
}


__declspec(naked) __cdecl lz()
{
	__asm
	{
			add eax,00 
			push 0x009bae8c
			ret
	}
}

DWORD sgcspdkg ,sgzbx,sgzby,xxcall=0x00525e10,sgxgJMP=0x00a21136,sgxgesp1,sgxgesp2;
__declspec(naked) __cdecl sgxg2()
{
	__asm
	{
			cmp [sgcspdkg],1
			je kssgxg
			pushad
			mov edx,dtjz
			mov edx,[edx]
			add edx,0xb0c
			mov eax,[edx]
			mov [sgzbx],eax
			add edx,0x4
			mov eax,[edx]
			mov [sgzby],eax
			popad
			mov [sgcspdkg],1
			jmp sgxgzctz
			kssgxg:
			push eax
			mov eax,ecx
			add eax,0x2e0
			mov eax,[eax]
			mov eax,0x6
			pop eax
			push eax
			mov eax,esp
			add eax,0x4
			mov eax,[eax]
			cmp eax,0x0067d43e
			pop eax
			jne sgxgzctz
			push eax
			mov eax,esp
			add eax,0x0000001c
			mov eax,[eax]
			cmp eax,0x2
			pop eax
			jne sgxgzctz
			push ecx
			mov eax,[sgzbx]
			mov [sgxgesp1],esp
			add esp,0x0c
			mov [esp],eax
			mov eax,[sgzby]
			add esp,0x4
			mov [esp],eax
			mov esp,[sgxgesp1]
			push eax
			mov ecx,0x00d06d38
			mov ecx,[ecx]
			call xxcall
			mov [sgxgesp2],esp
			add esp,0x00000020
			mov [esp],eax
			mov esp,[sgxgesp2]
			pop ecx
			sgxgzctz:
			push ebp
			mov ebp,esp
			and esp,0xffffffc0
			jmp sgxgJMP
	}
}


__declspec(naked)__cdecl sgxgzctz2()
{
	_asm
	{
			push ebp
			mov ebp,esp
			and esp,0xffffffc0
			jmp sgxgJMP
	}
	
}

__declspec(naked)__cdecl jxswyc()
{
	_asm
	{
		push 0x009c4cc3
		ret
	}
	
}


__declspec(naked)__cdecl ICS_qpgj()
{
	_asm
	{
			cmp dword ptr [esp],0x006888ee
			jne IntersectRectADD
			mov dword ptr [esp],offset qplf
			IntersectRectADD:
			jmp dword ptr [IntersectRect]
	}
	
}


__declspec(naked) __cdecl qplf()
{
	__asm
	{
		mov [esp+0x44],0xffffffff
			lea ecx,[esp+0x14]
			test eax,eax
			push 0x00688937
			ret
	}
}

DWORD wyckg=0;
DWORD jufeng_time;
DWORD jufeng_time2;
DWORD jufengwuyanchi_CALL=0x00461850;
DWORD jufengwuyanchi_CALL_1=0x00989010;
DWORD jufengwuyanchi_CALL_2=0x0043BCD0;
DWORD jufengwuyanchi_CALL_3=0x00461560;
DWORD jufengwuyanchi_CALL_4=0x004BD470;
DWORD jufengwuyanchi_CALL_5=0x00743750;
DWORD jufengwuyanchi_JMP=0x009BC8AE;

__declspec(naked) __cdecl jfwyc()
{
	SE_PROTECT_START();
	__asm
	{
			cmp dword ptr [wyckg],01
			je jufengwyc
			cmp dword ptr [wyckg],02 
			je jufeng_wuyanchi2_zhiling
			jufengwyc:		
			cmp [esp],0x009bb902
			je jufeng_fangt	
			cmp [esp],0x009baa1e
			je jufeng_wuyanchi1
			cmp [esp],0x009bd37c
			je jufeng_wuyanchi2_zhiling
			jmp wycks
			jufeng_fangt: //============防T===========
			mov eax,sjjz
			mov eax,[eax]
			mov eax,[eax+0x1C]
			cmp jufeng_time,0
			je svaeW_jufeng
			jmp retN_qidong_jufeng
			svaeW_jufeng:
			mov jufeng_time,eax
			ret
			retN_qidong_jufeng:
			mov eax,jufeng_time
			add eax,0x2710
			mov jufeng_time,eax
			ret
		
			wycks:
			mov eax,[sjjz]
			mov eax,[eax]
			mov eax,[eax+0x1c]
			ret
			jufeng_wuyanchi1://========无延迟1=========
			mov eax,sjjz
			mov eax,[eax]
			mov eax,[eax+0x1C]
			add esp,4
			mov [ebp-0x0000010c],eax
			mov ecx,[ebp-0x00001d88]
			add ecx,0x00000088
			call jufengwuyanchi_CALL
			test eax,eax
			je wuyanchije1
			mov [ebp-0x00001864],00000000
			mov [ebp-0x04],0xffffffff
			lea ecx,[ebp-0x00000190]
			call jufengwuyanchi_CALL_1
			mov eax,[ebp-0x00001864]
			jmp jufengwuyanchi_JMP
			wuyanchije1:
			mov ecx,[ebp-0x00001d88]
			add ecx,0x000017d0
			call jufengwuyanchi_CALL_2
			push eax
			call jufengwuyanchi_CALL_3
			add esp,0x04
			mov [ebp-0x000001a8],eax
			mov ecx,[ebp-0x000001a8]
			call jufengwuyanchi_CALL_4
			test eax,eax
			je wuyanchije2
			mov [ebp-0x00001868],0
			mov [ebp-0x04],0xffffffff
			lea ecx,[ebp-0x00000190]
			call jufengwuyanchi_CALL_1
			mov eax,[ebp-0x00001868]
			jmp jufengwuyanchi_JMP
			wuyanchije2:
			mov edx,[ebp-0x00000188]
			push edx
			call jufengwuyanchi_CALL_5
			add esp,04
			mov eax,0x0009bab21
			JMP eax
			
			jufeng_wuyanchi2_zhiling://========无延迟置零=========
			mov eax,0
			ret
	
	}



	SE_PROTECT_END();
}



//DWORD cxCALL=0X00cc916c;
DWORD CWxzb=0x200c0,CWyzb=0x200c4;
__declspec(naked)__cdecl chongxi()
{
	SE_PROTECT_START();
	_asm
	{
			mov eax,[esp+0x04]
			mov [CWxzb],eax
			mov eax,[esp+0x08]
			mov [CWyzb],eax
			call dword ptr [PtInRect]
			push 0x0051f73c+6
			ret
	}
	SE_PROTECT_END();
}
__declspec(naked)__cdecl chongxi_end()
	{
		_asm
		{
			call dword ptr [PtInRect]
			push 0x0051f73c+6
			ret
		}
		
}


DWORD chongxiCALL=0x00a1a320;
__declspec(naked)__cdecl xinchongxi()
{
	SE_PROTECT_START();
	__asm
	{
			push ebp
			mov ebp,esp
			push ecx
			cmp [CWxzb],0
			push ebx
			push esi
			push edi
			jne xinchongxijxtz
			cmp [CWyzb],0
			je xinchongxizctz
			xinchongxijxtz:
			mov eax,[rwjz]
			mov eax,[eax]
			mov eax,[eax+0x00002c40]
			mov eax,[eax+04]
			test eax,eax
			je xinchongxizctz
			mov eax,[eax+0x00000090]
			mov [ebp-04],eax
			test eax,eax
			je xinchongxizctz
			pushad
			mov eax,[ebp-04]
			sub eax,0x0c
			push 00
			push 00
			push 00
			push 00
			push [CWyzb]
			push [CWxzb]
			push 01
			mov ecx,eax
			mov esi,eax
			call chongxiCALL
			popad
			xinchongxizctz:
			pop edi
			pop esi
			pop ebx
			mov esp,ebp
			pop ebp
			ret


	}
	SE_PROTECT_END();
}

__declspec(naked)__cdecl xunhuangongneng()
{
	SE_PROTECT_START();
	__asm
	{
			pushad
			call xinchongxi
			popad
			xunhuanchongxizctz:
			ret

	}
	SE_PROTECT_END();
}


DWORD qpcall2=0x00464350;
__declspec(naked)__cdecl xinquanping()
{
	__asm
	{
			pushad
			mov ecx,[rwjz]
			mov ecx,[ecx]
			add ecx,4
			lea edi,[ecx+0x00001764]
			push edi
			lea ecx,[ebx+0x00000508]
			call qpcall2
			popad
			push 0x006830aa
			ret
			
	}
}



DWORD rwjianwuCALL=0x0051f380;
DWORD rwCALL=0x0042e690;
DWORD rwXzz=0x200e0;
DWORD rwYzz=0x200e4;
void DUxy()
{
	SE_PROTECT_START();
	__asm
	{

			pushad
			mov ecx,[rwjz]
			mov ecx,[ecx]
			add ecx,4
			lea esi,[ecx+0x00001764]
			lea ecx,[esi+0x0c]
			call rwCALL
			mov [rwXzz],eax
			mov ecx,esi
			mov edi,eax
			call rwCALL
			mov [rwYzz],eax
			popad
	}
	SE_PROTECT_END();
}



void ZDjianwu()
{
	SE_PROTECT_START();
	__asm
	{

		pushad
		mov edi,[0x00d091f8]
		mov edi,[edi]
		lea eax,[rwXzz]
		push  eax
		mov ecx,edi
		call rwjianwuCALL
        popad

	}
	SE_PROTECT_END();
}



