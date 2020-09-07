#pragma once
#include "Car.h"
#include"CarService.h"
class UI
{
	CarService& serv;

	void AddCar();
	
	void PrintCars(const vector<Car>& cars);

	void DeleteCar();

	void UpdateCar();

	void FindCar();

	void FilterByProd();
	void FilterByTip();
	void SortByNrInmatriculare();
	void SortByTip();

	//cos
	void AddCos();
	void GolesteCos();
	void RandomCos();//se genereaza masini random
	

	void cateModel();

	void undo();

	void Raport();

	void Salvare();


public:
	UI(CarService& serv) noexcept :serv{ serv } {}
	
	UI(const UI& ot) = delete;

	void meniu();
};


