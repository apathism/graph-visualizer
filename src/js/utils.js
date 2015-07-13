function addVertex(name, lon, lat, color) {
    myMap.geoObjects.add(new ymaps.Placemark([lon, lat], {
	hintContent: name
    }, {
	preset: 'islands#circleDotIcon',
	iconColor: color
    }));
}

function addEdge(x1, y1, x2, y2, color, name) {
    myMap.geoObjects.add(new ymaps.GeoObject({
	geometry: {
	    type: "LineString",
	    coordinates: [
		[x1, y1],
		[x2, y2]
	    ]
	},
	properties: {
	    hintContent: name
	}
    }, {
	strokeColor: color,
	strokeWidth: 3
    }));
}

function clearMap() {
    myMap.geoObjects.removeAll();
}
