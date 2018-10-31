int SWT_1 = 8;
int SWT_2 = 9;
int SWT_3 = 10;

int btnState = 0;
int btnState2 = 0;
int btnState3 = 0;

const char* helloWorld = "Hello, world!";

void setup() {
  Serial.begin(9600);
  pinMode(SWT_1,INPUT);
  pinMode(SWT_2,INPUT);
  pinMode(SWT_3,INPUT);
}

void loop() {
  btnState = digitalRead(SWT_1);
  btnState2 = digitalRead(SWT_2);
  btnState3 = digitalRead(SWT_3);

  if(btnState > 0){
    Serial.println("1");
  }
  else if(btnState2 > 0){
        Serial.println("2");
  }
  else if(btnState3 >0 ){
        Serial.println("3");
  }
  else
  {
    Serial.println("4");
  }
  delay(3000);
}
