//---------------------------------------------------------------------------
#ifndef sector_selH
#define sector_selH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include "sector.h"
#include <Mask.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TUpDown *sectorupdn;
    TEdit *currentsectorbox;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *objectnumberbox;
    TUpDown *objectnumberupdn;
    TLabel *Label3;
    TButton *addobjectbut;
    TButton *deleteobject;
    TMaskEdit *xposedit;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TScrollBar *xposscroll;
    TScrollBar *yposscroll;
    TEdit *yposedit;
    TEdit *xorbitbox;
    TScrollBar *xorbitscroll;
    TLabel *Label7;
    TLabel *Label8;
    TEdit *yorbitbox;
    TScrollBar *yorbitscroll;
    TLabel *Label9;
    TEdit *xsizeedit;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TEdit *ysizeedit;
    TScrollBar *xsizescroll;
    TScrollBar *ysizescroll;
    TLabel *Label13;
    TEdit *palleteedit;
    TScrollBar *palletescroll;
    TLabel *Label14;
    TEdit *gravityedit;
    TScrollBar *gravityscroll;
    TLabel *Label15;
    TLabel *Label16;
    TLabel *Label17;
    TLabel *Label18;
    TLabel *Label19;
    TLabel *Label20;
    TLabel *Label21;
    TLabel *Label22;
    TEdit *red1edit;
    TUpDown *red1updn;
    TEdit *rededit2;
    TUpDown *red2updn;
    TEdit *red3edit;
    TUpDown *red3updn;
    TEdit *red4edit;
    TUpDown *red4updn;
    TEdit *green1edit;
    TUpDown *green1updn;
    TEdit *green2edit;
    TUpDown *green2updn;
    TEdit *green3edit;
    TUpDown *green3updn;
    TEdit *green4edit;
    TUpDown *green4updn;
    TEdit *blue1edit;
    TUpDown *blue1updn;
    TEdit *blue2edit;
    TUpDown *blue2updn;
    TEdit *blue3edit;
    TUpDown *blue3updn;
    TEdit *blue4edit;
    TUpDown *blue4updn;
    TEdit *alpha1edit;
    TUpDown *alpha1updn;
    TEdit *alpha2edit;
    TUpDown *alpha2updn;
    TEdit *alpha3edit;
    TUpDown *alpha3updn;
    TEdit *alpha4edit;
    TUpDown *alpha4updn;
    TEdit *speededit;
    TScrollBar *speedscroll;
    TLabel *Label23;
    TEdit *rotationedit;
    TLabel *Label24;
    TScrollBar *rotationscroll;
        TCheckBox *typebox;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall currentsectorboxChange(TObject *Sender);
    void __fastcall addobjectbutClick(TObject *Sender);
    void __fastcall deleteobjectClick(TObject *Sender);
    void __fastcall xposscrollChange(TObject *Sender);
    void __fastcall objectnumberboxChange(TObject *Sender);
    void __fastcall yposscrollChange(TObject *Sender);
    void __fastcall xorbitscrollChange(TObject *Sender);
    void __fastcall yorbitscrollChange(TObject *Sender);
    void __fastcall xsizescrollChange(TObject *Sender);
    void __fastcall ysizescrollChange(TObject *Sender);
    void __fastcall palletescrollChange(TObject *Sender);
    void __fastcall gravityscrollChange(TObject *Sender);
    
    
    
    
    void __fastcall color1change(TObject *Sender);
    void __fastcall color2change(TObject *Sender);
    void __fastcall color3change(TObject *Sender);
    void __fastcall color4change(TObject *Sender);
    void __fastcall speedscrollChange(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall rotationscrollChange(TObject *Sender);
        void __fastcall typeboxClick(TObject *Sender);
private:	// User declarations
    int currentsector;
    int numobjpersec[20];
    int currentobject;
    sector *sectors;
    void resetobjparams();

    HANDLE filehandle;
    HANDLE filemaphandle;
    void *filepointer;
    AnsiString *mainfile;
    AnsiString directoryname;

public:		// User declarations

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
