#include "Repository.h"
#include"Exceptions.h"
#include<fstream>
#include<string>

using namespace std;

Repository::Repository()
{
	this->current = 0;
}

int Repository::findByBreedAndName(const std::string& breed, const std::string& name)
{
	Dog dFind(breed, name, Age{ 0, 0 }, "");



	for (unsigned i = 0; i<this->dogs.size(); i++)
	{
		Dog d = this->dogs.at(i);
		if (dFind == d)
		{
			return i;
		}
	}

	return -1;
}



Dog Repository::find(const std::string& breed, const std::string& name)
{
	int pos = findByBreedAndName(breed, name);
	if (pos == -1)
	{
		return Dog{};
	}
	return this->dogs.at(pos);
}

void Repository::writeToFile()
{
	ofstream file("C:/Users/catad/source/repos/Lab8-9/dogs.txt");
	if (file.is_open())
	{
		for (auto d : this->dogs)
		{
			//Dog d = this->dogs.at(i);
			file << d;
		}
	}
}

void Repository::addDog(const Dog& d)
{
	try
	{
		if (findByBreedAndName(d.getBreed(), d.getName()) != -1)
			throw RepoException("Entity already exists.");
		this->dogs.push_back(d);
		writeToFile();
	}
	catch (RepoException obj)
	{
		cout << "In catch block: " << obj.what() << endl;
	}

}
void Repository::deleteDog(const std::string& breed, const std::string& name)
{
	try
	{
		int pos = findByBreedAndName(breed, name);
		if (pos == -1)
			throw RepoException("Entity not found.");
		this->dogs.erase(this->dogs.begin() + pos);
		writeToFile();
	}
	catch (RepoException obj)
	{
		cout << "In catch block: " << obj.what() << endl;
	}
}


void Repository::updateDog(Dog& dog)
{
	try
	{
		int pos = findByBreedAndName(dog.getBreed(), dog.getName());
		if (pos == -1)
			throw RepoException("Entity not found. No updates were made.");
		this->dogs.insert(this->dogs.begin() + pos, dog);
		this->dogs.erase(this->dogs.begin() + pos + 1);
		writeToFile();
	}
	catch (RepoException obj)
	{
		cout << "In catch block: " << obj.what() << endl;
	}
}



Dog Repository::getCurrentDog()
{
	if (this->current == this->dogs.size())
	{
		this->current = 0;
	}
	if (this->dogs.capacity() == 0)
		return Dog{};

	return this->dogs.at(this->current);


}

int Repository::view()
{
	if (this->dogs.size() == 0)
		return 0;
	this->current = 0;
	Dog currentDog = this->getCurrentDog();
	int view = currentDog.view();

	return 1;

}

int Repository::next()
{
	if (this->dogs.size() == 0)
	{
		return 0;
	}
	this->current++;
	Dog currentDog = this->getCurrentDog();
	int view = currentDog.view();
	return 1;
}

bool Repository::isEmpty()
{
	return this->dogs.size() == 0;
}

Repository Repository::filter(const std::string& breed, const int years, int months)
{
	Repository result = Repository();
	if (this->dogs.size() == 0)
		return Repository{};

	if (breed.empty())
		for (auto d : this->dogs)
		{
			//Dog d = this->dogs[i];
			result.addDog(d);
		}
	else
	{
		for (auto d : this->dogs)
		{
			//Dog d = this->dogs[i];

			if (d.getBreed().compare(breed) == 0)
			{
				if (d.getAge().getYears() < years)
				{
					result.addDog(d);
				}
				else if (d.getAge().getYears() == years)
					if (d.getAge().getMonths() <= months)
						result.addDog(d);


			}
			else
				continue;
		}
	}
	if (result.getDogs().size() == 0)
		return Repository{};

	return result;
}


void Repository::initFile()
{
	std::string line;

	ifstream file("C:/Users/catad/source/repos/Lab8-9/testDogs.txt");
	if (file.is_open())
	{
		Dog d = Dog();
		while (file >> d)
		{
			try
			{
				if (d.validate() == false)
					throw EntityException("Invalid characteristics.");
				this->addDog(d);
			}
			catch (EntityException obj)
			{
				cout << "In catch block: " << obj.what() << endl;
			}

		}
		file.close();
	}
	else
	{
		cout << "Unable to open file.";
	}
}

void Repository::outFile()
{
	ofstream file("C:/Users/catad/source/repos/Lab8-9/testDogs.txt");
	if (file.is_open())
	{
		for (auto d : this->dogs)
		{
			//Dog d = this->ctrl.getRepo().getDogs().at(i);
			file << d;
 �Toke           
  l      ���.���                   