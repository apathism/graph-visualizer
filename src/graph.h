#ifndef MAPVISUALIZER_GRAPH_H
#define MAPVISUALIZER_GRAPH_H

#include <QVector>
#include <QColor>

class Graph {
public:
	Graph();
	~Graph();

	bool load(const QString &file = "map.txt");
	
	class City {
	public:
		City(const QString &, double, double, const QColor &color);
		~City();
	protected:
		QString city_name;
		double lon, lat;
		QColor color;
	};

	class Road {
	public:
		Road(City*, City*, const QColor &, const QString &);
		~Road();
	protected:
		City *city_1, *city_2;
		QString label;
		QColor color;
	};
protected:
	QVector<City*> cities;
	QVector<Road*> roads;

private:
	bool addVertexByString(const QString &);
	bool addEdgeByString(const QString &);
};

#endif
