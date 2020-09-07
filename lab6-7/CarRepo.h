#pragma once
#include <vector>
#include "Car.h"
#include <algorithm>
#include "VectorDinamicTemplate.h"
using std::vector;
using std::ostream;
class RepoException {
	string msg;
public:
	RepoException(string msg): msg{msg}{}
	string getMessage() {
		return msg;
		
	}
};


class CarRepo
{
private:
	//vector <Car> cars;
	VectorDinamic<Car> cars;
public:
	CarRepo() = default;
	CarRepo(const CarRepo& ot) = default;
	~CarRepo() = default;


	void  storeCar(const Car& car);


	/*const vector<Car>& getAll()const noexcept {
		return this->cars;
	}*/
	VectorDinamic<Car>& getAll() {
		return this->cars;
	}

		void sterge(const Car& c);

		void update(const Car& cNou);
		//const Car& find(string nrInmatriculare);
		int find(string nrInmatriculare);

	};

void RepoTests();