///-----------------------------------------------------------------
///
/// @file      00_GuiaLab2.cpp
/// @author    Fredy Kcrez
/// Created:   09/07/2014 06:11:32 p.m.
/// @section   DESCRIPTION
///            GuiaLab2 class implementation
///
///------------------------------------------------------------------

#include "00_GuiaLab2.h"
#include<windows.h>

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// GuiaLab2
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(GuiaLab2,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(GuiaLab2::OnClose)
	EVT_ACTIVATE(GuiaLab2::GuiaLab2Activate)
	EVT_BUTTON(ID_WXBUTTON2,GuiaLab2::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON1,GuiaLab2::WxButton1Click0)
END_EVENT_TABLE()
////Event Table End

GuiaLab2::GuiaLab2(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

GuiaLab2::~GuiaLab2()
{
}

void GuiaLab2::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxAnimationCtrl1 = new wxAnimationCtrl(this, ID_WXANIMATIONCTRL1, wxNullAnimation, wxPoint(16, 79), wxSize(348, 199) );
	wxAnimationCtrl1->LoadFile("C:/Users/Fredy Kcrez/Pictures/Anime/SE.gif");
	wxAnimationCtrl1->Play();
	wxAnimationCtrl1->Enable(false);
	wxAnimationCtrl1->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _("Showcard Gothic")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Fredy Kcrez"), wxPoint(417, 254), wxDefaultSize, wxALWAYS_SHOW_SB | wxALIGN_CENTRE, _("WxStaticText2"));
	WxStaticText2->SetForegroundColour(wxColour(0,0,128));
	WxStaticText2->SetFont(wxFont(12, wxSWISS, wxNORMAL, wxNORMAL, false, _("Stencil")));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Bienvenido al ambiente de Dev-C++"), wxPoint(32, 23), wxDefaultSize, wxALIGN_CENTRE, _("WxStaticText1"));
	WxStaticText1->SetForegroundColour(wxColour(0,0,128));
	WxStaticText1->SetFont(wxFont(22, wxSWISS, wxNORMAL, wxNORMAL, false, _("Showcard Gothic")));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, _("Salir"), wxPoint(397, 166), wxSize(153, 43), 0, wxDefaultValidator, _("WxButton2"));
	WxButton2->SetBackgroundColour(wxColour(255,106,106));
	WxButton2->SetFont(wxFont(12, wxSWISS, wxITALIC, wxBOLD, false, _("Segoe UI Symbol")));

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Iniciar Muestra"), wxPoint(398, 92), wxSize(153, 46), 0, wxDefaultValidator, _("WxButton1"));
	WxButton1->SetBackgroundColour(wxColour(255,106,106));
	WxButton1->SetFont(wxFont(12, wxSWISS, wxITALIC, wxBOLD, false, _("Segoe UI Symbol")));

	SetTitle(_("Ambiente Dev-C++"));
	SetIcon(wxNullIcon);
	SetSize(8,8,596,334);
	Center();
	
	////GUI Items Creation End
}

void GuiaLab2::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * PruebaFrmActivate
 */
void GuiaLab2::GuiaLab2Activate(wxActivateEvent& event)
{
	// insert your code here
}

//WxButton2Click
void GuiaLab2::WxButton2Click(wxCommandEvent& event)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void GuiaLab2::WxButton1Click(wxCommandEvent& event)
{
	
}

/*
 * WxButton1Click0
 */
void GuiaLab2::WxButton1Click0(wxCommandEvent& event)
{
	WxStaticText1->SetLabel("Este es el ambiente en C");
	Sleep(5000);
	WxStaticText1->SetLabel("Disfrute su practica");
}
