const int led[3] = {7,6,5};
const int ldr[3] = {A3,A4,A5};
const int sensorPin = A0;
int ranNum;
int score;
int norm;
int var;
int in[3];

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));
  Serial.begin(9600);
  norm = 0;
  for (int index = 0; index < 3; index++) {
    pinMode(led[index], OUTPUT);
    digitalWrite(led[index], LOW);
    norm = norm + analogRead(ldr[index]);
  }
  norm = norm/3;
  var = 50;
  score = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  ranNum = random(0,3);
//  Serial.print("LED: ");
//  Serial.print(ranNum);
//  Serial.println(" on.");
//  input = analogRead(A0);
//  Serial.print("Input = ");
//  Serial.println(input);
//  delay(250);
  
//  ranNum = 0;
  digitalWrite(led[ranNum], HIGH);
  delay(1000);
  digitalWrite(led[ranNum], LOW);
  for (int index = 0; index < 3; index++) {
    in[index] = analogRead(ldr[index]);
  }
  Serial.print("Value = ");
  Serial.print(in[ranNum]);
  if( ( norm - in[ranNum] >= var )  && ( norm - in[(ranNum+1)%3] <= var ) && ( norm - in[(ranNum+2)%3] <= var ) ) {
    score++;
    Serial.print(". Mole hit. Score is ");
  }
  else{
    Serial.print(". Mole missed. Score is ");
  }
  Serial.println(score);
  delay(3000);
}
