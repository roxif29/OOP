#include "GuiLista.h"

GuiCos::GuiCos(vector<Car> cars)
{
	QVBoxLayout* ly = new QVBoxLayout;
	setLayout(ly);
	l = new QListWidget;
	ly->addWidget(l);
	l->clear();
	for (auto car : cars) {
		auto c = car.getNrInmatriculare() + " " + car.getProducator() + " " + car.getModel();
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(c), l);
	}
}

GuiLista::GuiLista(vector<Car> cars)
{
	QVBoxLayout* ly = new QVBoxLayout;
	setLayout(ly);
	l = new QListWidget;
	ly->addWidget(l);
	l->clear();
	for (auto car : cars) {
		auto c = car.getNrInmatriculare() + " " + car.getProducator() + " " + car.getModel();
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(c), l);

	}
}

GuiLista::~GuiLista()
{

}
