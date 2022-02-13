#include <Keypad.h>
#include <TM1637Display.h>
#include <RCSwitch.h>

// Connection Pins
#define CLK 10
#define DIO 11

int ncheck = 1000;

//Variable Declaration Area
const int ROW_NUM = 4; //four rows
const int COLUMN_NUM = 4;
int button_check;
char key;
uint8_t fix_data[] = {0xff, 0xff, 0xff, 0xff};
String data_taken = "0000";


char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM] = {9, 8, 7, 6};
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2};

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
TM1637Display display(CLK, DIO);
RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableTransmit(12);
  set_fix_data_display();
}

void loop() {
  button_check = analogRead(A1);
  
  if (button_check > 1000) {
    mySwitch.send(ncheck, 24);
    Serial.println(ncheck);
    ncheck++;
    delay(200);
  }
  else {
    key = keypad.getKey();
    if (key) {
      if (key != 'A' && key != 'B' && key != 'C' && key != 'D' && key != '#' && key != '*') {
        for (int i = 0; i < 3; i++) {
          data_taken[i] = data_taken[i + 1];
        }
        data_taken[3] = key;
        Serial.println(data_taken);
        set_fix_data_display();
      }
      else if(key == '*'){
        mySwitch.send(data_taken.toInt() * 10000, 24);
        Serial.println(data_taken.toInt() * 10000);
      }
    }
  }
  display.setBrightness(0xff);
  display.setSegments(fix_data);

}

void set_fix_data_display() {

  for (int j = 0; j < 4; j++) {
    fix_data[j] = display_number(data_taken[j]);
  }
}

uint8_t display_number(char number) {
  uint8_t data = {SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F };
  switch (number) {
    case '1':
      data = {SEG_C | SEG_B};
      break;
    case '2':
      data = {SEG_A | SEG_B | SEG_D | SEG_E | SEG_G};
      break;
    case '3':
      data = {SEG_A | SEG_B | SEG_C | SEG_D | SEG_G};
      break;
    case '4':
      data = {SEG_F | SEG_G | SEG_B | SEG_C};
      break;
    case '5':
      data = {SEG_A | SEG_C | SEG_D | SEG_F | SEG_G};
      break;
    case '6':
      data = {SEG_A | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G};
      break;
    case '7':
      data = {SEG_A | SEG_B | SEG_C};
      break;
    case '8':
      data = {SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G};
      break;
    case '9':
      data = {SEG_A | SEG_B | SEG_C | SEG_D | SEG_F | SEG_G};
      break;
    default:
      data = {SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F};
  }
  return data;
}
