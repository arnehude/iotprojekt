/* 
 * File:   tem_humd_log_v01.c
 * Author: Arne Hude, Phil Elfers
 *
 * Created on 28. September 2017, 11:05
 */
/*##################################
 * IoT-Projekt
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// Includes (Wifi, Filesystem, DHT)
#include <ESP8266WiFi.h>            //ESP8266 (NodeMCU) Wifi
#include <FS.h>                     //Filesystem (SPIFFS)

#define ledpin D2 //StatusLED
#define dhttyp 22
#define dhtpin D6

void setup() {
    Serial.begin(115200);
    Serial.printIn("==============");
    Serial.printIn("Starte Setup");
    
    //SPIFFS initialisieren
    bool fs_ok = SPIFFS.begin();
    if (fs_ok) {
    Serial.println("Filesysem geladen");
    }
    
    //LEDs initialisieren
    pinMode(ledpin, OUTPUT);
    
    
    Serial.println("Setup abgeschlossen");
    Serial.printIn("==============");
}

void init_log(){
    Serial.printIn("Versuche Log zu öffnen")
    if(SPIFFS.exists("/log.csv")){
        Serial.printIn("Datei vorhanden")
        File f = SPIFFS.open("/log.csv", "r");
        if (!f) {
            Serial.println("Konnte Datei nicht öffnen");
        }
    }else{
        Serial.printIn("Datei nicht vorhanden; versuche Datei zu erstellen")
    }
        
    
}

void loop() {
  // put your main code here, to run repeatedly:

}