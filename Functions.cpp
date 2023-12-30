#pragma once
#include "Class_Handler.h"
#include<Windows.h>
#include <iostream>

#include <urlmon.h>
#pragma comment(lib,"urlmon.lib")
#include <zip.h>
#include <msclr/marshal_cppstd.h>

namespace Functions {

	using namespace System;
	using namespace System::IO;
    using namespace System::IO::Compression;
    using namespace System::Diagnostics;
    using namespace System::Windows::Forms;
    using namespace std;

	System::Void Functions::Function_Handler::Create_Directory(System::String^ Folder_Path)
	{
        if(!Check_If_Folder_Exists(Folder_Path))
        {
            Directory::CreateDirectory(Folder_Path);
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
    System::Boolean Functions::Function_Handler::Check_If_ASA_Server_Is_Running()
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
    System::Void Functions::Function_Handler::Start_ASA_Server()
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
    System::Void Functions::Function_Handler::Stop_ASA_Server()
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
    // Working on this one function but stuck on it
    System::Void Functions::Function_Handler::Download_SteamCMD(void)
    {
        LPCWSTR download_link = L"https://steamcdn-a.akamaihd.net/client/installer/steamcmd.zip";
        LPCWSTR Saved_Folder = L"ASA_Manager_Config\\SteamCMD_Zip\\";

        //Check if the folder exists and if not then create the folder
        if (!Check_If_Folder_Exists("ASA_Manager_Config\\Downloaded_SteamCMD_Zip\\")) {
            Create_Directory("ASA_Manager_Config\\Downloaded_SteamCMD_Zip\\");
        }

        HRESULT downloadFile;
        downloadFile = URLDownloadToFile(NULL, download_link, Saved_Folder, NULL, NULL);
        switch (downloadFile)
        {
            case S_OK:
                //Unzip_SteamCMD(); <-- make function
                break;
            case E_OUTOFMEMORY:
                MessageBox::Show("Ran out of memory while download the SteamCMD zip file!");
            break;
            case INET_E_DOWNLOAD_FAILURE:
                MessageBox::Show("Filed to download SteamCMD.zip file!");
            break;
        }
    }
    System::Void Functions::Function_Handler::Unzip_SteamCMD(void)
    {
        string zipPath = "ASA_Manager_Config\\Downloaded_SteamCMD_Zip\\steamcmd.zip";
        string extractPath = "ASA_Manager_Config\\SteamCMD\\";
        //Check if the folder exists and if not then create the folder
        if (!Check_If_Folder_Exists(msclr::interop::marshal_as<System::String^>(extractPath))) {
            Create_Directory(msclr::interop::marshal_as<System::String^>(extractPath));
        }
        extractZip(zipPath, extractPath);
    }

    System::Void Functions::Function_Handler::extractZip(string zipPath, string extractPath) {
        // Open the zip archive
        zip* archive = zip_open(zipPath.c_str(), 0, nullptr);

        // Check if the archive was opened successfully
        if (archive == nullptr) {
            // Handle error opening the archive
            return;
        }

        // Get the number of entries in the archive
        int numEntries = zip_get_num_entries(archive, 0);

        // Extract all entries in the archive
        for (int i = 0; i < numEntries; i++) {
            // Get the name of the entry
            const char* entryName = zip_get_name(archive, i, 0);

            // Build the full path for extracting the entry
            std::string entryPath = extractPath + "/" + std::string(entryName);

            // Open the entry for reading
            zip_file* entry = zip_fopen_index(archive, i, 0);

            // Check if the entry was opened successfully
            if (entry == nullptr) {
                // Handle error opening the entry
                continue;
            }

            // Create the directory for the entry if it doesn't exist
            string entryDirectory = entryPath.substr(0, entryPath.find_last_of("/\\"));
            Create_Directory(msclr::interop::marshal_as<System::String^>(entryDirectory));

            // Open the output file for writing
            FILE* outputFile = fopen(entryPath.c_str(), "wb");

            // Check if the output file was opened successfully
            if (outputFile == nullptr) {
                // Handle error opening the output file
                zip_fclose(entry);
                continue;
            }

            // Read and write the contents of the entry
            zip_int64_t bytesRead;
            char buffer[1024];
            while ((bytesRead = zip_fread(entry, buffer, sizeof(buffer))) > 0) {
                fwrite(buffer, 1, bytesRead, outputFile);
            }

            // Close the output file
            fclose(outputFile);

            // Close the entry
            zip_fclose(entry);
        }

        // Close the archive
        zip_close(archive);
    }
}