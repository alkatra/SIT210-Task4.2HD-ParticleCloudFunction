
int returnValue(String args);
int red = D4;
int yellow = D5;
int green = D6;
bool flash = false;
bool cycle = false;


void setup() {
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);
    Particle.function("returnValue", returnValue);

}

int returnValue(String args) {
    Particle.publish("Value", args);
    flash = false;
    cycle = false;
    if(args=="red") {
        redLight();
    }
    else if(args=="yellow") {
        yellowLight();
    } else if(args=="green") {
        greenLight();
    } else if(args=="maintenance") {
        resetLights();
        flash = true;
    } else if(args=="off") {
        resetLights();
    } else if(args=="cycle") {
        resetLights();
        cycle = true;
    } else {
        return 0;
    }
    return 1;
}

void redLight() {
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
}

void yellowLight() {
    digitalWrite(red, LOW);
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
}

void greenLight() {
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, HIGH);
}

void resetLights() {
    digitalWrite(green, LOW);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
}

void loop() {
    while(flash){
        delay(500);
        digitalWrite(yellow, HIGH);
        delay(500);
        digitalWrite(yellow, LOW);
    }
    
    while(cycle) {
        digitalWrite(green, HIGH);
        delay(3000);
        digitalWrite(green, LOW);
        digitalWrite(yellow, HIGH);
        delay(2000);
        digitalWrite(yellow, LOW);
        digitalWrite(red, HIGH);
        delay(3000);
        digitalWrite(red, LOW);
        
    }
}
