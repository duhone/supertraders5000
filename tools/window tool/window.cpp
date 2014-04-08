//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "window.h"
#include "onewindow.h"
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

void TForm1::update_form()
{
  one_window *temp;
  temp = (one_window*)window_list->Items[current_window-1];
  parent_window_scroll->Position = temp->getparent_window();
  pallette_scroll->Position = temp->getpallette_number();
  message_scroll->Position = temp->getmessage_number();
  arg_scroll->Position = temp->getmessage_arg();

  xloc_edit->Text = temp->getxoffset();
  yloc_edit->Text = temp->getyoffset();
  xscale_edit->Text = temp->getxscale();
  yscale_edit->Text = temp->getyscale();
  
}

void TForm1::super_update()
{
   one_window *temp;
  temp = (one_window*)window_list->Items[current_window-1];

  xloc_scroll->Position = temp->getxoffset() * 100;
  yloc_scroll->Position = temp->getyoffset() * 100;
  xscale_scroll->Position = temp->getxscale() * 100;
  yscale_scroll->Position = temp->getyscale() * 100;

  parent_window_scroll->Position = temp->getparent_window();
  pallette_scroll->Position = temp->getpallette_number();
  message_scroll->Position = temp->getmessage_number();
  arg_scroll->Position = temp->getmessage_arg();
  
}
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        current_window = 1;
        window_list = new TList;
        one_window *temp = new one_window;
        window_list->Add(temp);
        update_form();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
        one_window *temp;
        for(int count = 0;count < window_list->Count;count++)
        {
                temp = (one_window*)window_list->Items[count];
                delete temp;
        }
        delete window_list;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::xloc_scrollChange(TObject *Sender)
{
   one_window *temp;
   temp = (one_window*)window_list->Items[current_window-1];
   temp->setxoffset(((xloc_scroll->Position)/100.0));
   update_form();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::yloc_scrollChange(TObject *Sender)
{
     one_window *temp;
   temp = (one_window*)window_list->Items[current_window-1];
   temp->setyoffset(((yloc_scroll->Position)/100.0));
   update_form();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::xscale_scrollChange(TObject *Sender)
{
       one_window *temp;
   temp = (one_window*)window_list->Items[current_window-1];
   temp->setxscale(((xscale_scroll->Position)/100.0));
   update_form();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::yscale_scrollChange(TObject *Sender)
{
        one_window *temp;
   temp = (one_window*)window_list->Items[current_window-1];
   temp->setyscale(((yscale_scroll->Position)/100.0));
   update_form();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::add_newClick(TObject *Sender)
{
        current_window = window_numb_scroll->Max + 1;
        window_numb_scroll->Max += 1;
        parent_window_scroll->Max += 1;
        one_window *temp = new one_window;
        window_list->Add(temp);
        window_numb_scroll->Position = current_window;
        update_form();
        super_update();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::window_numb_editChange(TObject *Sender)
{
        current_window = window_numb_scroll->Position;
        update_form();
        super_update();
}
//---------------------------------------------------------------------------

