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
		
		//Still being worked on
		String^ filename = "ASA_Manager_Config\\ASA_Server_Manager_Settings.xml";
		XmlDocument^ doc_XML = gcnew XmlDocument();

		XmlDeclaration^ XML = doc_XML->CreateXmlDeclaration("1.0", "UTF-8", "no");
		XmlNode^ parent = doc_XML->AppendChild(XML);

		//XmlElement^ chiled = XML->CreateElement("Project");


		XmlElement^ newtitle = doc_XML->CreateElement("EName");
		newtitle->InnerText = "SomeText";
		XML->AppendChild(newtitle);

		doc_XML->Save(filename);
		return "";
	}
	System::String^ XML::XML_Handler::Update_XML_Config(System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods) {
		return "";
	}
}
