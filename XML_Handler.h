#pragma once
#include <string>
#using <System.Xml.dll>

namespace XML {

	using namespace System;
	using namespace System::Xml;

	public ref class XML_Hander : public System::Windows::Forms::Form
	{
		private: System::String^ Load_XML_Config(Void) {
			if (fopen("ASA_Manager_Config/Manager_Config.xml", "r")) {

			}
			else {
				Create_XML_Config();
			}
			return "";
		}
		private: System::String^ Create_XML_Config() {
			return "";
		}
		private: System::String^ Update_XML_Config(System::Object^ sender, System::EventArgs^ e) {
			return "";
		}
	};
}
