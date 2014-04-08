//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "sector_sel.h"
#include "sector.h"
#include<math.h>
#include<dir.h>
#include<io.h>
#include <fcntl.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   sectors = new sector[20];
    mainfile = new AnsiString;
    *mainfile = "C:\\";
    char temp2[1024];

// Setup Current directory
    getcurdir(3, temp2);
    AnsiString tempstring = temp2;
    directoryname = "C:\\" + tempstring + "\\";

//set up name of hpt file
    *mainfile += temp2;
    *mainfile += "\\niseclist.hpt";


    currentsector = 0;
    currentobject = 0;
    sectorupdn->Position = (short)currentsector;

   //load info from file using memory mapped files
 filehandle = CreateFile((*mainfile).c_str(),GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
 filemaphandle = CreateFileMapping(filehandle,NULL,PAGE_READONLY,0,0,NULL);
 filepointer = MapViewOfFile(filemaphandle,FILE_MAP_READ,0,0,0);
 void* tempfilepntr = filepointer;
 if(filepointer != NULL)
 {
    for(int count = 0;count < 20;count++)
    {
        numobjpersec[count] = *((int*)tempfilepntr);
        sectors[count].readinfo(tempfilepntr);
    }
  }
 else
 {
   //no memory mapped file exist so set to default setup
   for(int count = 0;count < 20;count++)
    {
        numobjpersec[count] = 1;
    }
    for(int count = 0;count < 20;count++)
    {
      sectors[count].addobject();
     }
 }
 UnmapViewOfFile(filepointer);
 CloseHandle(filemaphandle);
 CloseHandle(filehandle);
 

   objectnumberupdn->Max = (short)(numobjpersec[currentsector] - 1);
   resetobjparams();
}
//---------------------------------------------------------------------------













