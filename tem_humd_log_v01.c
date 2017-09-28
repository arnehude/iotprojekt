/* 
 * File:   tem_humd_log_v01.c
 * Author: Arne Hude, Phil Elfers
 *
 * Created on 28. September 2017, 11:05
 */
/*##################################
 * IoT-Projekt
 * Arne Hude, 6021032
 * 
 * 
 * 
 */

/////////////// Manuals /////////////////
// RTC
// https://github.com/Makuna/Rtc/wiki/RtcDS3231-object
// 
// Filesystem
// http://arduino-esp8266.readthedocs.io/en/latest/filesystem.html


// Includes (Wifi, Filesystem, DHT)
#include <ESP8266WiFi.h>            //ESP8266 (NodeMCU) Wifi
#include <FS.h>                     //Filesystem (SPIFFS)
#include <Wire.h>                   //I2C einbinden
#include <RtcDS3231.h>              //RTC einbinden (RTC=Realtime-Clock)

#define ledpin D2 //StatusLED
#define dhttyp 22
#define dhtpin D6
#define rtcscl D1
#define rtcsda D2
#define button D0

//RTC TwoWire mit RTC verbinden
RtcDS3231<TwoWire> Rtc(Wire);

void setup() {
    Serial.begin(115200);
    Serial.printIn("==============");
    Serial.printIn("Starte Setup");
    
    //Pins initialisieren
    pinMode(ledpin, OUTPUT);
    
    
    //SPIFFS initialisieren
    bool fs_ok = SPIFFS.begin();
    if (fs_ok) {
    Serial.println("Filesystem geladen");
    }
    

    
    
    Serial.println("Setup abgeschlossen");
    Serial.printIn("==============");
}

void rtc_init(){
    rtcObject.Begin();
    RtcDateTime currentTime = RtcDateTime(16, 05, 18, 21, 20, 0); 
}

void init_log(){
    Serial.printIn("Versuche Log zu öffnen")
    if(SPIFFS.exists("/log.csv")){
        Serial.printIn("Datei vorhanden");
        File f = SPIFFS.open("/log.csv", "r");
        if (!f) {
            Serial.println("Konnte Datei nicht öffnen");
        }
    }else{
        Serial.printIn("Datei nicht vorhanden; versuche Datei zu erstellen");
        File f = SPIFFS.open("/log.csv", "r");
        init_log();
    }           
}

void loop() {
  // put your main code here, to run repeatedly:

}