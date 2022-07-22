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

'��¼ ��������ͼ������� ����������NOTIFYICONDATA
Public Type NOTIFYICONDATA
    cbSize As Long  '������NOTIFYICONDATA���ݽṹ�ĳ���
    HWnd As Long    '���óɴ��ڵľ��
    Uid As Long     'Ϊͼ�������õ�IDֵ
    UFlags As Long  '��������������������uCallbackMessage��hIcon��szTip�Ƿ���Ч
    UCallbackMessage As Long     '��Ϣ���
    HIcon As Long      '��ʾ��״̬���ϵ�ͼ��
    SzTip As String * 64    '��ʾ��Ϣ
End Type

'TheData������¼��������ͼ�������
Private TheData As NOTIFYICONDATA

Public Function NewWindowProc(ByVal HWnd As Long, ByVal Msg As Long, _
    ByVal wParam As Long, ByVal lParam As Long) As Long
    
    '����û�����������е�ͼ�꣬������ж��ǵ������������Ҽ�
    If Msg = TRAY_CALLBACK Then
        '�����������
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
        '���������Ҽ�
        If lParam = WM_RBUTTONUP Then
            TheForm.PopupMenu TheMenu
            Exit Function
        End If
    End If
    
    '������������͵���Ϣ�򴫵ݸ�ԭ��Ĭ�ϵĴ��ں���
    NewWindowProc = CallWindowProc(OldWindowProc, HWnd, Msg, wParam, lParam)
End Function
' *********************************************
' ���������ͼ�꣨Form1.icon���Կɸı䣩��ӵ�������
' *********************************************
Public Sub AddToTray(frm As Form, mnu As Menu)

    '���浱ǰ����Ͳ˵���Ϣ
    Set TheForm = frm
    Set TheMenu = mnu
    
    'GWL_WNDPROC��øô��ڵĴ��ں����ĵ�ַ
    OldWindowProc = SetWindowLong(frm.HWnd, GWL_WNDPROC, AddressOf NewWindowProc)

    '��������ͼ�������������
    With TheData
        .Uid = 0    '�����𣿲ο�һ��ǰ������,Uidͼ�����ţ�������ͼ������
        .HWnd = frm.HWnd
        .cbSize = Len(TheData)
        .HIcon = frm.Icon.Handle
        .UFlags = NIF_ICON                  'ָ��Ҫ��ͼ���������
        .UCallbackMessage = TRAY_CALLBACK
        .UFlags = .UFlags Or NIF_MESSAGE    'ָ��Ҫ����ͼ��򷵻���Ϣ�������壬�˾䲻��ʡȥ
        .cbSize = Len(TheData)              'Ϊʲô�أ�������Ҫ�����ͼ���ͬʱ�����䷵����Ϣ
    End With                                '�������壬Or����˼��ͬʱ�������úͷ�����Ϣ
    Shell_NotifyIcon NIM_ADD, TheData       '����ǰ�涨��NIM_ADD������Ϊ�����ģʽ��
End Sub

Public Sub RemoveFromTray()
    'ɾ�������е�ͼ��
    With TheData
        .UFlags = 0
    End With
    Shell_NotifyIcon NIM_DELETE, TheData   '����ǰ�涨��NIM_DELETE������Ϊ��ɾ��ģʽ��
    
    '�ָ�ԭ�е�����
    SetWindowLong TheForm.HWnd, GWL_WNDPROC, OldWindowProc
End Sub

Public Sub SetTrayTip(tip As String)
    With TheData
        .SzTip = tip & vbNullChar
        .UFlags = NIF_TIP   'ָ��Ҫ�Ը�����ʾ��������
    End With
    Shell_NotifyIcon NIM_MODIFY, TheData    '����ǰ�涨��NIM_MODIFY������Ϊ���޸�ģʽ��
End Sub
