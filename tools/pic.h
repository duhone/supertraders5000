//---------------------------------------------------------------------------
#ifndef picH
#define picH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit1;
    TUpDown *UpDown1;
    TButton *Button1;
    TOpenDialog *openpic;
    TLabel *Label1;
    TComboBox *resalution_box;
    TLabel *Label2;
    TGroupBox *GroupBox1;
    TRadioButton *frame1button;
    TRadioButton *frame4button;
    TRadioButton *frame16button;
    TRadioButton *frame64button;
    TRadioButton *frame256button;
    TButton *deletebutton;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    
    void __fastcall resalution_boxChange(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
    void __fastcall Edit1Change(TObject *Sender);
    void __fastcall frame1buttonClick(TObject *Sender);
    void __fastcall frame4buttonClick(TObject *Sender);
    void __fastcall frame16buttonClick(TObject *Sender);
    void __fastcall frame64buttonClick(TObject *Sender);
    void __fastcall frame256buttonClick(TObject *Sender);
    void __fastcall deletebuttonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    int piccount;
    HANDLE filehandle;
    HANDLE filemaphandle;
   // TPicture *picture;
   void *filepointer;
   AnsiString filenames[512];
    __fastcall TForm1(TComponent* Owner);
   AnsiString mainfile;
   int texresalution[512];
   int framesanimation[512];
   void resetframes();
   AnsiString directoryname;
   TStringList *animationstrings;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
