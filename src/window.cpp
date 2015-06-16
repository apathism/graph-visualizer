#include "window.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
	// Установим ширину по-умолчанию
	resize(640, 480);
	// Инициализация веб-браузера
	web = new QWebEngineView(this);
	web->load(QUrl("https://google.com/"));
	// Центральный виджет — карта
	setCentralWidget(web);
	// Заголовок программы
	setWindowTitle("Визуализатор карт");
}

MainWindow::~MainWindow() {
}
