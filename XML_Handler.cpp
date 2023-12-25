#pragma once
#using <System.Xml.dll>
#include "Class_Handler.h"

namespace XML {

	using namespace System;
	using namespace System::Xml;

	System::String^ XML::XML_Handler::Load_XML_Config() {

		return "";
	}
	System::String^ XML::XML_Handler::Create_XML_Config(System::String^ CreateOrUpdateMessage, System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods){

		return "";
	}
	System::String^ XML::XML_Handler::Update_XML_Config(System::String^ CreateOrUpdateMessage, System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods) {
		return "";
	}
}
