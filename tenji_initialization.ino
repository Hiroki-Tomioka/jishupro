#define STEP1  2
#define STEP2  3
#define UP     5
#define MIDDLE 7
#define DOWN   9
#define BASESTEPANGLE 1.8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(STEP1, OUTPUT);
  pinMode(STEP2, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(MIDDLE, OUTPUT);
  pinMode(DOWN, OUTPUT);
  step_forward_ini(140);
  //dot_up();
  delay(1000);
  //dot_middle();
  delay(1000);
  //dot_down();
  delay(1000);
}

void step_forward_ini(int iRpm)
{
  delay(1000);
  int iStepTime_milli = (int)(1000 *  BASESTEPANGLE / (iRpm * 6));
  for (int i = 0; i < 353; i++){
    // P1:ON, P2:ON, P1B:off, P2B:off
    digitalWrite(STEP1, HIGH);
    digitalWrite(STEP2, HIGH);
    delay(iStepTime_milli);
    // P1:off, P2:ON, P1B:ON, P2B:off
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, HIGH);
    delay(iStepTime_milli);
    // P1:off, P2:off, P1B:ON, P2B:ON
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    delay(iStepTime_milli);
    // P1:ON, P2:off, P1B:off, P2B:ON
    digitalWrite(STEP1, HIGH);
    digitalWrite(STEP2, LOW);
    delay(iStepTime_milli);
  }
  delay(1000);
}

void dot_up()
{
  digitalWrite(UP    , HIGH);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , LOW);
  delay(50);
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , LOW);
  delay(150);
}

void dot_middle()
{
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(DOWN  , LOW);
  delay(50);
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , LOW);
  delay(150);
}

void dot_down()
{
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , HIGH);
  delay(50);
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , LOW);
  delay(150);
}

void loop() {
  // put your main code here, to run repeatedly:
}
