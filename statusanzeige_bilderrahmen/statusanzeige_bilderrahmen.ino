#include <ESP8266WiFi.h>
#include <PubSubClient.h>


//Variabeln zum Anpassen
const char* SSID = "SSID";
const char* KEY = "KEY";
const char* MQTT_BROKER = "IP-ADRESSE";
// 8 LEDs von 0 bis 7
#define numPix    8  //Anzahl LEDS
#define gpioLed   2  //Pinbelegung


WiFiClient espClient;
PubSubClient client(espClient);
String saveColor[numPix];
boolean savePowerState;

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(MQTT_BROKER, 1883);  //PORT vom MQTT Brocker
  client.setCallback(callback);
  initLed();
  Serial.println();
}

void setup_wifi() {
  delay(10);
  Serial.print("Connecting to ");
  Serial.println(SSID);
  WiFi.begin(SSID, KEY);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void callback(char* topic, byte* payload, unsigned int length) {
  String t = topic;
  int num = t.substring(31, 32).toInt();
  char msg[length + 1];
  for (int i = 0; i < length; i++) {
    msg[i] = (char)payload[i];
  }
  msg[length] = '\0';
  String value = msg;

  //Einschaltzustand
  if (t.indexOf("powerAll") > 0) {
    if (value.equals("false")) {
      savePowerState = false;
      farbWechsel(0, 0, 0, 0);
      client.publish(topic, "false");
      Serial.println("Alle LEDs ausschalten.");
    } else if (value.equals("true")) {
      savePowerState = true;
      client.publish(topic, "true");
      Serial.println("Alle LEDs auf zustand einschalten.");
      for (int z = 0 ; z < numPix; z++) {
        colorToRgb(z, saveColor[z]);
      }
    }else{ //Setzte State bei falscher eingabe auf false
      farbWechsel(0, 0, 0, 0);
      savePowerState = false;
      client.publish(topic, "false");
    }
    return;
  }

  //Dimmer
  if (t.indexOf("dimAll") > 0) {
    if (value.toInt() > 0) {
      dimAll(value.toInt());
      Serial.println("Alle LEDs werden auf " + value + " von 255 gedimmt.\n");
      client.publish(topic, msg);
    } else {
      client.publish(topic, "20");
    }
    return;
  }

  //Farbe der jeweiligen LED
  if (t.indexOf("led") > 0) {
    Serial.println("LED: " + String(num) + " wird auf " + value + " geschaltet.");
    if (strcmp(msg, "red") == 0) {
      colorToRgb(num, "red");
      saveColor[num] = "red";
      client.publish(topic, "red");
    }
    else if (strcmp(msg, "green") == 0) {
      colorToRgb(num, "green");
      saveColor[num] = "green";
      client.publish(topic, "green");
    }
    else if (strcmp(msg, "yellow") == 0) {
      colorToRgb(num, "yellow");
      saveColor[num] = "yellow";
      client.publish(topic, "yellow");
    }
    else if (strcmp(msg, "blue") == 0) {
      colorToRgb(num, "blue");
      saveColor[num] = "blue";
      client.publish(topic, "blue");
    }
    else if (strcmp(msg, "white") == 0) {
      colorToRgb(num, "white");
      saveColor[num] = "white";
      client.publish(topic, "white");
    }
    else if (strcmp(msg, "dark") == 0) {
      colorToRgb(num, "dark");
      saveColor[num] = "dark";
      client.publish(topic, "dark");
    }
    else {
      colorToRgb(num, "dark");
      saveColor[num] = "dark";
      client.publish(topic, "dark");
    }
  }

//Damit bei powerOff keine Leds beim wechsel angehen
  if (savePowerState == false) {
    farbWechsel(0, 0, 0, 0);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Reconnecting MQTT...");
    if (!client.connect("Statusanzeige_bilderrahmen")) {
      Serial.print("failed, rc = ");
      Serial.print(client.state());
      Serial.println(" retrying in 5 seconds");
      delay(5000);
    }
  }
  createLedStatus();
  Serial.println("MQTT Connected...\n");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
