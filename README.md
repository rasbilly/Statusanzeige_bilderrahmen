# Statusanzeige_bilderrahmen

<p align="center">
  <img src="https://raw.githubusercontent.com/rasbilly/Statusanzeige_bilderrahmen/master/images/grafik.PNG" width="30%" title="Grafik">
  <img src="https://raw.githubusercontent.com/rasbilly/Statusanzeige_bilderrahmen/master/images/20190308_224914.jpg" width="40%" alt="Proto">
</p>


<h2>Verwendete Bauteile</h2>
<table>
   <tr>
    <th>Produkt</th>
    <th>Beschreibung</th>
  </tr>
  <tr>
    <td>Bilderrahmen</td>
    <td>10x10cm (Innenfläche 7x7cm) Farbe: Stahl</td>
  </tr>
  <tr>
    <td>LEDs</td>
    <td>WS2812B 1*8Leds</td>
  </tr>
   <tr>
    <td>Microcontroller</td>
    <td>ESP8266-01</td>
  </tr>
   <tr>
    <td>Adapter</td>
    <td>Adapter Controller WS2812 Module (ESP–01)</td>
  </tr>
  <tr>
    <td>oder</td>
    <td>Wemos Mini D1</td>
  </tr>
</table>

<br>
<h3>Word Vorlage</h3>
<a href="https://github.com/rasbilly/Statusanzeige_bilderrahmen/blob/master/Bilderrahmen_Statusleiste_LED%20-%20DruckVorlage.docx">Druckvorlage
</a>

<h3>Arduino Libraries</h3>
<ul>
   <li>https://github.com/esp8266/Arduino</li>
   <li>https://github.com/knolleary/pubsubclient  (Version 2.0.6)</li>
</ul>



<br>
<h2>Integration in ioBroker</h2>
Voraussetzung
<ul>
  <li>MQTT Broker/Client</li>
  <li> --> Typ: Server/Broker</li>
  <li>JavaScript Adapter</li>
</ul>
  
<p>Datenpunkte werden Automatisch bei erster Verbindung angelegt. (ggf. MQTT Adapter Neustarten)</p>
<img src="https://raw.githubusercontent.com/rasbilly/Statusanzeige_bilderrahmen/master/images/iobokerDP.PNG" width="90%" title="iobrokerDP">


<h3>Befehle</h3>
<ul>
  <li>led X: red, green, yellow, blue, white, dark</li>
  <li>dimAll: Wert zwischen 1 und 255</li>
  <li>powerAll: Schaltet alle Leds ein und aus (true, false)</li>
</ul>

<h3>Javascript</h3>
<p>Die Scripte müssen per Hand in den JavaScript (Script Engine) Adapter Importiert werden. </p>
<br>
<p>Folgene Scripte sind im Ordner Bilderrahmen enthalten:</p>
<p>(Nur die gewünschten Aktivieren)</p>
<ul>
  <li>triggerLed: Erkennt den Status von den gewählten Objekten und sendet diesen.</li>
  <li>dimmer: Schaltet die Helligkeit nach gewählter Zeit heller und dunkler.</li> 
  <li>bwmPower: Bei Bewegung wird der powerAll Status auf true gesetzt. Nach X Sekunden wieder auf false. Setzt Bewegungsmelder oder Anwesendheitserkennung voraus.</li>
</ul>
<img src="https://raw.githubusercontent.com/rasbilly/Statusanzeige_bilderrahmen/master/images/js_uebersicht.PNG" width="40%" title="javaScript_Übersicht">

<p>Trigger für die LEDs</p>

```ruby
//Generic
on({id: 'Object ID', change: "ne"}, function (obj) {
   setState("MQTT LED", (getState("Object ID").val ? 'Farbe bei ture' : 'Farbe bei false'));
});
```
<br>
<h2>Weitere Bilder und Videos im images Ordner</h2>
<p align="center">
<img src="https://raw.githubusercontent.com/rasbilly/Statusanzeige_bilderrahmen/master/images/20190311_192838.jpg" width="70%" alt="NahaufnahmeFarben">
</p>




