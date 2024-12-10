// Declaração dos pinos para controle dos motores
const int motor1 = D5; // Sensor 1 que contra o motor 1
const int motor2 = D7; // Sensor 2 que contra o motor 2

void setup() {
    // Inicializa a comunicação serial para monitoramento
    Serial.begin(9600);
    
    // Configura os sensores como entrada
    pinMode(motor1, INPUT); 
    pinMode(motor2, INPUT);

    // Configuração das saídas para o Motor 1
    pinMode(5, OUTPUT); // saída A- 
    pinMode(0, OUTPUT); // saída A+

    // Configuração das saídas para o Motor 2
    pinMode(4, OUTPUT); // saída B-
    pinMode(2, OUTPUT); // saída B+
}

void loop() {
    // Monitoramento dos valores lidos pelos sensores
    Serial.print("Leitura Digital Sensor 1 = ");
    Serial.print(analogRead(motor2));
    Serial.print("\t Leitura Digital Sensor 2 = ");
    Serial.println(digitalRead(motor1));

    // Controle do Motor 1
    if (digitalRead(motor2) < 1) {
        // Motor 1 girando no sentido horário
        analogWrite(4, 90);   // Define a velocidade do motor
        digitalWrite(2, HIGH); // Liga o motor no sentido horário
    } else {
        // Motor 1 girando no sentido anti-horário
        analogWrite(4, 0);     // Define a velocidade do motor como 0
        digitalWrite(2, LOW);  // Desliga o motor
    }

    // Controle do Motor 2
    if (digitalRead(motor1) < 1) {
        // Motor 2 girando no sentido horário
        analogWrite(5, 90);   // Define a velocidade do motor
        digitalWrite(0, HIGH); // Liga o motor no sentido horário
    } else {
        // Motor 2 girando no sentido anti-horário
        analogWrite(5, 0);     // Define a velocidade do motor como 0
        digitalWrite(0, LOW);  // Desliga o motor
    }
}