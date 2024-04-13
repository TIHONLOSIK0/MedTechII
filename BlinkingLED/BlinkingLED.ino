#define LED_PIN_1 52
#define LED_PIN_2 50
#define LED_PIN_3 48
#define LED_PIN_4 46
#define LED_PIN_5 44
#define LED_PIN_6 42
#define INPUT_PIN 22


void setup() {
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  pinMode(INPUT_PIN, INPUT_PULLUP);
}

void loop() {
  int buttonVal = digitalRead(INPUT_PIN);
  // put your main code here, to run repeatedly:
  if (buttonVal == HIGH) {
    digitalWrite(LED_PIN_1, LOW);
  } else {
    digitalWrite(LED_PIN_1, HIGH);
  }

  
}
