#define DEBUG 0
#define in1  12
#define in2  14
#define in3  27
#define in4  26
#define mC1  25
#define mC2  33
#define iFRight  32
#define iFLeft  35


void setup() {
  #ifdef DEBUG
    Serial.begin(115200);
   #endif
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(mC1, OUTPUT);
  pinMode(mC2, OUTPUT);
  pinMode(iFRight, INPUT);
  pinMode(iFLeft, INPUT);
}

void backward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void left()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void foward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void right()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void stopMotor()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop()
{
  #ifdef DEBUG
    delay(50);
    Serial.println("Right:"+String(digitalRead(iFRight)));
    Serial.println("Left:"+iFLeft);
    #endif
   foward();
   if (digitalRead(iFRight) == 0 || digitalRead(iFLeft) == 0)
   {
    stopMotor();
    delay(100);
    backward();
    delay(250);
    right();
    delay(250);
   }
   delay(10);
}
