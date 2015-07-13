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
	return false; // Not Implemented
}

bool Graph::addVertexByString(const QString &) {
	return false; // Not Implemented
}

bool Graph::addEdgeByString(const QString &) {
	return false; // Not Implemented
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


