#pragma once
#include "Class_Handler.h"

namespace Functions {

	using namespace System;
	using namespace System::IO;
    using namespace System::Diagnostics;
    using namespace System::Windows::Forms;

	System::Void Functions::Function_Handler::Create_Directory(System::String^ Folder_Path)
	{
        if(Check_If_Folder_Exists(Folder_Path))
        {
            Directory::CreateDirectory(Folder_Path);
        }
	}
    System::Boolean^ Functions::Function_Handler::Check_If_Folder_Exists(System::String^ Folder_Path)
    {
        // Determine whether the directory exists.
        if (Directory::Exists(Folder_Path))
        {
            return true;
        }
        else {
            return false;
        }
    }
    System::Void Functions::Function_Handler::Open_curseforge_Website()
    {
        System::Diagnostics::Process^ process = gcnew System::Diagnostics::Process();
        ProcessStartInfo^ DonationProcess = gcnew ProcessStartInfo();
        DonationProcess->FileName = "Powershell.exe";
        DonationProcess->UseShellExecute = false;
        DonationProcess->CreateNoWindow = true;
        DonationProcess->Arguments = "Start-Process https://www.curseforge.com/ark-survival-ascended";
        DonationProcess->WindowStyle = ProcessWindowStyle::Hidden;
        process->StartInfo = DonationProcess;
        process->Start();
    }
    System::Void Functions::Function_Handler::Open_Donation_Website()
    {
        System::Diagnostics::Process^ process = gcnew System::Diagnostics::Process();
        ProcessStartInfo^ DonationProcess = gcnew ProcessStartInfo();
        DonationProcess->FileName = "Powershell.exe";
        DonationProcess->UseShellExecute = false;
        DonationProcess->CreateNoWindow = true;
        DonationProcess->Arguments = "Start-Process https://www.paypal.com/donate/?hosted_button_id=A8PXV3UDAHW54";
        DonationProcess->WindowStyle = ProcessWindowStyle::Hidden;
        process->StartInfo = DonationProcess;
        process->Start();
    }
    System::String^ Functions::Function_Handler::Open_Browse_Window()
    {
        String^ result;
        FolderBrowserDialog^ SelectFolderDialog = gcnew FolderBrowserDialog();

        //Setup dialog box
        SelectFolderDialog->Description = "Select directory to store your ASA server files to";
        SelectFolderDialog->ShowNewFolderButton = true;
        SelectFolderDialog->RootFolder = System::Environment::SpecialFolder::Desktop;

        //Display dialog box
        if (SelectFolderDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            result = SelectFolderDialog->SelectedPath;
        }
        return result;
    }
    System::Boolean^ Functions::Function_Handler::Check_If_ASA_Server_Is_Running()
    {
        cli::array<Process^>^ processes = Process::GetProcessesByName("ArkAscendedServer");
        Boolean^ result = false;
        if (processes->Length > 0)
        {
            for (int i = 0; i < processes->Length; i++)
            {
                //checking to make sure there is a process ID 
                if (processes[i]->Id > 0) {
                    //checking to make sure the ASA server process is responding and not in the Not Responding state
                    if (processes[i]->Responding > 0) {
                        //ASA server is running and responding
                        result = true;
                    }
                }
            }
        }
        return result;
    }
    System::Void Functions::Function_Handler::Start_ASA_Server()
    {
        System::Diagnostics::Process^ process = gcnew System::Diagnostics::Process();
        ProcessStartInfo^ StartServer = gcnew ProcessStartInfo();
        StartServer->FileName = "Powershell.exe";
        StartServer->UseShellExecute = false;
        StartServer->CreateNoWindow = true;
        StartServer->Arguments = "Start-Process ASA_Manager_Config/ASA_Start_Server.bat";
        StartServer->WindowStyle = ProcessWindowStyle::Hidden;
        process->StartInfo = StartServer;
        process->Start();
    }
}