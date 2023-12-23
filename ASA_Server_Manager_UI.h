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
			this->SuspendLayout();
			// 
			// ASA_Server_Manager_UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"ASA_Server_Manager_UI";
			this->Text = L"ASA_Server_Manager_UI";
			this->Load += gcnew System::EventHandler(this, &ASA_Server_Manager_UI::ASA_Server_Manager_UI_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ASA_Server_Manager_UI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
