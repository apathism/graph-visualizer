#ifndef MAPVISUALIZER_GRAPH_H
#define MAPVISUALIZER_GRAPH_H

#include <QVector>
#include <QColor>
#include "geoobject.h"

class Graph: public GeoObject {
public:
	Graph();
	~Graph();

	bool load(const QString &file = "map.txt");
	virtual QString getDrawingJavaScript() const;

	class Road;
	
	class City: public GeoObject {
	public:
		City(const QString &, double, double, const QColor &color);
		virtual ~City();

		virtual QString getDrawingJavaScript() const;
		friend Road;
	protected:
		QString city_name;
		double lon, lat;
		QColor color;
	};

	class Road: public GeoObject {
	public:
		Road(City*, City*, const QColor &, const QString &);
		virtual ~Road();

		virtual QString getDrawingJavaScript() const;
	protected:
		City *city_1, *city_2;
		QString label;
		QColor color;
	};
protected:
	QVector<City*> cities;
	QVector<Road*> roads;

private:
	bool addCityByString(const QString &);
	bool addRoadByString(const QString &);
};

#endif
