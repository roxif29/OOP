#include "UI.h"
#include <vector>
#include <iostream>
using namespace std;
void UI::AddCar()
{
	string nr, mod, prod, tip;

	cout << "Nr inmatriculare:";
	cin >> nr;
	cout << "Producator:";
	cin >> prod;
	cout << "Model:";
	cin >> mod;
	cout << "Tip:";
	cin >> tip;
	serv.add(nr, prod,mod,tip);
	cout << "Adaugat cu succes\n";
}

void UI::PrintCars( VectorDinamic<Car> cars)
{
	if (cars.getLungime() > 0)
	{
		cout << "Cars:\n";
		for (int i = 0; i < cars.getLungime();i++) {
			Car c = cars.getElem(i);
			cout << ' ' << c.getNrInmatriculare() << ' ' << c.getProducator() << ' ' << c.getModel() << ' ' << c.getTip() << '\n';
		}
		cout << "~~~~~~~~~~~~\n";
	}
	else
		cout << "Please add a car!\n";
}

void UI::DeleteCar()
{
	string nr;
	cout << "Nr inmatriculare:";
	cin >> nr;
	serv.del(nr);
	cout << "Deleted\n";
}

void UI::UpdateCar()
{
	string nr, mod, prod, tip;
	cout << "Nr inmatriculare:";
	cin >> nr;
	cout << "Producator nou:";
	cin >> prod;
	cout << "Model nou:";
	cin >> mod;
	cout << "Tip nou:";
	cin >> tip;
	serv.update(nr,prod,mod,tip);
	cout << "Updated\n";
	
}

void UI::
FindCar()
{
	string nr;
	cout <<"Nr inmatriculare:";
	cin >> nr;
	Car found = serv.findCar(nr);
	cout << ' ' << found.getNrInmatriculare() << ' ' << found.getProducator() << ' ' << found.getModel() << ' ' << found.getTip() << '\n';
	cout << "Succes\n";
}

void UI::FilterByProd()
{
	string prod;
	cout << "Producatorul:";
	cin >> prod;
	VectorDinamic<Car> rez=serv.filterByProd(prod);
	this->PrintCars(rez);
	
}

void UI::FilterByTip()
{
	string prod;
	cout << "Producatorul:";
	cin >> prod;
	VectorDinamic<Car> rez = serv.filterByProd(prod);
	this->PrintCars(rez);
}

void UI::SortByNrInmatriculare()
{
	VectorDinamic<Car> rez = serv.sortByNrInmatriculare();
	this->PrintCars(rez);
}

void UI::SortByTip()
{
	VectorDinamic<Car> rez = serv.sortByTip();
	this->PrintCars(rez);
}


void UI::meniu()
{
	cout << "Meniu:\n";
	cout << "0. Exit\n";
	cout << "1. Add car\n";
	cout << "2. Print car\n";
	cout << "3. Delete car\n";
	cout << "4. Update car\n";
	cout << "5. Find car\n";
	cout << "7. Filter by";
	cout << "8. Filter by";
	cout << "9. Sort= by\n";
	cout << "10. Sort= by\n";
	while (true) {
		
		int cmd;
		cin >> cmd;
		try {
			switch (cmd) {
			
			case 1:
				AddCar();
				break;
			case 2:
				PrintCars(serv.getAll());
				break;
			case 3:
				DeleteCar();
				break;
			case 4:
				UpdateCar();
				break;
			case 5:
				FindCar();
				break;
			case 6:
				FilterByProd();
				break;
			case 7:
				FilterByTip();
				break;
			case 8:
				SortByNrInmatriculare();
				break;
			case 9:
				SortByTip();
				break;
			case 0:
				return;
			default:
				cout << "Invalid cmd\n";
			}
		}
		catch (RepoException ex) {
			string err = ex.getMessage();
			cout << err;
		}
		catch (ValidateException ex) {
			string err = ex.getMsg();
			cout << err;
		}
	}
}