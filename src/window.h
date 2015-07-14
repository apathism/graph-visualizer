#ifndef MAPVISUALIZER_WINDOW_H
#define MAPVISUALIZER_WINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "geoobject.h"
#include <QProcess>

class MainWindow: public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	QWebEngineView* web;
	QVBoxLayout *vlayout;
	QHBoxLayout *hlayout;
	QPushButton *map_orig;
	QPushButton *map_prog;
	QWidget *central_widget;
	QProcess *process;
	void addGeoObject(const GeoObject &);

private slots:
	void clearMap();
	void loadingError();
	void loadOriginal();
	void executeProgram();
	void loadModified();
};

#endif
