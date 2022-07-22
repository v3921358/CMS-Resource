Attribute VB_Name = "APIStuff"
Option Explicit

Public OldWindowProc As Long
Public TheForm As Form
Public TheMenu As Menu

Declare Function CallWindowProc Lib "user32" Alias "CallWindowProcA" (ByVal lpPrevWndFunc As Long, ByVal HWnd As Long, ByVal Msg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function SetWindowLong Lib "user32" Alias "SetWindowLongA" (ByVal HWnd As Long, ByVal nIndex As Long, ByVal dwNewLong As Long) As Long
Declare Function Shell_NotifyIcon Lib "shell32.dll" Alias "Shell_NotifyIconA" (ByVal dwMessage As Long, lpData As NOTIFYICONDATA) As Long

Public Const WM_USER = &H400
Public Const WM_LBUTTONUP = &H202
Public Const WM_MBUTTONUP = &H208
Public Const WM_RBUTTONUP = &H205
Public Const TRAY_CALLBACK = (WM_USER + 1001&)
Public Const GWL_WNDPROC = (-4)
Public Const GWL_USERDATA = (-21)
Public Const NIF_ICON = &H2
Public Const NIF_TIP = &H4
Public Const NIM_ADD = &H0
Public Const NIF_MESSAGE = &H1
Public Const NIM_MODIFY = &H1
Public Const NIM_DELETE = &H2

'记录 设置托盘图标的数据 的数据类型NOTIFYICONDATA
Public Type NOTIFYICONDATA
    cbSize As Long  '需填入NOTIFYICONDATA数据结构的长度
    HWnd As Long    '设置成窗口的句柄
    Uid As Long     '为图标所设置的ID值
    UFlags As Long  '用来设置以下三个参数uCallbackMessage、hIcon、szTip是否有效
    UCallbackMessage As Long     '消息编号
    HIcon As Long      '显示在状态栏上的图标
    SzTip As String * 64    '提示信息
End Type

'TheData变量记录设置托盘图标的数据
Private TheData As NOTIFYICONDATA

Public Function NewWindowProc(ByVal HWnd As Long, ByVal Msg As Long, _
    ByVal wParam As Long, ByVal lParam As Long) As Long
    
    '如果用户点击了托盘中的图标，则进行判断是点击了左键还是右键
    If Msg = TRAY_CALLBACK Then
        '如果点击了左键
        If lParam = WM_LBUTTONUP Then
            If TheForm.WindowState = 0 Then
               TheForm.WindowState = 1
               TheForm.Visible = False
            Else
               TheForm.Visible = True
               TheForm.WindowState = 0
               TheForm.SetFocus
            End If
            Exit Function
        End If
        '如果点击了右键
        If lParam = WM_RBUTTONUP Then
            TheForm.PopupMenu TheMenu
            Exit Function
        End If
    End If
    
    '如果是其他类型的消息则传递给原有默认的窗口函数
    NewWindowProc = CallWindowProc(OldWindowProc, HWnd, Msg, wParam, lParam)
End Function
' *********************************************
' 把主窗体的图标（Form1.icon属性可改变）添加到托盘中
' *********************************************
Public Sub AddToTray(frm As Form, mnu As Menu)

    '保存当前窗体和菜单信息
    Set TheForm = frm
    Set TheMenu = mnu
    
    'GWL_WNDPROC获得该窗口的窗口函数的地址
    OldWindowProc = SetWindowLong(frm.HWnd, GWL_WNDPROC, AddressOf NewWindowProc)

    '将主窗体图标添加在托盘中
    With TheData
        .Uid = 0    '忘了吗？参考一下前面内容,Uid图标的序号，做动画图标有用
        .HWnd = frm.HWnd
        .cbSize = Len(TheData)
        .HIcon = frm.Icon.Handle
        .UFlags = NIF_ICON                  '指明要对图标进行设置
        .UCallbackMessage = TRAY_CALLBACK
        .UFlags = .UFlags Or NIF_MESSAGE    '指明要设置图标或返回信息给主窗体，此句不能省去
        .cbSize = Len(TheData)              '为什么呢？我们需要在添加图标的同时，让其返回信息
    End With                                '给主窗体，Or的意思是同时进行设置和返回消息
    Shell_NotifyIcon NIM_ADD, TheData       '根据前面定义NIM_ADD，设置为“添加模式”
End Sub

Public Sub RemoveFromTray()
    '删除托盘中的图标
    With TheData
        .UFlags = 0
    End With
    Shell_NotifyIcon NIM_DELETE, TheData   '根据前面定义NIM_DELETE，设置为“删除模式”
    
    '恢复原有的设置
    SetWindowLong TheForm.HWnd, GWL_WNDPROC, OldWindowProc
End Sub

Public Sub SetTrayTip(tip As String)
    With TheData
        .SzTip = tip & vbNullChar
        .UFlags = NIF_TIP   '指明要对浮动提示进行设置
    End With
    Shell_NotifyIcon NIM_MODIFY, TheData    '根据前面定义NIM_MODIFY，设置为“修改模式”
End Sub
