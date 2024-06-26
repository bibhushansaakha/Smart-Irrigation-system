// Smart Irrigation System using Arduino 
// Based on Temperature, Soil Moisture, Humidity & Rain

#include <Adafruit_LiquidCrystal.h>

// initializing LCD object
Adafruit_LiquidCrystal lcd(0);

// defining pins for different inputs & outputs
const int moistureIN = A1;
const int tempIN = A2;
const int humidityIN = A3;
const int rainIN = 2;
const int pumpOUT = 4;
const int buzzerOUT = 8;
const int greenLED = 12;
const int redLED = 13;

// initializing variables for holding values
int moisture = 0;
int temp = 0;
int humidity = 0;
int rain = 0;    // zero showing no rain
float voltage = 0;
float tempInCelsius = 0;
float humidityInPercentage = 0;

const int moistureUpperBound = 800;    // denoting optimum soil moisture
const int moistureLowerBound = 200;    // denoting less soil moisture
const int tempUpperBound = 30;         // denoting very hot day, hence more soil dry out
const int humidityUpperBound = 70;     // denoting high humidity, so less soil moisture loss
const int humidityLowerBound = 20;     // denoting low humidity, so high soil moisture loss

void setup() {
    // starting the LCD screen 
    lcd.begin(16, 2);

    // start up msg on LCD
    lcd.print("Smart Irrigation");
    lcd.setCursor(0, 1);
    lcd.print("System-vNote");
    delay(1000);
    lcd.clear();

    // defining pin modes
    pinMode(moistureIN, INPUT);
    pinMode(tempIN, INPUT);
    pinMode(humidityIN, INPUT);
    pinMode(rainIN, INPUT);
    pinMode(pumpOUT, OUTPUT);
    pinMode(buzzerOUT, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(redLED, OUTPUT);

    Serial.begin(9600);
    delay(500);    // delay to let the system boot
}

void loop() {
    // reading values
    moisture = analogRead(moistureIN);    // reading moisture value from sensor as analog value
    humidity = analogRead(humidityIN);    // reading moisture value from sensor as analog value
    rain = digitalRead(rainIN);           // reading rain value from switch as digital value
    temp = analogRead(tempIN);            // reading temperature value from sensor as analog value

    // convert temperature into Celsius value
    voltage = temp * (5.0 / 1023.0);      // brings value between 0-5V
    tempInCelsius = (voltage - 0.5) * 100;// convert the voltage to Celsius

    // convert humidity (potentiometer) value to percentage
    humidityInPercentage = map(humidity, 0, 1023, 0, 100);  // changing potentiometer scale from 0-1023 to 0-100

    // printing values to the console
    Serial.print("Temperature: ");
    Serial.print(tempInCelsius);
    Serial.println(" C");
    Serial.print("Moisture: ");
    Serial.println(moisture);
    Serial.print("Humidity: ");
    Serial.print(humidityInPercentage);
    Serial.println(" %");
    if (rain == 0) {
        Serial.println("Not Raining");
    } else {
        Serial.println("Its Raining");
    }
    Serial.println();

    // printing values on the screen
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(tempInCelsius);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Moisture: ");
    lcd.print(moisture);

    delay(3000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(humidityInPercentage);
    lcd.print("%");

    delay(3000);
    lcd.clear();

    // handling core logic
    // when its raining, there is no need for watering
    if (rain == 1) {
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        digitalWrite(buzzerOUT, LOW);
        digitalWrite(pumpOUT, LOW);
        lcd.print("Water Pump OFF");
        delay(2000);
        lcd.clear();
        lcd.print("Its Raining");
    } 
    // when moisture is lesser than minimum value, then water
    else if (moisture < moistureLowerBound) {
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
        digitalWrite(buzzerOUT, HIGH);
        digitalWrite(pumpOUT, HIGH);
        lcd.print("Water Pump ON");
    } 
    // when moisture is greater than minimum value but lesser than maximum value
    // and temperature is higher than maximum acceptable value, then water
    else if (moisture < moistureUpperBound && tempInCelsius > tempUpperBound) {
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
        digitalWrite(buzzerOUT, HIGH);
        digitalWrite(pumpOUT, HIGH);
        lcd.print("Water Pump ON");
    } 
    // when moisture is greater than minimum value but lesser than maximum value
    // and humidity is lower than minimum acceptable value, then water
    else if (moisture < moistureUpperBound && humidityInPercentage < humidityLowerBound) {
        digitalWrite(greenLED, LOW);
        digitalWrite(redLED, HIGH);
        digitalWrite(buzzerOUT, HIGH);
        digitalWrite(pumpOUT, HIGH);
        lcd.print("Water Pump ON");
    } else {
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        digitalWrite(buzzerOUT, LOW);
        digitalWrite(pumpOUT, LOW);
        lcd.print("Water Pump OFF");
    }

    delay(3000);
    lcd.clear();
}