#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;

class CarException {
	std::string msg;
public:
	CarException(const string& m ):msg{ m } {};
	string getMsg()const { return msg; }
};


class DTO
{
	std::string s;
	double cant = 0;
public:
	DTO(const string a, double b) :s{ a }, cant{ b }{}
	DTO() { }
	void add() {
		cant++;
	}
	string getStr() const
	{
		return s;
	}

	double get_cant() const
	{
		return cant;
	}
};


class Car
{
private:
	string nrInmatriculare;
	string producator;
	string model;
	string tip;
public:
	Car() = default;
	Car(const string& nrInmatriculare, const string& producator, const string& model, const string& tip) : nrInmatriculare{ nrInmatriculare }, producator{ producator }, model{ model }, tip{ tip }{
	}
	Car(const Car& c) = default;


	Car& operator=(const Car& ot) = default;

	string getNrInmatriculare() const {
		return this->nrInmatriculare;
	}

	string getProducator() const {
		return this->producator;
	}

	string getModel() const {
		return this->model;
	}

	string getTip() const {
		return this->tip;
	}

	void setProducator(string s) {
		this->producator = s;
	}

	void setModel(string s) {
		this->model = s;
	}

	void setTip(string s) {
		this->tip = s;

	}

};

