#pragma once

namespace XML {
	public ref class XML_Handler : public System::Windows::Forms::Form
	{
		public: static System::String^ Load_XML_Config(System::String^ text);
		public: static System::String^ Create_XML_Config();
		public: static System::String^ Update_XML_Config();
	};
}
namespace Batch {
	public ref class Batch_Hander : public System::Windows::Forms::Form
	{
		public: static System::String^ Build_Batch_Start_Server_File(System::String^ CreateOrUpdateMessage, System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods);
		public: static System::String^ SteamCMD_Install_ASA_Server_Batch_File();
	};
}