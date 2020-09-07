#include "lab10.h"
#include <QtWidgets/QApplication>
#include "CarService.h"
#include "GUI.h"
#include "CosMasini.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//lab10 w;
	//w.show();
	//CarRepo repo;
	CarRepoFile repo{ "masini.txt" };
	Validator valid;
	CarService serv{ repo,valid };
	//CosMasini cos;
	GUI gui{ serv };
	gui.show();
	return a.exec();
}
