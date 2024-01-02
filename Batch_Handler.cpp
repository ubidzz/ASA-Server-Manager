#pragma once
#include "Class_Handler.h"
#include <iostream>

namespace Batch {

	using namespace System;
	using namespace System::IO;

	System::String^ Batch::Batch_Hander::Build_Batch_Start_Server_File(String^ CreateOrUpdateMessage, String^ Folder_Path, String^ Max_Players, String^ Server_Name, String^ Server_Password, String^ Admin_Password, String^ Map, String^ Enable_BattleEye, String^ Enable_Crossplay, String^ Mods) {

		String^ BattleEye;
		String^ Crossplay;
		String^ result;

		if (Enable_BattleEye == "Battle Eye On")
		{
			BattleEye = "-UseBattlEye";
		}
		else {
			BattleEye = "-NoBattlEye";
		}
		if (Enable_Crossplay == "Crossplay On")
		{
			Crossplay = "-crossplay";
		}
		else {
			Crossplay = "";
		}
		String^ fileName = "ASA_Manager_Config\\ASA_Start_Server.bat";
		StreamWriter^ Server_Bat = gcnew StreamWriter(fileName);
		Server_Bat->WriteLine("@ECHO OFF");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem Don't change the ASA_EXE");
		Server_Bat->WriteLine("set ASA_EXE=ArkAscendedServer.exe");
		Server_Bat->WriteLine("set ASA_PROCCESS_NAME=ArkAscendedServer");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem --------------------- Server Settings ---------------------");
		Server_Bat->WriteLine("rem Change the stuff that is after \" = \" for each line");
		Server_Bat->WriteLine("rem -----------------------------------------------------------");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem With the line that says 'ASA_PATH = ' make sure it's pointed to the ASA server folder and has the '\' at the end of it.");
		Server_Bat->WriteLine("set ASA_PATH=" + Folder_Path + "\\ShooterGame\\Binaries\\Win64\\");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem Set max players for the server");
		Server_Bat->WriteLine("set ASA_MAX_PLAYERS=" + Max_Players);
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem Set the server name here.");
		Server_Bat->WriteLine("set ASA_SERVER_NAME=\"" + Server_Name + "\"");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem ------- Server password to make people use to join the server. -------");
		Server_Bat->WriteLine("rem Only edit that is between the \" \" ");
		Server_Bat->WriteLine("set ASA_JOIN_PASSWORD=\"" + Server_Password + "\"");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem ------- Server admin password -------");
		Server_Bat->WriteLine("rem Only edit that is between the \" \" ");
		Server_Bat->WriteLine("set ASA_ADMIN_PASSWORD=\"" + Admin_Password + "\"");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem ------- ASA Map -------");
		Server_Bat->WriteLine("rem This would only change when wildcard release new maps and you want to change it!");
		Server_Bat->WriteLine("rem You only change this if you was running a different map like the \"TheCenter_WP\" map.");
		Server_Bat->WriteLine("set ASA_MAP=" + Map + "");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem ------- Battle Eye -------");
		Server_Bat->WriteLine("rem Turn On Battle Eye -> -UseBattlEye");
		Server_Bat->WriteLine("rem Turn Off Battle Eye -> -NoBattlEye");
		Server_Bat->WriteLine("set ASA_BattlEye=" + BattleEye);
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem ------- crossplay -------");
		Server_Bat->WriteLine("rem Turn on crossplay -> -crossplay");
		Server_Bat->WriteLine("rem Turn off crossplay delete \" -crossplay \"");
		Server_Bat->WriteLine("set ASA_CROSSPLAY=" + Crossplay);
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem ------- Mods -------");
		Server_Bat->WriteLine("rem Turn on crossplay -> -crossplay");
		Server_Bat->WriteLine("rem Turn off crossplay delete \" -crossplay \"");
		Server_Bat->WriteLine("set ASA_MODS=-mods=" + Mods + "");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("rem -------------------------- Don't mess with the code below --------------------------");
		Server_Bat->WriteLine("rem		Starting the server back up");
		Server_Bat->WriteLine("START /B /high \"\" \"%ASA_PATH%%ASA_EXE%\" %ASA_MAP%?SessionName=%ASA_SERVER_NAME%?listen?ServerPassword=%ASA_JOIN_PASSWORD%?MaxPlayers=%ASA_MAX_PLAYERS%?ServerAdminPassword=%ASA_ADMIN_PASSWORD% %ASA_MODS% %ASA_BattlEye% %ASA_CROSSPLAY%");
		Server_Bat->WriteLine("");
		Server_Bat->WriteLine("exit");
		Server_Bat->Close();

		if (CreateOrUpdateMessage == "Create")
		{
			result = "the start server batch file was successfully created!";
		}
		else {
			result = "the start server batch file was successfully Updated!";
		}
		return result;
	}
	System::String^ Batch::Batch_Hander::SteamCMD_Install_ASA_Server_Batch_File(System::String^ Server_Folder_Path, System::String^ directoryPath) {
		String^ fileName = directoryPath + "\\ASA_Manager_Config\\SteamCMD_Install_ASA_Server.bat";
		StreamWriter^ steamCMD_Bat = gcnew StreamWriter(fileName);
		steamCMD_Bat->WriteLine("@ECHO OFF");
		steamCMD_Bat->WriteLine("start /B ASA_Manager_Config\\SteamCMD\\steamcmd.exe +force_install_dir \"" + Server_Folder_Path + "\" +login anonymous +app_update 2430930 validate +quit");
		steamCMD_Bat->WriteLine("exit");
		steamCMD_Bat->Close();
		return "";
	}
}