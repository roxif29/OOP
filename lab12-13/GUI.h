#include <QtWidgets/qwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qpushbutton.h>
#include <qmessagebox.h>
#include <QtWidgets/qcombobox.h>
#include <QTWidgets/qgridlayout.h>
#include <QDebug>
#include <QRadioButton>
#include <QComboBox>
#include <QTabWidget>
#include <QStackedLayout>
#include <QCloseEvent>
#include "QTableWidget"
#include "CarService.h"
#include "GuiLista.h"
#include "Observer.h"
#include "CosMasini.h"
class GUI:public QWidget{
private:
	CarService& serv;


	QWidget w{};
	QHBoxLayout* lyMain = new QHBoxLayout{};// in asta o sa bag alealalte
	QVBoxLayout* lyOptiuni1 = new QVBoxLayout{};//aici o sa fie lista cu masini si btn pt sort si filtrari
	QHBoxLayout* lyOptiuni2 = new QHBoxLayout{};//aici o sa fie detalii masina+btn pt crud+ undo
	QHBoxLayout* lyOptiuni3 = new QHBoxLayout{};//aici o sa fie cosu+optiuni cos+ exportu

	//liste
	QListWidget* listCars = new QListWidget;
	QListWidget* listCos = new QListWidget;

	//text
	QLineEdit* txtNr = new QLineEdit;
	QLineEdit* txtProd = new QLineEdit;
	QLineEdit* txtModel = new QLineEdit;
	QLineEdit* txtTip = new QLineEdit;
	QLineEdit* txtFisier = new QLineEdit;


	//butoane
	//cos
	QPushButton* btnAddCos = new QPushButton{ "&Add cos" };
	QPushButton* btnGolesteCos = new QPushButton{ "&Goleste cos" };
	QPushButton* btnRandomCos = new QPushButton{ "&Genereaza cos" };
	//export
	QPushButton* btnExporta = new QPushButton{ "&Exporta" };
	//crud
	QPushButton* btnAdd = new QPushButton{ "&Add car" };
	QPushButton* btnUpdate = new QPushButton{ "&Update car" };
	QPushButton* btnDelete = new QPushButton{ "&Delete car" };
	//undo
	QPushButton* btnUndo = new QPushButton{ "&Undo" };
	//filtrari
	QPushButton* btnFilterTip = new QPushButton{ "&Filtrare tip" };
	QPushButton* btnFilterProd = new QPushButton{ "&Filtrare producator" };
	//sortari
	QPushButton* btnSortNr = new QPushButton{ "&Sortare nr inmatr" };
	QPushButton* btnSortTip = new QPushButton{ "&Sortare tip" };
	//exit
	QPushButton* btnExit = new QPushButton{ "&Exit" };
	//fereastra noua
	QPushButton* btnNewWin = new QPushButton("&Deschide fereastra cos");
	
	//tabel 
	QTableWidget* carsTable = new QTableWidget{ 1,2 };

	void AddCar();
	void DeleteCar();
	void UpdateCar();

	void FilterByProd();
	void FilterByTip();
	void SortByNrInmatriculare();
	void SortByTip();

	//cos
	void AddCos();
	void GolesteCos();
	void RandomCos();

	void Undo();

	void Exportare();

	void initGUI();
	void initButoane();
	void reload(const vector<Car>&cars);
	void reloadCos(const vector<Car>&cos);


public:
	GUI(CarService& serv) :serv{ serv } {
		initGUI();
		initButoane();
		reload(serv.getAll());
		reloadCos(serv.toateDinCos());
	}
	void loadTable(vector<Car> cars);
	~GUI() = default;
};

