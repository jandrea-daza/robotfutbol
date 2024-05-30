// Conexiones puente h
// motor 1_izquierdo
int IN1 = 6;  // enmascaro al pin 10 con el nombre de IN1 
int IN2 = 9;  // enmascaro al pin 9 con el nombre de IN2 

// motor 2_derecho
int IN3 = 3;  // enmascaro al pin 8 con el nombre de IN3
int IN4 = 5;  // enmascaro al pin 7 con el nombre de IN4

char command = 'S'; // creo la variable de lectura del bluetooth y la inicializo en 'S'

// Declaración de los punteros a función
typedef void (*CommandFunction)();

// Prototipos de funciones
void moveForward();
void moveBackward();
void turnRight();
void turnLeft();
void stop();
void rightWheelOnly();
void leftWheelOnly();

// Mapa de comandos a funciones
CommandFunction commandFunctions[128];

void setup() {
    Serial.begin(9600); // inicio el puerto serial para la comunicación con el bluetooth
    pinMode(IN1, OUTPUT); // configuro el pin donde conecte IN1 como salida
    pinMode(IN2, OUTPUT); // configuro el pin donde conecte IN2 como salida
    pinMode(IN3, OUTPUT); // configuro el pin donde conecte IN3 como salida
    pinMode(IN4, OUTPUT); // configuro el pin donde conecte IN4 como salida

    // Inicialización del mapa de comandos
    commandFunctions['F'] = moveForward;
    commandFunctions['B'] = moveBackward;
    commandFunctions['R'] = turnRight;
    commandFunctions['L'] = turnLeft;
    commandFunctions['S'] = stop;
    commandFunctions['I'] = rightWheelOnly;
    commandFunctions['G'] = leftWheelOnly;
}

void loop() {
    if (Serial.available() > 0) {
        command = Serial.read(); // leo el puerto serial y cargo el dato en la variable command
        if (commandFunctions[command] != NULL) { // verifico si la función para el comando existe
            commandFunctions[command](); // llamo a la función correspondiente al comando
        }
    }
}

// Definiciones de funciones de comando
void moveForward() {
    // giro motor 1 sentido antihorario
    analogWrite(IN1, 0); // envió 0V al pin donde conecte IN1
    analogWrite(IN2, 100); // envió 5V al pin donde conecte IN2
    // giro motor 2 sentido horario
    analogWrite(IN3, 0); // envió 5V al pin donde conecte IN3
    analogWrite(IN4, 157); // envió 0V al pin donde conecte IN4
}

void moveBackward() {
    // giro motor 1 sentido horario
    analogWrite(IN1, 103); // envió 5V al pin donde conecte IN1
    analogWrite(IN2, 0); // envió 0V al pin donde conecte IN2
    // giro motor 2 sentido antihorario
    analogWrite(IN3, 160); // envió 0V al pin donde conecte IN3
    analogWrite(IN4, 0); // envió 5V al pin donde conecte IN4
}

void turnRight() {
    // giro motor 1 sentido antihorario
    analogWrite(IN1, 0); // envió 0V al pin donde conecte IN1
    analogWrite(IN2, 100); // envió 5V al pin donde conecte IN2
    // giro motor 2 sentido antihorario
    analogWrite(IN3, 0); // envió 0V al pin donde conecte IN3
    analogWrite(IN4, 255); // envió 5V al pin donde conecte IN4
}

void turnLeft() {
    // giro motor 1 sentido horario
    analogWrite(IN1, 100); // envió 5V al pin donde conecte IN1
    analogWrite(IN2, 0); // envió 0V al pin donde conecte IN2
    // giro motor 2 sentido horario
    analogWrite(IN3, 255); // envió 5V al pin donde conecte IN3
    analogWrite(IN4, 0); // envió 0V al pin donde conecte IN4
}

void stop() {
    // motor 1 DETENIDO
    analogWrite(IN1, 0); // envió 0V al pin donde conecte IN1
    analogWrite(IN2, 0); // envió 0V al pin donde conecte IN2
    // motor 2 DETENIDO
    analogWrite(IN3, 0); // envió 0V al pin donde conecte IN3
    analogWrite(IN4, 0); // envió 0V al pin donde conecte IN4
}

void rightWheelOnly() {
    // giro motor 1 sentido antihorario
    analogWrite(IN1, 0); // envió 0V al pin donde conecte IN1
    analogWrite(IN2, 255); // envió 5V al pin donde conecte IN2
}

void leftWheelOnly() {
    // giro motor 2 sentido horario
    analogWrite(IN3, 255); // envió 5V al pin donde conecte IN3
    analogWrite(IN4, 0); // envió 0V al pin donde conecte IN4
    delay(100); // demora de 100 milisegundos
}
