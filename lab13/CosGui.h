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
class CosGui : public QWidget, public Observer {
private:
	CosMasini& cos;
	QListWidget* lst;
	QPushButton* btn;
	QPushButton* btnRandom;
	void loadList(const std::vector<Car>& cars) {
		lst->clear();
		for (auto& c : cars) {
			lst->addItem(QString::fromStdString(c.getNrInmatriculare()));
		}
	}
	void initGUI() {
		QHBoxLayout* ly = new QHBoxLayout;
		lst = new QListWidget;
		ly->addWidget(lst);
		btn = new QPushButton("Clear cos");
		//ly->addWidget(btn);

		btnRandom = new QPushButton("Random cos");
		//ly->addWidget(btnRandom);
		setLayout(ly);
	}
	void connectSignals() {
		cos.addObserver(this);
		QObject::connect(btn, &QPushButton::clicked, [&]() {
			cos.golesteCos();
			loadList(cos.getAllCos());
		});
		QObject::connect(btnRandom, &QPushButton::clicked, [&]() {
			cos.randomAdd(3,cos.getAllCos());
			loadList(cos.getAllCos());
		});
	}
public:
	CosGui(CosMasini& cos) :cos{ cos } {
		initGUI();
		connectSignals();
		loadList(cos.getAllCos());
	}

	void update() override {
		loadList(cos.getAllCos());
	}

	~CosGui() {
		cos.removeObserver(this);
	}

};