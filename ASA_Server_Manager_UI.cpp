#include "ASA_Server_Manager_UI.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ASAServerManager::ASA_Server_Manager_UI form;
	Application::Run(% form);
}