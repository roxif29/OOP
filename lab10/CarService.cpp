#include "CarService.h"
#include<cstring>
#include <string.h>
#include <iostream>

#include<functional>
#include <numeric> 
#include <memory>
#include <memory>

using namespace std;
void CarService::add(const string & nrInmatr, const string & prod, const string & model, const string & tip)
{
	Car c{ nrInmatr,prod,model,tip };
	validator.validate(c);
	repo.storeCar(c);

	undoActions.push_back(make_unique<UndoAdd>(repo, c));
}

void CarService::del(const string & nrInmatriculare)
{
	Car c;
	try {
		c = repo.find(nrInmatriculare);
	}
	catch (RepoException) {};
	//catch (RepoExceptionMAP) {};

	repo.sterge(c);
	undoActions.push_back(make_unique<UndoDelete>(repo, c));
}

void CarService::update(const string & nrInmatr, const string & prodNou, const string & modelNou, const string & tipNou)
{
	Car c{ nrInmatr,prodNou,modelNou,tipNou };
	validator.validate(c);
	repo.update(c);
	undoActions.push_back(make_unique<UndoUpdate>(repo, c));
}

Car CarService::findCar(const string & nrInmatriculare)
{
	Car c;
	try {
		c = repo.find(nrInmatriculare);
	}
	catch (RepoException) {}
	//catch (RepoExceptionMAP){}
	validator.validate(c);
	return c;

}

vector<Car> CarService::getAll()
{
	return repo.getAll();
}

void CarService::salvare(string fName) {
	//repo.storeCar.storeToFile(fName);
}
vector<Car> CarService::filterByProd(string s)
{
	vector<Car> rez;

	for (const auto& c : repo.getAll()) {
		string prod = c.getProducator();
		std::size_t found = prod.find(s);
		if (found != std::string::npos)
			rez.push_back(c);

	}
	return rez;
}

vector<Car> CarService::filterByTip(string s)
{
	vector<Car> rez;

	for (const auto& c : repo.getAll()) {
		string prod = c.getTip();
		std::size_t found = prod.find(s);
		if (found != std::string::npos)
			rez.push_back(c);

	}
	return rez;
}


vector<Car> CarService::sortByNrInmatriculare()
{
	auto rez = repo.getAll();
	std::sort(rez.begin(), rez.end(), [](const Car&c1, const Car&c2) {
		return c1.getNrInmatriculare() < c2.getNrInmatriculare();
	});
	return rez;
}

vector<Car> CarService::sortByTip()
{
	auto rez = repo.getAll();
	std::sort(rez.begin(), rez.end(), [](const Car&c1, const Car&c2) {
		return c1.getTip() < c2.getTip();
	});
	return rez;
}
vector<DTO> CarService::raport()//model
{
	vector<Car> cars = repo.getAll();
	vector<DTO> rez;
	unordered_map<string, DTO> uMap;
	for (const auto& c : cars) {
		string model = c.getModel();
		if (uMap.find(model) == uMap.end()) {
			DTO car{ model,1 };
			uMap[model] = car;
			continue;
		};
		uMap[model].add();
	}
	for (const auto& i : uMap)
		rez.push_back(i.second);
	return rez;

}

void CarService::undo()
{
	if (undoActions.empty()) {
		throw CarException{ "Nu mai exista operatii" };
	}

	undoActions.back()->doUndo();
	undoActions.pop_back();
}
const vector<Car>& CarService::addToCos(const string & nrInmatriculare)
{
	const Car&c = repo.find(nrInmatriculare);
	cos.addCos(c);
	return cos.getAllCos();
	//undoActionsCos.push_back(make_unique<UndoAddCos>(repo, c));
}
const vector<Car>& CarService::addRandom(int cate)
{
	cos.randomAdd(cate, repo.getAll());
	return cos.getAllCos();
}
const vector<Car>& CarService::golesteCos()
{
	cos.golesteCos();
	return cos.getAllCos();
}
const vector<Car>& CarService::toateDinCos()
{
	return cos.getAllCos();
}



