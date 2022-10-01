#include <Keypad.h>  
int i=0;
bool checked = false;
const byte lines = 4, password_length = 2;  
const byte columns = 4;  
const byte pin_led = A0,pin_led_green = 12;
const char matriz_keys[lines][columns] = {  
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

const byte lines_pines[lines] = { 11, 10, 7, 6 };  
const byte pin_columns[columns] = { 5, 4, 3, 2 };  
char password[password_length] = {};

Keypad keyboard = Keypad(makeKeymap(matriz_keys), lines_pines, pin_columns, lines, columns); 

void setup() {
  Serial.begin(9600); 
  pinMode(pin_led, OUTPUT);
  pinMode(pin_led_green ,OUTPUT);
  //digitalWrite(pin_led, LOW);
}

void loop() {


  char read_key = keyboard.getKey();  


  if (read_key) { 
    if (!checked) {
     
      Serial.print("OI") ;
      password[i] = read_key;
        Serial.print(String(password[i]));
      i++;
      checked = String(password[0]) == "9" && String(password[1]) == "2";
       if (i == password_length && !checked || i > password_length) {
   Serial.print("ERROU") ;        
          digitalWrite(pin_led_green, HIGH);
          delay(2000);
           digitalWrite(pin_led_green, LOW);          
        delay(5000);   
        checked = false;
        password[password_length] = {};  
        i = 0;
          Serial.print("END"); 
      }
     
    } 
    
        
    //
    
    
  }


  if (checked) {
    //Serial.print("OIffff") ;
       digitalWrite(pin_led, HIGH);
       delay(10000);
       digitalWrite(pin_led, LOW);
       checked = false;
       password[password_length] = {};  
       i = 0;
       Serial.print("Ten seconds") ;
       
  }
}
