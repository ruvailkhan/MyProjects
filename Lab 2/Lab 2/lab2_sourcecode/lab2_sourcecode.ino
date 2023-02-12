#define BUZZER_PIN WIO_BUZZER 

//function prototypes (arduino make them automatically in most casses)
int seriesB(int);
int seriesA(int);
void blinking(int);
void buzzer();


void setup() {
  int ButtonA_press_count=0;
  int ButtonB_press_count=0;

  Serial.begin(115200);
  pinMode(WIO_KEY_A, INPUT_PULLUP);
  pinMode(WIO_KEY_B, INPUT_PULLUP);
  pinMode(WIO_KEY_C, INPUT_PULLUP);
  pinMode(WIO_BUZZER, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
   if (digitalRead(WIO_KEY_A) == LOW) {
    buzzer();
    ButtonA_press_count++;
    blinking(seriesA(ButtonA_press_count));
   }
   
   else if (digitalRead(WIO_KEY_B) == LOW) {
     buzzer();
     ButtonB_press_count++;
     blinking(seriesB(ButtonB_press_count));
   }
   
   else if (digitalRead(WIO_KEY_C) == LOW) {
    buzzer();
    //resetting both counts
    ButtonA_press_count=0;
    ButtonB_press_count=0;
   }
   //to give time so one press doesnt registered as multiple presses.
   delay(200);
}


void buzzer()
{
  //beep for 1/10th of a second
  analogWrite(WIO_BUZZER, 128);
  delay(100);
  analogWrite(WIO_BUZZER, 0);
  delay(100); 
}

void blinking(int times)
{
  //blink in a second
  for (int i=0;i<times;i++)
  {
  digitalWrite(LED_BUILTIN, HIGH);   
  delay(500);                      
  digitalWrite(LED_BUILTIN, LOW);   
  delay(500);                       
  }
}

int seriesA(int val)
{
 //return number of blinks
 int factorial=1
 for (int i=2; i<=val;i++){
  factorial=factorial*i;
  }
 return factorial+1;
}

int seriesB(int val)
{
 //return number of blinks
 return (val*(val+1))/2;
}
