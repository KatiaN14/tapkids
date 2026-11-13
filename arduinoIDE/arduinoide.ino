//CONEXION AL EXTERIOR del Blackboard:

// REGION: Librerias
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>

//REGION: Configuración wireless
const char* ssid="AAAAAAAAAA";
const char* password = "jfu84Dj2";
const char* namehost="NODE1";

//REGION: Conectividad
WiFiClient espClient;
void setup() {
/* Enviamos mensajes via puerto serie */
initSerial();
/* Conectamos el nodeMCU a la red Wifi */
initWifi();
}
void initSerial()
{
Serial.begin(115200);
Serial.setTimeout(5000);
// Inicialización del puerto serie
while(!Serial) { }
//Mensaje de bienvenida
Serial.println("Booting ...... \n");
Serial.println("\tDispositivo en marcha");
}
void initWifi()
{
Serial.println();
Serial.print("Wifi conectando a: ");
Serial.println( ssid );
WiFi.hostname(namehost);
WiFi.begin(ssid,password);
while( WiFi.status() != WL_CONNECTED ){
delay(500);
Serial.print(".");
}
Serial.println("Wifi conectada!");
Serial.print("NodeMCU IP Address : ");
Serial.println(WiFi.localIP() );
}