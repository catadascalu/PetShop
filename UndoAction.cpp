#include "UndoAction.h"

void UndoAdd::executeUndo()
{
	this->repo.deleteDog(this->dog.getBreed(), this->dog.getName());
}

void UndoRemove::executeUndo()
{
	this->repo.addDog(this->dog);
}

void UndoUpdate::executeUndo()
{
	this->repo.updateDog(this->dog);
}