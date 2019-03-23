#pragma once
# define SW_SHOWNORMAL 1

#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<shellapi.h>
#include "Storage.h"

using namespace std;

class HTML :public Storage
{
public:
	void writeToFile(Repository list, std::string filename) override
	{
		ofstream file(filename);
		if (file.is_open())
		{
			file << "<!DOCTYPE html>\n<html>\n<head>\n<title>Adoption List</title>\n</head>\n<body>\n<table border='1'>" << endl;
			file << "<tr>\n<td>Breed</td>\n<td>Name</td>\n<td>Age</td>\n<td>Photo</td>\n</tr>" << endl;
			for (auto d : list.getDogs())
			{
				file << "<tr>\n";
				file << "<td>" << d.getBreed() << "</td>" << endl;
				file << "<td>" << d.getName() << "</td>" << endl;
				file << "<td>" << d.getAge().getYears() << " years and " << d.getAge().getMonths() << " months" << "</td>" << endl;
				file << "<td><a href=" << d.getSource() << ">Link" << "</a>" << "</td>" << endl;
				file << "</tr>" << endl;
			}
			file << "</table>\n</body>\n</html>";
		}
	}

	void openFile()
	{
		ShellExecuteA(NULL, "open", "C:/Users/catad/source/repos/Lab8-9/AL.html", NULL, NULL, SW_SHOWNORMAL);
	}
};