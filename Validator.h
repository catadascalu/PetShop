#pragma once
#include "Dog.h"
#include<string>
#include<iostream>
#include<vector>


class Validator
{
private:
	std::vector<string> messages;

public:
	Validator() {}

	void validate(const std::string& breed, const std::string& name, Age& age, const std::string link);

	std::vector<string> getErrors() { return this->messages; }

	~Validator() {}


};