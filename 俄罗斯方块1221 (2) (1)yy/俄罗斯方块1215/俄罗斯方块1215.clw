; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSJKDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "俄罗斯方块1215.h"
LastPage=0

ClassCount=7
Class1=CMy1215App
Class2=CMy1215Doc
Class3=CMy1215View
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_DIALOG1
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CZHUCEDLG
Resource3=IDD_ABOUTBOX
Class7=CSJKDlg
Resource4=IDD_DIALOG2

[CLS:CMy1215App]
Type=0
HeaderFile=俄罗斯方块1215.h
ImplementationFile=俄罗斯方块1215.cpp
Filter=N

[CLS:CMy1215Doc]
Type=0
HeaderFile=俄罗斯方块1215Doc.h
ImplementationFile=俄罗斯方块1215Doc.cpp
Filter=N

[CLS:CMy1215View]
Type=0
HeaderFile=俄罗斯方块1215View.h
ImplementationFile=俄罗斯方块1215View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_SCORE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=俄罗斯方块1215.cpp
ImplementationFile=俄罗斯方块1215.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_M_QUICK
Command18=ID_M_MEDIUMEN
Command19=ID_M_SLOW
Command20=ID_M_START
Command21=ID_M_STOP
Command22=ID_M_END
Command23=ID_M_ZHUCE
Command24=ID_SCORE
CommandCount=24

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CZHUCEDLG
ControlCount=5
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_BUTTON1,button,1342242816

[CLS:CZHUCEDLG]
Type=0
HeaderFile=ZHUCEDLG.h
ImplementationFile=ZHUCEDLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CZHUCEDLG

[DLG:IDD_DIALOG2]
Type=1
Class=CSJKDlg
ControlCount=3
Control1=IDC_LIST4,SysListView32,1350631441
Control2=IDC_BUTTON_DELETE,button,1342242816
Control3=IDC_BUTTON_SHOWALL,button,1342242816

[CLS:CSJKDlg]
Type=0
HeaderFile=SJKDlg.h
ImplementationFile=SJKDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSJKDlg
VirtualFilter=dWC

