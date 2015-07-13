#ifndef MAPVISUALIZER_GEOOBJECT_H
#define MAPVISUALIZER_GEOOBJECT_H

#include <QString>

class GeoObject {
public:
	virtual QString getDrawingJavaScript() const = 0;
};

#endif
