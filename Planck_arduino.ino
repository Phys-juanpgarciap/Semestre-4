

/*
este ejemplo muestra como ejecutar un fade en un led en el  pin 9 usando
la función analogWrite().

*/
int Vcc = 0; 
int Vr = 0; //tensión en el resistor
int Vd=0; //tensión en el diodo
int Vaux=0; //Vr+Vd
int sensorVccPin = A0;      //Pin de lectuura de Vcc
int sensor1Pin = A2;       //Pin de lectura de Vr+Vd
int sensor2Pin = A4;       //Pin de lectura de Vr

void setup(){
// define el pin 9 como salida;
//pinmode(led, OUTPUT);
Serial.begin(9600); 
}

// el bucle se ejecuta en secuencia continuamente;
void loop(){
Vcc = analogRead(sensorVccPin); //programa al sensor para que efectue una lectura analogica de la tensión de alimentación 
Vaux = analogRead(sensor1Pin); //programa al sensor que mide a Vaux = Vr+ Vd- la suma de la tensión del resistor + diodo 
Vr = analogRead(sensor2Pin); //programa al sensor que mide Vr la tensión en la resistencia

Vd = Vaux -Vr;




//imprime el resultado en el monitor de serie:
Serial.print(" Vr =  ");
Serial.print(Vr);
Serial.print(" , Vd =  ");
Serial.println(Vd);

//esperar 1000 milisegundos para ver el efecto de atenuación:
delay(1000);
}
