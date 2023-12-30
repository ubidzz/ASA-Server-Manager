#pragma once
#using <System.Xml.dll>
#include "Class_Handler.h"

namespace XML {

	using namespace System;
	using namespace System::Xml;
	using namespace System::IO;

	System::String^ XML::XML_Handler::Load_XML_Config() {
		Functions::Function_Handler::Create_Directory("ASA_Manager_Config\\");
		return "";
	}
	System::String^ XML::XML_Handler::Create_XML_Config(System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods){
		
		XmlDocument^ Doc = gcnew XmlDocument();
		XmlDeclaration^ dec = Doc->CreateXmlDeclaration("1.0", "UTF-8", "no");
		Doc->AppendChild(dec);

		XmlElement^ ASA_Manager_Settings_Tag = Doc->CreateElement("ASA_Manager_Settings");
		dec->AppendChild(ASA_Manager_Settings_Tag);

		XmlElement^ Settings_Tag = Doc->CreateElement("Settings");
		ASA_Manager_Settings_Tag->AppendChild(Settings_Tag);

		XmlElement^ Server_Folder_Path_Tag = Doc->CreateElement("Server_Folder_Path");
		Settings_Tag->InnerText = "grdg";
		Settings_Tag->AppendChild(Server_Folder_Path_Tag);

		XmlElement^ Server_Name_Tag = Doc->CreateElement("Server_Name");
		Settings_Tag->InnerText = "test";
		Settings_Tag->AppendChild(Server_Name_Tag);
		/*
		XmlElement^ Server_Password_Tag = Doc->CreateElement("Server_Password");
		//Settings_Tag->InnerText("");
		Settings_Tag->AppendChild(Server_Password_Tag);

		XmlElement^ Map_Tag = Doc->CreateElement("Map");
		//Settings_Tag->InnerText("");
		Settings_Tag->AppendChild(Map_Tag);

		XmlElement^ Max_Players_Tag = Doc->CreateElement("Max_Players");
		//Settings_Tag->InnerText("");
		Settings_Tag->AppendChild(Max_Players_Tag);

		XmlElement^ BattlEye_Tag = Doc->CreateElement("BattlEye");
		//Settings_Tag->InnerText("");
		Settings_Tag->AppendChild(BattlEye_Tag);

		XmlElement^ Crossplay_Tag = Doc->CreateElement("Crossplay");
		//Settings_Tag->InnerText("");
		Settings_Tag->AppendChild(Crossplay_Tag);

		XmlElement^ Admin_Password_Tag = Doc->CreateElement("Admin_Password");
		//Settings_Tag->InnerText("");
		Settings_Tag->AppendChild(Admin_Password_Tag);

		XmlElement^ RCON_Enable_Tag = Doc->CreateElement("RCON_Enable");
		//Settings_Tag->InnerText("");
		Settings_Tag->AppendChild(RCON_Enable_Tag);

		XmlElement^ RCON_Port_Tag = Doc->CreateElement("RCON_Port");
		//Settings_Tag->InnerText("");
		Settings_Tag->AppendChild(RCON_Port_Tag);

		XmlElement^ Mods_Tag = Doc->CreateElement("Mods");
		//Settings_Tag->InnerText("");
		Settings_Tag->AppendChild(Mods_Tag);
		*/
		Doc->Save("ASA_Manager_Config\\ASA_Server_Manager_Settings.xml");

		return "The ASA Server Manager config file was created successfully!";
	}
	System::String^ XML::XML_Handler::Update_XML_Config(System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods) {
		return "";
	}
}
