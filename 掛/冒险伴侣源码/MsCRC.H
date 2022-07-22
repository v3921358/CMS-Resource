#define JumpCall(frm, to) (int)(((int)to - (int)frm) - 5)
DWORD MsCr1 = 0x00A1D60C,JMP1 = 0x00A1D614;
DWORD MsCr2 = 0x00D108F7,JMP2 = 0x00D10EA1;
DWORD MsCr3 = 0x00DC2438,JMP3 = 0x00DC243E;
LPVOID lpvMemDump,Allocation;
int HSAddr;
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
	lea eax,[esi+ecx*4]
	cmp eax,0x00401000
	jb End
	cmp eax,0x00A31000
	ja End
	push ebx
	mov ebx,[lpvMemDump]
	add esi,ebx
	sub esi,0x00400000
	pop ebx
End:
	pop eax
	xor eax,[esi+ecx*4]
	and eax,0x000000ff
	jmp dword ptr [JMP1]
	}
}
//======================================================================================
void __declspec(naked) MSCRC2()
{
	__asm
	{
	cmp edx,0x00401000
	jb End
	cmp edx,0x00A31000
	ja Satrt
	push ebx
	mov ebx,[lpvMemDump]
	sub edx,0x00400000
	add edx,ebx
	pop ebx
Satrt:
	cmp edx,0x00DC1000
	jb End
	cmp edx,0x00DC3000
	ja End
	push ebx
	mov ebx,[Allocation]
	sub edx,0x00DC1000
	add edx,ebx
	pop ebx
End:
	push [edx]
	jmp dword ptr [JMP2]
	}
}
//======================================================================================
void __declspec(naked) MSCRC3()
{
	__asm
	{
	cmp ecx,0x00401000
	jb End
	cmp ecx,0x00A31000
	ja End
	push eax
	mov eax,[lpvMemDump]
	sub ecx,0x00400000
	add ecx,eax
	pop eax
End:
	add al,[ecx]
	pop ecx
	push ebx
	mov bh,0x35
	jmp dword ptr [JMP3]
   }
}
//======================================================================================
void __declspec(naked) HSCRC()
{
try{
	__asm
	{
	pushad
	mov eax,HSAddr
	mov ebx,0xD08B1E8A   //还原hs 
	mov [eax],ebx
	add eax,4
	mov ebx,0x00FFE281   //还原hs 
	mov [eax],ebx
	popad
	}
	while(FindWindow("MapleStoryClass","MapleStory")){Sleep(5000);}}
catch(...){}
	ExitProcess(0);
}
//======================================================================================
void CRCBypass()
{
try{
//======================================================================================
	while(!*(PWORD)0x00CC1C00){Sleep(500);}
	HSAddr = (int)GetModuleHandle("ehsvc.dll")+0x27C2;
	Jump(HSAddr,HSCRC,3);
//======================================================================================
	int lpvMsCRC1 = 0x640000,lpvMsCRC2 = 0x2000;
	lpvMemDump = VirtualAlloc(NULL,lpvMsCRC1,MEM_COMMIT,PAGE_EXECUTE_READWRITE);
	MakeMemoryWritable(0x00400000,lpvMsCRC1);
	memcpy((void*)lpvMemDump,(void*)0x00400000,lpvMsCRC1);
//======================================================================================
	Allocation = VirtualAlloc(NULL,lpvMsCRC2,MEM_COMMIT,PAGE_EXECUTE_READWRITE);
	MakeMemoryWritable(0x00DC1000,lpvMsCRC2);
	memcpy((void*)Allocation,(void*)0x00DC1000,lpvMsCRC2);
//	*(PWORD)0x00CC1C18=10;
	Sleep(1000);
//======================================================================================
	Jump(MsCr1,MSCRC1,3);
	Jump(MsCr2,MSCRC2,2);
	Jump(MsCr3,MSCRC3,1);
//======================================================================================
}
catch(...){}
//__except (EXCEPTION_EXECUTE_HANDLER) {}
ExitThread(0);
}