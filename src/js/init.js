var myMap;

ymaps.ready(function () {
    var myMap = new ymaps.Map('map', {
        center: [30, 20],
        zoom: 2,
        controls: ['smallMapDefaultSet']
    });
});
