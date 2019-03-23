#pragma once
#include<fstream>
#include "Repository.h"
//#include "UndoAction.h"
class Controller
{
private:
	Repository repo;
	Repository list;
	Repository filtered;
	//std::vector<UndoAction*> undoActions;
	
public:

	Controller() {}
	Controller(const Repository& r, const Repository& f) : repo(r), filtered(f) {}

	Repository getRepo()  { return this->repo; }
	Repository getAdoptionList()  { return this->list; }
	Repository getFiltered()  { return this->filtered; }
	//adds a dog with the given data to the dog database
	void addDogToRepo(const std::string& breed, const std::string& name, const int years, const int months, const std::string& source);
	//removes a dog from the database(when it is adopted)
	void removeDogFromRepo(const std::string& breed, const std::string& name);
	//updates the info ona dog (age or link)
	//input: the dog with modified information
	//output: the information inside the database is modified
	void updateDogRepo(Dog d);
	//adds a dog to the adoption list
	//input: dog - it must exist in the repository
	//output: the dog is added to the adoption list
	void addDogToAdoptionList(const Dog& dog);

	int StartAdopting();
	int nextDog();
	void filter(const std::string& breed, const int years, const int months);
	int startSelectivelyAdopting();
	int nextDogSelectively();
	//void undo();
	

	~Controller()
	{
		/*
		for (auto action : this->undoActions)
		delete action;
		for (auto action : this->redoActions)
		delete action;
		*/
	}
};