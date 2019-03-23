#include "Dog.h"
#include "Exceptions.h"
#include "Validator.h"
#include<fstream>
#include<sstream>
#include<vector>
#include<Windows.h>
#include<shellapi.h>

using namespace std;

Dog::Dog() : breed(""), name(""), age(Age()), source("") {}


void Dog::setAge(Age& newAge)
{
	try
	{
		if (newAge.getYears() < 0 || newAge.getMonths() < 0 || newAge.getMonths() > 11)
			throw EntityException("Age not valid.");
		this->age = newAge;
	}
	catch (EntityException obj)
	{
		cout << "In catch block: " << obj.what() << endl;
	}
}

void Dog::setSource(const std::string& newSource)
{
	try
	{
		if (newSource.find("www") == std::string::npos)
			throw EntityException("Source link not valid.");
		this->source = newSource;
	}
	catch (EntityException obj)
	{
		cout << "In catch block: " << obj.what() << endl;
	}
}

bool Dog::validate()
{
	Validator v = Validator();
	v.validate(this->breed, this->name, this->age, this->source);
	if (v.getErrors().size() != 0)
		return false;

	return true;

}

std::string Dog::toString()
{
	std::string str;
	str = this->name + " - " + this->breed + ", " + std::to_string(this->age.getYears()) + " years and " + std::to_string(this->age.getMonths()) + " months.";
	return str;
}

bool operator==(const Dog &a, const Dog &b) {
	return a.getName().compare(b.getName()) == 0 && a.getBreed().compare(b.getBreed()) == 0;
}

bool operator!=(const Dog& a, const Dog& b) {
	return a.getName().compare(b.getName()) != 0 || a.getBreed().compare(b.getBreed()) != 0;
}
ostream& operator<<(ostream& os, const Dog& d)
{
	os << d.breed << "," << d.name << "," << d.getAge().getYears() << "," << d.getAge().getMonths() << "," << d.source << "\n";
	return os;
}

istream& operator>>(istream& is, Dog& d)
{
	std::string line;
	getline(is, line);
	std::stringstream ss(line);
	string attribute;
	std::vector<string> temp;
	while (getline(ss, attribute, ','))
	{
		temp.push_back(attribute);
	}

	if (temp.size() != 5)
		return is;

	d.breed = temp.at(0);
	d.name = temp.at(1);
	d.age.setYears(std::stoi(temp.at(2)));
	d.age.setMonths(std::stoi(temp.at(3)));
	d.source = temp.at(4);

	return is;
}
int Dog::view()
{

	ShellExecuteA(NULL, "open", this->getSource().c_str(), NULL, NULL, SW_SHOWMINIMIZED);
	return 1;
}