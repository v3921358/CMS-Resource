VERSION 5.00
Object = "{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}#1.1#0"; "ieframe.dll"
Begin VB.Form Form2 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "CC制作的(防外挂测试版)"
   ClientHeight    =   5760
   ClientLeft      =   45
   ClientTop       =   330
   ClientWidth     =   8550
   Icon            =   "Form2.frx":0000
   LinkTopic       =   "Form2"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   384
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   570
   StartUpPosition =   2  '屏幕中心
   Begin VB.Frame Frame4 
      Caption         =   "游戏公告"
      Height          =   5655
      Left            =   120
      TabIndex        =   16
      Top             =   0
      Width           =   4095
      Begin SHDocVwCtl.WebBrowser Web 
         Height          =   5295
         Left            =   120
         TabIndex        =   17
         Top             =   240
         Width           =   3855
         ExtentX         =   6800
         ExtentY         =   9340
         ViewMode        =   0
         Offline         =   0
         Silent          =   0
         RegisterAsBrowser=   0
         RegisterAsDropTarget=   1
         AutoArrange     =   0   'False
         NoClientEdge    =   0   'False
         AlignLeft       =   0   'False
         NoWebView       =   0   'False
         HideFileNames   =   0   'False
         SingleClick     =   0   'False
         SingleSelection =   0   'False
         NoFolders       =   0   'False
         Transparent     =   0   'False
         ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
         Location        =   "http:///"
      End
   End
   Begin VB.Frame Frame3 
      Caption         =   "游戏说明"
      Height          =   1335
      Left            =   4320
      TabIndex        =   14
      Top             =   0
      Width           =   4095
      Begin VB.Label Label2 
         Caption         =   "顺便弄个网站的给你们吧,我看很多人都要这玩意.我觉得添加了后曾加内存的容量.所以我不建议大家用这个.如果非要用就自便吧.不防碍你们."
         Height          =   615
         Left            =   120
         TabIndex        =   18
         Top             =   600
         Width           =   3855
      End
      Begin VB.Label Label1 
         Caption         =   "建议大家生成软件后把登陆器加壳.这样方面你的登陆器不会有什么差错."
         Height          =   375
         Left            =   120
         TabIndex        =   15
         Top             =   240
         Width           =   3855
      End
   End
   Begin VB.Timer Timer2 
      Interval        =   200
      Left            =   6120
      Top             =   5280
   End
   Begin VB.CommandButton Command3 
      Caption         =   "启动游戏"
      Height          =   375
      Left            =   4560
      TabIndex        =   13
      Top             =   5280
      Width           =   1215
   End
   Begin VB.Timer Timer1 
      Left            =   6120
      Top             =   4680
   End
   Begin VB.CommandButton Command4 
      Caption         =   "隐藏程序"
      Height          =   375
      Left            =   6960
      TabIndex        =   12
      Top             =   5280
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "某某论坛"
      Height          =   375
      Left            =   6960
      TabIndex        =   11
      Top             =   4680
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "某某网站"
      Height          =   375
      Left            =   4560
      TabIndex        =   10
      Top             =   4680
      Width           =   1215
   End
   Begin VB.Frame Frame2 
      Caption         =   "游戏设置"
      Height          =   1215
      Left            =   4320
      TabIndex        =   5
      Top             =   3360
      Width           =   4095
      Begin VB.CheckBox Check4 
         Caption         =   "关闭音乐"
         Height          =   255
         Left            =   2160
         TabIndex        =   9
         Top             =   720
         Width           =   1095
      End
      Begin VB.CheckBox Check3 
         Caption         =   "关闭音效"
         Height          =   255
         Left            =   480
         TabIndex        =   8
         Top             =   720
         Width           =   1095
      End
      Begin VB.CheckBox Check2 
         Caption         =   "启动跳帧"
         Height          =   255
         Left            =   2160
         TabIndex        =   7
         Top             =   360
         Value           =   1  'Checked
         Width           =   1095
      End
      Begin VB.CheckBox Check1 
         Caption         =   "窗口模式"
         Height          =   255
         Left            =   480
         TabIndex        =   6
         Top             =   360
         Value           =   1  'Checked
         Width           =   1095
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "显卡及画质选项"
      Height          =   1935
      Left            =   4320
      TabIndex        =   0
      Top             =   1440
      Width           =   4095
      Begin VB.OptionButton Option4 
         Caption         =   "4档 高画质 高速 需要硬件D3D加速及T&&L"
         Height          =   255
         Left            =   120
         TabIndex        =   4
         Top             =   360
         Width           =   3615
      End
      Begin VB.OptionButton Option3 
         Caption         =   "3档 高画质 中速 需要硬件D3D加速"
         Height          =   255
         Left            =   120
         TabIndex        =   3
         Top             =   720
         Width           =   3255
      End
      Begin VB.OptionButton Option2 
         Caption         =   "2档 高画质 慢速 D3D软件运算模式"
         Height          =   255
         Left            =   120
         TabIndex        =   2
         Top             =   1080
         Width           =   3255
      End
      Begin VB.OptionButton Option1 
         Caption         =   "1档 低画质 高速 2D模式(无透明效果)"
         Height          =   255
         Left            =   120
         TabIndex        =   1
         Top             =   1440
         Value           =   -1  'True
         Width           =   3495
      End
   End
   Begin VB.Menu menus 
      Caption         =   "菜单"
      Visible         =   0   'False
      Begin VB.Menu mnuExit 
         Caption         =   "退出"
      End
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'本登陆器由CC本人自制.
'防外挂登陆器(原始版)
'程序作者:CC
'版权归CC所有.
'
'请大家尊重他人的劳动成果.
'本人QQ:8754347 (没什么事别加呵,如果要加的话请著名加入的理由)
'
'如果有需要可以联系我买个完整的防外挂哈.不过先说明没什么技术含量的.
'毕竟我也不是靠做登陆器吃饭的.只是混点钱过过日子而已.才刚刚高二就要出来赚钱了,我命真苦.


