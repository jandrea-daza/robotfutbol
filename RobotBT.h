#ifndef ROBOTBT_H
#define ROBOTBT_H

#include <Arduino.h>
#include <SoftwareSerial.h>

/// @brief Clase que representa un robot controlado a distancia mediante Bluetooth.
class RobotBT {
private:
    // Atributos
    SoftwareSerial* bluetooth; ///< Comunicación Bluetooth.
    const int motorSpeed; ///< Velocidad de los motores.
    
    const int rxPin; ///< Pin RX para la comunicación Bluetooth.
    const int txPin; ///< Pin TX para la comunicación Bluetooth.
    const int buzzerPin; ///< Pin del buzzer.
    const int motorRightPin1; ///< Pin de control 1 del motor derecho.
    const int motorRightPin2; ///< Pin de control 2 del motor derecho.
    const int motorLeftPin1; ///< Pin de control 1 del motor izquierdo.
    const int motorLeftPin2; ///< Pin de control 2 del motor izquierdo.

public:
    // Métodos
    /// @brief Constructor de la clase inicializa el BT con un Baudrate, HC05 38400, HC06 9600. Y envía "AT".
    /// @param rxPin PIN Arduino que recibe la señal del Tx del BT.
    /// @param txPin PIN Arduino que envía la señal al Rx del BT.
    /// @param buzzerPin PIN Arduino que envía la señal para el Buzzer.
    /// @param motorSpeed Velocidad de los motores.
    /// @param motorRightPin1 Pin de control 1 del motor derecho PWM.
    /// @param motorRightPin2 Pin de control 2 del motor derecho PWM.
    /// @param motorLeftPin1 Pin de control 1 del motor izquierdo PWM.
    /// @param motorLeftPin2 Pin de control 2 del motor izquierdo PWM.
    RobotBT(    int rxPin, int txPin, int buzzerPin, int motorSpeed,
                int motorRightPin1, int motorRightPin2,
                int motorLeftPin1, int motorLeftPin2, int baudRate = 9600
            );

    /// @brief Obtiene el valor de 'datos' recibido por el BT.
    char receiveData();

    /// @brief Limpia los datos de entrada del BT.
    void clearBluetooth();

    /// @brief Envía un comando AT al BT y escribe la respuesta en SERIAL
    void sendATCommand(const String &command);

    /// @brief Reproduce una nota en el buzzer.
    /// @param note Nota a reproducir (frecuencia en Hz).
    /// @param duration Duración de la nota (en milisegundos).
    void playTone(int note, int duration);

    /// @brief Mueve el robot hacia adelante.
    void moveForward();

    /// @brief Mueve el robot hacia atrás.
    void moveBackward();

    /// @brief Gira el robot hacia la izquierda.
    void turnLeft();

    /// @brief Gira el robot hacia la derecha.
    void turnRight();

    /// @brief Detiene todos los motores del robot.
    void stopMotors();

    /// @brief Gira el robot rápidamente hacia la izquierda.
    void turnLeftFast();

    /// @brief Gira el robot rápidamente hacia la derecha.
    void turnRightFast();
};

#endif
