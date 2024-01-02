#pragma once
#using <System.Xml.dll>
#include "Class_Handler.h"

namespace XML {

	using namespace System;
	using namespace System::Xml;

	System::Collections::Generic::List<System::Tuple<System::String^, System::String^>^>^ XML::XML_Handler::Load_XML_Config(void) {
		
		System::Xml::XmlDocument^ doc = gcnew System::Xml::XmlDocument();
		doc->Load("ASA_Manager_Config\\ASA_Server_Manager_Settings.xml");

		System::Collections::Generic::List<System::Tuple<System::String^, System::String^>^>^ elementList = gcnew System::Collections::Generic::List<System::Tuple<System::String^, System::String^>^>();

		System::Xml::XmlNodeList^ elements = doc->GetElementsByTagName("*");

		for each (System::Xml::XmlNode ^ element in elements)
		{
			if (element->HasChildNodes)
			{
				System::String^ elementName = element->Name;
				System::String^ innerText = element->InnerText;
				elementList->Add(gcnew System::Tuple<System::String^, System::String^>(elementName, innerText));
			}
		}
		return elementList;
	}
	System::Void XML::XML_Handler::Create_XML_Config(void){

		//Create default config folder
		Functions::Function_Handler::Create_Directory("ASA_Manager_Config\\");

		System::Xml::XmlDocument^ Doc = gcnew System::Xml::XmlDocument();
		XmlDeclaration^ dec = Doc->CreateXmlDeclaration("1.0", "UTF-8", nullptr);
		Doc->AppendChild(dec);

		System::Xml::XmlElement^ ASA_Manager_Settings_Tag = Doc->CreateElement("ASA_Manager_Settings");
		Doc->AppendChild(ASA_Manager_Settings_Tag);

		System::Xml::XmlElement^ Settings_Tag = Doc->CreateElement("Settings");
		ASA_Manager_Settings_Tag->AppendChild(Settings_Tag);

		System::Xml::XmlElement^ Server_Folder_Path_Tag = Doc->CreateElement("Server_Folder_Path");
		Server_Folder_Path_Tag->InnerText = "";
		Settings_Tag->AppendChild(Server_Folder_Path_Tag);
		
		System::Xml::XmlElement^ Server_Name_Tag = Doc->CreateElement("Server_Name");
		Server_Name_Tag->InnerText = "";
		Settings_Tag->AppendChild(Server_Name_Tag);
		
		System::Xml::XmlElement^ Server_Password_Tag = Doc->CreateElement("Server_Password");
		Server_Password_Tag->InnerText = "";
		Settings_Tag->AppendChild(Server_Password_Tag);

		System::Xml::XmlElement^ Map_Tag = Doc->CreateElement("Map");
		Map_Tag->InnerText = "TheIsland_WP";
		Settings_Tag->AppendChild(Map_Tag);

		System::Xml::XmlElement^ Max_Players_Tag = Doc->CreateElement("Max_Players");
		Max_Players_Tag->InnerText = "70";
		Settings_Tag->AppendChild(Max_Players_Tag);

		System::Xml::XmlElement^ BattlEye_Tag = Doc->CreateElement("BattlEye");
		BattlEye_Tag->InnerText = "Battle Eye On";
		Settings_Tag->AppendChild(BattlEye_Tag);

		System::Xml::XmlElement^ Crossplay_Tag = Doc->CreateElement("Crossplay");
		Crossplay_Tag->InnerText = "Crossplay Off";
		Settings_Tag->AppendChild(Crossplay_Tag);

		System::Xml::XmlElement^ Admin_Password_Tag = Doc->CreateElement("Admin_Password");
		Admin_Password_Tag->InnerText = "";
		Settings_Tag->AppendChild(Admin_Password_Tag);

		System::Xml::XmlElement^ RCON_Enable_Tag = Doc->CreateElement("RCON_Enable");
		RCON_Enable_Tag->InnerText = "Off";
		Settings_Tag->AppendChild(RCON_Enable_Tag);

		System::Xml::XmlElement^ RCON_Port_Tag = Doc->CreateElement("RCON_Port");
		RCON_Port_Tag->InnerText = "27020";
		Settings_Tag->AppendChild(RCON_Port_Tag);

		System::Xml::XmlElement^ Mods_Tag = Doc->CreateElement("Mods");
		Mods_Tag->InnerText = "";
		Settings_Tag->AppendChild(Mods_Tag);
		
		Doc->Save("ASA_Manager_Config\\ASA_Server_Manager_Settings.xml");
	}

