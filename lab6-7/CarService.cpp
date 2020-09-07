#include "CarService.h"
#include<cstring>
#include <string.h>
#define _CRTDBG_MAP_ALLOC
#include <algorithm>
using namespace std;
void CarService::add(const string & nrInmatr, const string & prod, const string & model, const string & tip)
{
	Car c{ nrInmatr,prod,model,tip };
	validator.validate(c);
	repo.storeCar(c);
}

void CarService::del(const string & nrInmatriculare)
{
	Car c;
	try {
		int i = repo.find(nrInmatriculare);
		c = repo.getAll().getElem(i);
	}catch (RepoException) {};

	repo.sterge(c);
}

void CarService::update(const string & nrInmatr, const string & prodNou, const string & modelNou, const string & tipNou)
{
	Car c{ nrInmatr,prodNou,modelNou,tipNou };
	validator.validate(c);
	repo.update(c);
}

Car CarService::findCar(const string & nrInmatriculare)
{
	Car c;
	try {
		int i= repo.find(nrInmatriculare);
		c = repo.getAll().getElem(i);
	}catch (RepoException){}
	validator.validate(c);
	return c;

}

VectorDinamic<Car> CarService::getAll()
{
	return repo.getAll();
}

VectorDinamic<Car> CarService::filterByProd(string s)
{
	VectorDinamic<Car> rez;
	VectorDinamic<Car> v = repo.getAll();

	for (int i = 0; i < v.getLungime(); i++) {
		Car c = v.getElem(i);
		string prod = c.getProducator();
		std::size_t found = prod.find(s);
		if (found != std::string::npos)
			rez.addElem(c);
	}
	return rez;
}

VectorDinamic<Car> CarService::filterByTip(string s)
{
	VectorDinamic<Car> rez;    
	VectorDinamic<Car> v=repo.getAll();    
	
	for (int i = 0; i < v.getLungime(); i++) {
		Car c = v.getElem(i);
		string prod = c.getTip();
		std::size_t found = prod.find(s);
		if (found != std::string::npos)
			rez.addElem(c);
	}
	return rez;
}

VectorDinamic<Car> CarService::sortByNrInmatriculare()
{
	auto rez = repo.getAll();
	for (int i = 0; i < rez.getLungime()-1; i++) {
		for (int j = 1; j < rez.getLungime(); j++) {
			if (rez.getElem(i).getNrInmatriculare() > rez.getElem(j).getNrInmatriculare()) {
				Car aux = rez.getElem(i);
				rez.getElem(i) = rez.getElem(j);
				rez.getElem(j) = aux;
			}
		}
		
	}

	/*std::sort(rez.begin(), rez.end(), [](const Car&c1, const Car&c2) {
		return c1.getNrInmatriculare() < c2.getNrInmatriculare();
	});*/

	return rez;
}

VectorDinamic<Car> CarService::sortByTip()
{/*
	auto rez = repo.getAll();
	std::sort(rez.begin(), rez.end(), [](const Car&c1, const Car&c2) {
		return c1.getTip() < c2.getTip();
	});
	return rez;*/
	auto rez = repo.getAll();
	for (int i = 0; i < rez.getLungime() - 1; i++) {
		for (int j = 1; j < rez.getLungime(); j++) {
			if (rez.getElem(i).getTip() > rez.getElem(j).getTip()) {
				Car aux = rez.getElem(i);
				rez.getElem(i) = rez.getElem(j);
				rez.getElem(j) = aux;
			}
		}

	}

	return rez;

}

/*
vector<Car> CarService::sortByProdSiModel()
{
	return vector<Car>();
}

*/


void TestService() {
	CarRepo repo;
	Validator valid;
	CarService serv{ repo,valid };

	// ADD
	serv.add("nr1", "p1", "m1", "t1");
	serv.add("nr2", "p2", "m2", "t2");
	serv.add("nr3", "p3", "m3", "t2");
	assert(serv.getAll().getLungime() == 3);
	try {
		serv.add("", "", "", "");}catch (ValidateException){ };
	

	//UP
	serv.update("nr2", "22", "2", "222");
	Car found1=serv.findCar("nr2");
	assert(found1.getProducator() == "22" && found1.getModel() == "2" && found1.getTip() == "222");
	

	//DEL
	serv.del("nr2");
	assert(serv.getAll().getLungime() == 2);
	
	//FIND
	Car found = serv.findCar("nr1");
	assert(found.getProducator() == "p1" && found.getModel() == "m1" && found.getTip() == "t1");
	

	//Filter tip
	serv.add("nr2", "p2", "m2", "t2");
	VectorDinamic<Car> filtruTip = serv.filterByTip("t2");
	assert(filtruTip.getLungime () == 2);
	

	//Filter prod
	VectorDinamic<Car> filtruProd = serv.filterByProd("p");
	assert(filtruProd.getLungime() == 3);
	
	//Sort nr
	VectorDinamic<Car> sortNr = serv.sortByNrInmatriculare();
	assert(sortNr.getElem(1).getNrInmatriculare() == "nr2");
	
	//Sort tip
	VectorDinamic<Car> sortTip = serv.sortByTip();
	assert(sortNr.getElem(2).getTip() == "t2");


	

}

