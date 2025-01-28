#include <Wire.h>
#include <DHT.h>

#define DHTPIN 4       // Pin where DHT sensor is connected
#define DHTTYPE DHT22  // DHT11 or DHT22 sensor
#define MOTOR1_PIN 12  // Motor 1 (fan 1)
#define MOTOR2_PIN 13  // Motor 2

DHT dht(DHTPIN, DHTTYPE);  // Initialize the DHT sensor

void setup() {
  Serial.begin(9600);
  
  pinMode(MOTOR1_PIN, OUTPUT); // Set Motor 1 as output
  pinMode(MOTOR2_PIN, OUTPUT); // Set Motor 2 as output
  
  dht.begin();  // Initialize DHT sensor
}

void loop() {
  // Read humidity and temperature from the DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();  // Temperature in Celsius

  // Check if the sensor is reading correctly
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Output the temperature and humidity to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Control the motors based on temperature conditions
  if (temperature < 20) {
    digitalWrite(MOTOR1_PIN, HIGH);  // Turn on fan1 (Motor 1)
    digitalWrite(MOTOR2_PIN, LOW);   // Turn off motor2 (fan2)
    Serial.println("Motor 1 ON (fan1 running)");
  } else if (temperature > 28) {
    digitalWrite(MOTOR1_PIN, LOW);   // Turn off fan1 (Motor 1)
    digitalWrite(MOTOR2_PIN, HIGH);  // Turn on motor2 (fan2)
    Serial.println("Motor 2 ON (fan2 running)");
  } else {
    digitalWrite(MOTOR1_PIN, LOW);   // Turn off fan1 (Motor 1)
    digitalWrite(MOTOR2_PIN, LOW);   // Turn off motor2 (fan2)
    Serial.println("Both motors OFF");
  }

  delay(2000);  // Wait for 2 seconds before the next reading
}