Option Explicit

Dim E As Long
Dim S(19) As String
Dim S1(4) As String
Dim S2(20) As String
Private Declare Function FindWindowEx Lib "user32" Alias "FindWindowExA" (ByVal hWnd1 As Long, ByVal hWnd2 As Long, ByVal lpsz1 As String, ByVal lpsz2 As String) As Long
Private Declare Function PostMessage Lib "user32" Alias "PostMessageA" (ByVal HWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Private Declare Function GetWindowText Lib "user32" Alias "GetWindowTextA" (ByVal HWnd As Long, ByVal lpString As String, ByVal cch As Long) As Long
Private Declare Function GetWindowTextLength Lib "user32" Alias "GetWindowTextLengthA" (ByVal HWnd As Long) As Long
Private Declare Function FindWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String) As Long
Private Const WM_CLOSE = &H10
Private Type PROCESSENTRY32
dwSize As Long
cntUsage As Long
th32ProcessID As Long
th32DefaultHeapID As Long
th32ModuleID As Long
cntThreads As Long
th32ParentProcessID As Long
pcPriClassBase As Long
dwFlags As Long
szExeFile As String * 260
End Type
Private Declare Function CreateToolhelp32Snapshot Lib "kernel32" (ByVal dwFlags As Long, ByVal th32ProcessID As Long) As Long
Private Declare Function Process32First Lib "kernel32" (ByVal hSnapShot As Long, lppe As PROCESSENTRY32) As Long
Private Declare Function Process32Next Lib "kernel32" (ByVal hSnapShot As Long, lppe As PROCESSENTRY32) As Long
Private Declare Function OpenProcess Lib "kernel32" (ByVal dwDesiredAccess As Long, ByVal blnheritHandle As Long, ByVal dwAppProcessId As Long) As Long
Private Declare Function TerminateProcess Lib "kernel32" (ByVal ApphProcess As Long, ByVal uExitCode As Long) As Long
Private Declare Sub CloseHandle Lib "kernel32" (ByVal hPass As Long)
Private Const TH32CS_SNAPPROCESS = &H2&
Private Sub KillProcess(sProcess As String)
Dim lSnapShot As Long
Dim lNextProcess As Long
Dim tPE As PROCESSENTRY32
lSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0&)
If lSnapShot <> -1 Then
tPE.dwSize = Len(tPE)
lNextProcess = Process32First(lSnapShot, tPE)
Do While lNextProcess
If LCase$(sProcess) = LCase$(Left(tPE.szExeFile, InStr(1, tPE.szExeFile, Chr(0)) - 1)) Then
Dim lProcess As Long
Dim lExitCode As Long
lProcess = OpenProcess(1, False, tPE.th32ProcessID)
TerminateProcess lProcess, lExitCode
CloseHandle lProcess
End If
lNextProcess = Process32Next(lSnapShot, tPE)
Loop
CloseHandle (lSnapShot)
End If
End Sub

Private Sub Command1_Click()
Shell "Explorer.exe http://www.mlysj.cn"
End Sub

