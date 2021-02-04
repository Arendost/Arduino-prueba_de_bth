#include <SoftwareSerial.h>
 
 //Práctica encender un LED con Bluetooth HC-05
int ledPin = 9; // usamos un pin de salida al LED
int state = 0; // Variable lectrura serial
 SoftwareSerial mySerial(10, 11); // RX, TX
void setup() {
    pinMode(ledPin, OUTPUT);   //Declara pin de Salida
    digitalWrite(ledPin, LOW); //Normalmente Apagado
    mySerial.begin(9600);
}
 
void loop() {
 //si el modulo a manda dato, guardarlo en estado.
  if(mySerial.available() > 0){
       state = mySerial.read();
  } // esta parte del código es para solo 1 Carácter o Unidad. 
 
 // si el estado es 0 ese sería Apagado “OFF”
 if (state == '0') {
    digitalWrite(ledPin, LOW);
    mySerial.println("LED: off");
 }
 
 // de lo contrario si el estado es 1 ese sería Encendido “ON”
 else
 if (state == '1') {
     digitalWrite(ledPin, HIGH);
     mySerial.println("LED: on");
 }
}
