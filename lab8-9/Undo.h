#pragma once
#include "CarRepo.h"
#include "Car.h"


class ActiuneUndo
{
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() = default;
};



class UndoAdd : public ActiuneUndo{
private:
	Car adaugat;
	CarRepo& repo;
public:
	UndoAdd(CarRepo& repo, const Car& c) : repo{ repo }, adaugat{ c }{}

	void doUndo() override
	{
		repo.sterge(adaugat);
	}
};


class UndoDelete : public ActiuneUndo
{private:
	Car sters;
	CarRepo& repo;
public:
	UndoDelete(CarRepo& repo, const Car& c) : repo{ repo }, sters{ c }{}

	void doUndo() override
	{
		repo.storeCar(sters);
	}
};


class UndoUpdate : public ActiuneUndo
{private:
	Car updated;
	CarRepo& repo;
public:
	UndoUpdate(CarRepo& repo,  const Car& c) : repo{ repo }, updated{ c } {}

	void doUndo() override
	{
		repo.update(updated);
	}
};


class ActiuneUndoCos
{
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndoCos() = default;
};


class UndoAddCos : public ActiuneUndoCos
{private:
	Car adaugat;
	CarRepo& repo;
public:
	UndoAddCos(CarRepo& repo, const Car& c) :adaugat{ c }, repo{ repo }{}

	void doUndo() override
	{
		repo.sterge(adaugat);
	}
};