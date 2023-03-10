



struct joystickValues 
  {
  char joystickName[20];
  const int pin;
  int value;
  };

struct joystickValues controller[]
{
  {"JoystickLeftX", A0, 0 },
  {"JoystickRightY", A1, 0 }
};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 2; i++)
  {
    pinMode(controller[i].pin, INPUT);
  }

}
 
void loop() {
  
  // put your main code here, to run repeatedly:
 for(int i = 0; i < 2; i++)
 {
   controller[i].value = analogRead(controller[i].pin);

 }
  debug();
  
   
 
 }
 
 void debug(){
  Serial.print(controller[0].joystickName ); Serial.print(": ");  Serial.print(controller[0].value);
  Serial.print("  ");
  Serial.print(controller[1].joystickName ); Serial.print(": ");  Serial.println(controller[1].value);
 }