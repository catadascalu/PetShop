#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "Controller.h"
#include "Exceptions.h"
using namespace std;

void Controller::addDogToRepo(const std::string& breed, const std::string& name, const int years, const int months, const std::string& source)
{
	try
	{
		Dog d(breed, name, Age(years, months), source);
		if (d.validate() == false)
			throw EntityException("Invalid characteristics.");
		this->repo.addDog(d);
		//UndoAdd* action = new UndoAdd(d, this->getRepo());
		//this->undoActions.push_back(action);
	}
	catch (EntityException obj)
	{
		cout << "In catch block: " << obj.what() << endl;
	}
}

void Controller::removeDogFromRepo(const std::string& breed, const std::string& name)
{
	Dog dog = this->repo.find(breed, name);
	this->repo.deleteDog(breed, name);
	//UndoRemove* action = new UndoRemove(dog, *this);
	//this->undoActions.push_back(action);
}

void Controller::updateDogRepo(Dog d)
{
	Dog dog = this->repo.find(d.getBreed(), d.getName());
	this->repo.updateDog(d);
	//UndoUpdate* action = new UndoUpdate(dog, *this);
	//this->undoActions.push_back(action);
}

void Controller::addDogToAdoptionList(const Dog& dog)
{
	this->list.addDog(dog);
}



int Controller::StartAdopting()
{
	int view = this->repo.view();
	return view;
}

int Controller::nextDog()
{
	int view = this->repo.next();
	return view;
}


void Controller::filter(const std::string& breed, const int years, const int months)
{
	//for (int i = 0; i < this->filtered.getDogs().size(); i++)
	//this->filtered.getDogs().erase(this->filtered.getDogs().begin() + i);

	Repository result = this->getRepo().filter(breed, years, months);
	for (int i = 0; i < result.getDogs().size(); i++)
		this->filtered.addDog(result.getDogs().at(i));
	//return result;
}

int Controller::startSelectivelyAdopting()
{
	int view = this->filtered.view();
	return view;
}

int Controller::nextDogSelectively()
{
	int view = this->filtered.next();
	return view;
}
/*
void Controller::undo()
{
	UndoAction* action = this->undoActions.back();
	action->executeUndo();
	this->undoActions.pop_back();
	delete action;
}

void Controller::redo()
{
RedoAction* action = this->redoActions.back();
action->executeRedo();
this->redoActions.pop_back();
delete action;
}
*/

