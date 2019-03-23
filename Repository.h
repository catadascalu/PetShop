#pragma once
#include<sstream>
#include<string>
#include "Dog.h"
#include<vector>
//#include "UndoAction.h"

class Repository
{
private:
	std::vector<Dog> dogs;
	//std::vector<RedoAction*> redoActions;
	int current;

public:

	//default constructor
	//initializes an object of type Repository
	Repository();

	//add a dog to the repository
	//input: d - the dog to be added
	//output: the dog is added to the repository

	void addDog(const Dog& d);

	//removes a dog from the database
	//input: d - the dog to be removed
	//output: the dog is removed

	void deleteDog(const std::string& breed, const std::string& name);

	//updates the info on a dog
	//input: d - the new dog
	//output: the info is modified

	void updateDog(Dog& d);


	//finds the position of an element
	//input: d - the dog
	//output: pos - an int

	int findByBreedAndName(const std::string& breed, const std::string& name);

	//finds a dog by name and breed
	//input: breed, name - string
	//output: (the dog that was found, or an "empty" dog if no dog was found) the position of the dog

	Dog find(const std::string& breed, const std::string& name);
	std::vector<Dog> getDogs() const { return dogs; }
	Dog getCurrentDog();
	void writeToFile();
	int view();
	int next();
	bool isEmpty();
	void initFile();
	void outFile();
	Repository filter(const std::string& breed, const int years, const int months);
	~Repository() {};
};