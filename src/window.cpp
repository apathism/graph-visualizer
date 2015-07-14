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
	connect(map_prog, SIGNAL(clicked()), this, SLOT(executeProgram()));

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
	web->page()->runJavaScript(geo.getDrawingJavaScript());
}

void MainWindow::clearMap() {
	web->page()->runJavaScript("clearMap();");
}

void MainWindow::loadingError() {
	QMessageBox msgBox(this);
	msgBox.setText("Ошибка при загрузке файла карты!");
	msgBox.exec();
}

void MainWindow::loadOriginal() {
	clearMap();
	Graph graph;
	if (!graph.load("map1.txt"))
		loadingError();
	else
		addGeoObject(graph);
}

void MainWindow::executeProgram() {
	clearMap();
	map_orig->setEnabled(false);
	map_prog->setEnabled(false);

	process = new QProcess(this);
	process->setStandardInputFile("./map1.txt");
	process->setStandardOutputFile("./map2.txt");
	connect(process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(loadModified()));
	process->start("./program.exe");
}

void MainWindow::loadModified() {
	delete process;
	map_orig->setEnabled(true);
	map_prog->setEnabled(true);
	Graph graph;
	if (!graph.load("map2.txt"))
		loadingError();
	else
		addGeoObject(graph);
}
