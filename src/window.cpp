#include "window.h"
#include <QResizeEvent>

#include "graph.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent) {
	resize(800, 640);

	web = new QWebEngineView();
	web->load(QUrl("qrc:/js/main.html"));

	map_orig = new QPushButton("Показать оригинал карты");
	connect(map_orig, SIGNAL(clicked()), this, SLOT(loadOriginal()));
	map_prog = new QPushButton("Запустить программу");

	hlayout = new QHBoxLayout();
	hlayout->addWidget(map_orig);
	hlayout->addWidget(map_prog);

	vlayout = new QVBoxLayout();
	vlayout->addWidget(web);
	vlayout->addLayout(hlayout);

	central_widget = new QWidget();
	central_widget->setLayout(vlayout);

	setCentralWidget(central_widget);
	setWindowTitle("Визуализатор карт");
}

MainWindow::~MainWindow() {
	delete central_widget;
}

void MainWindow::addGeoObject(const GeoObject &geo) {
	QMessageBox msgBox;
	msgBox.setText(geo.getDrawingJavaScript());
	msgBox.exec();
	web->page()->runJavaScript(geo.getDrawingJavaScript());
}

void MainWindow::clearMap() {
	web->page()->runJavaScript("clearMap();");
}

void MainWindow::loadOriginal() {
	clearMap();
	// Not Implemented
}

void MainWindow::executeProgram() {
	clearMap();
	// Not Implemented
}