void CarService::exportaCosCVS(string fName) const
{
	exportToCVS(fName, cos.getAllCos());
}
void CarService::exportaCosHTML(string fName) const
{
	exportToHTML(fName, cos.getAllCos());
}
/*
int CarService::cateModel(const string& model) {
	vector<Car>v = repo.getAll();
	return std::accumulate(v.begin(), v.end(), 0, [model](int x, const Car& c)
	{
		if (c.getModel() == model)
			return x + 1;
		return x;
	});
}*/
/*
void TestService() {
	CarRepo repo;
	//CarRepoMAP repo;
	Validator valid;
	CarService serv{ repo,valid };

	// ADD
	serv.add("nr1", "p1", "m1", "t1");
	serv.add("nr2", "p2", "m2", "t2");
	serv.add("nr3", "p3", "m3", "t2");

	std::cout << serv.getAll().size();
	assert(serv.getAll().size() == 3);
	try {
		serv.add("", "", "", "");
	}
	catch (ValidateException) {};


	//UP
	serv.update("nr2", "22", "2", "222");
	Car found1 = serv.findCar("nr2");
	assert(found1.getProducator() == "22" && found1.getModel() == "2" && found1.getTip() == "222");


	//DEL
	serv.del("nr2");
	assert(serv.getAll().size() == 2);

	//FIND
	Car found = serv.findCar("nr1");
	assert(found.getProducator() == "p1" && found.getModel() == "m1" && found.getTip() == "t1");


	//Filter tip
	serv.add("nr2", "p2", "m2", "t2");
	vector<Car> filtruTip = serv.filterByTip("t2");
	assert(filtruTip.size() == 2);


	//Filter prod
	vector<Car> filtruProd = serv.filterByProd("p");
	assert(filtruProd.size() == 3);

	//Sort nr
	vector<Car> sortNr = serv.sortByNrInmatriculare();
	assert(sortNr.at(1).getNrInmatriculare() == "nr2");
	//Sort tip
	vector<Car> sortTip = serv.sortByTip();
	assert(sortNr.at(2).getTip() == "t2");


	//raport
	serv.add("nr4", "p3", "m3", "t2");
	serv.add("nr5", "p3", "m3", "t2");
	vector<DTO> rap = serv.raport();
	assert(rap.size() == 3);
	for (const auto& i : rap) {
		if (i.getStr() == "m1") {
			assert(i.get_cant() == 1);
			continue;
		}
		if (i.getStr() == "m2") {
			assert(i.get_cant() == 1);
			continue;
		}
		if (i.getStr() == "m3") {
			assert(i.get_cant() == 3);
		}


	}

	//undo
	assert(serv.getAll().size() == 5);
	serv.add("nr7", "p3", "m3", "t2");
	assert(serv.getAll().size() == 6);
	serv.update("nr7", "p3", "m5", "t7");
	serv.del("nr7");
	assert(serv.getAll().size() == 5);
	serv.undo();
	assert(serv.getAll().size() == 6);
	serv.undo();
	serv.undo();
	assert(serv.getAll().size() == 5);


	//cate

}

void testCos()
{
	CarRepo repo;
	Validator valid;
	CarService serv{ repo,valid };
	serv.add("nr1", "p1", "m1", "t1");
	serv.add("nr2", "p2", "m2", "t2");
	serv.add("nr3", "p3", "m3", "t2");
	assert(serv.toateDinCos().size() == 0);
	serv.addToCos("nr1");
	assert(serv.toateDinCos().size() == 1);
	try
	{
		serv.addToCos("nr100"); assert(false);
	}
	catch (RepoException&) { assert(true); }
	serv.golesteCos();
	assert(serv.toateDinCos().size() == 0);
	serv.addRandom(10);
	assert(serv.toateDinCos().size() == 3);
	vector<Car> all = serv.toateDinCos();
	for (Car c : all) {
		std::cout << c.getModel() << c.getNrInmatriculare() << c.getTip();
	}

}

*/