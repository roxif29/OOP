#pragma once
#include "Car.h"
#include"CarService.h"
class UI
{
	CarService& serv;

	void AddCar();
	
	void PrintCars(VectorDinamic<Car> cars);

	void DeleteCar();

	void UpdateCar();

	void FindCar();

	void FilterByProd();
	void FilterByTip();
	void SortByNrInmatriculare();
	void SortByTip();
	



public:
	UI(CarService& serv) noexcept :serv{ serv } {}
	
	UI(const UI& ot) = delete;

	void meniu();
};


