#pragma once
#include <vector>
#include <algorithm>
#include <random>    
#include <chrono>    
#include "Car.h"
using std::vector;
class CosMasini
{
private:
	vector<Car> cos;
public:
	CosMasini() = default;
	void addCos(const Car&c);
	void golesteCos();
	void randomAdd(size_t cate, vector<Car>allCars);
	const vector<Car>& getAllCos()const;
	
	
};

