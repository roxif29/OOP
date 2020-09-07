#include "CosMasini.h"
#include "CarRepo.h"
#include <iostream>

void CosMasini::addCos(const Car & c)
{// in serv trebe sa caut dupa nr inmatriculare si daca gasesc sa adaug in lista asta
	cos.push_back(c);
}

void CosMasini::golesteCos()
{
	cos.clear();
}

void CosMasini::randomAdd(size_t cate, vector<Car> allCars)
{
	std::shuffle(allCars.begin(), allCars.end(), std::default_random_engine(std::random_device{}()));
	while (cos.size() < cate && allCars.size() > 0) {
		cos.push_back(allCars.back());
		allCars.pop_back();
	}
}

const vector<Car>& CosMasini::getAllCos() const
{
	return cos;
}



