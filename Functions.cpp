#pragma once
#include "Class_Handler.h"

namespace Functions {

	using namespace System;
	using namespace System::IO;

	System::Boolean^ Functions::Function_Handler::Create_Directory(System::String^ Folder_Path)
	{
        if(Check_If_Folder_Exists(Folder_Path))
        {
            Directory::CreateDirectory(Folder_Path);
            return true;
        }
        else {
            return false;
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
}