
#define LED_PIN_1 52
#define LED_PIN_2 50
#define LED_PIN_3 48
#define LED_PIN_4 46
#define LED_PIN_5 44
#define LED_PIN_6 42
#define INPUT_PIN 40



void setup() {

  // Seed generation for random()
  randomSeed(analogRead(0));

  // Pin setup
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  pinMode(INPUT_PIN, INPUT_PULLUP);
}

void loop() {

  if (ButtonPressedOnce(INPUT_PIN)) {
    RollDice(LED_PIN_1, LED_PIN_2, LED_PIN_3, LED_PIN_4, LED_PIN_5, LED_PIN_6);
  } 
  
}

// Function that rolls the dice!!

void RollDice(int led_pin_1, int led_pin_2, int led_pin_3, int led_pin_4, int led_pin_5, int led_pin_6){
  
  // Make LED Array for ease of use
  int led_pin_array[6] = {led_pin_1, led_pin_2, led_pin_3, led_pin_4, led_pin_5, led_pin_6};
  
  // Turn off all LEDs
  for (int i = 0; i < 6; i++)
    digitalWrite(led_pin_array[i], LOW);

  // Randomly choose and turn on one LED
  int led_to_light = random(0,6);
  digitalWrite(led_pin_array[led_to_light], HIGH);

}


// Function that checks the press of a button with debounce correctuion.
// Only looks for the change from unpressed to pressed and produces
// a pulse of bool True independant of press time.

long int debounceTime = 200;
long int timeSinceLastPress = 0;
int lastState = HIGH;

bool ButtonPressedOnce(int inputPin) {
  int currentState = digitalRead(inputPin);
  if (millis() - timeSinceLastPress > debounceTime) {
    if (currentState != lastState && currentState == LOW) {
      timeSinceLastPress = millis();
      return true;
    }
  }
  lastState = currentState; 
  return false;
}

