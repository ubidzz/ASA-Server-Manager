#pragma once
#include "Class_Handler.h"

namespace Batch {

	using namespace System;
	using namespace System::IO;

	String^ Batch::Batch_Hander::Build_Batch_Start_Server_File(String^ CreateOrUpdateMessage, String^ Folder_Path, String^ Max_Players, String^ Server_Name, String^ Server_Password, String^ Admin_Password, String^ Map, String^ Enable_BattleEye, String^ Enable_Crossplay, String^ Mods) {

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
		StreamWriter^ bat = gcnew StreamWriter(fileName);
		bat->WriteLine("@ECHO OFF");
		bat->WriteLine("");
		bat->WriteLine("rem Don't change the ASA_EXE");
		bat->WriteLine("set ASA_EXE=ArkAscendedServer.exe");
		bat->WriteLine("set ASA_PROCCESS_NAME=ArkAscendedServer");
		bat->WriteLine("");
		bat->WriteLine("rem --------------------- Server Settings ---------------------");
		bat->WriteLine("rem Change the stuff that is after \" = \" for each line");
		bat->WriteLine("rem -----------------------------------------------------------");
		bat->WriteLine("");
		bat->WriteLine("rem With the line that says 'ASA_PATH = ' make sure it's pointed to the ASA server folder and has the '\' at the end of it.");
		bat->WriteLine("set ASA_PATH=" + Folder_Path);
		bat->WriteLine("");
		bat->WriteLine("rem Set max players for the server");
		bat->WriteLine("set ASA_MAX_PLAYERS=" + Max_Players);
		bat->WriteLine("");
		bat->WriteLine("rem Set the server name here.");
		bat->WriteLine("set ASA_SERVER_NAME=\"" + Server_Name + "\"");
		bat->WriteLine("");
		bat->WriteLine("rem ------- Server password to make people use to join the server. -------");
		bat->WriteLine("rem Only edit that is between the \" \" ");
		bat->WriteLine("set ASA_JOIN_PASSWORD=\"" + Server_Password + "\"");
		bat->WriteLine("");
		bat->WriteLine("rem ------- Server admin password -------");
		bat->WriteLine("rem Only edit that is between the \" \" ");
		bat->WriteLine("set ASA_ADMIN_PASSWORD=\"" + Admin_Password + "\"");
		bat->WriteLine("");
		bat->WriteLine("rem ------- ASA Map -------");
		bat->WriteLine("rem This would only change when wildcard release new maps and you want to change it!");
		bat->WriteLine("rem You only change this if you was running a different map like the \"TheCenter_WP\" map.");
		bat->WriteLine("set ASA_MAP=" + Map + "");
		bat->WriteLine("");
		bat->WriteLine("rem ------- Battle Eye -------");
		bat->WriteLine("rem Turn On Battle Eye -> -UseBattlEye");
		bat->WriteLine("rem Turn Off Battle Eye -> -NoBattlEye");
		bat->WriteLine("set ASA_BattlEye=" + BattleEye);
		bat->WriteLine("");
		bat->WriteLine("rem ------- crossplay -------");
		bat->WriteLine("rem Turn on crossplay -> -crossplay");
		bat->WriteLine("rem Turn off crossplay delete \" -crossplay \"");
		bat->WriteLine("set ASA_CROSSPLAY=" + Crossplay);
		bat->WriteLine("");
		bat->WriteLine("rem ------- Mods -------");
		bat->WriteLine("rem Turn on crossplay -> -crossplay");
		bat->WriteLine("rem Turn off crossplay delete \" -crossplay \"");
		bat->WriteLine("set ASA_MODS=" + Mods + "");
		bat->WriteLine("");
		bat->WriteLine("rem -------------------------- Don't mess with the code below --------------------------");
		bat->WriteLine("rem		Starting the server back up");
		bat->WriteLine("START /B /high \"\" \"%ASA_PATH%%ASA_EXE%\" %ASA_MAP%?SessionName=%ASA_SERVER_NAME%?listen?ServerPassword=%ASA_JOIN_PASSWORD%?MaxPlayers=%ASA_MAX_PLAYERS%?ServerAdminPassword=%ASA_ADMIN_PASSWORD% %ASA_BattlEye% %ASA_CROSSPLAY% %ASA_MODS%");
		bat->WriteLine("");
		bat->WriteLine("exit");
		bat->Close();

		if (CreateOrUpdateMessage == "Create")
		{
			result = "The start server batch file was successfully created!";
		}
		else {
			result = "The start server batch file was successfully Updated!";
		}
		return result;
	}
	String^ Batch::Batch_Hander::SteamCMD_Install_ASA_Server_Batch_File() {
		return "";
	}
}