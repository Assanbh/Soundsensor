/*
  Titre      : Titre du programme
  Auteur     : Assane Seck
  Date       : 28/11/2021
  Description: Une description du programme
  Version    : 0.0.1
*/



#include <iostream>
#include <Arduino.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"


int sensorPin = A1;
int ledrouge = 3.3; 



void setup() {

 Serial.begin(9600); 

 wifiConnect();                  //Branchement au réseau WIFI 
 MQTTConnect();
 pinMode(sensorPin,INPUT);
 pinMode(ledrouge,OUTPUT);

}

void loop() {
  Serial.println(analogRead(sensorPin));
  int val=digitalRead(sensorPin);
   if(val==HIGH){
    digitalWrite(ledrouge,HIGH);
   }
  else{
  
     digitalWrite(ledrouge,LOW);
 }

 appendPayload( "decibels",(analogRead(sensorPin)) );  //Ajout de la donnée température au message MQTT
 sendPayload();                                   //Envoie du message via le protocole MQTT

 delay(1000);

 }