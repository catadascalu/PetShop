#pragma once
#include "Repository.h"
#include<iostream>
#include<string>

using namespace std;

class Storage
{
public:
	Storage() {}
	virtual void writeToFile(Repository list, std::string filename) = 0;
	virtual void openFile() = 0;
	~Storage() {}
};