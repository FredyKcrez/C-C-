///-----------------------------------------------------------------
///
/// @file      00_GuiaLab2.h
/// @author    Fredy Kcrez
/// Created:   09/07/2014 06:11:31 p.m.
/// @section   DESCRIPTION
///            GuiaLab2 class declaration
///
///------------------------------------------------------------------

#ifndef __GUIALAB2_H__
#define __GUIALAB2_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/animate.h>
#include <wx/stattext.h>
#include <wx/button.h>
////Header Include End

////Dialog Style Start
#undef GuiaLab2_STYLE
#define GuiaLab2_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX
////Dialog Style End

class GuiaLab2 : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		GuiaLab2(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Ambiente Dev-C++"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = GuiaLab2_STYLE);
		virtual ~GuiaLab2();
		void GuiaLab2Activate(wxActivateEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void WxButton1Click0(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxAnimationCtrl *wxAnimationCtrl1;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxButton *WxButton2;
		wxButton *WxButton1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXANIMATIONCTRL1 = 1008,
			ID_WXSTATICTEXT2 = 1006,
			ID_WXSTATICTEXT1 = 1003,
			ID_WXBUTTON2 = 1002,
			ID_WXBUTTON1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
			
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