	System::Void XML::XML_Handler::Update_XML_Config(System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods, System::String^ Enable_RCON, System::String^ RCON_Port) {
		System::Xml::XmlDocument^ Doc = gcnew System::Xml::XmlDocument();
		XmlDeclaration^ dec = Doc->CreateXmlDeclaration("1.0", "UTF-8", nullptr);
		Doc->AppendChild(dec);

		System::Xml::XmlElement^ ASA_Manager_Settings_Tag = Doc->CreateElement("ASA_Manager_Settings");
		Doc->AppendChild(ASA_Manager_Settings_Tag);

		System::Xml::XmlElement^ Settings_Tag = Doc->CreateElement("Settings");
		ASA_Manager_Settings_Tag->AppendChild(Settings_Tag);

		System::Xml::XmlElement^ Server_Folder_Path_Tag = Doc->CreateElement("Server_Folder_Path");
		Server_Folder_Path_Tag->InnerText = Folder_Path;
		Settings_Tag->AppendChild(Server_Folder_Path_Tag);

		System::Xml::XmlElement^ Server_Name_Tag = Doc->CreateElement("Server_Name");
		Server_Name_Tag->InnerText = Server_Name;
		Settings_Tag->AppendChild(Server_Name_Tag);

		System::Xml::XmlElement^ Server_Password_Tag = Doc->CreateElement("Server_Password");
		Server_Password_Tag->InnerText = Server_Password;
		Settings_Tag->AppendChild(Server_Password_Tag);

		System::Xml::XmlElement^ Map_Tag = Doc->CreateElement("Map");
		Map_Tag->InnerText = Map;
		Settings_Tag->AppendChild(Map_Tag);

		System::Xml::XmlElement^ Max_Players_Tag = Doc->CreateElement("Max_Players");
		Max_Players_Tag->InnerText = Max_Players;
		Settings_Tag->AppendChild(Max_Players_Tag);

		System::Xml::XmlElement^ BattlEye_Tag = Doc->CreateElement("BattlEye");
		BattlEye_Tag->InnerText = Enable_BattleEye;
		Settings_Tag->AppendChild(BattlEye_Tag);

		System::Xml::XmlElement^ Crossplay_Tag = Doc->CreateElement("Crossplay");
		Crossplay_Tag->InnerText = Enable_Crossplay;
		Settings_Tag->AppendChild(Crossplay_Tag);

		System::Xml::XmlElement^ Admin_Password_Tag = Doc->CreateElement("Admin_Password");
		Admin_Password_Tag->InnerText = Admin_Password;
		Settings_Tag->AppendChild(Admin_Password_Tag);

		System::Xml::XmlElement^ RCON_Enable_Tag = Doc->CreateElement("RCON_Enable");
		RCON_Enable_Tag->InnerText = Enable_RCON;
		Settings_Tag->AppendChild(RCON_Enable_Tag);

		System::Xml::XmlElement^ RCON_Port_Tag = Doc->CreateElement("RCON_Port");
		RCON_Port_Tag->InnerText = RCON_Port;
		Settings_Tag->AppendChild(RCON_Port_Tag);

		System::Xml::XmlElement^ Mods_Tag = Doc->CreateElement("Mods");
		Mods_Tag->InnerText = Mods;
		Settings_Tag->AppendChild(Mods_Tag);

		Doc->Save("ASA_Manager_Config\\ASA_Server_Manager_Settings.xml");
	}
}
