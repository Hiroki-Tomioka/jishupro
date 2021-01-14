#define STEP1  2
#define STEP2  3
#define UP     5
#define MIDDLE 7
#define DOWN   9
#define BASESTEPANGLE 1.8
float count = 0;
int flag = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(STEP1, OUTPUT);
  pinMode(STEP2, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(MIDDLE, OUTPUT);
  pinMode(DOWN, OUTPUT);
}

void dot_none()
{
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , LOW);
  delay(250);
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
  delay(200);
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
  delay(200);
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
  delay(200);
}

void dot_up_middle()
{
  digitalWrite(UP    , HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(DOWN  , LOW);
  delay(50);
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , LOW);
  delay(200);
}

void dot_up_down()
{
  digitalWrite(UP    , HIGH);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , HIGH);
  delay(50);
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , LOW);
  delay(200);
}

void dot_middle_down()
{
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(DOWN  , HIGH);
  delay(50);
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , LOW);
  delay(200);
}

void dot_all()
{
  digitalWrite(UP    , HIGH);
  digitalWrite(MIDDLE, HIGH);
  digitalWrite(DOWN  , HIGH);
  delay(50);
  digitalWrite(UP    , LOW);
  digitalWrite(MIDDLE, LOW);
  digitalWrite(DOWN  , LOW);
  delay(200);
}

void step_forward_narrow(int iRpm)
{
  int iStepTime_milli = (int)(1000 *  BASESTEPANGLE / (iRpm * 6));
  for (int i = 0; i < 15; i++){
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
  // P1:ON, P2:ON, P1B:off, P2B:off
  //digitalWrite(STEP1, HIGH);
  //digitalWrite(STEP2, HIGH);
  //delay(iStepTime_milli);
  // P1:off, P2:ON, P1B:ON, P2B:off
  //digitalWrite(STEP1, LOW);
  //digitalWrite(STEP2, HIGH);
  //delay(iStepTime_milli);
}

void step_forward_broad(int iRpm)
{
  int iStepTime_milli = (int)(1000 *  BASESTEPANGLE / (iRpm * 6));
  // P1:ON, P2:off, P1B:off, P2B:ON
  //digitalWrite(STEP1, HIGH);
  //digitalWrite(STEP2, LOW);
  //delay(iStepTime_milli);
  for (int i = 0; i < 19; i++){
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
}

void step_reverse_all( int iRpm )
{int iStepTime_milli = (int)(1000.0 * BASESTEPANGLE / (iRpm * 6));
  for (int i = 0; i < 725; i++){
    // P1:off, P2:off, P1B:ON, P2B:ON
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, LOW);
    delay(iStepTime_milli);
    // P1:off, P2:ON, P1B:ON, P2B:off
    digitalWrite(STEP1, LOW);
    digitalWrite(STEP2, HIGH);
    delay(iStepTime_milli);
    // P1:ON, P2:ON, P1B:off, P2B:off
    digitalWrite(STEP1, HIGH);
    digitalWrite(STEP2, HIGH);
    delay(iStepTime_milli);
    // P1:ON, P2:off, P1B:off, P2B:ON
    digitalWrite(STEP1, HIGH);
    digitalWrite(STEP2, LOW);
    delay(iStepTime_milli);
  }
  // P1:off, P2:off, P1B:ON, P2B:ON
  digitalWrite(STEP1, LOW);
  digitalWrite(STEP2, LOW);
  delay(iStepTime_milli);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    byte var;
    var = Serial.read();
    Serial.println(count);
    switch(var){
      case '0':
        dot_none();
        break;
      case '1':
        dot_up();
        break;
      case '2':
        dot_middle();
        break;
      case '3':
        dot_down();
        break;
      case '4':
        dot_up_middle();
        break;
      case '5':
        dot_up_down();
        break;
      case '6':
        dot_middle_down();
        break;
      case '7':
        dot_all();
        break;
      default:
        break;
    }
    if (flag == 0){
      step_forward_narrow(140);
      flag = 1;
      count += 1;
    }
    else{
      if (count > 21){
        step_reverse_all(140);
        count = 0;
      }
      else{
        step_forward_broad(140);
        flag = 0;
      }
    }
  }
}
