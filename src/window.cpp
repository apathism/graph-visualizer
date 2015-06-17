#include "window.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
	// Установим ширину по-умолчанию
	resize(800, 640);
	// Инициализация веб-браузера
	web = new QWebEngineView(this);
	web->load(QUrl("qrc:/js/main.html"));
	// Центральный виджет — карта
	setCentralWidget(web);
	// Заголовок программы
	setWindowTitle("Визуализатор карт");
}

MainWindow::~MainWindow() {
}
