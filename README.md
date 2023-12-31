# ASA Server Manager

![ASA Server Manager](https://i.ibb.co/3R3Zngv/ASA-Server-Manager.png)

If your windows computer is 32bit download the x86 zip file
[ASA Server Manager x86](https://github.com/ubidzz/ASA-Server-Manager/raw/master/ASA_Server_Manager_x86.zip)

If your windows computer is 64bit download the x64 zip file
[ASA Server Manager x64](https://github.com/ubidzz/ASA-Server-Manager/raw/master/ASA_Server_Manager_x64.zip)

* The manager has a builtin auto restart server if the server ever crashes.
* Easy to use create server backups.
* The manager will automatically create the server Game.ini file for the server if it doesn't exist.
* The manager will do a server check every 2 minutes so see if your server has crashed or stop responding.

> [!IMPORTANT]
> Due to wildcard releasing a update that made it so you can't change the ports it's listing on the manager uses the default ports of 7777 and 27015
> 
> The only thing that don't work in the ASA Server Manager right now is the RCON stuff.
>
> When you run the ASA Server Manager file windows will give you a warning to allow the program to run due to it doesn't have a code signing certificate.

## How to use the ASA Server Manager
1. download the zip file
2. extract the ASA Server Manager.exe file to a location on your computer where you want to run it from
3. Fill in your server info and click the Save ASA Manager Config button
4. Click the Install/Update ASA Server button (A black window will popup wait for it to finish)
5. Click the Start Server button.
6. Your finish enjoy.

When you run the ASA Server Manager it will create a ASA_Manager_Config folder into the directory where the ASA Server Manager.exe is located at. The folder contains the ASA_Server_Manager_Settings.xml file, SteamCMD folder, Server_backups folder, ASA_Start_Server.bat file and SteamCMD_Install_ASA_Server.bat file.

The EXE file was built in c++/clr .Net framework v4.7.2

# License
ASA Server Manager is licensed under the GPL 3 License. See LICENSE for more information.

You can freely share this program with people but you can not take clame of owning it or sell it. I am trying to get a code signing certificate for this program but due to that i am not a business it is very hard to get a code signing certificate and they are expensive to buy.