Private Sub Command2_Click()
Shell "Explorer.exe http://bbs.mlysj.cn"
End Sub

'
'本提交参数是由原来我发布过的登陆器原码那直接拿过来的,之间的启动跳帧
'关闭音效、关闭音乐都无法能实现嘿.因为我也是从网上找来的.一直都没修正.
'我自己制作的提交参数就没问题.为什么我不拿我那个出来?为了方面大家习惯吧.
'毕竟你们也用过这个提交参数了.

Private Sub Command3_Click()
Dim RetVal As Long
If Dir(App.Path & "\mlysj.exe", vbDirectory) <> "" Then
    If Check1.Value = 1 Then
        If Option1.Value = True Then
            WindowState = vbMinimized
            Me.Hide
            RetVal = Shell("mlysj.exe updated graphicbin:32 graphicinfobin:32 animebin:7 animeinfobin:7 graphicbinv2:6 graphicinfobinv2:6 animebinv2:1 animeinfobinv2:1 IP:0:192.168.0.128:9020 graphicbinv3:22 graphicinfobinv3:22 animebinv3:11 animeinfobinv3:11 graphicbin_puk2:2 graphicinfobin_puk2:2 animebin_puk2:3 animeinfobin_puk2:3 graphicbin_puk3:1 graphicinfobin_puk3:1 animebin_puk3:2 animeinfobin_puk3:2 coordinatebinv3:2 coordinateinfobinv3:2 graphicbin_kw:1 graphicinfobin_kw:1 3Ddevice:1 windowmode", 1)
        ElseIf Option2.Value = True Then
            WindowState = vbMinimized
            Me.Hide
            RetVal = Shell("mlysj.exe updated graphicbin:32 graphicinfobin:32 animebin:7 animeinfobin:7 graphicbinv2:6 graphicinfobinv2:6 animebinv2:1 animeinfobinv2:1 IP:0:192.168.0.128:9020 graphicbinv3:22 graphicinfobinv3:22 animebinv3:11 animeinfobinv3:11 graphicbin_puk2:2 graphicinfobin_puk2:2 animebin_puk2:3 animeinfobin_puk2:3 graphicbin_puk3:1 graphicinfobin_puk3:1 animebin_puk3:2 animeinfobin_puk3:2 coordinatebinv3:2 coordinateinfobinv3:2 graphicbin_kw:1 graphicinfobin_kw:1 3Ddevice:2 onlyactive", 1)
        ElseIf Option3.Value = True Then
            WindowState = vbMinimized
            Me.Hide
            RetVal = Shell("mlysj.exe updated graphicbin:32 graphicinfobin:32 animebin:7 animeinfobin:7 graphicbinv2:6 graphicinfobinv2:6 animebinv2:1 animeinfobinv2:1 IP:0:192.168.0.128:9020 graphicbinv3:22 graphicinfobinv3:22 animebinv3:11 animeinfobinv3:11 graphicbin_puk2:2 graphicinfobin_puk2:2 animebin_puk2:3 animeinfobin_puk2:3 graphicbin_puk3:1 graphicinfobin_puk3:1 animebin_puk3:2 animeinfobin_puk3:2 coordinatebinv3:2 coordinateinfobinv3:2 graphicbin_kw:1 graphicinfobin_kw:1 3Ddevice:3 soundoff", 1)
        ElseIf Option4.Value = True Then
            WindowState = vbMinimized
            Me.Hide
            RetVal = Shell("mlysj.exe updated graphicbin:32 graphicinfobin:32 animebin:7 animeinfobin:7 graphicbinv2:6 graphicinfobinv2:6 animebinv2:1 animeinfobinv2:1 IP:0:192.168.0.128:9020 graphicbinv3:22 graphicinfobinv3:22 animebinv3:11 animeinfobinv3:11 graphicbin_puk2:2 graphicinfobin_puk2:2 animebin_puk2:3 animeinfobin_puk2:3 graphicbin_puk3:1 graphicinfobin_puk3:1 animebin_puk3:2 animeinfobin_puk3:2 coordinatebinv3:2 coordinateinfobinv3:2 graphicbin_kw:1 graphicinfobin_kw:1 3Ddevice:4 musicoff", 1)
        Else
            Unload Me
        End If
    
    ElseIf Check1.Value = 0 Then
        If Option1.Value = True Then
            WindowState = vbMinimized
            Me.Hide
            RetVal = Shell("mlysj.exe updated graphicbin:32 graphicinfobin:32 animebin:7 animeinfobin:7 graphicbinv2:6 graphicinfobinv2:6 animebinv2:1 animeinfobinv2:1 IP:0:192.168.0.128:9020 graphicbinv3:22 graphicinfobinv3:22 animebinv3:11 animeinfobinv3:11 graphicbin_puk2:2 graphicinfobin_puk2:2 animebin_puk2:3 animeinfobin_puk2:3 graphicbin_puk3:1 graphicinfobin_puk3:1 animebin_puk3:2 animeinfobin_puk3:2 coordinatebinv3:2 coordinateinfobinv3:2 graphicbin_kw:1 graphicinfobin_kw:1 3Ddevice:1", 1)
        ElseIf Option2.Value = True Then
            WindowState = vbMinimized
            Me.Hide
            RetVal = Shell("mlysj.exe updated graphicbin:32 graphicinfobin:32 animebin:7 animeinfobin:7 graphicbinv2:6 graphicinfobinv2:6 animebinv2:1 animeinfobinv2:1 IP:0:192.168.0.128:9020 graphicbinv3:22 graphicinfobinv3:22 animebinv3:11 animeinfobinv3:11 graphicbin_puk2:2 graphicinfobin_puk2:2 animebin_puk2:3 animeinfobin_puk2:3 graphicbin_puk3:1 graphicinfobin_puk3:1 animebin_puk3:2 animeinfobin_puk3:2 coordinatebinv3:2 coordinateinfobinv3:2 graphicbin_kw:1 graphicinfobin_kw:1 3Ddevice:2", 1)
        ElseIf Option3.Value = True Then
            WindowState = vbMinimized
            Me.Hide
            RetVal = Shell("mlysj.exe updated graphicbin:32 graphicinfobin:32 animebin:7 animeinfobin:7 graphicbinv2:6 graphicinfobinv2:6 animebinv2:1 animeinfobinv2:1 IP:0:192.168.0.128:9020 graphicbinv3:22 graphicinfobinv3:22 animebinv3:11 animeinfobinv3:11 graphicbin_puk2:2 graphicinfobin_puk2:2 animebin_puk2:3 animeinfobin_puk2:3 graphicbin_puk3:1 graphicinfobin_puk3:1 animebin_puk3:2 animeinfobin_puk3:2 coordinatebinv3:2 coordinateinfobinv3:2 graphicbin_kw:1 graphicinfobin_kw:1 3Ddevice:3", 1)
        ElseIf Option4.Value = True Then
            WindowState = vbMinimized
            Me.Hide
            RetVal = Shell("mlysj.exe updated graphicbin:32 graphicinfobin:32 animebin:7 animeinfobin:7 graphicbinv2:6 graphicinfobinv2:6 animebinv2:1 animeinfobinv2:1 IP:0:192.168.0.128:9020 graphicbinv3:22 graphicinfobinv3:22 animebinv3:11 animeinfobinv3:11 graphicbin_puk2:2 graphicinfobin_puk2:2 animebin_puk2:3 animeinfobin_puk2:3 graphicbin_puk3:1 graphicinfobin_puk3:1 animebin_puk3:2 animeinfobin_puk3:2 coordinatebinv3:2 coordinateinfobinv3:2 graphicbin_kw:1 graphicinfobin_kw:1 3Ddevice:4", 1)
        Else
            Unload Me
        End If
    Else
        WindowState = vbMinimized
    Me.Hide
            RetVal = Shell("mlysj.exe updated graphicbin:32 graphicinfobin:32 animebin:7 animeinfobin:7 graphicbinv2:6 graphicinfobinv2:6 animebinv2:1 animeinfobinv2:1 IP:0:192.168.0.128:9020 graphicbinv3:22 graphicinfobinv3:22 animebinv3:11 animeinfobinv3:11 graphicbin_puk2:2 graphicinfobin_puk2:2 animebin_puk2:3 animeinfobin_puk2:3 graphicbin_puk3:1 graphicinfobin_puk3:1 animebin_puk3:2 animeinfobin_puk3:2 coordinatebinv3:2 coordinateinfobinv3:2 graphicbin_kw:1 graphicinfobin_kw:1 3Ddevice:1 windowmode", 1)
