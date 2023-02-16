

int PWM1 = 11;
int in1 = 8;
int in2 = 7;
void setup() {
  
  Serial.begin(9600);
  Serial.println("Serial working");
pinMode(PWM1, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
}

void loop(){

digitalWrite(PWM1, HIGH);
digitalWrite(in1, HIGH);
digitalWrite(in2, HIGH);
}
