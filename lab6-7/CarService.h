#pragma once
#include "Car.h"
#include "CarRepo.h"
#include "Validator.h"
#include <vector>
#include <assert.h>
using std::vector;
class CarService
{
	CarRepo& repo;
	Validator validator;
public:
	CarService(CarRepo& repo,Validator validator ):repo{repo},validator{validator}{}

	void add(const string& nrInmatr, const string& prod, const string& model, const string& tip);

	void del(const string& nrInmatriculare);

	void update(const string& nrInmatr, const string& prodNou, const string& modelNou, const string& tipNou);

	Car findCar(const string& nrInmatriculare);

	VectorDinamic<Car> getAll();
	
	VectorDinamic<Car> filterByProd(string s);
	VectorDinamic<Car> filterByTip(string s);
	VectorDinamic<Car> sortByNrInmatriculare();
	VectorDinamic<Car> sortByTip();
	
	

};

void TestService();
