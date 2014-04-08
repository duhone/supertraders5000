//---------------------------------------------------------------------------

#ifndef windowH
#define windowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *window_numb_edit;
        TUpDown *window_numb_scroll;
        TLabel *Label1;
        TEdit *parent_window_edit;
        TUpDown *parent_window_scroll;
        TLabel *Label2;
        TEdit *pallette_edit;
        TUpDown *pallette_scroll;
        TLabel *Label3;
        TEdit *xloc_edit;
        TScrollBar *xloc_scroll;
        TLabel *Label4;
        TEdit *yloc_edit;
        TScrollBar *yloc_scroll;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *message_edit;
        TUpDown *message_scroll;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TEdit *arg_edit;
        TUpDown *arg_scroll;
        TLabel *Label12;
        TButton *add_new;
        TButton *Button1;
        TEdit *xscale_edit;
        TScrollBar *xscale_scroll;
        TEdit *yscale_edit;
        TScrollBar *yscale_scroll;
        TLabel *Label13;
        TLabel *Label14;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall xloc_scrollChange(TObject *Sender);
        void __fastcall yloc_scrollChange(TObject *Sender);
        void __fastcall xscale_scrollChange(TObject *Sender);
        void __fastcall yscale_scrollChange(TObject *Sender);
        void __fastcall add_newClick(TObject *Sender);
        void __fastcall window_numb_editChange(TObject *Sender);
private:	// User declarations
        TList *window_list;
        int current_window;
public:		// User declarations
        void update_form();
         void super_update();
       __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
