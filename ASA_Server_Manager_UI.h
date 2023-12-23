#pragma once

namespace ASAServerManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Button^ Stop_Server_button;
	protected:
	private: System::Windows::Forms::Button^ Start_Server_button;
	private: System::Windows::Forms::Label^ ASA_Server_Crashed_Log_label;
	private: System::Windows::Forms::ListBox^ Displayed_Server_Crash_Logs;
	private: System::Windows::Forms::ListBox^ Displayed_Manager_Status;


	private: System::Windows::Forms::Label^ Manager_Status_label;
	private: System::Windows::Forms::ProgressBar^ Server_Crashed_Check_progressBar;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ Mods_textBox;

	private: System::Windows::Forms::Label^ Server_Install_Folder_label;
	private: System::Windows::Forms::TextBox^ Server_Install_Folder_textBox;

	private: System::Windows::Forms::Label^ Server_Name_label;
	private: System::Windows::Forms::TextBox^ Server_Name_textBox;

	private: System::Windows::Forms::Label^ Mods_label;
	private: System::Windows::Forms::Label^ Server_Password_label;
	private: System::Windows::Forms::TextBox^ Server_Password_textBox;




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
			this->Displayed_Server_Crash_Logs = (gcnew System::Windows::Forms::ListBox());
			this->Displayed_Manager_Status = (gcnew System::Windows::Forms::ListBox());
			this->Manager_Status_label = (gcnew System::Windows::Forms::Label());
			this->Server_Crashed_Check_progressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->Mods_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Server_Install_Folder_label = (gcnew System::Windows::Forms::Label());
			this->Server_Install_Folder_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Server_Name_label = (gcnew System::Windows::Forms::Label());
			this->Server_Name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->Mods_label = (gcnew System::Windows::Forms::Label());
			this->Server_Password_label = (gcnew System::Windows::Forms::Label());
			this->Server_Password_textBox = (gcnew System::Windows::Forms::TextBox());
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
			this->Start_Server_button->Location = System::Drawing::Point(854, 13);
			this->Start_Server_button->Name = L"Start_Server_button";
			this->Start_Server_button->Size = System::Drawing::Size(105, 31);
			this->Start_Server_button->TabIndex = 1;
			this->Start_Server_button->Text = L"Start Server";
			this->Start_Server_button->UseVisualStyleBackColor = false;
			// 
			// ASA_Server_Crashed_Log_label
			// 
			this->ASA_Server_Crashed_Log_label->AutoSize = true;
			this->ASA_Server_Crashed_Log_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ASA_Server_Crashed_Log_label->Location = System::Drawing::Point(872, 55);
			this->ASA_Server_Crashed_Log_label->Name = L"ASA_Server_Crashed_Log_label";
			this->ASA_Server_Crashed_Log_label->Size = System::Drawing::Size(162, 15);
			this->ASA_Server_Crashed_Log_label->TabIndex = 2;
			this->ASA_Server_Crashed_Log_label->Text = L"ASA Server Crashed Log";
			// 
			// Displayed_Server_Crash_Logs
			// 
			this->Displayed_Server_Crash_Logs->FormattingEnabled = true;
			this->Displayed_Server_Crash_Logs->Location = System::Drawing::Point(826, 73);
			this->Displayed_Server_Crash_Logs->Name = L"Displayed_Server_Crash_Logs";
			this->Displayed_Server_Crash_Logs->ScrollAlwaysVisible = true;
			this->Displayed_Server_Crash_Logs->Size = System::Drawing::Size(246, 264);
			this->Displayed_Server_Crash_Logs->TabIndex = 5;
			this->Displayed_Server_Crash_Logs->UseTabStops = false;
			// 
			// Displayed_Manager_Status
			// 
			this->Displayed_Manager_Status->FormattingEnabled = true;
			this->Displayed_Manager_Status->Location = System::Drawing::Point(499, 44);
			this->Displayed_Manager_Status->Name = L"Displayed_Manager_Status";
			this->Displayed_Manager_Status->Size = System::Drawing::Size(303, 355);
			this->Displayed_Manager_Status->TabIndex = 6;
			// 
			// Manager_Status_label
			// 
			this->Manager_Status_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Manager_Status_label->Location = System::Drawing::Point(582, 13);
			this->Manager_Status_label->Name = L"Manager_Status_label";
			this->Manager_Status_label->Size = System::Drawing::Size(121, 28);
			this->Manager_Status_label->TabIndex = 7;
			this->Manager_Status_label->Text = L"Manager Status";
			this->Manager_Status_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Server_Crashed_Check_progressBar
			// 
			this->Server_Crashed_Check_progressBar->Location = System::Drawing::Point(826, 368);
			this->Server_Crashed_Check_progressBar->Name = L"Server_Crashed_Check_progressBar";
			this->Server_Crashed_Check_progressBar->Size = System::Drawing::Size(246, 23);
			this->Server_Crashed_Check_progressBar->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(872, 350);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 15);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Server Crashed Check";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 413);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(93, 413);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(174, 413);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 12;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(255, 413);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 13;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(337, 413);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 14;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(418, 413);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 15;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// Mods_textBox
			// 
			this->Mods_textBox->Location = System::Drawing::Point(12, 371);
			this->Mods_textBox->Name = L"Mods_textBox";
			this->Mods_textBox->Size = System::Drawing::Size(450, 20);
			this->Mods_textBox->TabIndex = 16;
			// 
			// Server_Install_Folder_label
			// 
			this->Server_Install_Folder_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Server_Install_Folder_label->Location = System::Drawing::Point(12, 9);
			this->Server_Install_Folder_label->Name = L"Server_Install_Folder_label";
			this->Server_Install_Folder_label->Size = System::Drawing::Size(184, 23);
			this->Server_Install_Folder_label->TabIndex = 17;
			this->Server_Install_Folder_label->Text = L"Server Installation Folder";
			this->Server_Install_Folder_label->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// Server_Install_Folder_textBox
			// 
			this->Server_Install_Folder_textBox->Location = System::Drawing::Point(12, 35);
			this->Server_Install_Folder_textBox->Name = L"Server_Install_Folder_textBox";
			this->Server_Install_Folder_textBox->Size = System::Drawing::Size(450, 20);
			this->Server_Install_Folder_textBox->TabIndex = 18;
			// 
			// Server_Name_label
			// 
			this->Server_Name_label->AutoSize = true;
			this->Server_Name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Server_Name_label->Location = System::Drawing::Point(15, 62);
			this->Server_Name_label->Name = L"Server_Name_label";
			this->Server_Name_label->Size = System::Drawing::Size(80, 13);
			this->Server_Name_label->TabIndex = 19;
			this->Server_Name_label->Text = L"Server Name";
			// 
			// Server_Name_textBox
			// 
			this->Server_Name_textBox->Location = System::Drawing::Point(12, 79);
			this->Server_Name_textBox->Name = L"Server_Name_textBox";
			this->Server_Name_textBox->Size = System::Drawing::Size(450, 20);
			this->Server_Name_textBox->TabIndex = 20;
			// 
			// Mods_label
			// 
			this->Mods_label->AutoSize = true;
			this->Mods_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Mods_label->Location = System::Drawing::Point(18, 351);
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
			this->Server_Password_label->Location = System::Drawing::Point(18, 106);
			this->Server_Password_label->Name = L"Server_Password_label";
			this->Server_Password_label->Size = System::Drawing::Size(102, 13);
			this->Server_Password_label->TabIndex = 22;
			this->Server_Password_label->Text = L"Server Password";
			// 
			// Server_Password_textBox
			// 
			this->Server_Password_textBox->Location = System::Drawing::Point(12, 123);
			this->Server_Password_textBox->Name = L"Server_Password_textBox";
			this->Server_Password_textBox->Size = System::Drawing::Size(450, 20);
			this->Server_Password_textBox->TabIndex = 23;
			// 
			// ASA_Server_Manager_UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(1084, 452);
			this->Controls->Add(this->Server_Password_textBox);
			this->Controls->Add(this->Server_Password_label);
			this->Controls->Add(this->Mods_label);
			this->Controls->Add(this->Server_Name_textBox);
			this->Controls->Add(this->Server_Name_label);
			this->Controls->Add(this->Server_Install_Folder_textBox);
			this->Controls->Add(this->Server_Install_Folder_label);
			this->Controls->Add(this->Mods_textBox);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Server_Crashed_Check_progressBar);
			this->Controls->Add(this->Manager_Status_label);
			this->Controls->Add(this->Displayed_Manager_Status);
			this->Controls->Add(this->Displayed_Server_Crash_Logs);
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
	}
	};
}
