///-----------------------------------------------------------------
///
/// @file      Proyecto 1Frm.cpp
/// @author    Fredy Kcrez
/// Created:   18/07/2014 08:00:37 p.m.
/// @section   DESCRIPTION
///            Proyecto_1Frm class implementation
///
///------------------------------------------------------------------

#include "Proyecto 1Frm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// Proyecto_1Frm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Proyecto_1Frm, wxFrame)
	////Manual Code Start
	////Manual Code End
	EVT_CLOSE(Proyecto_1Frm::OnClose)
END_EVENT_TABLE()
////Event Table End

Proyecto_1Frm::Proyecto_1Frm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Proyecto_1Frm::~Proyecto_1Frm()
{
}

void Proyecto_1Frm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start
	////GUI Items Creation End
}

void Proyecto_1Frm::OnClose(wxCloseEvent& event)
{
	Destroy();
}
