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


// Includes (Wifi, Filesystem, DHT, RTC)
//ESP8266 (NodeMCU) Wifi
#include <ESP8266WiFi.h>            
//Filesystem (SPIFFS)
#include <FS.h>                     
//I2C einbinden
#include <Wire.h>                  
//RTC einbinden (RTC=Realtime-Clock)
#include <RtcDS3231.h>
RtcDS3231<TwoWire> Rtc(Wire);                 

#define ledpin D2 //StatusLED
#define dhttyp 22
#define dhtpin D6
#define rtcscl D1
#define rtcsda D2
#define button D0

//DHT initialisieren    
DHT dht(dhtpin, dhttyp);
const dht.begin();
//RTC initialisieren
Wire.begin(rtcsda, rtcscl);
const Rtc.Begin();   

void setup() {
    Serial.begin(115200);
    Serial.println("==============");
    Serial.println("Starte Setup");
    
    //Pins initialisieren
    pinMode(ledpin, OUTPUT);
    
    //SPIFFS initialisieren
    bool fs_ok = SPIFFS.begin();
    if (fs_ok) {
    Serial.println("Filesystem geladen");
    }
    
    //RTC initialisieren
    Wire.begin(rtcsda, rtcscl);
    Rtc.Begin();
    
    //DHT initialisieren
    dht.begin();
    
    Serial.println("Setup abgeschlossen");
    Serial.println("==============");
}

void init_log(){
    Serial.println("Versuche Log zu öffnen");
    if(SPIFFS.exists("/log.csv")){
        Serial.println("Datei vorhanden");
        File f = SPIFFS.open("/log.csv", "r");
        if (!f) {
            Serial.println("Konnte Datei nicht öffnen");
        }else{
            f.close();            
        }
    }else{
        Serial.println("Datei nicht vorhanden; versuche Datei zu erstellen");
        File f = SPIFFS.open("/log.csv", "r");
        init_log();
    }           
}

int write_log(){
    float humi = dht.readHumidity();
    float temp = dht.readTemperature();
    
    if(!Rtc.isrunning()){
        Serial.println("RTC nicht aktiviert");
    }else{
        Serial.println("RTC aktiviert");
        DateTime now = rtc.now();
        Serial.println(now);
    }
    Serial.println("Schreibe Zeitstempel")
    File log = f.SPIFFS.open("/log.csv","a");
    log.println("%.2f;%.2f;%.2f;",temp,humi,now);
    Seriall.println("%.2f;%.2f;%.2f;",temp,humi,now);
    log.close(); 
}
void loop() {
  // put your main code here, to run repeatedly:

}