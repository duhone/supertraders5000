//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("window_tool.res");
USEFORM("window.cpp", Form1);
USEUNIT("onewindow.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
