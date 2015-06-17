var myMap;

ymaps.ready(function () {
    myMap = new ymaps.Map('map', {
        center: [30, 20],
        zoom: 2,
        controls: []
    });
    myMap.container.fitToContainer(true);
});
