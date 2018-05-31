//---------------------------------------------------------------------------
//
// Name:        00_GuiaLab2App.cpp
// Author:      Fredy Kcrez
// Created:     09/07/2014 06:11:30 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#include "00_GuiaLab2App.h"
#include "00_GuiaLab2.h"

IMPLEMENT_APP(GuiaLab2App)

bool GuiaLab2App::OnInit()
{
    GuiaLab2* frame = new GuiaLab2(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int GuiaLab2App::OnExit()
{
	return 0;
}
