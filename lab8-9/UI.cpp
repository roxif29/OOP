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

void UI::PrintCars(const vector<Car>& cars)
{
	if (cars.size() > 0)
	{
		cout << "Cars:\n";
		for (const auto& c : cars) {
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
	cout << "Deleted\n";
	
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
	vector<Car> rez=serv.filterByProd(prod);
	this->PrintCars(rez);
	
}

void UI::FilterByTip()
{
	string prod;
	cout << "Producatorul:";
	cin >> prod;
	vector<Car> rez = serv.filterByProd(prod);
	this->PrintCars(rez);
}

void UI::SortByNrInmatriculare()
{
	vector<Car> rez = serv.sortByNrInmatriculare();
	this->PrintCars(rez);
}

void UI::SortByTip()
{
	vector<Car> rez = serv.sortByTip();
	this->PrintCars(rez);
}

void UI::AddCos()
{
	string s;
	cout << "introduceti nr inmatriculare \n";
	cin >> s;
	try
	{
		serv.addToCos(s);

	}
	catch (RepoException& e)
	{
		cout << e.getMessage();
	}
	cout << "adaugat in cos\n";
}

void UI::GolesteCos()
{
	serv.golesteCos();
	cout << "cos golit\n";
}

void UI::RandomCos()
{
	string s;
	cout << "introduceti nr de masini pe care doriti sa le generati\n ";
	cin >> s;
	int nr = s[0] - '0';// tr sa fac si pt cazu in care nr>10
	serv.addRandom(nr);

	cout << "generat cu succes\n";
}

void UI::undo() {

	try
	{
		serv.undo();
	}catch (CarException& e)
	{
			cout << e.getMsg();
	}
	
}

void UI::Raport() {
	vector<DTO> rap = serv.raport();
	for (const auto& i : rap) {
		cout << i.getStr() << "   " << i.get_cant()<<"\n";
	}
}
void UI::Salvare()
{
	string fName;
	cout << "introduceti numele fisierului ";
	cin >> fName;
	serv.salvare(fName);
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
	cout << "6. Filter by\n";
	cout << "7. Filter by\n";
	cout << "8. Sort by nr inm\n";
	cout << "9. Sort by tip\n";
	cout << "10. Adauga cos\n";
	cout << "11. Goleste cos\n";
	cout << "12. Random cos\n";
	cout << "13. Afisare cos\n";
	cout << "14. Undo\n";
	cout << "15. Raport\n";
	cout << "16. Store to file\n";



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
			case 10:
				AddCos();
				break;
			case 11:
				GolesteCos();
				break;
			case 12:
				RandomCos();
				break;
			case 13:
				this->PrintCars(serv.toateDinCos());
				break;
			case 14:
				undo();
				break;
			case 15:
				Raport();
				break;
			case 16:
				Salvare();
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