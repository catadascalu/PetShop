#pragma once
#include "Dog.h"
#include "Controller.h"
#include "Repository.h"

class UndoAction
{
public:
	UndoAction() {}
	virtual ~UndoAction() {}
	virtual void executeUndo() = 0;
};

class UndoAdd :public UndoAction
{
private:
	Dog dog;
	Repository& repo;

public:
	UndoAdd(Dog d, Repository& r) : dog(d), repo(r) {}
	~UndoAdd() {}
	void executeUndo();
};

class UndoRemove :public UndoAction
{
private:
	Dog dog;
	Repository& repo;
public:
	UndoRemove(Dog d, Repository& r) : dog(d), repo(r) {}
	~UndoRemove() {}
	void executeUndo();
};

class UndoUpdate : public UndoAction
{
private:
	Dog dog;
	Repository& repo;
public:
	UndoUpdate(Dog d, Repository& r) : dog(d), repo(r) {}
	~UndoUpdate() {}
	void executeUndo();
};