 #include <Servo.h> 
 #define echoPin 2
 #define trigPin 3
 #define MOTOR1 7
#define MOTOR2 5
#define EN 6
#define POT 0
 Servo myservo;
 long duration;
 int distance;
 const int relayPin = 13;  
const int ldrPin = A0;  
int servopin = 10;
int servopossion = 250;
const int buzzer = 11;
void setup() {

  Serial.begin(9600);
  pinMode(relayPin, OUTPUT); 
  pinMode(ldrPin, INPUT);   
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT); 
  myservo.attach(servopin); 
   pinMode(buzzer, OUTPUT); 
  Serial.begin(9600);
  pinMode(EN,OUTPUT);
  pinMode(MOTOR1,OUTPUT);
  pinMode(MOTOR2,OUTPUT);
}

void loop() {
  //code of ultrasonic
  digitalWrite(trigPin,LOW);
  delay(200);
  digitalWrite(trigPin,HIGH);
  delay(1000);
  digitalWrite(trigPin,LOW);
  duration =pulseIn(echoPin,HIGH);
  distance= (duration * 0.034 )/ 2;
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println("cm");
  if (distance <= 10 && ldrStatus <=400 ){
    digitalWrite(relayPin, HIGH);               
    Serial.println("LDR is DARK, LED is ON");
   
    
  }
   if (distance <= 10 && ldrStatus >400 ){
    digitalWrite(relayPin, LOW);               
    Serial.println("LDR is DARK, LED is OFF");
  
  }
   if (distance > 10 && ldrStatus >400 ){
    digitalWrite(relayPin, LOW);               
    Serial.println("LDR is DARK, LED is OFF");
  
  }
  //code of LRD and LED
  int ldrStatus = analogRead(ldrPin);  
   Serial.println(ldrStatus);
   delay(1000);

   /*if (ldrStatus <=400) {

    digitalWrite(relayPin, HIGH);               
    Serial.println("LDR is DARK, LED is ON");
    
   }
  else {

    digitalWrite(relayPin, LOW);         
    Serial.println("---------------");
  }*/
  //CODE OF SERVO MOTOR
  myservo.detach();
    delay(1500);
    myservo.attach(servopin);
   myservo.write(servopossion);
    delay(1500);
    myservo.detach();
    
    myservo.attach(servopin);
    myservo.write(0);
    delay(1500);
    //CODE OF BUZZER
     tone(buzzer, 2900); 
  delay(1000);        
  noTone(buzzer);     
  delay(1000);
      
   POT_VAL=analogRead(POT);

  if(POT_VAL<(512)){
    POT_VAL = map(POT_VAL, 0, 512, 0, 255);  
    Serial.println(POT_VAL);
   analogWrite(EN,POT_VAL);
  digitalWrite(MOTOR1,HIGH);
  digitalWrite(MOTOR2,LOW);
  
  
    }else{
      POT_VAL = map(POT_VAL, 512, 1023, 0, 255);
      Serial.println(POT_VAL);
      analogWrite(EN,POT_VAL);
      digitalWrite(MOTOR1,LOW);
      digitalWrite(MOTOR2,HIGH);
}
