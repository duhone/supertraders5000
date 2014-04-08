# Microsoft Developer Studio Project File - Name="super trader 5000" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=super trader 5000 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "super trader 5000.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "super trader 5000.mak" CFG="super trader 5000 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "super trader 5000 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "super trader 5000 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "super trader 5000 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "super trader 5000 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /version:0.3 /subsystem:windows /profile /debug /machine:I386

!ENDIF 

# Begin Target

# Name "super trader 5000 - Win32 Release"
# Name "super trader 5000 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\beam_weapon.cpp
# End Source File
# Begin Source File

SOURCE=.\cargo.cpp
# End Source File
# Begin Source File

SOURCE=.\character.cpp
# End Source File
# Begin Source File

SOURCE=".\current info.cpp"
# End Source File
# Begin Source File

SOURCE=.\cursor_class.cpp
# End Source File
# Begin Source File

SOURCE=.\graphic_object.cpp
# End Source File
# Begin Source File

SOURCE=".\missle weapon.cpp"
# End Source File
# Begin Source File

SOURCE=.\MUSIC.cpp
# End Source File
# Begin Source File

SOURCE=.\niobject.cpp
# End Source File
# Begin Source File

SOURCE=.\niobjectlist.cpp
# End Source File
# Begin Source File

SOURCE=.\noorbitniobject.cpp
# End Source File
# Begin Source File

SOURCE=.\onestar.cpp
# End Source File
# Begin Source File

SOURCE=.\orbitniobject.cpp
# End Source File
# Begin Source File

SOURCE=.\planet.cpp
# End Source File
# Begin Source File

SOURCE=.\player.cpp
# End Source File
# Begin Source File

SOURCE=.\power_plant.cpp
# End Source File
# Begin Source File

SOURCE=".\projectile list.cpp"
# End Source File
# Begin Source File

SOURCE=.\projectile.cpp
# End Source File
# Begin Source File

SOURCE=.\sector.cpp
# End Source File
# Begin Source File

SOURCE=.\ship.cpp
# End Source File
# Begin Source File

SOURCE=".\solar system.cpp"
# End Source File
# Begin Source File

SOURCE=.\starfeild.cpp
# End Source File
# Begin Source File

SOURCE=".\super trader 5000.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Ai_engine_dll.h
# End Source File
# Begin Source File

SOURCE=.\AI_INTERFACE.H
# End Source File
# Begin Source File

SOURCE=.\beam_weapon.h
# End Source File
# Begin Source File

SOURCE=.\cargo.h
# End Source File
# Begin Source File

SOURCE=.\character.h
# End Source File
# Begin Source File

SOURCE=".\current info.h"
# End Source File
# Begin Source File

SOURCE=.\cursor_class.h
# End Source File
# Begin Source File

SOURCE=.\Display.h
# End Source File
# Begin Source File

SOURCE=.\graphic_object.h
# End Source File
# Begin Source File

SOURCE=.\input.h
# End Source File
# Begin Source File

SOURCE=".\missle weapon.h"
# End Source File
# Begin Source File

SOURCE=.\MMEngine.h
# End Source File
# Begin Source File

SOURCE=.\music.h
# End Source File
# Begin Source File

SOURCE=.\niobject.h
# End Source File
# Begin Source File

SOURCE=.\niobjectlist.h
# End Source File
# Begin Source File

SOURCE=.\noorbitniobject.h
# End Source File
# Begin Source File

SOURCE=.\onestar.h
# End Source File
# Begin Source File

SOURCE=.\orbitniobject.h
# End Source File
# Begin Source File

SOURCE=.\planet.h
# End Source File
# Begin Source File

SOURCE=.\player.h
# End Source File
# Begin Source File

SOURCE=.\power_plant.h
# End Source File
# Begin Source File

SOURCE=".\projectile list.h"
# End Source File
# Begin Source File

SOURCE=.\projectile.h
# End Source File
# Begin Source File

SOURCE=.\sector.h
# End Source File
# Begin Source File

SOURCE=.\ship.h
# End Source File
# Begin Source File

SOURCE=".\solar system.h"
# End Source File
# Begin Source File

SOURCE=.\Sound.h
# End Source File
# Begin Source File

SOURCE=.\starfield.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\input.lib
# End Source File
# Begin Source File

SOURCE=.\MMEngine.lib
# End Source File
# Begin Source File

SOURCE=.\AI_ENGINE.lib
# End Source File
# End Target
# End Project
