int angle;
int pwm;

void setup()
{
  pinMode(10, OUTPUT);
}

void loop ()
{
  for (angle = 60; angle <= 120; angle += 1)  {
    servoPulse(10, angle);  
  }
  for (angle = 120; angle >= 60; angle -= 1)  {
    servoPulse(10, angle); 
  }
}
  
void servoPulse (int servo, int angle)
{
  pwm = (angle*11) + 500;      // Convert angle to microseconds
  digitalWrite(servo, HIGH);
  delayMicroseconds(pwm);
  digitalWrite(servo, LOW);
  delay(50);                   // Refresh cycle of servo
}