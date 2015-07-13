#include "graph.h"
#include <QFile>
#include <QTextStream>

Graph::Graph() {
}

Graph::~Graph() {
	for (int i = 0; i < roads.size(); ++i)
		delete roads[i];
	for (int i = 0; i < cities.size(); ++i)
		delete cities[i];
}

bool Graph::load(const QString &filename) {
	QFile file(filename);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return false;
	QTextStream in(&file);
	bool ok = true;
	int n = in.readLine().toInt(&ok);
	if (!ok) return false;
	for (int i = 0; i < n; ++i)
		if (!addCityByString(in.readLine()))
			return false;
	int m = in.readLine().toInt(&ok);
	if (!ok) return false;
	for (int i = 0; i < m; ++i)
		if (!addRoadByString(in.readLine()))
			return false;
	return true;
}

bool Graph::addCityByString(const QString &input) {
	QStringList strlist = input.split(" ", QString::SkipEmptyParts);
	if (strlist.length() < 3 || strlist.length() > 4) return false;
	bool ok = true;
	double lon = strlist[1].toDouble(&ok);
	if (!ok) return false;
	double lat = strlist[2].toDouble(&ok);
	if (!ok) return false;
	QColor color(0, 0, 0);
	if (strlist.length() == 4) {
		QColor test_color(strlist[3]);
		if (test_color.isValid())
			color = test_color;
	}
	cities.push_back(new City(strlist[0], lon, lat, color));
	return true;
}

bool Graph::addRoadByString(const QString &input) {
	QStringList strlist = input.split(" ", QString::SkipEmptyParts);
	if (strlist.length() < 2 || strlist.length() > 4) return false;
	bool ok = true;
	int i = strlist[0].toInt(&ok);
	if (!ok) return false;
	int j = strlist[1].toInt(&ok);
	if (!ok) return false;
	if (i <= 0 || j <= 0 || i > cities.size() || j > cities.size())
		return false;
	QColor color(0, 0, 0);
	if (strlist.length() > 2) {
		QColor test_color(strlist[2]);
		if (test_color.isValid())
			color = test_color;
	}
	QString label = "";
	if (strlist.length() > 3)
		label = strlist[3];
	roads.push_back(new Road(cities[i - 1], cities[j - 1], color, label));
	return true;
}

Graph::City::City(const QString &name, double lon, double lat, const QColor &color) {
	this->city_name = name;
	this->lon = lon;
	this->lat = lat;
	this->color = color;
}

Graph::City::~City() {
}

Graph::Road::Road(Graph::City* city_1, Graph::City* city_2, const QColor &color, const QString &label) {
	this->city_1 = city_1;
	this->city_2 = city_2;
	this->label = label;
	this->color = color;
}

Graph::Road::~Road() {
}


