#include "GUI.h"
#include "GuiLista.h"
/*
void GUI::AddCar()
{
	try {
		serv.add(txtNr->text().toStdString(), txtProd->text().toStdString(), txtModel->text().toStdString(), txtTip->text().toStdString());
		reload(serv.getAll());
	}
	catch (CarException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}
	catch (RepoException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
	}
	catch (ValidateException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}
}

void GUI::DeleteCar()
{
	try {
		serv.del(txtNr->text().toStdString());
		reload(serv.getAll());
	}
	catch (CarException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}
	catch (RepoException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
	}
	catch (ValidateException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}

}

void GUI::UpdateCar()
{
	try {
		serv.update(txtNr->text().toStdString(), txtProd->text().toStdString(), txtModel->text().toStdString(), txtTip->text().toStdString());
		reload(serv.getAll());
	}
	catch (CarException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}
	catch (RepoException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
	}
	catch (ValidateException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}

}

void GUI::FilterByProd()
{
	vector<Car>filtru = serv.filterByProd(txtProd->text().toStdString());
	if (filtru.size() == 0 && txtProd->text()=="") {
		QMessageBox::warning(this, "ioi", "Introdu datele prima data!");
	}
	else {
		if(filtru.size() == 0 && txtProd->text() != "")
			QMessageBox::warning(this, "ioi", "Nu s-a gasit niciun rezultat!");
		else 
			if (filtru.size() != 0) {
				reload(filtru);
			}

		
	}
	
	
}

void GUI::FilterByTip()
{

	vector<Car>filtru = serv.filterByProd(txtTip->text().toStdString());
	if (filtru.size() == 0 && txtTip->text() == "") {
		QMessageBox::warning(this, "ioi", "Introdu datele prima data!");
	}
	else {
		if (filtru.size() == 0 && txtTip->text() != "")
			QMessageBox::warning(this, "ioi", "Nu s-a gasit niciun rezultat!");
		else
			if (filtru.size() != 0) {
				reload(filtru);
			}


	}
}

void GUI::SortByNrInmatriculare()
{

	vector<Car>sortate = serv.sortByNrInmatriculare();
	if (sortate.size() == 0) {
		QMessageBox::warning(this, "ioi", "Introdu date daca vrei sa sortezi..!");
	}
	else {
		reload(sortate);
	}
			


	
}

void GUI::SortByTip()
{
	vector<Car>sortate = serv.sortByTip();
	if (sortate.size() == 0) {
		QMessageBox::warning(this, "ioi", "Introdu date daca vrei sa sortezi..!");
	}
	else {
		reload(sortate);
	}


}

void GUI::AddCos()
{
	try {
		serv.addToCos(txtNr->text().toStdString());
		reloadCos(serv.toateDinCos());
	}
	catch (CarException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}
	catch (RepoException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
	}
	catch (ValidateException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}
}

void GUI::GolesteCos()
{
	serv.golesteCos();
	reloadCos(serv.toateDinCos());
}

void GUI::RandomCos()
{
	serv.addRandom(5);
	reloadCos(serv.toateDinCos());
}

void GUI::Undo()
{
	try {
		serv.undo();
		reload(serv.getAll());
	}
	catch (CarException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}
	catch (RepoException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
	}
	catch (ValidateException& ex) {
		QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
	}
}

void GUI::Exportare()
{
	
}


*/
void GUI::initGUI()
{
	setLayout(lyMain);

	// aici am pus lista cu prod si butoanele pt sortari si filtrari
	lyOptiuni1->addWidget(listCars);
	lyOptiuni1->addWidget(btnFilterProd);
	lyOptiuni1->addWidget(btnFilterTip);
	lyOptiuni1->addWidget(btnSortNr);
	lyOptiuni1->addWidget(btnSortTip);

	lyMain->addLayout(lyOptiuni1);

	//campurile cu info despre masini, btn pt add up del si undo
	auto lyInfo = new QFormLayout;
	lyInfo->addRow("Nr. inmatr.", txtNr);
	lyInfo->addRow("Producator", txtProd);
	lyInfo->addRow("Model", txtModel);
	lyInfo->addRow("Tip", txtTip);
	lyInfo->addRow("Nume fisier pt export", txtFisier);

	lyOptiuni2->addLayout(lyInfo);


	auto lyBtnOpt = new QVBoxLayout;
	lyBtnOpt->addWidget(btnAdd);
	lyBtnOpt->addWidget(btnUpdate);
	lyBtnOpt->addWidget(btnDelete);
	lyBtnOpt->addWidget(btnUndo);
	lyBtnOpt->addWidget(btnExporta);

	lyOptiuni2->addLayout(lyBtnOpt);
	lyMain->addLayout(lyOptiuni2);

	//lyOptiuni3->addWidget(listCos);

	auto lyBtnOpt2 = new QVBoxLayout;
	lyBtnOpt2->addWidget(btnAddCos);
	lyBtnOpt2->addWidget(btnRandomCos);
	lyBtnOpt2->addWidget(btnGolesteCos); 
	lyBtnOpt2->addWidget(btnNewWin); 

	lyOptiuni3->addLayout(lyBtnOpt2);
	lyMain->addLayout(lyOptiuni3);
	lyMain->addLayout(lyAddBtn);


	//lyMain->addWidget(listCars);
	//lyMain->addLayout(lyOptiuni1);
	//w.show();
}

