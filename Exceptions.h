#pragma once
#include<iostream>
#include<string>

using namespace std;

class RepoException
{
public:
	RepoException()
	{
		message = "Repository exception.";
	}

	RepoException(string str)
	{
		message = str;
	}

	string what()
	{
		return message;
	}

	~RepoException() {}

private:
	string message;
};

class EntityException
{
private:
	string message;
public:
	EntityException() {}

	EntityException(string str)
	{
		message = str;
	}

	string what()
	{
		return message;
	}

	~EntityException() {}
};