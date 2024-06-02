#include "RobotBT.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

// Constructor de la clase inicializa el BT con un Baudrate, HC05 38400, HC06 9600. Y envía "AT".
RobotBT::RobotBT(int rx, int tx, int buzzer, int speed,
                 int motorRight1, int motorRight2, 
                 int motorLeft1, int motorLeft2, int baudRate = 9600)
    : rxPin(rx), txPin(tx), buzzerPin(buzzer), motorSpeed(speed),
      motorRightPin1(motorRight1), motorRightPin2(motorRight2),
      motorLeftPin1(motorLeft1), motorLeftPin2(motorLeft2)
{
    bluetooth = new SoftwareSerial(rx, tx);
    bluetooth->begin(baudRate);
    delay(100);
    sendATCommand("AT");

    pinMode(motorRight1, OUTPUT);
    pinMode(motorRight2, OUTPUT);
    pinMode(motorLeft1, OUTPUT);
    pinMode(motorLeft2, OUTPUT);
    pinMode(buzzer, OUTPUT);

    analogWrite(motorRight1, 0);
    analogWrite(motorRight2, 0);
    analogWrite(motorLeft1, 0);
    analogWrite(motorLeft2, 0);
}

// Reproduce una nota en el buzzer.
void RobotBT::playTone(int note, int duration) {
    tone(buzzerPin, note, duration);
    delay(duration * 1.30);
    noTone(buzzerPin);
}

// Obtiene el valor de 'datos' recibido por el BT.
char RobotBT::receiveData() {
    if (bluetooth->available()) {
        return (char)bluetooth->read();  // Devolver el dato leído
    }
    return '\0';  // Devolver null character si no hay datos disponibles
}

// Envía un comando AT al BT y escribe la respuesta en SERIAL
void RobotBT::sendATCommand(const String &command) {
    bluetooth->println(command);
    delay(100);  // Esperar respuesta

    while (bluetooth->available()) {
        char c = bluetooth->read();
        Serial.write(c);  // Mostrar respuesta en el monitor serie
    }
}

// Limpia los datos de entrada del BT.
void RobotBT::clearBluetooth() {
    while (bluetooth->available()) {
        char c = bluetooth->read();
        Serial.write(c);  // Mostrar respuesta en el monitor serie
    }
}

// Mueve el robot hacia adelante.
void RobotBT::moveForward() {
    analogWrite(motorRightPin1, motorSpeed);
    analogWrite(motorRightPin2, 0);
    analogWrite(motorLeftPin1, motorSpeed);
    analogWrite(motorLeftPin2, 0);
}

// Mueve el robot hacia atrás.
void RobotBT::moveBackward() {
    analogWrite(motorRightPin1, 0);
    analogWrite(motorRightPin2, motorSpeed);
    analogWrite(motorLeftPin1, 0);
    analogWrite(motorLeftPin2, motorSpeed);
}

// Gira el robot hacia la izquierda.
void RobotBT::turnLeft() {
    analogWrite(motorRightPin1, motorSpeed);
    analogWrite(motorRightPin2, 0);
    analogWrite(motorLeftPin1, 0);
    analogWrite(motorLeftPin2, 0);
}

// Gira el robot hacia la derecha.
void RobotBT::turnRight() {
    analogWrite(motorRightPin1, 0);
    analogWrite(motorRightPin2, 0);
    analogWrite(motorLeftPin1, motorSpeed);
    analogWrite(motorLeftPin2, 0);
}

// Detiene todos los motores del robot.
void RobotBT::stopMotors() {
    analogWrite(motorRightPin1, 0);
    analogWrite(motorRightPin2, 0);
    analogWrite(motorLeftPin1, 0);
    analogWrite(motorLeftPin2, 0);
}

// Gira el robot rápidamente hacia la derecha.
void RobotBT::turnRightFast() {
    analogWrite(motorRightPin1, 0);
    analogWrite(motorRightPin2, motorSpeed);
    analogWrite(motorLeftPin1, motorSpeed);
    analogWrite(motorLeftPin2, 0);
}

// Gira el robot rápidamente hacia la izquierda.
void RobotBT::turnLeftFast() {
    analogWrite(motorRightPin1, motorSpeed);
    analogWrite(motorRightPin2, 0);
    analogWrite(motorLeftPin1, 0);
    analogWrite(motorLeftPin2, motorSpeed);
}
