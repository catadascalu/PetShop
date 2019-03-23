#include "Validator.h"


void Validator::validate(const std::string& breed, const std::string& name, Age& age, const std::string link)
{
	string error;

	if (breed == "")
	{
		error = "Breed must be specified.";
		this->messages.push_back(error);
	}

	if (name == "")
	{
		error = "Name must be specified.";
		this->messages.push_back(error);
	}

	if (age.getYears() < 0)
	{
		error = "Age must be a positive number.";
		this->messages.push_back(error);
	}

	if (age.getMonths() > 11)
	{
		error = "Number of months must not exceed 11.";
		this->messages.push_back(error);
	}
	if (age.getMonths() < 0)
	{
		error = "Number of months must be a positive number.";
		this->messages.push_back(error);
	}

	if (link == "")
	{
		error = "Source must be specified.";
		this->messages.push_back(error);
	}
	if (link.find("www") == std::string::npos)
	{
		error = "Link source not valid.";
		this->messages.push_back(error);
	}
}
