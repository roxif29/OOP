#pragma once
#include <QWidget.h>
#include <QPushButton.h>
#include <QBoxLayout.h>
#include <QTableWidget.h>
#include <Qlineedit.h>
#include <QFormLayout.h>
#include <QMessageBox.h>
#include <qlistwidget.h>
#include "CarService.h"
#include "Car.h"

class GuiLista :QWidget
{
	friend class GUI;
	QListWidget* l;
public:
	GuiLista(vector<Car>cars);
	~GuiLista();
};

class GuiCos :QWidget {
	friend class GUI;
	QListWidget* l;
public:

	GuiCos(vector<Car>cars);
};