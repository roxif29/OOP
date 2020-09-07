#pragma once
#include <vector>
#include "Car.h"
#include <algorithm>
#include <map>

using std::vector;
using std::ostream;
using std::map;
using std::unique_ptr;
class RepoException {
	string msg;
public:
	RepoException(string msg) : msg{ msg } {}
	string getMessage() {
		return msg;

	}
};


class CarRepo
{
private:
	vector <Car> cars;
	//map<string, Car> cars;

public:
	CarRepo() = default;
	CarRepo(const CarRepo& ot) = delete;
	~CarRepo() = default;



	virtual void  storeCar(const Car& car);


	const vector<Car>& getAll()const noexcept {
		return cars;
	}
	/*const map<string,Car>& getAll()const noexcept {
		return cars;
	}*/

	virtual void sterge(const Car& c);

	virtual void update(const Car& cNou);
	const Car& find(string nrInmatriculare);



};

class CarRepoFile : public CarRepo {
private:
	string fileName;
	void loadFromFile();
	void storeToFile();

public:
	CarRepoFile() = default;
	CarRepoFile(string fileName) :CarRepo(), fileName{ fileName }{
		loadFromFile();
	}
	//CarRepoFile(const CarRepo& ot) = delete;
	
	void storeCar(const Car&car) override;
	void update(const Car&cNou)override;
	void sterge(const Car& c)override;
};

void RepoTests();