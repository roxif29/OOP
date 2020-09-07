#include "CarRepo.h"
#include <assert.h>
#include "VectorDinamicTemplate.h"

void CarRepo::storeCar(const Car & car)
{
	for (const Car& c : cars) {
		if (c.getNrInmatriculare() == car.getNrInmatriculare())
			throw RepoException{ "Car already exists" };
	}
	cars.addElem(car);
}

void CarRepo::sterge(const Car & c)
{
	for (int i = 0; i < this->cars.getLungime(); i++)
	{
		if (this->cars.getElem(i).getNrInmatriculare() == c.getNrInmatriculare()) {
			this->cars.deleteElem(i);
			return;
		}
	}
	throw RepoException("Insxistent car");
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
int CarRepo::find(string nrInmatriculare)
{
	for (int i = 0; i < (int)this->cars.getLungime(); i++)
		if (this->cars.getElem(i).getNrInmatriculare() == nrInmatriculare)
			return i;
	return -1;
}
/*
const Car & CarRepo::find(string nrInmatriculare)
{
	VectorDinamic<Car> v = getAll();
	Car c;
	for (int i = 0; i < v.getLungime(); i++) {
		c = v.getElem(i);
		if (c.getNrInmatriculare() == nrInmatriculare)
			return v.getElem(i);
	}
	return Car{ "","","","" };
}

*/

void testRepo() {
	CarRepo repo;
	repo.storeCar(Car{ "a","b1","c","d" });
	repo.storeCar(Car{ "aa","b2","c","d" });
	repo.storeCar(Car{ "aaa","b3","c","d" });
	
	assert(repo.getAll().getLungime() == 3);
	
	try { repo.storeCar(Car{ "a","b1","c","d" }); }
	catch (RepoException){}

	repo.sterge(Car{ "a","b1","c","d" });
	assert(repo.getAll().getLungime() == 2);
	
	try {
		repo.sterge(Car{ "a","b1","c","d" });
		//assert(false);
	}catch (RepoException){}

	try {
		repo.update(Car{ "a","b1","b","b" });
		//assert(false);

	}catch(RepoException){}

	repo.update(Car{ "aa","b1","b","b" });
	
	int i = repo.find("aa");
	Car car = repo.getAll().getElem(i);
	assert(car.getNrInmatriculare() == "aa" && car.getProducator() == "b1"&& car.getModel() == "b"&&car.getTip() == "b");

	




}


void RepoTests() {
	testRepo();
}