#pragma once
#include "Class_Handler.h"

namespace ASAServerManager {

	using namespace System;
	using namespace XML;
	using namespace Batch;
	using namespace Functions;

	/// <summary>
	/// Summary for ASA_Server_Manager_UI
	/// </summary>
	public ref class ASA_Server_Manager_UI : public System::Windows::Forms::Form
	{
		public:
			ASA_Server_Manager_UI(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~ASA_Server_Manager_UI()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Void Crash_Log_Message()
		{
			DateTime^ Timestamp = System::DateTime::Now;
			String^ LineBrake = "\r\n-----------------------------------------------------------------------------\r\n";
			Displayed_Server_Crash_Logs->Text = Timestamp + " \r\nThe server has crashed and is tempting to restart the " + Server_Name_textBox->Text + " server!" + LineBrake + Displayed_Server_Crash_Logs->Text;
		}
		private: System::Void Manager_Status_Message(String^ Message)
		{
			DateTime^ Timestamp = System::DateTime::Now;
			String^ LineBrake = "\r\n-----------------------------------------------------------------------------\r\n";
			Manager_Status_Messages->Text = Timestamp + "\r\n" + Message + LineBrake + Manager_Status_Messages->Text;
		}
		private: System::Void Add_Mods(String^ Mod)
		{
			if (Mods_textBox->Text->Contains(Mod) == false)
			{
				if (Mods_textBox->Text == "")
				{
					Mods_textBox->Text = Mod;
				}
				else {
					Mods_textBox->Text = Mod + "," + Mods_textBox->Text->Trim();
				}
			}
		}
		private: System::Void Load_Config()
		{
			String^ result = XML::XML_Handler::Load_XML_Config();
			//Manager_Status_Message(result);
		}
		private: System::Void Update_Config()
		{
			String^ result = XML::XML_Handler::Update_XML_Config("Update", Server_Install_Folder_textBox->Text, Max_Players_textBox->Text, Server_Name_textBox->Text, Server_Password_textBox->Text, Admin_Password_textBox->Text, Map_comboBox->SelectedText, Anti_Cheat_comboBox->SelectedText, Crossplay_comboBox->SelectedText, Mods_textBox->Text);
			Manager_Status_Message(result);
		}
		private: System::Void Create_Config()
		{
			String^ result = XML::XML_Handler::Create_XML_Config("Create", Server_Install_Folder_textBox->Text, Max_Players_textBox->Text, Server_Name_textBox->Text, Server_Password_textBox->Text, Admin_Password_textBox->Text, Map_comboBox->SelectedText, Anti_Cheat_comboBox->SelectedText, Crossplay_comboBox->SelectedText, Mods_textBox->Text);
			Manager_Status_Message(result);
		}

		private: System::Windows::Forms::Button^ Stop_Server_button;
		protected:
			private: System::Windows::Forms::Button^ Start_Server_button;
			private: System::Windows::Forms::Label^ ASA_Server_Crashed_Log_label;
			private: System::Windows::Forms::Label^ Manager_Status_label;
			private: System::Windows::Forms::ProgressBar^ Server_Crashed_Check_progressBar;
			private: System::Windows::Forms::Label^ Server_Crashed_Check_label;
			private: System::Windows::Forms::Button^ Save_ASA_Manager_Config_button;
			private: System::Windows::Forms::Button^ Install_Update_ASA_Server_button;
			private: System::Windows::Forms::Button^ Create_ASA_Server_Backup_Files_button;
			private: System::Windows::Forms::Button^ Edit_GameUserSettings_ini_file_button;
			private: System::Windows::Forms::Button^ Edit_Game_ini_file_button;
			private: System::Windows::Forms::Button^ Donate_button;
			private: System::Windows::Forms::TextBox^ Mods_textBox;
			private: System::Windows::Forms::Label^ Server_Install_Folder_label;
			private: System::Windows::Forms::TextBox^ Server_Install_Folder_textBox;
			private: System::Windows::Forms::Label^ Server_Name_label;
			private: System::Windows::Forms::TextBox^ Server_Name_textBox;
			private: System::Windows::Forms::Label^ Mods_label;
			private: System::Windows::Forms::Label^ Server_Password_label;
			private: System::Windows::Forms::TextBox^ Server_Password_textBox;
			private: System::Windows::Forms::ComboBox^ Map_comboBox;
			private: System::Windows::Forms::Label^ Map_label;
			private: System::Windows::Forms::Label^ Max_players_label;
			private: System::Windows::Forms::TextBox^ Max_Players_textBox;
			private: System::Windows::Forms::Label^ Anti_Cheat_label;
			private: System::Windows::Forms::ComboBox^ Anti_Cheat_comboBox;
			private: System::Windows::Forms::Label^ Crossplay_label;
			private: System::Windows::Forms::ComboBox^ Crossplay_comboBox;
			private: System::Windows::Forms::Label^ Admin_Password_label;
			private: System::Windows::Forms::TextBox^ Admin_Password_textBox;
			private: System::Windows::Forms::Label^ RCON_Enable_label;
			private: System::Windows::Forms::ComboBox^ RCON_Enable_comboBox;
			private: System::Windows::Forms::Label^ RCON_Port_label;
			private: System::Windows::Forms::TextBox^ RCON_Port_textBox;
			private: System::Windows::Forms::Label^ Adding_Mods_Info_label;
			private: System::Windows::Forms::Button^ Open_Curseforge_Website_button;
			private: System::Windows::Forms::Button^ Turkey_Triales_button;
			private: System::Windows::Forms::Label^ Add_ASA_Events_label;
			private: System::Windows::Forms::Button^ Winter_Wonderland_button;
			private: System::Windows::Forms::Button^ Browse_button;
			private: System::Windows::Forms::TextBox^ Displayed_Server_Crash_Logs;
			private: System::Windows::Forms::TextBox^ Manager_Status_Messages;
		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>
			System::ComponentModel::Container ^components;

			#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ASA_Server_Manager_UI::typeid));
				this->Stop_Server_button = (gcnew System::Windows::Forms::Button());
				this->Start_Server_button = (gcnew System::Windows::Forms::Button());
				this->ASA_Server_Crashed_Log_label = (gcnew System::Windows::Forms::Label());
				this->Manager_Status_label = (gcnew System::Windows::Forms::Label());
				this->Server_Crashed_Check_progressBar = (gcnew System::Windows::Forms::ProgressBar());
				this->Server_Crashed_Check_label = (gcnew System::Windows::Forms::Label());
				this->Save_ASA_Manager_Config_button = (gcnew System::Windows::Forms::Button());
				this->Install_Update_ASA_Server_button = (gcnew System::Windows::Forms::Button());
				this->Create_ASA_Server_Backup_Files_button = (gcnew System::Windows::Forms::Button());
				this->Edit_GameUserSettings_ini_file_button = (gcnew System::Windows::Forms::Button());
				this->Edit_Game_ini_file_button = (gcnew System::Windows::Forms::Button());
				this->Donate_button = (gcnew System::Windows::Forms::Button());
				this->Mods_textBox = (gcnew System::Windows::Forms::TextBox());
				this->Server_Install_Folder_label = (gcnew System::Windows::Forms::Label());
				this->Server_Install_Folder_textBox = (gcnew System::Windows::Forms::TextBox());
				this->Server_Name_label = (gcnew System::Windows::Forms::Label());
				this->Server_Name_textBox = (gcnew System::Windows::Forms::TextBox());
				this->Mods_label = (gcnew System::Windows::Forms::Label());
				this->Server_Password_label = (gcnew System::Windows::Forms::Label());
				this->Server_Password_textBox = (gcnew System::Windows::Forms::TextBox());
				this->Map_comboBox = (gcnew System::Windows::Forms::ComboBox());
				this->Map_label = (gcnew System::Windows::Forms::Label());
				this->Max_players_label = (gcnew System::Windows::Forms::Label());
				this->Max_Players_textBox = (gcnew System::Windows::Forms::TextBox());
				this->Anti_Cheat_label = (gcnew System::Windows::Forms::Label());
				this->Anti_Cheat_comboBox = (gcnew System::Windows::Forms::ComboBox());
				this->Crossplay_label = (gcnew System::Windows::Forms::Label());
				this->Crossplay_comboBox = (gcnew System::Windows::Forms::ComboBox());
				this->Admin_Password_label = (gcnew System::Windows::Forms::Label());
				this->Admin_Password_textBox = (gcnew System::Windows::Forms::TextBox());
				this->RCON_Enable_label = (gcnew System::Windows::Forms::Label());
				this->RCON_Enable_comboBox = (gcnew System::Windows::Forms::ComboBox());
				this->RCON_Port_label = (gcnew System::Windows::Forms::Label());
				this->RCON_Port_textBox = (gcnew System::Windows::Forms::TextBox());
				this->Adding_Mods_Info_label = (gcnew System::Windows::Forms::Label());
				this->Open_Curseforge_Website_button = (gcnew System::Windows::Forms::Button());
				this->Turkey_Triales_button = (gcnew System::Windows::Forms::Button());
				this->Add_ASA_Events_label = (gcnew System::Windows::Forms::Label());
				this->Winter_Wonderland_button = (gcnew System::Windows::Forms::Button());
				this->Browse_button = (gcnew System::Windows::Forms::Button());
				this->Displayed_Server_Crash_Logs = (gcnew System::Windows::Forms::TextBox());
				this->Manager_Status_Messages = (gcnew System::Windows::Forms::TextBox());
				this->SuspendLayout();
				// 
				// Stop_Server_button
				// 
				this->Stop_Server_button->BackColor = System::Drawing::Color::Red;
				this->Stop_Server_button->Cursor = System::Windows::Forms::Cursors::Hand;
				this->Stop_Server_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Stop_Server_button->ForeColor = System::Drawing::Color::Black;
				this->Stop_Server_button->Location = System::Drawing::Point(965, 13);
				this->Stop_Server_button->Name = L"Stop_Server_button";
				this->Stop_Server_button->Size = System::Drawing::Size(107, 31);
				this->Stop_Server_button->TabIndex = 0;
				this->Stop_Server_button->Text = L"Stop Server";
				this->Stop_Server_button->UseVisualStyleBackColor = false;
				// 
				// Start_Server_button
				// 
				this->Start_Server_button->BackColor = System::Drawing::Color::Green;
				this->Start_Server_button->Cursor = System::Windows::Forms::Cursors::Hand;
				this->Start_Server_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Start_Server_button->Location = System::Drawing::Point(851, 13);
				this->Start_Server_button->Name = L"Start_Server_button";
				this->Start_Server_button->Size = System::Drawing::Size(108, 31);
				this->Start_Server_button->TabIndex = 1;
				this->Start_Server_button->Text = L"Start Server";
				this->Start_Server_button->UseVisualStyleBackColor = false;
				// 
				// ASA_Server_Crashed_Log_label
				// 
				this->ASA_Server_Crashed_Log_label->AutoSize = true;
				this->ASA_Server_Crashed_Log_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->ASA_Server_Crashed_Log_label->Location = System::Drawing::Point(863, 55);
				this->ASA_Server_Crashed_Log_label->Name = L"ASA_Server_Crashed_Log_label";
				this->ASA_Server_Crashed_Log_label->Size = System::Drawing::Size(162, 15);
				this->ASA_Server_Crashed_Log_label->TabIndex = 2;
				this->ASA_Server_Crashed_Log_label->Text = L"ASA Server Crashed Log";
				// 
				// Manager_Status_label
				// 
				this->Manager_Status_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Manager_Status_label->Location = System::Drawing::Point(582, 24);
				this->Manager_Status_label->Name = L"Manager_Status_label";
				this->Manager_Status_label->Size = System::Drawing::Size(121, 17);
				this->Manager_Status_label->TabIndex = 7;
				this->Manager_Status_label->Text = L"Manager Status";
				this->Manager_Status_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				// 
				// Server_Crashed_Check_progressBar
				// 
				this->Server_Crashed_Check_progressBar->Location = System::Drawing::Point(815, 368);
				this->Server_Crashed_Check_progressBar->Name = L"Server_Crashed_Check_progressBar";
				this->Server_Crashed_Check_progressBar->Size = System::Drawing::Size(257, 23);
				this->Server_Crashed_Check_progressBar->TabIndex = 8;
				// 
				// Server_Crashed_Check_label
				// 
				this->Server_Crashed_Check_label->AutoSize = true;
				this->Server_Crashed_Check_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Server_Crashed_Check_label->Location = System::Drawing::Point(866, 350);
				this->Server_Crashed_Check_label->Name = L"Server_Crashed_Check_label";
				this->Server_Crashed_Check_label->Size = System::Drawing::Size(148, 15);
				this->Server_Crashed_Check_label->TabIndex = 9;
				this->Server_Crashed_Check_label->Text = L"Server Crashed Check";
				// 
				// Save_ASA_Manager_Config_button
				// 
				this->Save_ASA_Manager_Config_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Save_ASA_Manager_Config_button->Location = System::Drawing::Point(12, 417);
				this->Save_ASA_Manager_Config_button->Name = L"Save_ASA_Manager_Config_button";
				this->Save_ASA_Manager_Config_button->Size = System::Drawing::Size(171, 23);
				this->Save_ASA_Manager_Config_button->TabIndex = 10;
				this->Save_ASA_Manager_Config_button->Text = L"Save ASA Manager Config";
				this->Save_ASA_Manager_Config_button->UseVisualStyleBackColor = true;
				this->Save_ASA_Manager_Config_button->Click += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::Save_ASA_Manager_Config_button_Click);
				// 
				// Install_Update_ASA_Server_button
				// 
				this->Install_Update_ASA_Server_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Install_Update_ASA_Server_button->Location = System::Drawing::Point(189, 417);
				this->Install_Update_ASA_Server_button->Name = L"Install_Update_ASA_Server_button";
				this->Install_Update_ASA_Server_button->Size = System::Drawing::Size(181, 23);
				this->Install_Update_ASA_Server_button->TabIndex = 11;
				this->Install_Update_ASA_Server_button->Text = L"Install/Update ASA Server";
				this->Install_Update_ASA_Server_button->UseVisualStyleBackColor = true;
				this->Install_Update_ASA_Server_button->Click += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::Install_Update_ASA_Server_button_Click);
				// 
				// Create_ASA_Server_Backup_Files_button
				// 
				this->Create_ASA_Server_Backup_Files_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Create_ASA_Server_Backup_Files_button->Location = System::Drawing::Point(376, 417);
				this->Create_ASA_Server_Backup_Files_button->Name = L"Create_ASA_Server_Backup_Files_button";
				this->Create_ASA_Server_Backup_Files_button->Size = System::Drawing::Size(200, 23);
				this->Create_ASA_Server_Backup_Files_button->TabIndex = 12;
				this->Create_ASA_Server_Backup_Files_button->Text = L"Create ASA Server Backup Files";
				this->Create_ASA_Server_Backup_Files_button->UseVisualStyleBackColor = true;
				// 
				// Edit_GameUserSettings_ini_file_button
				// 
				this->Edit_GameUserSettings_ini_file_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Edit_GameUserSettings_ini_file_button->Location = System::Drawing::Point(582, 417);
				this->Edit_GameUserSettings_ini_file_button->Name = L"Edit_GameUserSettings_ini_file_button";
				this->Edit_GameUserSettings_ini_file_button->Size = System::Drawing::Size(184, 23);
				this->Edit_GameUserSettings_ini_file_button->TabIndex = 13;
				this->Edit_GameUserSettings_ini_file_button->Text = L"Edit GameUserSettings.ini file";
				this->Edit_GameUserSettings_ini_file_button->UseVisualStyleBackColor = true;
				this->Edit_GameUserSettings_ini_file_button->Click += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::Edit_GameUserSettings_ini_file_button_Click);
				// 
				// Edit_Game_ini_file_button
				// 
				this->Edit_Game_ini_file_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Edit_Game_ini_file_button->Location = System::Drawing::Point(772, 417);
				this->Edit_Game_ini_file_button->Name = L"Edit_Game_ini_file_button";
				this->Edit_Game_ini_file_button->Size = System::Drawing::Size(126, 23);
				this->Edit_Game_ini_file_button->TabIndex = 14;
				this->Edit_Game_ini_file_button->Text = L"Edit Game.ini file";
				this->Edit_Game_ini_file_button->UseVisualStyleBackColor = true;
				// 
				// Donate_button
				// 
				this->Donate_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Donate_button->Location = System::Drawing::Point(986, 408);
				this->Donate_button->Name = L"Donate_button";
				this->Donate_button->Size = System::Drawing::Size(86, 32);
				this->Donate_button->TabIndex = 15;
				this->Donate_button->Text = L"Donate!";
				this->Donate_button->UseVisualStyleBackColor = true;
				this->Donate_button->Click += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::Donate_button_Click);
				// 
				// Mods_textBox
				// 
				this->Mods_textBox->Location = System::Drawing::Point(12, 379);
				this->Mods_textBox->Name = L"Mods_textBox";
				this->Mods_textBox->Size = System::Drawing::Size(477, 20);
				this->Mods_textBox->TabIndex = 16;
				// 
				// Server_Install_Folder_label
				// 
				this->Server_Install_Folder_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Server_Install_Folder_label->Location = System::Drawing::Point(12, 9);
				this->Server_Install_Folder_label->Name = L"Server_Install_Folder_label";
				this->Server_Install_Folder_label->Size = System::Drawing::Size(156, 23);
				this->Server_Install_Folder_label->TabIndex = 17;
				this->Server_Install_Folder_label->Text = L"Server Installation Folder";
				this->Server_Install_Folder_label->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
				// 
				// Server_Install_Folder_textBox
				// 
				this->Server_Install_Folder_textBox->Location = System::Drawing::Point(12, 35);
				this->Server_Install_Folder_textBox->Name = L"Server_Install_Folder_textBox";
				this->Server_Install_Folder_textBox->Size = System::Drawing::Size(396, 20);
				this->Server_Install_Folder_textBox->TabIndex = 18;
				// 
				// Server_Name_label
				// 
				this->Server_Name_label->AutoSize = true;
				this->Server_Name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Server_Name_label->Location = System::Drawing::Point(12, 63);
				this->Server_Name_label->Name = L"Server_Name_label";
				this->Server_Name_label->Size = System::Drawing::Size(80, 13);
				this->Server_Name_label->TabIndex = 19;
				this->Server_Name_label->Text = L"Server Name";
				// 
				// Server_Name_textBox
				// 
				this->Server_Name_textBox->Location = System::Drawing::Point(12, 79);
				this->Server_Name_textBox->Name = L"Server_Name_textBox";
				this->Server_Name_textBox->Size = System::Drawing::Size(477, 20);
				this->Server_Name_textBox->TabIndex = 20;
				// 
				// Mods_label
				// 
				this->Mods_label->AutoSize = true;
				this->Mods_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Mods_label->Location = System::Drawing::Point(15, 363);
				this->Mods_label->Name = L"Mods_label";
				this->Mods_label->Size = System::Drawing::Size(37, 13);
				this->Mods_label->TabIndex = 21;
				this->Mods_label->Text = L"Mods";
				// 
				// Server_Password_label
				// 
				this->Server_Password_label->AutoSize = true;
				this->Server_Password_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Server_Password_label->Location = System::Drawing::Point(12, 107);
				this->Server_Password_label->Name = L"Server_Password_label";
				this->Server_Password_label->Size = System::Drawing::Size(102, 13);
				this->Server_Password_label->TabIndex = 22;
				this->Server_Password_label->Text = L"Server Password";
				// 
				// Server_Password_textBox
				// 
				this->Server_Password_textBox->Location = System::Drawing::Point(12, 123);
				this->Server_Password_textBox->Name = L"Server_Password_textBox";
				this->Server_Password_textBox->Size = System::Drawing::Size(477, 20);
				this->Server_Password_textBox->TabIndex = 23;
				// 
				// Map_comboBox
				// 
				this->Map_comboBox->FormattingEnabled = true;
				this->Map_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"TheIsland_WP" });
				this->Map_comboBox->Location = System::Drawing::Point(12, 162);
				this->Map_comboBox->Name = L"Map_comboBox";
				this->Map_comboBox->Size = System::Drawing::Size(140, 21);
				this->Map_comboBox->TabIndex = 24;
				this->Map_comboBox->SelectedIndex = 0;
				// 
				// Map_label
				// 
				this->Map_label->AutoSize = true;
				this->Map_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Map_label->Location = System::Drawing::Point(12, 146);
				this->Map_label->Name = L"Map_label";
				this->Map_label->Size = System::Drawing::Size(31, 13);
				this->Map_label->TabIndex = 25;
				this->Map_label->Text = L"Map";
				// 
				// Max_players_label
				// 
				this->Max_players_label->AutoSize = true;
				this->Max_players_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Max_players_label->Location = System::Drawing::Point(158, 146);
				this->Max_players_label->Name = L"Max_players_label";
				this->Max_players_label->Size = System::Drawing::Size(75, 13);
				this->Max_players_label->TabIndex = 26;
				this->Max_players_label->Text = L"Max Players";
				// 
				// Max_Players_textBox
				// 
				this->Max_Players_textBox->Location = System::Drawing::Point(158, 162);
				this->Max_Players_textBox->Name = L"Max_Players_textBox";
				this->Max_Players_textBox->Size = System::Drawing::Size(75, 20);
				this->Max_Players_textBox->TabIndex = 27;
				this->Max_Players_textBox->Text = L"70";
				// 
				// Anti_Cheat_label
				// 
				this->Anti_Cheat_label->AutoSize = true;
				this->Anti_Cheat_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Anti_Cheat_label->Location = System::Drawing::Point(242, 146);
				this->Anti_Cheat_label->Name = L"Anti_Cheat_label";
				this->Anti_Cheat_label->Size = System::Drawing::Size(66, 13);
				this->Anti_Cheat_label->TabIndex = 28;
				this->Anti_Cheat_label->Text = L"Anti-Cheat";
				// 
				// Anti_Cheat_comboBox
				// 
				this->Anti_Cheat_comboBox->FormattingEnabled = true;
				this->Anti_Cheat_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Battle Eye On", L"Battle Eye Off" });
				this->Anti_Cheat_comboBox->Location = System::Drawing::Point(240, 161);
				this->Anti_Cheat_comboBox->Name = L"Anti_Cheat_comboBox";
				this->Anti_Cheat_comboBox->Size = System::Drawing::Size(121, 21);
				this->Anti_Cheat_comboBox->TabIndex = 29;
				this->Anti_Cheat_comboBox->SelectedIndex = 0;
				// 
				// Crossplay_label
				// 
				this->Crossplay_label->AutoSize = true;
				this->Crossplay_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->Crossplay_label->Location = System::Drawing::Point(370, 146);
				this->Crossplay_label->Name = L"Crossplay_label";
				this->Crossplay_label->Size = System::Drawing::Size(61, 13);
				this->Crossplay_label->TabIndex = 30;
				this->Crossplay_label->Text = L"Crossplay";
				// 
				// Crossplay_comboBox
				// 
				this->Crossplay_comboBox->FormattingEnabled = true;
				this->Crossplay_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Crossplay On", L"Crossplay Off" });
				this->Crossplay_comboBox->Location = System::Drawing::Point(368, 160);
				this->Crossplay_comboBox->Name = L"Crossplay_comboBox";
				this->Crossplay_comboBox->Size = System::Drawing::Size(121, 21);
				this->Crossplay_comboBox->TabIndex = 31;
				this->Crossplay_comboBox->SelectedIndex = 1;
				// 
				// Admin_Password_label
				// 
				this->Admin_Password_label->AutoSize = true;
				this->Admin_Password_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Admin_Password_label->Location = System::Drawing::Point(12, 190);
				this->Admin_Password_label->Name = L"Admin_Password_label";
				this->Admin_Password_label->Size = System::Drawing::Size(99, 13);
				this->Admin_Password_label->TabIndex = 32;
				this->Admin_Password_label->Text = L"Admin Password";
				// 
				// Admin_Password_textBox
				// 
				this->Admin_Password_textBox->Location = System::Drawing::Point(12, 207);
				this->Admin_Password_textBox->Name = L"Admin_Password_textBox";
				this->Admin_Password_textBox->Size = System::Drawing::Size(249, 20);
				this->Admin_Password_textBox->TabIndex = 33;
				// 
				// RCON_Enable_label
				// 
				this->RCON_Enable_label->AutoSize = true;
				this->RCON_Enable_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->RCON_Enable_label->Location = System::Drawing::Point(275, 190);
				this->RCON_Enable_label->Name = L"RCON_Enable_label";
				this->RCON_Enable_label->Size = System::Drawing::Size(85, 13);
				this->RCON_Enable_label->TabIndex = 34;
				this->RCON_Enable_label->Text = L"RCON Enable";
				// 
				// RCON_Enable_comboBox
				// 
				this->RCON_Enable_comboBox->FormattingEnabled = true;
				this->RCON_Enable_comboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"On", L"Off" });
				this->RCON_Enable_comboBox->Location = System::Drawing::Point(271, 206);
				this->RCON_Enable_comboBox->Name = L"RCON_Enable_comboBox";
				this->RCON_Enable_comboBox->Size = System::Drawing::Size(90, 21);
				this->RCON_Enable_comboBox->TabIndex = 35;
				this->RCON_Enable_comboBox->SelectedIndex = 1;
				// 
				// RCON_Port_label
				// 
				this->RCON_Port_label->AutoSize = true;
				this->RCON_Port_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->RCON_Port_label->Location = System::Drawing::Point(370, 190);
				this->RCON_Port_label->Name = L"RCON_Port_label";
				this->RCON_Port_label->Size = System::Drawing::Size(69, 13);
				this->RCON_Port_label->TabIndex = 36;
				this->RCON_Port_label->Text = L"RCON Port";
				// 
				// RCON_Port_textBox
				// 
				this->RCON_Port_textBox->Location = System::Drawing::Point(368, 206);
				this->RCON_Port_textBox->Name = L"RCON_Port_textBox";
				this->RCON_Port_textBox->Size = System::Drawing::Size(121, 20);
				this->RCON_Port_textBox->TabIndex = 37;
				this->RCON_Port_textBox->Text = L"27020";
				// 
				// Adding_Mods_Info_label
				// 
				this->Adding_Mods_Info_label->BackColor = System::Drawing::Color::White;
				this->Adding_Mods_Info_label->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				this->Adding_Mods_Info_label->Location = System::Drawing::Point(12, 234);
				this->Adding_Mods_Info_label->Name = L"Adding_Mods_Info_label";
				this->Adding_Mods_Info_label->Size = System::Drawing::Size(477, 57);
				this->Adding_Mods_Info_label->TabIndex = 38;
				this->Adding_Mods_Info_label->Text = resources->GetString(L"Adding_Mods_Info_label.Text");
				// 
				// Open_Curseforge_Website_button
				// 
				this->Open_Curseforge_Website_button->BackColor = System::Drawing::Color::Aqua;
				this->Open_Curseforge_Website_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Open_Curseforge_Website_button->Location = System::Drawing::Point(316, 264);
				this->Open_Curseforge_Website_button->Name = L"Open_Curseforge_Website_button";
				this->Open_Curseforge_Website_button->Size = System::Drawing::Size(165, 23);
				this->Open_Curseforge_Website_button->TabIndex = 39;
				this->Open_Curseforge_Website_button->Text = L"Open Curseforge Website";
				this->Open_Curseforge_Website_button->UseVisualStyleBackColor = false;
				this->Open_Curseforge_Website_button->Click += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::Open_Curseforge_Website_button_Click);
				// 
				// Turkey_Triales_button
				// 
				this->Turkey_Triales_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Turkey_Triales_button->Location = System::Drawing::Point(12, 314);
				this->Turkey_Triales_button->Name = L"Turkey_Triales_button";
				this->Turkey_Triales_button->Size = System::Drawing::Size(99, 23);
				this->Turkey_Triales_button->TabIndex = 40;
				this->Turkey_Triales_button->Text = L"Turkey Triales";
				this->Turkey_Triales_button->UseVisualStyleBackColor = true;
				this->Turkey_Triales_button->Click += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::Turkey_Triales_button_Click);
				// 
				// Add_ASA_Events_label
				// 
				this->Add_ASA_Events_label->AutoSize = true;
				this->Add_ASA_Events_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Add_ASA_Events_label->Location = System::Drawing::Point(15, 295);
				this->Add_ASA_Events_label->Name = L"Add_ASA_Events_label";
				this->Add_ASA_Events_label->Size = System::Drawing::Size(100, 13);
				this->Add_ASA_Events_label->TabIndex = 41;
				this->Add_ASA_Events_label->Text = L"Add ASA Events";
				// 
				// Winter_Wonderland_button
				// 
				this->Winter_Wonderland_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
					System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				this->Winter_Wonderland_button->Location = System::Drawing::Point(117, 314);
				this->Winter_Wonderland_button->Name = L"Winter_Wonderland_button";
				this->Winter_Wonderland_button->Size = System::Drawing::Size(125, 23);
				this->Winter_Wonderland_button->TabIndex = 42;
				this->Winter_Wonderland_button->Text = L"Winter Wonderland";
				this->Winter_Wonderland_button->UseVisualStyleBackColor = true;
				this->Winter_Wonderland_button->Click += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::Winter_Wonderland_button_Click);
				// 
				// Browse_button
				// 
				this->Browse_button->Location = System::Drawing::Point(414, 35);
				this->Browse_button->Name = L"Browse_button";
				this->Browse_button->Size = System::Drawing::Size(75, 23);
				this->Browse_button->TabIndex = 43;
				this->Browse_button->Text = L"Browse";
				this->Browse_button->UseVisualStyleBackColor = true;
				this->Browse_button->Click += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::Browse_button_Click);
				// 
				// Displayed_Server_Crash_Logs
				// 
				this->Displayed_Server_Crash_Logs->Location = System::Drawing::Point(815, 78);
				this->Displayed_Server_Crash_Logs->Multiline = true;
				this->Displayed_Server_Crash_Logs->Name = L"Displayed_Server_Crash_Logs";
				this->Displayed_Server_Crash_Logs->ReadOnly = true;
				this->Displayed_Server_Crash_Logs->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				this->Displayed_Server_Crash_Logs->Size = System::Drawing::Size(257, 269);
				this->Displayed_Server_Crash_Logs->TabIndex = 44;
				// 
				// Manager_Status_Messages
				// 
				this->Manager_Status_Messages->Location = System::Drawing::Point(504, 44);
				this->Manager_Status_Messages->Multiline = true;
				this->Manager_Status_Messages->Name = L"Manager_Status_Messages";
				this->Manager_Status_Messages->ReadOnly = true;
				this->Manager_Status_Messages->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				this->Manager_Status_Messages->Size = System::Drawing::Size(305, 355);
				this->Manager_Status_Messages->TabIndex = 45;
				// 
				// ASA_Server_Manager_UI
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
					static_cast<System::Int32>(static_cast<System::Byte>(255)));
				this->ClientSize = System::Drawing::Size(1084, 452);
				this->Controls->Add(this->Manager_Status_Messages);
				this->Controls->Add(this->Displayed_Server_Crash_Logs);
				this->Controls->Add(this->Browse_button);
				this->Controls->Add(this->Winter_Wonderland_button);
				this->Controls->Add(this->Add_ASA_Events_label);
				this->Controls->Add(this->Turkey_Triales_button);
				this->Controls->Add(this->Open_Curseforge_Website_button);
				this->Controls->Add(this->Adding_Mods_Info_label);
				this->Controls->Add(this->RCON_Port_textBox);
				this->Controls->Add(this->RCON_Port_label);
				this->Controls->Add(this->RCON_Enable_comboBox);
				this->Controls->Add(this->RCON_Enable_label);
				this->Controls->Add(this->Admin_Password_textBox);
				this->Controls->Add(this->Admin_Password_label);
				this->Controls->Add(this->Crossplay_comboBox);
				this->Controls->Add(this->Crossplay_label);
				this->Controls->Add(this->Anti_Cheat_comboBox);
				this->Controls->Add(this->Anti_Cheat_label);
				this->Controls->Add(this->Max_Players_textBox);
				this->Controls->Add(this->Max_players_label);
				this->Controls->Add(this->Map_label);
				this->Controls->Add(this->Map_comboBox);
				this->Controls->Add(this->Server_Password_textBox);
				this->Controls->Add(this->Server_Password_label);
				this->Controls->Add(this->Mods_label);
				this->Controls->Add(this->Server_Name_textBox);
				this->Controls->Add(this->Server_Name_label);
				this->Controls->Add(this->Server_Install_Folder_textBox);
				this->Controls->Add(this->Server_Install_Folder_label);
				this->Controls->Add(this->Mods_textBox);
				this->Controls->Add(this->Donate_button);
				this->Controls->Add(this->Edit_Game_ini_file_button);
				this->Controls->Add(this->Edit_GameUserSettings_ini_file_button);
				this->Controls->Add(this->Create_ASA_Server_Backup_Files_button);
				this->Controls->Add(this->Install_Update_ASA_Server_button);
				this->Controls->Add(this->Save_ASA_Manager_Config_button);
				this->Controls->Add(this->Server_Crashed_Check_label);
				this->Controls->Add(this->Server_Crashed_Check_progressBar);
				this->Controls->Add(this->Manager_Status_label);
				this->Controls->Add(this->ASA_Server_Crashed_Log_label);
				this->Controls->Add(this->Start_Server_button);
				this->Controls->Add(this->Stop_Server_button);
				this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				this->MaximumSize = System::Drawing::Size(1100, 491);
				this->MinimumSize = System::Drawing::Size(1100, 491);
				this->Name = L"ASA_Server_Manager_UI";
				this->Text = L"ASA Server Manager";
				this->Load += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::ASA_Server_Manager_UI_Load);
				this->ResumeLayout(false);
				this->PerformLayout();

			}
		#pragma endregion
		private: System::Void ASA_Server_Manager_UI_Load(System::Object^ sender, System::EventArgs^ e) {
			Load_Config();
		}
		private: System::Void Browse_button_Click(System::Object^ sender, System::EventArgs^ e) {
			Server_Install_Folder_textBox->Text = Functions::Function_Handler::Open_Browse_Window()->Trim();
		}
		private: System::Void Edit_GameUserSettings_ini_file_button_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void Donate_button_Click(System::Object^ sender, System::EventArgs^ e) {
			Functions::Function_Handler::Open_Donation_Website();
		}
		private: System::Void Open_Curseforge_Website_button_Click(System::Object^ sender, System::EventArgs^ e) {
			Functions::Function_Handler::Open_curseforge_Website();
		}
		private: System::Void Save_ASA_Manager_Config_button_Click(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void Install_Update_ASA_Server_button_Click(System::Object^ sender, System::EventArgs^ e) {
		
		}
		private: System::Void Turkey_Triales_button_Click(System::Object^ sender, System::EventArgs^ e) {
			Add_Mods("927083");
		}
		private: System::Void Winter_Wonderland_button_Click(System::Object^ sender, System::EventArgs^ e) {
			Add_Mods("927090");
		}
	};
}
