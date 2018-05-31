//---------------------------------------------------------------------------
//
// Name:        Proyecto 1App.h
// Author:      Fredy Kcrez
// Created:     18/07/2014 08:00:36 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __PROYECTO_1FRMApp_h__
#define __PROYECTO_1FRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class Proyecto_1FrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
