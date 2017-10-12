#define BUTTON_PIN D0
int ledPin = 5; // choose the pin for the LED
#define inPin 3   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status

String lightMode;
String thing;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inPin, INPUT);    // declare pushbutton as input
  
  RGB.control(true);
  RGB.color(0, 0, 0);

  pinMode(BUTTON_PIN, INPUT);
  Particle.subscribe("patricia_tracy_pmt15_tl177_b", cloudOn);
}

void loop(){
  val = digitalRead(inPin);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH);  // turn LED ON
  }
  
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH) {
    Particle.publish("patricia_tracy_pmt15_tl177", "rainbow"); // replace with your team's name and choose a color for your button
    delay(2000);
  }
}
void cloudOn(const char *event, const char *data){
    thing = data;
    if (thing == "cloud"){
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW); }
    else{digitalWrite(ledPin, LOW); }
}

    void blinkLight(const char *event, const char *data) {
      lightMode = data;

      if (lightMode == "rainbow") {
        turnOffLight();
      }
    }

    void turnOffLight() {
      RGB.color(0, 0, 0);
    }
