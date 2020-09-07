#include "CarRepo.h"
#include <assert.h>
#include <fstream>
void CarRepo::storeCar(const Car & car)

{
	for (const Car& c : cars) {
		if (c.getNrInmatriculare() == car.getNrInmatriculare())
			throw RepoException{ "Car already exists" };
	}
	cars.push_back(car);
}

void CarRepo::sterge(const Car & c)
{
	auto found = std::find_if(cars.begin(), cars.end(), [c](const Car& cc) {
		return cc.getNrInmatriculare() == c.getNrInmatriculare();
	});
	if (found == cars.end()) {
		throw RepoException{ "Inexistent car" };
	}

	auto rez = cars.erase(found);
}

void CarRepo::update(const Car & cNou)
{
	for (Car& c : cars)
	{
		if (c.getNrInmatriculare() == cNou.getNrInmatriculare())
		{
			c.setModel(cNou.getModel());
			c.setTip(cNou.getTip());
			c.setProducator(cNou.getProducator());
			return;
		}
	}
	throw RepoException("");
}

const Car & CarRepo::find(string nrInmatriculare)
{
	auto found = std::find_if(cars.begin(), cars.end(), [&](const Car& cc) {
		return cc.getNrInmatriculare() == nrInmatriculare;
	});
	if (found == cars.end()) {
		throw RepoException{ "Inexistent car" };
	}
	return *found;
}



void testRepo() {
	CarRepo repo;
	repo.storeCar(Car{ "a","b1","c","d" });
	repo.storeCar(Car{ "aa","b2","c","d" });
	repo.storeCar(Car{ "aaa","b3","c","d" });
	
	assert(repo.getAll().size() == 3);

	try { repo.storeCar(Car{ "a","b1","c","d" }); }
	catch (RepoException){}

	repo.sterge(Car{ "a","b1","c","d" });
	assert(repo.getAll().size() == 2);

	try {
		repo.sterge(Car{ "a","b1","c","d" });
		//assert(false);
	}
	catch (RepoException){}

	try {
		repo.update(Car{ "a","b1","b","b" });
		//assert(false);

	}catch(RepoException){}

	repo.update(Car{ "aa","b1","b","b" });
	Car car = repo.find("aa");
	assert(car.getNrInmatriculare() == "aa" && car.getProducator() == "b1"&& car.getModel() == "b"&&car.getTip() == "b");






}


void RepoTests() {
	testRepo();
}

void CarRepoFile::loadFromFile()
{
	std::ifstream in(fileName);
	if (!in.is_open()) { 		
		throw CarException("Unable to open file:" + fileName);
	}
	while (!in.eof()) {
		std::string nrInmatriculare;
		in >> nrInmatriculare;
		std::string producator;
		in >> producator;
		std::string model;
		in >> model;
		std::string tip;
		in >> tip;

	
		if (in.eof()) {	//nu am reusit sa citesc numarul
			break;
		}
		Car c{ nrInmatriculare.c_str(), producator.c_str(), model.c_str() , tip.c_str() };
		CarRepo::storeCar(c);
	}
	in.close();
}
/*string nrInmatriculare;
	string producator;
	string model;
	string tip;*/
void CarRepoFile::storeToFile()
{
	std::ofstream out(fileName);
	if (!out.is_open()) { 
		throw CarException("Unable to open file:");
	}
	for (auto& c : getAll()) {
		out << c.getNrInmatriculare();
		out << std::endl;
		out << c.getProducator();
		out << std::endl;
		out << c.getModel();
		out << std::endl;
		out << c.getTip();
		out << std::endl;
	}
	out.close();
}

void CarRepoFile::storeCar(const Car & car)
{
	CarRepo::storeCar(car);
	storeToFile();
}

void CarRepoFile::
update(const Car & cNou)
{
	CarRepo::update(cNou);
	storeToFile();
}

void CarRepoFile::sterge(const Car & c)
{
	CarRepo::sterge(c);
	storeToFile();
}