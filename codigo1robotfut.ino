// Conexiones puente h
//motor 1_izquierdo
int IN1=10; // enmascaro al pin 10 con el nombre de IN1 
int IN2=9; // enmascaro al pin 9 con el nombre de IN2 

//motor 2_derecho
int IN3=8; // enmascaro al pin 8 con el nombre de IN3
int IN4=7; // enmascaro al pin 7 con el nombre de IN4

char command = 'S';      // creo la variable de lectura del bluetooth y la inicializo en 'S'

void setup()  
{
  Serial.begin(9600); // inicio el puerto serial para la comunicación con el bluetooth
  pinMode(IN1, OUTPUT); // configuro el pin donde conecte IN1 como salida
  pinMode(IN2, OUTPUT); // configuro el pin donde conecte IN2 como salida
  pinMode(IN3, OUTPUT); // configuro el pin donde conecte IN3 como salida
  pinMode(IN4, OUTPUT); // configuro el pin donde conecte IN4 como salida
}

void loop(){
  
if (Serial.available()>0) {         // leo el puerto serial

command=Serial.read(); // si hay un dato lo cargo en la variable commanddato

if (command== 'F') // si recibo 'F' voy hacia adelante
{
//giro motor 1 sentido anti horario
digitalWrite(IN1,LOW); //envió 0V al pin donde conecte IN1
digitalWrite(IN2,HIGH); //envió 5V al pin donde conecte IN2
//giro motor 2 sentido horario
digitalWrite(IN3,HIGH); //envió 5V al pin donde conecte IN3
digitalWrite(IN4,LOW); //envió 0V al pin donde conecte IN4

}

if (command== 'B') // si recibo 'B' voy hacia atras
{
//giro motor 1 sentido horario
digitalWrite(IN1,HIGH); //envió 5V al pin donde conecte IN1
digitalWrite(IN2,LOW); //envió 0V al pin donde conecte IN2
//giro motor 2 sentido antihorario
digitalWrite(IN3,LOW); //envió 0V al pin donde conecte IN3
digitalWrite(IN4,HIGH); //envió 5V al pin donde conecte IN4

}

if (command== 'R') // si recibo 'R' voy a la derecha con ambas ruedas
{
//giro motor 1 sentido anti horario
digitalWrite(IN1,LOW); //envió 0V al pin donde conecte IN1
digitalWrite(IN2,HIGH); //envió 5V al pin donde conecte IN2
//giro motor 2 sentido antihorario
digitalWrite(IN3,LOW); //envió 0V al pin donde conecte IN3
digitalWrite(IN4,HIGH); //envió 5V al pin donde conecte IN4
}

if (command== 'L') // si recibo 'L' voy a la izquierda con ambas ruedas
{
//giro motor 1 sentido horario
digitalWrite(IN1,HIGH); //envió 5V al pin donde conecte IN1
digitalWrite(IN2,LOW); //envió 0V al pin donde conecte IN2
//giro motor 2 sentido horario
digitalWrite(IN3,HIGH); //envió 5V al pin donde conecte IN3
digitalWrite(IN4,LOW); //envió 0V al pin donde conecte IN4
}

if (command== 'S') // si recibo 'S' me detengo
{
//motor 1 DETENIDO
digitalWrite(IN1,LOW); //envió 0V al pin donde conecte IN1
digitalWrite(IN2,LOW); //envió 0V al pin donde conecte IN2
//motor 2 DETENIDO
digitalWrite(IN3,LOW); //envió 0V al pin donde conecte IN3
digitalWrite(IN4,LOW); //envío 0V al pin donde conecte IN4
}

if (command== 'I') // si recibo 'I' voy a la derecha con una rueda
{
//giro motor 1 sentido anti horario
digitalWrite(IN1,LOW); //envió 0V al pin donde conecte IN1
digitalWrite(IN2,HIGH); //envió 5V al pin donde conecte IN2
}

if (command== 'G') // si recibo 'G' voy a la izquierda con una rueda
{
//giro motor 2 sentido horario
digitalWrite(IN3,HIGH); //envió 5V al pin donde conecte IN3
digitalWrite(IN4,LOW); //envió 0V al pin donde conecte IN4
delay(100);// demora de 100 milisegundos
}

}
 
}