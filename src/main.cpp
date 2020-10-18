/*****************************************************************************/
//	Auteur:				    Guillaume Pelletier
//	Description:		  Prototype Senseur de Température
//	Date de creation:	Octobre 2020
//	But:				      Vérifier le fonctionnement d'une sonde de température
/*****************************************************************************/
#include <OneWire.h>              //Librairie pour communique avec les appareils OneWire (tel la sonde utilisée)
#include <DallasTemperature.h>    //Librairie requise pour la sonde DS18B20.
 
//Le fil d'information de la sonde est sur le port: 25
#define ONE_WIRE_BUS 25
 
//Instance communiquant avec l'appareil connecté sur le port défini plus haut
OneWire oneWire(ONE_WIRE_BUS);
 
//Envoi de la référence à la librairie du senseur
DallasTemperature sensors(&oneWire);
 
//Lancement de la librairie pour la sonde
void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
}

//Demande continuellement à toutes les secondes la température en C et F détectée par la sonde
void loop(void){ 
  sensors.requestTemperatures(); 
  Serial.print("Celsius temperature: ");
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(sensors.getTempFByIndex(0));
  delay(1000);
}