//---------------------------------------------------------------------------
//
// Name:        00_GuiaLab2App.h
// Author:      Fredy Kcrez
// Created:     09/07/2014 06:11:30 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __GUIALAB2App_h__
#define __GUIALAB2App_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class GuiaLab2App : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
