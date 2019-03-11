// Dimmer für Tag und Nachtmodus
schedule({astro: "sunriseEnd", shift: 0}, function () {
    setState("Object ID", '50');   //dimALL
});
schedule({astro: "dusk", shift: 0}, function () {
    setState("Object ID", '30');    //dimALL
});