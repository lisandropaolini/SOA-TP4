// Definición de los pines
const int SENSOR_PIN = A0; // Pin de entrada para el sensor de temperatura
const int LED_PIN = 13;    // Pin de salida para el LED (LED_BUILTIN)

// Umbral de temperatura para encender el LED (en grados Celsius)
const float UMBRAL_TEMPERATURA = 25.0;

void setup() {
  // 1. Definir el pin 13 como salida.
  pinMode(LED_PIN, OUTPUT);

  // 2. Abrir puerto serial en 9600 bps.
  Serial.begin(9600);

  // 3. Activar la salida digital 13 para indicar que el programa ha iniciado.
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  // 4. Leer la entrada del sensor.
  int valorSensor = analogRead(SENSOR_PIN);

  // Hacer las conversiones necesarias para obtener la temperatura en Celsius.
  // El voltaje de referencia es 5V y el ADC tiene 1024 niveles (0-1023).
  float voltaje = valorSensor * (5.0 / 1023.0);
  
  // Convertir el voltaje a temperatura en grados Celsius (fórmula para TMP36).
  float temperaturaC = (voltaje - 0.5) * 100;

  // 5. Definir el encendido/apagado del led según los requisitos.
  // En este caso, el LED del pin 13 se apagará si la temperatura
  // supera el umbral definido.
  if (temperaturaC > UMBRAL_TEMPERATURA) {
    digitalWrite(LED_PIN, LOW); // Apaga el LED si la temperatura es alta
  } else {
    digitalWrite(LED_PIN, HIGH); // Mantiene el LED encendido si es baja
  }

  // 6. Mostrar en la salida serial el valor leído en grados Celsius.
  Serial.print("Temperatura: ");
  Serial.print(temperaturaC);
  Serial.println(" C");

  // Esperar un segundo antes de la siguiente lectura.
  delay(1000);
}