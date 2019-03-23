#pragma once
#include<iostream>
#include<string>

using namespace std;

class Age
{
private:
	int years;
	int months;
public:
	Age() : years(0), months(0) {}
	Age(int yrs, int mts) : years(yrs), months(mts) {}


	int getYears() { return years; }
	int getMonths() { return months; }
	void setYears(int yrs) { years = yrs; }
	void setMonths(int mts) { months = mts; }

};



class Dog
{
private:
	std::string breed;
	std::string name;
	Age age;
	std::string source;

public:

	Dog();

	Dog(const std::string& breed, const std::string& name, const Age& age, const std::string& source) : breed(breed), name(name), age(age), source(source) {}

	std::string getBreed() const { return breed; }
	std::string getName() const { return name; }
	Age getAge() const { return age; }
	std::string getSource() const { return source; }

	void setAge(Age& newAge);
	void setSource(const std::string& newSource);

	bool validate();

	std::string toString();

	friend bool operator==(const Dog &a, const Dog &b);
	friend bool operator!=(const Dog& a, const Dog& b);
	friend std::ostream& operator<<(ostream& os, const Dog& d);
	friend std::istream& operator>>(istream& is, Dog& d);
	int view();   //the picture is opened in browser
	~Dog() {};
};