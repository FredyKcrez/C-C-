//---------------------------------------------------------------------------
//
// Name:        Proyecto 1App.cpp
// Author:      Fredy Kcrez
// Created:     18/07/2014 08:00:36 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#include "Proyecto 1App.h"
#include "Proyecto 1Frm.h"

IMPLEMENT_APP(Proyecto_1FrmApp)

bool Proyecto_1FrmApp::OnInit()
{
    Proyecto_1Frm* frame = new Proyecto_1Frm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int Proyecto_1FrmApp::OnExit()
{
	return 0;
}
