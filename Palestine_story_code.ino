/*
 Palestine Story board
SW1
 Mode0: All blink twice and stop one it starts
 Mode1: Sequantial arrow leds 1
 Mode2: Sequantial arrow leds 2
 Mode3: Blinky arrow leds
 Mode4: All ON
 Mode5: All OFF 

SW2
 Mode0: All blink twice and stop one it starts
 Mode1: Fade out Gaza/Jerusalem
 Mode2: Fade out Key
 Mode3: Fade out both
 Mode4: All ON
 Mode5: All Blink
 Mode6: All OFF

*/
int i;
int SW1 = 0;
int SW2 = 0;
int mode1=0;
int mode2=0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);


//Mode0
  for (i=0; i<2; i++)
{
digitalWrite(0, HIGH);
digitalWrite(1, HIGH);
digitalWrite(2, HIGH);
digitalWrite(3, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
delay(300);
digitalWrite(0, LOW);
digitalWrite(1, LOW);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
delay(300);
}
}

// the loop function runs over and over again forever
void loop() {

SW1 = analogRead(A6) > 100 ? 1 : 0;
SW2 = analogRead(A7) > 100 ? 1 : 0;

if (SW1 == 1)
{ delay(3);
  while (analogRead(A6) > 100 ? 1 : 0);      
   SW1 = 0;
   mode1++;
   if (mode1 > 5) mode1=1;
}  

if (SW2 == 1)
{ delay(3);
  while (analogRead(A7) > 100 ? 1 : 0);      
   SW2 = 0;
   mode2++;
   if (mode2 > 6) mode2=1;
}


///////////////////////////////// SW1  Mode1
if (mode1 == 1)
{
  while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1)
  {  
      digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(300);                       // wait for a second

       digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(300);                       // wait for a second

        digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(300);                       // wait for a second
    
        digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(300);                       // wait for a second

    digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
      delay(500);                       // wait for a second
     }
     
}

///////////////////////////////// SW1  Mode2
if (mode1 == 2)
{
  while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1)
  {  
      digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(300);                       // wait for a second
      digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
      delay(300);                       // wait for a second

      digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(300);                       // wait for a second
      digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
      delay(300);                       // wait for a second

      digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(300);                       // wait for a second
      digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
      delay(300);                       // wait for a second
    
      digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(300);                       // wait for a second
      digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
      delay(300);                       // wait for a second

     }
     
}

///////////////////////////////// SW1  Mode3
if (mode1 == 3)
{
  while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1)
  {  
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      delay(300);
      digitalWrite(0, LOW);
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      delay(300);
  }    
}

///////////////////////////////// SW1  Mode4
if (mode1 == 4)
{
      digitalWrite(0, HIGH);
      digitalWrite(1, HIGH);
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
//  while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1);    
}

///////////////////////////////// SW1  Mode5
if (mode1 == 5)
{
      digitalWrite(0, LOW);
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
//  while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1);    
}



///////////////////////////////// SW2  Mode1
if (mode2 == 1)
{
  while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1)
  {  
      for (i=0; i<255;i++)
        {
          analogWrite(10, i);
          delay(10);                       
        }
          analogWrite(10, 0);
  }
}

///////////////////////////////// SW2  Mode2
if (mode2 == 2)
{
  while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1)
  {  
      for (i=0; i<255;i++)
        {
          analogWrite(9, i);
          delay(10);                       
        }
          analogWrite(9, 0);
  }
}

///////////////////////////////// SW2  Mode3
if (mode2 == 3)
{
  while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1)
  {  
      for (i=0; i<255;i++)
        {
          analogWrite(9, i);
          analogWrite(10, i);
          delay(10);                       
        }
          analogWrite(9, 0);
          analogWrite(10, 0);
  }
}

///////////////////////////////// SW2  Mode4
if (mode2 == 4)
{
    analogWrite(9, 255);
    analogWrite(10, 255);
//    while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1);
}

///////////////////////////////// SW2  Mode5
if (mode2 == 5)
{
    while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1)
    {
      analogWrite(9, 0);
      analogWrite(10, 0);
      delay(300);
      analogWrite(9, 255);
      analogWrite(10, 255);
      delay(300);
    }
}

///////////////////////////////// SW2  Mode6
if (mode2 == 6)
{
    analogWrite(9, 0);
    analogWrite(10, 0);
//    while (analogRead(A6) > 100 ? 0 : 1  && analogRead(A7) > 100 ? 0 : 1);
}


}
