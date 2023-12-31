#pragma once
#include "Class_Handler.h"
#include <windows.h>
#include <iostream>
#include <string>
#pragma comment(lib,"urlmon.lib")
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <thread>
#include <cstdio>
#include <chrono>
#include <iomanip>

namespace Functions {

	using namespace System;
	using namespace System::IO;
    using namespace System::IO::Compression;
    using namespace System::Diagnostics;
    using namespace System::Windows::Forms;
    using namespace std;
    using namespace msclr::interop;
    using namespace System::Runtime::InteropServices;
    using namespace System::Text;
    using namespace System::Net::Sockets;

    std::wstring Functions::Function_Handler::ExePath(void) {
        TCHAR buffer[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, buffer, MAX_PATH);
        std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
        return std::wstring(buffer).substr(0, pos);
    }
	System::Void Functions::Function_Handler::Create_Directory(System::String^ Folder_Path)
	{
        System::String^ exepath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
        System::String^ directoryPath = System::IO::Path::GetDirectoryName(exepath);

        if(!Check_If_Folder_Exists(directoryPath + "\\" + Folder_Path))
        {
            Directory::CreateDirectory(directoryPath + "\\" + Folder_Path);
        }
	}
    System::Boolean Functions::Function_Handler::Check_If_File_Exists(System::String^ filePath)
    {
        System::String^ exepath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
        System::String^ directoryPath = System::IO::Path::GetDirectoryName(exepath);

        if (System::IO::File::Exists(directoryPath + "\\" + filePath)) {
            return true;
        }
        else {
            return false;
        }
    }
    System::Boolean Functions::Function_Handler::Check_If_Folder_Exists(System::String^ Folder_Path)
    {
        System::String^ exepath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
        System::String^ directoryPath = System::IO::Path::GetDirectoryName(exepath);

        // Determine whether the directory exists.
        if (Directory::Exists(directoryPath + "\\" + Folder_Path))
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
    System::Void Functions::Function_Handler::EditLineInFile(System::String^ filePath, System::String^ targetLine, System::String^ newLine) {
        std::string filePathStr = msclr::interop::marshal_as<std::string>(filePath);
        std::string targetLineStr = msclr::interop::marshal_as<std::string>(targetLine);
        std::string newLineStr = msclr::interop::marshal_as<std::string>(newLine);

        std::ifstream inputFile(filePathStr);
        if (!inputFile) {
            return;
        }

        std::ofstream outputFile("temp.txt");
        if (!outputFile) {
            inputFile.close();
            return;
        }

        std::string line;

        while (std::getline(inputFile, line)) {
            if (line == targetLineStr) {
                outputFile << newLineStr << std::endl;
            }
            else {
                outputFile << line << std::endl;
            }
        }

        inputFile.close();
        outputFile.close();

        if (std::remove(filePathStr.c_str()) != 0) {
            std::cerr << "Failed to remove original file: " << filePathStr << std::endl;
            return;
        }

        if (std::rename("temp.txt", filePathStr.c_str()) != 0) {
            std::cerr << "Failed to rename temporary file" << std::endl;
            return;
        }
    }
    System::String^ Functions::Function_Handler::Download_SteamCMD(System::String^ ASA_Server_Path)
    {

        std::wstring download_link = L"http://steamcdn-a.akamaihd.net/client/installer/steamcmd.zip";
        LPCWSTR download_link_LPCWSTR = download_link.c_str();

        std::wstring Saved_Folder = ExePath() + L"\\ASA_Manager_Config\\steamcmd.zip";
        LPCWSTR Saved_Folder_LPCWSTR = Saved_Folder.c_str();

        HRESULT downloadFile;
        downloadFile = URLDownloadToFile(NULL, download_link_LPCWSTR, Saved_Folder_LPCWSTR, NULL, NULL);
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
        String^ zipPath = directoryPath + "\\ASA_Manager_Config\\steamcmd.zip";
        String^ extractPath = directoryPath + "\\ASA_Manager_Config\\SteamCMD";

		// Check if the folder exists and if not then create the folder
		if (!Functions::Function_Handler::Check_If_Folder_Exists("\\ASA_Manager_Config\\SteamCMD")) {
            Functions::Function_Handler::Create_Directory("\\ASA_Manager_Config\\SteamCMD");
		}

		// Unziping the zip file
        System::Diagnostics::Process^ StartProcess = gcnew System::Diagnostics::Process();
        ProcessStartInfo^ unzipProcess = gcnew ProcessStartInfo();
        unzipProcess->FileName = "PowerShell.exe";
        unzipProcess->UseShellExecute = true;
        unzipProcess->CreateNoWindow = false;
        unzipProcess->Arguments = "Expand-Archive '" + zipPath + "' -DestinationPath '" + extractPath + "'";
        unzipProcess->WindowStyle = ProcessWindowStyle::Hidden;
        StartProcess->StartInfo = unzipProcess;
        StartProcess->Start();
		StartProcess->WaitForExit();

		//making sure that the steamcmd.exe file exists before continuing on or stop here and returning an error
		if (Functions::Function_Handler::Check_If_File_Exists("\\ASA_Manager_Config\\SteamCMD\\steamcmd.exe")) {

			// removing the zip file from the ASA_Manager_Config folder because we don't need it no more
            std::string convertedString = msclr::interop::marshal_as<std::string>(zipPath);
            const char* path = convertedString.c_str();
            std::remove(path);

			// building the steamcmd install batch file
            Batch::Batch_Hander::SteamCMD_Install_ASA_Server_Batch_File(ASA_Server_Path, directoryPath);

			//starting the steamcmd install batch file
			Functions::Function_Handler::Start_SteamCMD_Batch_File();

            INI::INI_Handler::Game_INI_File(ASA_Server_Path);

			//returning the success message
			return "Successfully extracted the steamcmd.exe file and will now start the steamcmd.exe to download and install the ASA Server files! \r\n\r\nA black window will open and when it close your ASA server will be fully installed!";
		}
		else {
			//returning the error message
			return "Was not able to write the steamcmd.exe file to the folder: " + extractPath;
		}
    }
    System::Void Functions::Function_Handler::Start_SteamCMD_Batch_File(void) {

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

    System::String^ Functions::Function_Handler::CreateBackup(System::String^ folderPath)
    {
        if (!Functions::Function_Handler::Check_If_Folder_Exists("ASA_Manager_Config\\Server_backups"))
        {
            Functions::Function_Handler::Create_Directory("ASA_Manager_Config\\Server_backups");
        }

        // Get the path to the current executable
        System::String^ exepath = System::Reflection::Assembly::GetExecutingAssembly()->Location;
        System::String^ directoryPath = System::IO::Path::GetDirectoryName(exepath);

		// full path to the backup folder and server folder
		System::String^ backupFolderPath = directoryPath + "\\ASA_Manager_Config\\Server_backups\\";
		System::String^ ServerFolderPath = folderPath + "\\ShooterGame\\Saved";

        try
        {
            // Check if the source folder exists
            if (!Directory::Exists(ServerFolderPath))
            {
                return "Source folder does not exist.";
            }

            // Get the current time
            auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            std::tm timeInfo;
            localtime_s(&timeInfo, &currentTime);

            // Get the name of the month
            std::string monthName;
            switch (timeInfo.tm_mon)
            {
                case 0: monthName = "January"; break;
                case 1: monthName = "February"; break;
                case 2: monthName = "March"; break;
                case 3: monthName = "April"; break;
                case 4: monthName = "May"; break;
                case 5: monthName = "June"; break;
                case 6: monthName = "July"; break;
                case 7: monthName = "August"; break;
                case 8: monthName = "September"; break;
                case 9: monthName = "October"; break;
                case 10: monthName = "November"; break;
                case 11: monthName = "December"; break;
                default: monthName = "Unknown"; break;
            }

            // Determine AM/PM based on the hour
            std::string amPm = (timeInfo.tm_hour >= 12) ? "PM" : "AM";
            int hour12 = (timeInfo.tm_hour % 12 == 0) ? 12 : timeInfo.tm_hour % 12;

            // Create the backup folder name with timestamp
            String^ backupPathStr = String::Format("{0}{1} {2} {3} {4}.{5:00} {6}",
                backupFolderPath, gcnew String(monthName.c_str()), timeInfo.tm_mday, timeInfo.tm_year + 1900,
                hour12, timeInfo.tm_min, gcnew String(amPm.c_str()));

            // Check if the backup folder exists, if not create it
            if (!Functions::Function_Handler::Check_If_Folder_Exists(backupPathStr))
            {
                Directory::CreateDirectory(backupPathStr);
            }

            // Copy all files and subfolders recursively
            CopyFilesAndSubfolders(ServerFolderPath, backupPathStr);

            // Backup completed
			return "Backup created successfully at: " + backupPathStr;
        }
        catch (const std::exception& ex)
        {
            // Handle any exceptions and display error message
			return gcnew System::String(ex.what());
        }
    }
    System::Void Functions::Function_Handler::CopyFilesAndSubfolders(System::String^ sourcePath, System::String^ destinationPath)
    {
        // Copy all files in the source folder to the destination folder
        for each (String ^ filePath in Directory::GetFiles(sourcePath))
        {
            String^ fileName = Path::GetFileName(filePath);
            String^ destinationFilePath = Path::Combine(destinationPath, fileName);
            File::Copy(filePath, destinationFilePath, true);
        }

        // Recursively copy all subfolders
        for each (String ^ subfolderPath in Directory::GetDirectories(sourcePath))
        {
            String^ subfolderName = Path::GetFileName(subfolderPath);
            String^ destinationSubfolderPath = Path::Combine(destinationPath, subfolderName);
            Directory::CreateDirectory(destinationSubfolderPath);
            CopyFilesAndSubfolders(subfolderPath, destinationSubfolderPath);
        }
    }
    /*
	//RCON function to send commands to the ASA server (Still being developed)
    System::String^ Functions::Function_Handler::SendRconCommand(System::String^ serverIP, int serverPort, System::String^ password, System::String^ command) {
        System::String^ serverIP = "127.0.0.1";
        int serverPort = System::Convert::ToInt32(RCON_Port_textBox->Text);
        System::String^ password = Admin_Password_textBox->Text;
        System::String^ command = "SaveWorld";
        
        System::String^ response = nullptr;
        TcpClient^ client = gcnew TcpClient();
        try {
            client->Connect(serverIP, serverPort);
            if (client->Connected) {
                // Get the network stream to send and receive data
                NetworkStream^ stream = client->GetStream();

                // Convert the password to bytes using ASCII encoding
                cli::array<Byte>^ passwordBytes = Encoding::ASCII->GetBytes(password);

                // Convert the command to bytes using ASCII encoding
                cli::array<Byte>^ commandBytes = Encoding::ASCII->GetBytes(command);

                // Prepare the SERVERDATA_AUTH packet
                cli::array<Byte>^ authPacket = gcnew cli::array<Byte>(10 + passwordBytes->Length);
                authPacket[0] = 0xFF;
                authPacket[1] = 0xFF;
                authPacket[2] = 0xFF;
                authPacket[3] = 0xFF;

                // Calculate the packet size
                int authPacketSize = authPacket->Length - 4;

                // Convert the packet size to bytes using little endian encoding
                cli::array<Byte>^ authPacketSizeBytes = BitConverter::GetBytes(authPacketSize);

                // Copy the packet size bytes to the authPacket array
                Array::Copy(authPacketSizeBytes, 0, authPacket, 4, authPacketSizeBytes->Length);

                authPacket[8] = 0x03; // Set the packet ID for SERVERDATA_AUTH
                authPacket[9] = 0x00;
                Array::Copy(passwordBytes, 0, authPacket, 10, passwordBytes->Length);

                // Send the SERVERDATA_AUTH packet
                stream->Write(authPacket, 0, authPacket->Length);

                // Receive and discard the response to the SERVERDATA_AUTH packet
                cli::array<Byte>^ discardBytes = gcnew cli::array<Byte>(4096);
                int discardBytesRead = stream->Read(discardBytes, 0, discardBytes->Length);

                // Prepare the SERVERDATA_EXECCOMMAND packet
                cli::array<Byte>^ execCommandPacket = gcnew cli::array<Byte>(10 + passwordBytes->Length + commandBytes->Length);
                execCommandPacket[0] = 0xFF;
                execCommandPacket[1] = 0xFF;
                execCommandPacket[2] = 0xFF;
                execCommandPacket[3] = 0xFF;

                // Calculate the packet size
                int execCommandPacketSize = execCommandPacket->Length - 4;

                // Convert the packet size to bytes using little endian encoding
                cli::array<Byte>^ execCommandPacketSizeBytes = BitConverter::GetBytes(execCommandPacketSize);

                // Copy the packet size bytes to the execCommandPacket array
                Array::Copy(execCommandPacketSizeBytes, 0, execCommandPacket, 4, execCommandPacketSizeBytes->Length);

                execCommandPacket[8] = 0x02; // Set the packet ID for SERVERDATA_EXECCOMMAND
                execCommandPacket[9] = 0x00;
                Array::Copy(passwordBytes, 0, execCommandPacket, 10, passwordBytes->Length);
                Array::Copy(commandBytes, 0, execCommandPacket, 10 + passwordBytes->Length, commandBytes->Length);

                // Send the SERVERDATA_EXECCOMMAND packet
				stream->Write(execCommandPacket, 0, execCommandPacket->Length);
                // Receive the response to the SERVERDATA_EXECCOMMAND packet
                cli::array<Byte>^ responseBytes = gcnew cli::array<Byte>(4096);
                int bytesRead = stream->Read(responseBytes, 0, responseBytes->Length);

                // Convert the response bytes to a string using ASCII encoding
                response = Encoding::ASCII->GetString(responseBytes, 0, bytesRead);

                // Close the connection
                stream->Close();
                client->Close();
            }
            else {
                response = "Error: Connection failed.";
            }
        }
        catch (Exception^ ex) {
            response = "Error: " + ex->Message;
        }
        return response;
	}*/

}