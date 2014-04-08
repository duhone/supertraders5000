//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "pic.h"
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
    animationstrings = new TStringList;

    mainfile = "C:\\";
    char temp2[1024];

// Setup Current directory
    getcurdir(3, temp2);
    AnsiString tempstring = temp2;
    directoryname = "C:\\" + tempstring + "\\";

//set up name of hpt file
    mainfile += temp2;
    mainfile += "\\piclist.hpt";
    piccount = 0;


//give default values to all pictures
    for(int count = 0;count < 512;count++)
      filenames[count] = "";
 for(int count = 0;count < 512;count++)
 {
    texresalution[count] = 0;
 }
 for(int count = 0;count < 512;count++)
 {
    framesanimation[count] = 0;
 }

//load info from file using memory mapped files
 filehandle = CreateFile(mainfile.c_str(),GENERIC_READ,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
 filemaphandle = CreateFileMapping(filehandle,NULL,PAGE_READONLY,0,0,NULL);
 filepointer = MapViewOfFile(filemaphandle,FILE_MAP_READ,0,0,0);
 if(filepointer != NULL)
 {
  char* temp = (char*)filepointer;
  for(int count1 = 0;count1 < 512;count1++)
  {
        strcpy(temp2,temp);
        filenames[count1] = temp2;
      temp+= strlen(temp2) + 1;
      texresalution[count1] = *((int*)temp);
      temp += 4;
      framesanimation[count1] = *((int*)temp);
      temp += 4;


  }
 }
 UnmapViewOfFile(filepointer);
 CloseHandle(filemaphandle);
 CloseHandle(filehandle);

//add directory information to selections
  for(int count1 = 0;count1 < 512;count1++)
 {
    filenames[count1] = "C:\\" + tempstring + "\\" + filenames[count1];
 }
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//open file dialog and get new selection form user
    if(openpic->Execute())
    {
      Label1->Caption = openpic->FileName;
      filenames[piccount] = openpic->FileName;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 //calculate the neccesary size of the file to store all data in
 int filelength = 0;
 for(int count1 = 0;count1 < 512;count1++)
 {
   filelength +=  filenames[count1].Length() + 1;
 }
 filelength += (512*4)*2;
 filelength++;
 AnsiString tempstring;
 int tempstringindex;
//reset file to 4 bytes to insure file is no larger than neccesary
 int handle;
 handle = open(mainfile.c_str(),O_TRUNC | O_RDWR | O_BINARY);
 chsize(handle, 4);
 close(handle);
//save all info into memory mapped file
 filehandle = CreateFile(mainfile.c_str(),GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
 filemaphandle = CreateFileMapping(filehandle,NULL,PAGE_READWRITE,0,filelength,NULL);
 filepointer = MapViewOfFile(filemaphandle,FILE_MAP_WRITE,0,0,0);
 char* temp = (char*)filepointer;
 char* temp2;
 for(int count1 = 0;count1 < 512;count1++)
 {
        tempstringindex = filenames[count1].LastDelimiter("\\");
        tempstring = filenames[count1].SubString(tempstringindex+1,(filenames[count1].Length() - tempstringindex));
        temp2 = tempstring.c_str();
        strcpy(temp,temp2);
        temp += strlen(temp2)+1;
        *((int*)temp) = texresalution[count1];
        temp += 4;
        *((int*)temp) = framesanimation[count1];
        temp += 4;
 }
 UnmapViewOfFile(filepointer);
 CloseHandle(filemaphandle);
 CloseHandle(filehandle);
 delete animationstrings;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::resalution_boxChange(TObject *Sender)
{
//change to new resalution user has specified
    texresalution[piccount] = resalution_box->ItemIndex;
    resetframes();
}
//---------------------------------------------------------------------------

void TForm1::resetframes()
{
//reset the frame box to allowable number of frames based on tex resalution
  frame1button->Enabled = false;
    frame4button->Enabled = false;
    frame16button->Enabled = false;
    frame64button->Enabled = false;
    frame256button->Enabled = false;

    if(texresalution[piccount] <= 4)
       frame1button->Enabled = true;
    if(texresalution[piccount] <= 3)
       frame4button->Enabled = true;
    if(texresalution[piccount] <= 2)
       frame16button->Enabled = true;
    if(texresalution[piccount] <= 1)
       frame64button->Enabled = true;
    if(texresalution[piccount] <= 0)
       frame256button->Enabled = true;

    if(framesanimation[piccount] > (4-texresalution[piccount]))
         framesanimation[piccount] = (4-texresalution[piccount]);
    if(framesanimation[piccount] == 0) frame1button->Checked = true;
    if(framesanimation[piccount] == 1) frame4button->Checked = true;
    if(framesanimation[piccount] == 2) frame16button->Checked = true;
    if(framesanimation[piccount] == 3) frame64button->Checked = true;
    if(framesanimation[piccount] == 4) frame256button->Checked = true;


}

void __fastcall TForm1::FormActivate(TObject *Sender)
{
 



//set up some additional start up values
  Label1->Caption = filenames[piccount];
  resalution_box->ItemIndex = texresalution[piccount];
  resetframes();
  openpic->InitialDir = directoryname;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
 piccount = UpDown1->Position;
 Label1->Caption = filenames[piccount];
 resalution_box->ItemIndex = texresalution[piccount];
 resetframes();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::frame1buttonClick(TObject *Sender)
{
    framesanimation[piccount] = 0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::frame4buttonClick(TObject *Sender)
{
        framesanimation[piccount] = 1;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::frame16buttonClick(TObject *Sender)
{
    framesanimation[piccount] = 2;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::frame64buttonClick(TObject *Sender)
{
        framesanimation[piccount] = 3;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::frame256buttonClick(TObject *Sender)
{
       framesanimation[piccount] = 4;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::deletebuttonClick(TObject *Sender)
{
      Label1->Caption = directoryname;
      filenames[piccount] = directoryname;
      framesanimation[piccount] = 0;
      texresalution[piccount] = 0;
      resalution_box->ItemIndex = 0;
      resetframes();
}
//---------------------------------------------------------------------------

