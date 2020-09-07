#pragma once
#include "Car.h"
#include "CarRepo.h"
#include "CosMasini.h"
//#include "RepoMap.h"
#include "Validator.h"
#include <vector>
#include <assert.h>
#include "Exporta.h"
#include<unordered_map>
#include "Undo.h"
#include<cstring>
#include <string.h>
#include <iostream>
#include<functional>
#include <numeric> 

using std::vector;
class CarService
{
	//CarRepo& repo;
	CarRepoFile& repo;

	CosMasini cos;
	//CarRepoMAP& repo;
	Validator& validator;
	vector<unique_ptr<ActiuneUndo> >undoActions;

	vector<unique_ptr<ActiuneUndoCos> >undoActionsCos;

public:
	CarService(CarRepoFile& repo, Validator& validator) :repo{ repo }, validator{ validator }{}
	//CarService(CarRepoMAP& repo,Validator validator ):repo{repo},validator{validator}{}
	CarService(const CarService&ot) = delete;
	~CarService() {}
	void add(const string& nrInmatr, const string& prod, const string& model, const string& tip);

	void del(const string& nrInmatriculare);

	void update(const string& nrInmatr, const string& prodNou, const string& modelNou, const string& tipNou);

	Car findCar(const string& nrInmatriculare);

	vector<Car> getAll();

	int cateModel(const string& model);

	vector<Car> filterByProd(string s);
	vector<Car> filterByTip(string s);
	vector<Car> sortByNrInmatriculare();
	vector<Car> sortByTip();
	//vector<Car> sortByProdSiModel();

	//raport 
	vector<DTO>raport();

	//undo 
	void undo();

	void salvare(string fName);




	//cos 
	const vector<Car>& addToCos(const string&nrInmatriculare);
	const vector<Car>& addRandom(int cate);
	const vector<Car>& golesteCos();
	const vector<Car>& toateDinCos();


	//export
	void exportaCosCVS(std::string fName) const;
	void exportaCosHTML(std::string fName)const;


};

void TestService();
void testCos();