void __fastcall TForm1::currentsectorboxChange(TObject *Sender)
//change to new sector
{
    currentsector = sectorupdn->Position;
    objectnumberupdn->Max = (short)(numobjpersec[currentsector] - 1);
    objectnumberupdn->Position = 0;
    resetobjparams();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::addobjectbutClick(TObject *Sender)
//add a new object to current sector
{
  objectnumberupdn->Max += (short)1;
  objectnumberupdn->Position =  objectnumberupdn->Max;
  numobjpersec[currentsector]++;
  sectors[currentsector].addobject();
    resetobjparams();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::deleteobjectClick(TObject *Sender)
//deletes the currently selected object
{
  if(numobjpersec[currentsector] > 0)
  {
    objectnumberupdn->Max -= (short)1;
    numobjpersec[currentsector]--;
    sectors[currentsector].deleteobject(currentobject);
    if(currentobject > objectnumberupdn->Max)
    {
        currentobject = objectnumberupdn->Max;
        objectnumberupdn->Position =  objectnumberupdn->Max;
    }
   }
    resetobjparams();

}
//---------------------------------------------------------------------------

void TForm1::resetobjparams()
//reset values in entire form for when the current object has changed
{
     typebox->Checked = sectors[currentsector].getorbitmode(currentobject);
     xposscroll->Position = sectors[currentsector].getxposition(currentobject) * 10.0;
     xposedit->Text = xposscroll->Position/10.0;
     yposscroll->Position = sectors[currentsector].getyposition(currentobject) * 10.0;
     yposedit->Text = yposscroll->Position/10.0;
     xorbitscroll->Position = sectors[currentsector].getxorbit(currentobject) * 10.0;
     xorbitbox->Text = xorbitscroll->Position/10.0;
     yorbitscroll->Position = sectors[currentsector].getyorbit(currentobject) * 10.0;
     yorbitbox->Text = yorbitscroll->Position/10.0;
     xsizescroll->Position = sectors[currentsector].getxsize(currentobject) * 10.0;
     xsizeedit->Text = xsizescroll->Position/10.0;
     ysizescroll->Position = sectors[currentsector].getysize(currentobject) * 10.0;
     ysizeedit->Text = ysizescroll->Position/10.0;
     palletescroll->Position = sectors[currentsector].getpallete(currentobject);
     palleteedit->Text = palletescroll->Position;
     gravityscroll->Position = sectors[currentsector].getgravity(currentobject) * 10.0;
     gravityedit->Text = gravityscroll->Position/10.0;
     int r,g,b,a;
     sectors[currentsector].getcolor1(currentobject,r,g,b,a);
     red1updn->Position = (short)r;
     green1updn->Position = (short)g;
     blue1updn->Position = (short)b;
     alpha1updn->Position = (short)a;
     sectors[currentsector].getcolor2(currentobject,r,g,b,a);
     red2updn->Position = (short)r;
     green2updn->Position = (short)g;
     blue2updn->Position = (short)b;
     alpha2updn->Position = (short)a;
     sectors[currentsector].getcolor3(currentobject,r,g,b,a);
     red3updn->Position = (short)r;
     green3updn->Position = (short)g;
     blue3updn->Position = (short)b;
     alpha3updn->Position = (short)a;
     sectors[currentsector].getcolor4(currentobject,r,g,b,a);
     red4updn->Position = (short)r;
     green4updn->Position = (short)g;
     blue4updn->Position = (short)b;
     alpha4updn->Position = (short)a;
     speedscroll->Position = sectors[currentsector].getspeed(currentobject) * 10.0;
     speededit->Text = speedscroll->Position/10.0;
     rotationscroll->Position = sectors[currentsector].getrotspeed(currentobject) * 10.0;
     rotationedit->Text = rotationscroll->Position/10.0;
 }

void __fastcall TForm1::xposscrollChange(TObject *Sender)
{
     sectors[currentsector].setxposition(currentobject,(xposscroll->Position/10.0));
     xposedit->Text = xposscroll->Position/10.0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::objectnumberboxChange(TObject *Sender)
{
    currentobject = objectnumberupdn->Position;
    resetobjparams();


}
//---------------------------------------------------------------------------

void __fastcall TForm1::yposscrollChange(TObject *Sender)
{
     sectors[currentsector].setyposition(currentobject,(yposscroll->Position/10.0));
     yposedit->Text = yposscroll->Position/10.0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::xorbitscrollChange(TObject *Sender)
{
     sectors[currentsector].setxorbit(currentobject,(xorbitscroll->Position/10.0));
     xorbitbox->Text = xorbitscroll->Position/10.0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::yorbitscrollChange(TObject *Sender)
{
     sectors[currentsector].setyorbit(currentobject,(yorbitscroll->Position/10.0));
     yorbitbox->Text = yorbitscroll->Position/10.0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::xsizescrollChange(TObject *Sender)
{
     sectors[currentsector].setxsize(currentobject,(xsizescroll->Position/10.0));
     xsizeedit->Text = xsizescroll->Position/10.0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ysizescrollChange(TObject *Sender)
{
     sectors[currentsector].setysize(currentobject,(ysizescroll->Position/10.0));
     ysizeedit->Text = ysizescroll->Position/10.0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::palletescrollChange(TObject *Sender)
{
     sectors[currentsector].setpallete(currentobject,(palletescroll->Position));
     palleteedit->Text = palletescroll->Position;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::gravityscrollChange(TObject *Sender)
{
     sectors[currentsector].setgravity(currentobject,(gravityscroll->Position/10.0));
     gravityedit->Text = gravityscroll->Position/10.0;

}
//---------------------------------------------------------------------------


void __fastcall TForm1::color1change(TObject *Sender)
{
    sectors[currentsector].setcolor1(currentobject,red1updn->Position,green1updn->Position,blue1updn->Position,alpha1updn->Position);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::color2change(TObject *Sender)
{
     sectors[currentsector].setcolor2(currentobject,red2updn->Position,green2updn->Position,blue2updn->Position,alpha2updn->Position);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::color3change(TObject *Sender)
{
     sectors[currentsector].setcolor3(currentobject,red3updn->Position,green3updn->Position,blue3updn->Position,alpha3updn->Position);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::color4change(TObject *Sender)
{
     sectors[currentsector].setcolor4(currentobject,red4updn->Position,green4updn->Position,blue4updn->Position,alpha4updn->Position);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::speedscrollChange(TObject *Sender)
{
     sectors[currentsector].setspeed(currentobject,(speedscroll->Position/10.0));
     speededit->Text = speedscroll->Position/10.0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
int filelength = 0;
for(int count = 0;count < 20;count++)
{
    filelength += numobjpersec[count];
}
filelength *= (27*4);
filelength += (20*4);

//reset file to 4 bytes to insure file is no larger than neccesary
 int handle;
 handle = open((*mainfile).c_str(),O_TRUNC | O_RDWR | O_BINARY);
 if(handle != -1)
 {
        chsize(handle, 4);
        close(handle);
 }

 //save all info into memory mapped file
 filehandle = CreateFile((*mainfile).c_str(),GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
 filemaphandle = CreateFileMapping(filehandle,NULL,PAGE_READWRITE,0,filelength,NULL);
 filepointer = MapViewOfFile(filemaphandle,FILE_MAP_WRITE,0,0,0);
 void* tempfilepntr = filepointer;
 for(int count = 0;count < 20;count++)
 {
      sectors[count].writeinfo(tempfilepntr);
 }
 UnmapViewOfFile(filepointer);
 CloseHandle(filemaphandle);
 CloseHandle(filehandle);
 delete mainfile;
 delete[] sectors;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rotationscrollChange(TObject *Sender)
{
     sectors[currentsector].setrotspeed(currentobject,(rotationscroll->Position/10.0));
     rotationedit->Text = rotationscroll->Position/10.0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::typeboxClick(TObject *Sender)
//reset form for new type of object (orbit or not orbit)
{
        if(typebox->Checked)
        {
                Label7->Caption = "Orbit Position";
                Label8->Caption = "X";
                Label9->Caption = "Y";
                Label7->Left = 424;
                xorbitscroll->Max = 10000;
                yorbitbox->Enabled = true;
                yorbitscroll->Enabled = true;
                sectors[currentsector].setorbitmode(currentobject,true);

        }
        else
        {
                Label7->Caption = "Object Direction";
                char temp[2];
                temp[0] = 233;
                temp[1] = 0;
                Label8->Caption = temp;
                Label9->Caption = "";
                Label7->Left = 333;
                xorbitscroll->Max = 3600;
                yorbitbox->Enabled = false;
                yorbitscroll->Enabled = false;
                sectors[currentsector].setorbitmode(currentobject,false);

       }
}
//---------------------------------------------------------------------------

