#include "RepoMap.h"
#include <assert.h>
#include <iterator>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
using std::vector;
using std::map;
using std::pair;
void CarRepoMAP::storeCar(const Car & car)
{
	map<string , Car>::iterator itr;
	for (itr = cars.begin(); itr != cars.end(); ++itr) {
		if (itr->second.getNrInmatriculare() == car.getNrInmatriculare())
			throw RepoExceptionMAP{ "Car already exists" };
	}
	cars.insert(std::pair<string, Car>(car.getNrInmatriculare(),car));
	/*for (const Car& c : cars) {
		if (c.getNrInmatriculare() == car.getNrInmatriculare())
			throw RepoExceptionMAP{ "Car already exists" };
	}
	cars.push_back(car);*/
}

 vector<Car> CarRepoMAP::getAll() 
{

	 vector<Car> vect{ cars.size() };
	//vector<Car> carss;
	//std::transform(cars.begin(), cars.end(), std::back_inserter(carss), [](auto &kv) { return kv.second; });
	/*map<string, Car>::iterator itr;
	for (itr = cars.begin(); itr != cars.end(); ++itr) {
		carss.push_back(itr->second);
	}*/
	 std::transform(cars.begin(), cars.end(), vect.begin(), [](auto c) {
		 return c.second;
	 });
	//for (int i = 0; i < vect.size(); i++)
		//carss.push_back(vect[i]);
	 
	return vect;
}

void CarRepoMAP::sterge(const Car & c)
{
	/*auto found = std::find_if(cars.begin(), cars.end(), [c](const Car& cc) {
		return cc.getNrInmatriculare() == c.getNrInmatriculare();
	});
	if (found == cars.end()) {
		throw RepoExceptionMAP{ "Inexistent car" };
	}

	auto rez = cars.erase(found);*/
	/*
	map<string, Car>::iterator itr;
	for (itr = cars.begin(); itr != cars.end(); ++itr) {
		if (itr->second.getNrInmatriculare() == c.getNrInmatriculare()) {
			cars.erase(itr);
		}

	}throw RepoExceptionMAP{ "x car" };
	*/
	//merge 
	map<string, Car>::iterator itr;
	itr = cars.find(c.getNrInmatriculare());
	if (itr == cars.end()) throw RepoExceptionMAP{ "x car" };
	cars.erase(itr);
}

void CarRepoMAP::update(const Car & cNou)
{/*for (Car& c : cars)
	{
		if (c.getNrInmatriculare() == cNou.getNrInmatriculare())
		{
			c.setModel(cNou.getModel());
			c.setTip(cNou.getTip());
			c.setProducator(cNou.getProducator());
			return;
		}
	}
	throw RepoExceptionMAP("");*/
	map<string, Car>::iterator itr;
	for (itr = cars.begin(); itr != cars.end(); ++itr) {
		if (itr->second.getNrInmatriculare() == cNou.getNrInmatriculare())
		{
			
			itr->second.setModel(cNou.getModel());
			itr->second.setTip(cNou.getTip());
			itr->second.setProducator(cNou.getProducator());

			return;
		}
			
	}throw RepoExceptionMAP(" ");
	
	
}

const Car & CarRepoMAP::find(string nrInmatriculare)
{
	/*auto found = std::find_if(cars.begin(), cars.end(), [&](const Car& cc) {
		return cc.getNrInmatriculare() == nrInmatriculare;
	});
	if (found == cars.end()) {
		throw RepoExceptionMAP{ "Inexistent car" };
	}
	return *found;*/
	map<string, Car>::iterator itr;
	for (itr = cars.begin(); itr != cars.end(); ++itr) {
		if (itr->second.getNrInmatriculare() == nrInmatriculare) {
			return itr->second;
		}

	}throw RepoExceptionMAP{ "Inexistent car" };
	
}



void testRepoMAP() {
	CarRepoMAP repo;
	repo.storeCar(Car{ "a","b1","c","d" });
	repo.storeCar(Car{ "aa","b2","c","d" });
	repo.storeCar(Car{ "aaa","b3","c","d" });

	assert(repo.getAll().size() == 3);

	try { repo.storeCar(Car{ "a","b1","c","d" }); }
	catch (RepoExceptionMAP) {}

	repo.sterge(Car{ "a","b1","c","d" });
	assert(repo.getAll().size() == 2);

	try {
		repo.sterge(Car{ "a","b1","c","d" });
		assert(false);
	}
	catch (RepoExceptionMAP) {}

	try {
		repo.update(Car{ "a","b1","b","b" });
		assert(false);

	}
	catch (RepoExceptionMAP) {}

	repo.update(Car{ "aa","b1","b","b" });
	Car car = repo.find("aa");
	assert(car.getNrInmatriculare() == "aa" && car.getProducator() == "b1"&& car.getModel() == "b"&&car.getTip() == "b");






}


void RepoTestsMAP() {
	testRepoMAP();
}