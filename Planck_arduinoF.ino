

/*
El Atmega328 AVR 8 bits es un circuito integrado de alto rendimiento que está basado un microcontrolador 
RISC,combinando 32 KB (ISP) flash una memoria con la capacidad de leer-mientras-escribe.El arudino alimentará el circuito y medirá datos 

*/
int Vcc = 0; //
int Vr = 0; //tensión de la resistencia entre los terminales del diodo
int Vd=0; //tensión en el diodo
int Vaux=0; //varialbe auxiliar Vr+Vd
int sensorVccPin = A0;      //Pin de lectuura del potencial electrico de alimentación Vcc
int sensor1Pin = A2;       //Pin de lectura de Vr+Vd
int sensor2Pin = A4;       //Pin de lectura de Vr

// La linea de codigo siguiente hará un enlace de comunicación en serie  que controlará el orden en el que se leen los valores de tensión y se alimenta el monitor. Luego 
// permitirá presentar y recolectar los datos de medida de la tensión en la resistencia y el diodo
void setup(){ 
// define el pin 9 como salida;
//pinmode(led, OUTPUT);
Serial.begin(9600); 
}

// el bucle se ejecuta en secuencia continuamente a lo largo del tiempo
void loop(){
Vcc = analogRead(sensorVccPin); //programa al sensor para que efectue una lectura analogica de la tensión de alimentación 
Vaux = analogRead(sensor1Pin); //programa al sensor para que  mida un potencial encima del diodo 
Vr = analogRead(sensor2Pin); //programa al sensor que mida Vr la tensión encima del resistor

Vd = Vaux -Vr; // Esa diferencia entre Vaux y Vr nos otorgorá la tensión medida entre los dos polos del diodo




//imprime el resultado en el monitor de serie:
Serial.print(Vr);
Serial.print(";");
Serial.println(Vd);

//Delay de 1000 milisegundos (1 seg ) para evitar el efecto de atenuación:
delay(1000);
}
