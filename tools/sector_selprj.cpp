//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("sector_selprj.res");
USEFORM("sector_sel.cpp", Form1);
USEUNIT("sector.cpp");
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
