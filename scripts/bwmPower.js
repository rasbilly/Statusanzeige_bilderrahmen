on({id: 'default', change: "ne"}, function (obj) {
  if (getState("ID auswählen").val == true) {
    setState("mqtt.0.statusanzeige_bilderrahmen.powerAll", 'true');
    setStateDelayed("mqtt.0.statusanzeige_bilderrahmen.powerAll", 'false', 300000, false);  //300000 = 5min
  }
});