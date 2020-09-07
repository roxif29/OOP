#include <iostream>
#include "Car.h"
#include "CarRepo.h"
#include "CosMasini.h"
#include "CarService.h"
#include "Validator.h"
#include  "UI.h"

#define _CRTDBG_MAP_ALLOC
int main()
{
	
	RepoTests();	
	std::cout << "repo ok\n";
	CarRepo repo;
	
	/*repo.storeCar(c);
	repo.update(Car{ "nr1", "prod2", "model2", "tip2" });
	Car gasit = repo.find("nr1");
	std::cout << gasit.getModel() << gasit.getNrInmatriculare() << gasit.getTip();
	*/
	Validator validator;
	CarService serv{ repo,validator };

	TestService();
	std::cout << "serv ok\n";

	testCos();
	std::cout << "cos ok\n";
	
	serv.add("nr1", "prod1", "model1", "tip1");
	serv.add("nr2", "prod2", "model2", "tip2");
	serv.add("nr3", "prod3", "model4", "tip3");
	serv.add("nr4", "prod4", "model4", "tip4");
	UI ui{ serv };
	
	
	ui.meniu();
	_CrtDumpMemoryLeaks();
	return 0;
}

	