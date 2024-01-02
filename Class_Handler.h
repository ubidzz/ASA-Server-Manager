#pragma once
#include <string>

namespace XML {
	public ref class XML_Handler : public System::Windows::Forms::Form
	{
		public: 
			static System::Collections::Generic::List<System::Tuple<System::String^, System::String^>^>^ Load_XML_Config(void);
			static System::Void Create_XML_Config(void);
			static System::Void Update_XML_Config(System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods, System::String^ Enable_RCON, System::String^ RCON_Port);
	};
}
namespace Batch {
	public ref class Batch_Hander : public System::Windows::Forms::Form
	{
		public: 
			static System::String^ Build_Batch_Start_Server_File(System::String^ CreateOrUpdateMessage, System::String^ Folder_Path, System::String^ Max_Players, System::String^ Server_Name, System::String^ Server_Password, System::String^ Admin_Password, System::String^ Map, System::String^ Enable_BattleEye, System::String^ Enable_Crossplay, System::String^ Mods);
			static System::String^ SteamCMD_Install_ASA_Server_Batch_File(System::String^ Server_Folder_Path);
	};
}
namespace Functions {
	public ref class Function_Handler : public System::Windows::Forms::Form
	{
		public: 
			static System::Void Create_Directory(System::String^ Folder_Path);
			static System::Boolean Check_If_File_Exists(System::String^ filePath);
			static System::Boolean Check_If_Folder_Exists(System::String^ Folder_Path);
			static System::Void Open_curseforge_Website(void);
			static System::Void Open_Donation_Website(void);
			static System::String^ Open_Browse_Window(void);
			static System::Boolean Check_If_ASA_Server_Is_Running(void);
			static System::Void Start_ASA_Server(void);
			static System::Void Stop_ASA_Server(void);
			static System::String^ Download_SteamCMD(void);
			static System::String^ Unzip_SteamCMD(void);
			static std::wstring ExePath(void);
	};
}