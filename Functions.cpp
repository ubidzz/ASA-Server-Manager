#pragma once
#include "Class_Handler.h"
#include <windows.h>
#include <iostream>
#include <string>
#pragma comment(lib,"urlmon.lib")
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <thread>

namespace Functions {

	using namespace System;
	using namespace System::IO;
    using namespace System::IO::Compression;
    using namespace System::Diagnostics;
    using namespace System::Windows::Forms;
    using namespace std;
    using namespace msclr::interop;
    using namespace System::Runtime::InteropServices;

    std::wstring Functions::Function_Handler::ExePath(void) {
        TCHAR buffer[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, buffer, MAX_PATH);
        std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
        return std::wstring(buffer).substr(0, pos);
    }
	System::Void Functions::Function_Handler::Create_Directory(System::String^ Folder_Path)
	{
        if(!Check_If_Folder_Exists(Folder_Path))
        {
            Directory::CreateDirectory(Folder_Path);
        }
	}
    System::Boolean Functions::Function_Handler::Check_If_File_Exists(System::String^ filePath)
    {
        if (System::IO::File::Exists(filePath)) {
            return true;
        }
        else {
            return false;
        }
    }
    System::Boolean Functions::Function_Handler::Check_If_Folder_Exists(System::String^ Folder_Path)
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
    System::Void Functions::Function_Handler::Open_curseforge_Website(void)
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
    System::Void Functions::Function_Handler::Open_Donation_Website(void)
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
    System::String^ Functions::Function_Handler::Open_Browse_Window(void)
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
    System::Boolean Functions::Function_Handler::Check_If_ASA_Server_Is_Running(void)
    {
        cli::array<Process^>^ processes = Process::GetProcessesByName("ArkAscendedServer");
        Boolean result = false;
        if (processes->Length > 0)
        {
            for (int i = 0; i < processes->Length; i++)
            {
                //checking to make sure there is a process ID 
                if (processes[i]->Id > 0) {
                    //checking to make sure the ASA server process is responding and not in the Not Responding state
                    result = processes[i]->Responding;
                }
            }
        }
        return result;
    }
    System::Void Functions::Function_Handler::Start_ASA_Server(void)
    {
        System::Diagnostics::Process^ process = gcnew System::Diagnostics::Process();
        ProcessStartInfo^ StartServer = gcnew ProcessStartInfo();
        StartServer->FileName = "Powershell.exe";
        StartServer->UseShellExecute = false;
        StartServer->CreateNoWindow = true;
        StartServer->Arguments = "Start-Process ASA_Manager_Config\\ASA_Start_Server.bat";
        StartServer->WindowStyle = ProcessWindowStyle::Hidden;
        process->StartInfo = StartServer;
        process->Start(); 
    }
    System::Void Functions::Function_Handler::Stop_ASA_Server(void)
    {
        if (Check_If_ASA_Server_Is_Running())
        {
            System::Diagnostics::Process^ process = gcnew System::Diagnostics::Process();
            ProcessStartInfo^ StartServer = gcnew ProcessStartInfo();
            StartServer->FileName = "Powershell.exe";
            StartServer->UseShellExecute = false;
            StartServer->CreateNoWindow = true;
            StartServer->Arguments = "Stop-Process -name ArkAscendedServer";
            StartServer->WindowStyle = ProcessWindowStyle::Hidden;
            process->StartInfo = StartServer;
            process->Start();
        }
    }

    System::String^ Functions::Function_Handler::Download_SteamCMD(System::String^ ASA_Server_Path)
    {
        //Check if the folder exists and if not then create the folder
        if (!Check_If_Folder_Exists("ASA_Manager_Config\\Downloaded_SteamCMD_Zip\\")) {
            Create_Directory("ASA_Manager_Config\\Downloaded_SteamCMD_Zip\\");
        }

        std::wstring download_link = L"http://steamcdn-a.akamaihd.net/client/installer/steamcmd.zip";
        LPCWSTR download_link_LPCWSTR = download_link.c_str();

        std::wstring Saved_Folder = ExePath() + L"\\ASA_Manager_Config\\Downloaded_SteamCMD_Zip\\steamcmd.zip";
        LPCWSTR Saved_Folder_LPCWSTR = Saved_Folder.c_str();

        HRESULT downloadFile;
        downloadFile = URLDownloadToFile(NULL, download_link_LPCWSTR, Saved_Folder_LPCWSTR, 0, NULL);
        switch (downloadFile)
        {
            case S_OK:
                return Unzip_SteamCMD(ASA_Server_Path);
            break;
			default:
                return "Unknown error: " + Marshal::GetExceptionForHR(downloadFile)->Message;
            break;
        }
    }

    System::String^ Functions::Function_Handler::Unzip_SteamCMD(System::String^ ASA_Server_Path) {
		// Get the path to the current executable
        System::String^ exepath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
        System::String^ directoryPath = System::IO::Path::GetDirectoryName(exepath);

		// Get the full path to the zip file and extract path folder
        String^ zipPath = directoryPath + "\\ASA_Manager_Config\\Downloaded_SteamCMD_Zip\\steamcmd.zip";
        String^ extractPath = directoryPath + "\\ASA_Manager_Config\\SteamCMD";

		// Check if the folder exists and if not then create the folder
		if (!Functions::Function_Handler::Check_If_Folder_Exists(extractPath)) {
            Functions::Function_Handler::Create_Directory(extractPath);
		}

        System::Diagnostics::Process^ StartProcess = gcnew System::Diagnostics::Process();
        ProcessStartInfo^ unzipProcess = gcnew ProcessStartInfo();
        unzipProcess->FileName = "PowerShell.exe";
        unzipProcess->UseShellExecute = true;
        unzipProcess->CreateNoWindow = false;
        unzipProcess->Arguments = "Expand-Archive '" + zipPath + "' -DestinationPath '" + extractPath + "'";
        unzipProcess->WindowStyle = ProcessWindowStyle::Hidden;
        StartProcess->StartInfo = unzipProcess;
        StartProcess->Start();

		Boolean^ steamcmdExists = Functions::Function_Handler::Check_If_File_Exists(extractPath + "steamcmd.exe");
		if (steamcmdExists) {
			// build the steamcmd install batch file
            Batch::Batch_Hander::SteamCMD_Install_ASA_Server_Batch_File(ASA_Server_Path);

			Functions::Function_Handler::Start_Steam_Batch_File();

			return "Successfully extracted the steamcmd.exe file and will now start the steamcmd.exe to download and install the ASA Server files! \r\n\r\nA black window will open and when it close your ASA server will be fully installed!";
		}
		else {
			return "Was not able to write the steamcmd.exe file to the folder: " + extractPath;
		}

    }
    System::Void Functions::Function_Handler::Start_Steam_Batch_File(void) {
		// Get the path to the current executable
        System::String^ exepath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
        System::String^ directoryPath = System::IO::Path::GetDirectoryName(exepath);

		// run the steamcmd install batch file
        System::Diagnostics::Process^ StartProcess = gcnew System::Diagnostics::Process();
        ProcessStartInfo^ unzipProcess = gcnew ProcessStartInfo();
        unzipProcess->FileName = directoryPath + "\\ASA_Manager_Config\\SteamCMD_Install_ASA_Server.bat";
        unzipProcess->UseShellExecute = false;
        unzipProcess->CreateNoWindow = false;
        unzipProcess->WindowStyle = ProcessWindowStyle::Normal;
        StartProcess->StartInfo = unzipProcess;
        StartProcess->Start();
    }
}