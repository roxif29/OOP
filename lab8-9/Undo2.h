#pragma once
#pragma once
#include "Car.h"
#include "CarRepo.h"
/*
class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	//destructorul e virtual pentru a ne asigura ca daca dau delete se apeleaza destructorul din clasa care trebuie
	virtual ~ActiuneUndo() = default;
};

class UndoAdauga : public ActiuneUndo {
	Car petAdaugat;
	CarRepo& rep;
public:
	UndoAdauga(CarRepo& rep, const  Car& p) :rep{ rep }, petAdaugat{ p } {}

	void doUndo() override {
		rep.sterge(petAdaugat);
	}
};

class UndoSterge : public ActiuneUndo {
	Car petSters;
	CarRepo& rep;
public:
	UndoSterge(CarRepo& rep, const  Car& p) :rep{ rep }, petSters{ p } {}
	void doUndo() override {
		rep.storeCar(petSters);
	}
};*/