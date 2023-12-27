#pragma once

namespace XML {
	public ref class XML_Handler : public System::Windows::Forms::Form
	{
		public: static System::String^ Load_XML_Config();
		public: static System::String^ Create_XML_Config(System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods);
		public: static System::String^ Update_XML_Config(System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods);
	};
}
namespace Batch {
	public ref class Batch_Hander : public System::Windows::Forms::Form
	{
		public: static System::String^ Build_Batch_Start_Server_File(System::String^ CreateOrUpdateMessage, System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods);
		public: static System::String^ SteamCMD_Install_ASA_Server_Batch_File(System::String^ Server_Folder_Path);
	};
}
namespace Functions {
	public ref class Function_Handler : public System::Windows::Forms::Form
	{
		public: static System::Void Create_Directory(System::String^ Folder_Path);
		public: static System::Boolean^ Check_If_Folder_Exists(System::String^ Folder_Path);
		public: static System::Void Open_curseforge_Website();
		public: static System::Void Open_Donation_Website();
		public: static System::String^ Open_Browse_Window();
		public: static System::Boolean^ Check_If_ASA_Server_Is_Running();
		public: static System::Void Start_ASA_Server();
		public: static System::Void Stop_ASA_Server();
	};
}