//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <time.h>
#include <math.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int T=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnStratClick(TObject *Sender)
{
    if(Timer1->Enabled==true){
        Timer1->Enabled=false;
        btnStrat->Caption="Start";
    }
    else if(Timer1->Enabled==false){
        Timer1->Enabled=true;
        btnStrat->Caption="Stop";
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    Form1->Caption=Now();
    float A=0,B=0;
    A=sin(3.141215967*T*10./180.);
    B=cos(3.141215967*T*10./180.);
    //Edit1->Text=A;
    Series1->AddXY(Series1->XValues->Last()+1,A,"",clRed);
    Series2->AddXY(Series2->XValues->Last()+1,B,"",clBlue);
    Series4->AddXY(Series2->XValues->Last()+1,A,"",clRed);
    Series3->AddXY(Series2->XValues->Last()+1,B,"",clBlue);
    T++;
    Series1->Delete(0);
    Series2->Delete(0);
    Series4->Delete(0);
    Series3->Delete(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    for(int i=0;i<100;i++){
        Series1->AddXY(i,0,"",clRed);
        Series2->AddXY(i,0,"",clBlue);
        Series4->AddXY(i,0,"",clRed);
        Series3->AddXY(i,0,"",clBlue);
    }
}
//---------------------------------------------------------------------------