End If
Else
MsgBox "错误：没有找到mlysj.exe文件,请将登陆放的目录下运行.", , "魔力异世界提示您"
End If
Unload Me
End Sub

Private Sub Command4_Click()
Unload Me
End Sub

Private Sub Form_Load()
App.TaskVisible = False
Call HideCurrentProcess
Web.Navigate "http://www.mlysj.cn"

S(0) = "MOLIKISS 免费版  2007/2/3"  'S(0)-S(19)这些是禁止打开的文件
S(1) = "登陆(07.01.08)修正版"
S(2) = "魔力YOYO会员VIP版(2007.07.08)修正版"
S(3) = "魔力KISS VIP收费版"
S(4) = "魔力YOYO 免费版"
S(5) = "WPE9.0"
S(6) = "YOYO[852618]"
S(7) = "超 级 兔 子  V7.99"
S(8) = "YOYO[852618]"
S(9) = "IsHelp"
S(10) = "IceSword"
S(11) = "登陆(0213)"
S(11) = "WinPatrol 看门狗＋进程猫"
S(11) = "木马杀客 V5.31 绿色特别版"
S(11) = "木马辅助查找器"
S(12) = "进程杀手 2.7"
S(13) = "快嘴进程隐藏专家"
S(14) = "窗口隐藏专家"
S(15) = "冰剑"
S(16) = "冰刃"
S(17) = "变速齿轮 0.441"
S(18) = "Select target program"
S(19) = "外挂"


