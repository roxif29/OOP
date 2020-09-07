#pragma once
#include <qwidget.h>
#include <qtimer.h>
#include <QtWidgets/QHBoxLayout>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qtablewidget.h>
#include <qstring.h>
#include <qlabel.h>
#include <vector>
#include "CosMasini.h"
#include "Observer.h"
#include "CarService.h"
class CosGui : public QWidget, public Observer {
private:
	CosMasini& cos;
	CarService& serv;
	QListWidget* lst;
	QPushButton* btn;
	QPushButton* btnRandom;
	QListWidget* listaRaport = new QListWidget;

	// pt statistica 

	void loadList(const std::vector<Car>& cars) {
		lst->clear();
		for (auto& c : cars) {
			lst->addItem(QString::fromStdString(c.getNrInmatriculare()));
		}

		

	}
	void loadRaport() {
		listaRaport->clear();
		vector<DTO> rap = serv.raport();
		for (auto& r : rap) {
			QString cant = QString::number(r.get_cant());
			QString str = QString::fromStdString(r.getStr());

			listaRaport->addItem(str + " " + cant);
		}
	}
	void initGUI() {
		QHBoxLayout* ly = new QHBoxLayout;
		lst = new QListWidget;
		ly->addWidget(lst);
		btn = new QPushButton("Clear cos");
		ly->addWidget(btn);

		btnRandom = new QPushButton("Random cos");
		ly->addWidget(btnRandom);

		ly->addWidget(listaRaport);
		setLayout(ly);
	}
	void connectSignals() {
		//cos.addObserver(this);
		serv.addObserver(this);
		QObject::connect(btn, &QPushButton::clicked, [&]() {
			serv.golesteCos();
			loadList(serv.toateDinCos());
			//loadList(cos.toateDinCos());
		});
		QObject::connect(btnRandom, &QPushButton::clicked, [&]() {
			//cos.randomAdd(3,cos.getAllCos());
			//loadList(cos.getAllCos());
			//cos.addRandom(3);
			serv.addRandom(3);
			loadList(serv.toateDinCos());
		});
		//cos.addObserver(this);
		QObject::connect(listaRaport, &QListWidget::itemSelectionChanged, []() {});
		
	}
public:
	CosGui(CosMasini& cos, CarService& serv) :cos{ cos }, serv{ serv } {
		initGUI();
		connectSignals();
		loadList(serv.toateDinCos());
		loadRaport();
	}

	void update() override {
		//loadList(cos.getAllCos());
		loadList(serv.toateDinCos());
		loadRaport();
	}

	~CosGui() {
		serv.removeObserver(this);
		//cos.removeObserver(this);
	}

};