/*
//Generic
on({id: 'Object ID', change: "ne"}, function (obj) {
   setState("MQTT LED", (getState("Object ID").val ? 'Farbe bei ture' : 'Farbe bei false'));
});

// Muster Beispiel
on({id: 'sonoff.0.Bett_14DDBF.POWER', change: "ne"}, function (obj) {
   setState("mqtt.0.statusanzeige_bilderrahmen.led0", (getState("sonoff.0.Bett_14DDBF.POWER").val ? 'green' : 'red'));
});
*/


//LED0
on({id: 'Object ID', change: "ne"}, function (obj) {
    setState("mqtt.0.statusanzeige_bilderrahmen.led0", (getState("Object ID").val ? 'green' : 'red'));
});

//LED1
on({id: 'Object ID', change: "ne"}, function (obj) {
    setState("mqtt.0.statusanzeige_bilderrahmen.led1", (getState("Object ID").val ? 'green' : 'red'));
});

//LED2
on({id: 'Object ID', change: "ne"}, function (obj) {
    setState("mqtt.0.statusanzeige_bilderrahmen.led2", (getState("Object ID").val ? 'green' : 'red'));
});

//LED3
on({id: 'Object ID', change: "ne"}, function (obj) {
    setState("mqtt.0.statusanzeige_bilderrahmen.led3", (getState("Object ID").val ? 'green' : 'red'));
});

//LED4
on({id: 'Object ID', change: "ne"}, function (obj) {
    setState("mqtt.0.statusanzeige_bilderrahmen.led4", (getState("Object ID").val ? 'green' : 'red'));
});

//LED5
on({id: 'Object ID', change: "ne"}, function (obj) {
    setState("mqtt.0.statusanzeige_bilderrahmen.led5", (getState("Object ID").val ? 'green' : 'red'));
});

//LED6
on({id: 'Object ID', change: "ne"}, function (obj) {
    setState("mqtt.0.statusanzeige_bilderrahmen.led6", (getState("Object ID").val ? 'green' : 'red'));
});

//LED7
on({id: 'Object ID', change: "ne"}, function (obj) {
    setState("mqtt.0.statusanzeige_bilderrahmen.led7", (getState("Object ID").val ? 'green' : 'red'));
});
