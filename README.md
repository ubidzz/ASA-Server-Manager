# ASA Server Manager

### I had a 95% finished project and when i try to push it to github i lost everything but I was able to keep the build exe file that works in till i rebuild the hole thing over.
The EXE file is unplublished so you will get a warning downloading it and when you start it. The file is clean there no hacking, no virues and it don't even ask to run it in Admin.

![ASA Server Manager](https://i.ibb.co/KV6M9Rb/2023-12-23.png)

[Download ASA Server Manager](https://1drv.ms/u/s!Av5X05qIbM66h4IA_OIfY4Kklvt74Q?e=9mZHry)

The only things that I didn't get done was to finish 2 buttons that edit the ASA server config files but everything else works and will run a server.
The manager also has a builtin auto restart server if the server ever crashes.
Due to wildcard releasing a update that made it so you can't change the ports it's listing on the manager uses the default ports of 7777 and 27015

> [!IMPORTANT]
> If your ASA Server Installation Folder path has a space in it you will have to edit the ASA_Start_Server.bat file.
> Location: ASA_Manager_Config/ASA_Start_Server.bat

# Looking for this code.
```
START /B /high %ASA_PATH%%ASA_EXE% %ASA_MAP%?SessionName=%ASA_SERVER_NAME%?listen?ServerPassword=%ASA_JOIN_PASSWORD%?MaxPlayers=%ASA_MAX_PLAYERS%?ServerAdminPassword=%ASA_ADMIN_PASSWORD% %ASA_BattlEye% %ASA_CROSSPLAY% %ASA_MODS%
```
Replace it with this code.
```
START /B /high "" "%ASA_PATH%%ASA_EXE%" %ASA_MAP%?SessionName=%ASA_SERVER_NAME%?listen?ServerPassword=%ASA_JOIN_PASSWORD%?MaxPlayers=%ASA_MAX_PLAYERS%?ServerAdminPassword=%ASA_ADMIN_PASSWORD% %ASA_BattlEye% %ASA_CROSSPLAY% %ASA_MODS%
```
Save and click the Start Server button.
You will have to replace the line every time the ASA Server Manger saves it's config file and I could not fix this before I lost my files.

## The EXE file was built in c++/cli .Net framework v4.7.2

# The Files that are in the Github are not the same as the download ASA Server Manager link that I have posted and are the new files for a rebuilt version!