S1(0) = "魔力宝贝"               'S(0)-S1(4)这些是关闭程序后自动关闭的窗口名字
S1(1) = "魔力宝贝 魔力异世界"
S1(2) = "魔力宝贝 魔力异世界 [魔力异世界1线]"
S1(3) = "IceSword"
S1(4) = "魔力宝贝 魔力异世界[魔力异世界1线]"

S2(0) = "魔力YOYO会员VIP版(2007.07.08)修正版"  'S2(0)-S1(20)发现这些窗口名字立即关闭登陆器
S2(1) = "登陆(0213)  魔力YOYO免费版"
S2(2) = "外挂"
S2(3) = "IceSword"
S2(4) = "进程终结者"
S2(5) = "进程查看器V1.0"
S2(6) = "YOYO[852618]"
S2(7) = "Windows Resizer 1.0.2 中文版"
S2(8) = "选择游戏"
S2(9) = "Windows Resizer 1.0.5 中文版"
S2(10) = "Windows Resizer 1.0.4 中文版"
S2(11) = "Select target program"
S2(12) = "进程杀手 2.7"
S2(13) = "WinPatrol 看门狗＋进程猫"
S2(14) = "木马杀客 V5.31 绿色特别版"
S2(15) = "木马辅助查找器"
S2(16) = "快嘴进程隐藏专家"
S2(17) = "窗口隐藏专家"
S2(18) = "进程杀手 2.7"
S2(19) = "冰剑"
S2(20) = "冰刃"

Timer1.Interval = 100
Timer1.Enabled = True
AddToTray Me, menus
SetTrayTip Me.Caption
End Sub

Private Sub Form_Unload(Cancel As Integer)
If E = 0 Then
   Cancel = 1
   Me.WindowState = 1
   Me.Visible = False
Else
   RemoveFromTray
   Dim H As Long, I As Long, L As Long, T As String
   Do
      H = FindWindowEx(0, H, vbNullString, vbNullString)
      L = GetWindowTextLength(H)
      T = Space(L)
      GetWindowText H, T, L + 1
      T = Left(T, L)
      For I = 0 To 4
         If T Like "*" & S1(I) & "*" Then PostMessage H, WM_CLOSE, 0, ByVal 0
      Next
   Loop Until H = 0
End If
End Sub

Private Sub mnuExit_Click()
E = 1
Unload Me
End Sub

Private Sub Timer1_Timer()
Dim H As Long, I As Long
For I = 0 To 19
   H = 0
   H = FindWindow(vbNullString, S(I))
   If H <> 0 Then
       PostMessage H, WM_CLOSE, 0, ByVal 0
   End If
Next
For I = 0 To 20
   H = 0
   H = FindWindow(vbNullString, S2(I))
   If H <> 0 Then
       mnuExit_Click
   End If
Next
End Sub
Private Sub Timer2_Timer()
Call KillProcess("YOYO.exe")   '这是进程的.发现现在进程名字直接KILL掉.
Call KillProcess("360tray.exe")
Call KillProcess("taskmgr.exe")
Call KillProcess("IceSword.exe")
Call KillProcess("MOLIKISSVIP.exe")
Call KillProcess("360Safe.exe")
Call KillProcess("KillProcess.exe")
Call KillProcess("魔力YOYO免费版.exe")
Call KillProcess("Procmon.exe")
Call KillProcess("WPE 专业版 - mlysj.exe")
Call KillProcess("魔力YOYO免费版.exe")
Call KillProcess("KISS.exe")
Call KillProcess("kiss.exe")

End Sub
