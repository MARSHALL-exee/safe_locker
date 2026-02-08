#include <Keypad.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
    
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define RED_LED 12
#define GREEN_LED 11
#define BUZZER 10

String password = "1A77";
String input = " ";

int attempts = 0;
bool locked = false;

void checkPassword();
void wrongAlert();


void setup() {
pinMode(RED_LED, OUTPUT);
pinMode(GREEN_LED, OUTPUT);
pinMode(BUZZER, OUTPUT);

lcd.init();
lcd.backlight();

lcd.print("Enter Password");

digitalWrite(RED_LED, HIGH);
digitalWrite(GREEN_LED, LOW);
}

void loop() {
    if (locked) return;

    char key = keypad.getKey();

    if (key) {
        if (key == '*') {
            input = "";
            lcd.clear();
            lcd.print("Enter Password");
        } else {
            input += key;
            lcd.setCursor(input.length()-1,1);
            lcd.print("*");
        }

        if (input.length() == 4) {
            checkPassword();
        }
    }
}

void checkPassword() {
    lcd.clear();

    if ( input == password ) {
        lcd.print("OPEN");
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);

        tone(BUZZER, 1000);
        delay(200);
        noTone(BUZZER);

        while (1);
    } else {
        attempts++;
        lcd.print("WRONG ");
        lcd.print(attempts);

        wrongAlert();

        if (attempts >=3 ){
            lcd.clear();
            lcd.print("LOCKED");
            locked = true;
        }
    }

    input = "";
    delay(1500);
    if (!locked) {
        lcd.clear();
        lcd.print("Enter Password");
    }
}

void wrongAlert() {
    unsigned long startTime = millis();

    while (millis() - startTime < 2000) {
        tone(BUZZER,1000);
        digitalWrite(RED_LED, HIGH);
        delay(200);
        digitalWrite(RED_LED,LOW);
        delay(200);
    }

    noTone(BUZZER);
}