void GUI::initButoane()
{

	QObject::connect(btnAdd, &QRadioButton::clicked, [=]() {
		try {
			serv.add(txtNr->text().toStdString(), txtProd->text().toStdString(), txtModel->text().toStdString(), txtTip->text().toStdString());
			reload(serv.getAll());
		}
		catch (CarException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
		catch (RepoException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
		}
		catch (ValidateException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
		addBtns(serv.getAll());
	
	});
	QObject::connect(btnUpdate, &QRadioButloadton::clicked, [=]() {
		try {
			serv.update(txtNr->text().toStdString(), txtProd->text().toStdString(), txtModel->text().toStdString(), txtTip->text().toStdString());
			reload(serv.getAll());
		}
		catch (CarException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
		catch (RepoException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
		}
		catch (ValidateException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
	});
	QObject::connect(btnDelete, &QRadioButton::clicked, [=]() {
		try {
			serv.del(txtNr->text().toStdString());
			reload(serv.getAll());
		}
		catch (CarException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
		catch (RepoException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
		}
		catch (ValidateException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
	});

	QObject::connect(btnAddCos, &QRadioButton::clicked, [=]() {
		try {
			serv.addToCos(txtNr->text().toStdString());
			reloadCos(serv.toateDinCos());
		}
		catch (CarException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
		catch (RepoException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
		}
		catch (ValidateException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
	});

	QObject::connect(btnExporta, &QRadioButton::clicked, [=]() {
		try {
			serv.exportaCosHTML(txtFisier->text().toStdString());
		}
		catch (CarException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
		catch (RepoException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
		}
		catch (ValidateException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
	});
	QObject::connect(btnGolesteCos, &QRadioButton::clicked,[=]() {
		serv.golesteCos();
		reloadCos(serv.toateDinCos());
	});
	QObject::connect(btnRandomCos, &QRadioButton::clicked, [=]() {
		serv.addRandom(5);
		reloadCos(serv.toateDinCos());
	
	});
	QObject::connect(btnExporta, &QRadioButton::clicked,[]() {
		
	});
	QObject::connect(btnExit, &QRadioButton::clicked,[=]() {
		close();
	});
	QObject::connect(btnUndo, &QRadioButton::clicked, [=]() {
		try {
			serv.undo();
			reload(serv.getAll());
			addBtns(serv.getAll());
		}
		catch (CarException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
		catch (RepoException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMessage()));
		}
		catch (ValidateException& ex) {
			QMessageBox::warning(this, "ioi", QString::fromStdString(ex.getMsg()));
		}
	
	});
	QObject::connect(btnFilterTip, &QRadioButton::clicked, [=]() {
		vector<Car>filtru = serv.filterByProd(txtTip->text().toStdString());
		if (filtru.size() == 0 && txtTip->text() == "") {
			QMessageBox::warning(this, "ioi", "Introdu datele prima data!");
		}
		else {
			if (filtru.size() == 0 && txtTip->text() != "")
				QMessageBox::warning(this, "ioi", "Nu s-a gasit niciun rezultat!");
			else
				if (filtru.size() != 0) {
					reload(filtru);
				}


		}
	});
	QObject::connect(btnFilterProd, &QRadioButton::clicked, [=](){
		vector<Car>filtru = serv.filterByProd(txtProd->text().toStdString());
	if (filtru.size() == 0 && txtProd->text() == "") {
		QMessageBox::warning(this, "ioi", "Introdu datele prima data!");
	}
	else {
		if (filtru.size() == 0 && txtProd->text() != "")
			QMessageBox::warning(this, "ioi", "Nu s-a gasit niciun rezultat!");
		else
			if (filtru.size() != 0) {
				reload(filtru);
			}


	} 
	});
	QObject::connect(btnSortNr, &QRadioButton::clicked,[=]() {
		vector<Car>sortate = serv.sortByNrInmatriculare();
		if (sortate.size() == 0) {
			QMessageBox::warning(this, "ioi", "Introdu date daca vrei sa sortezi..!");
		}
		else {
			reload(sortate);
		}
	});
	QObject::connect(btnSortTip, &QRadioButton::clicked,[=]() {
		vector<Car>sortate = serv.sortByTip();
		if (sortate.size() == 0) {
			QMessageBox::warning(this, "ioi", "Introdu date daca vrei sa sortezi..!");
		}
		else {
			reload(sortate);
		}

	});

	QObject::connect(listCars, &QListWidget::itemSelectionChanged, [=]() {
		auto selected = listCars->selectedItems();
		if (selected.isEmpty()) {
			txtNr->setText("");
			txtProd->setText("");
			txtModel->setText("");
			txtTip->setText("");
		}
		else {
			auto car = selected.at(0);
			auto nr = car->text();
			txtNr->setText(nr);
			Car c = serv.findCar(nr.toStdString());
			txtProd->setText(QString::fromStdString(c.getProducator()));
			txtModel->setText(QString::fromStdString(c.getModel()));
			txtTip->setText(QString::fromStdString(c.getTip()));
		}
	});

	QObject::connect(btnNewWin, &QPushButton::clicked, [&]() {
		
		auto v = serv.toateDinCos();
		if (v.size() == 0) {
			QMessageBox::warning(nullptr, "ioi", "Nu sunt masini in cos!");
			return;
		}
		QWidget* w = new GuiCos{ v };

		w->show();
	});
}

void GUI::reload(const vector<Car>& cars)
{
	listCars->clear();
	for (const auto& c : cars)
	{
		listCars->addItem(QString::fromStdString(c.getNrInmatriculare()));
	}
}
void GUI::reloadCos(const vector<Car>& cos)
{
	listCos->clear();
	for (const auto& c : cos)
	{
		listCos->addItem(QString::fromStdString(c.getNrInmatriculare()));
	}
}

void GUI::addBtns(const vector<Car>& cars)
{
	for (auto b : btns)
		delete b;
	btns.clear();

	for (auto c : cars)
	{
		auto btn = new QPushButton{ QString::fromStdString(c.getNrInmatriculare()) };
		btns.push_back(btn);
		//btn->setStyleSheet("background-color:#ff5e5e");
		lyAddBtn->addWidget(btn);
		QObject::connect(btn, &QPushButton::clicked, [this, btn, c]()
		{
			serv.del(c.getNrInmatriculare());
			addBtns(serv.getAll());
			reload(serv.getAll());
		});
		for (auto b : btns)
		{
			lyAddBtn->addWidget(b);
		}
	}
}

