#pragma once
# define SW_SHOWNORMAL 1

#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<shellapi.h>
#include "Storage.h"

using namespace std;

class CSV :public Storage
{
public:
	void writeToFile(Repository list, std::string filename) override
	{
		ofstream file(filename);
		if (file.is_open())
		{
			for (auto d : list.getDogs())
			{
				file << d;
			}
		}
	}

	void openFile()
	{
		ShellExecuteA(NULL, "open", "C:/Users/catad/source/repos/Lab8-9/adoptionList.csv", NULL, NULL, SW_SHOWNORMAL);
	}
};