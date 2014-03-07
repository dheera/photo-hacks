 

int param_dx=5;
int param_dy=0;
int param_dt=500;
int running=0;
  
// SoftwareSerial BTSerial(2,3);

void setup() {
  pinMode(8, OUTPUT);
  analogWrite(8, 0);

  pinMode(6, OUTPUT);
  analogWrite(6, 0);
  pinMode(9, OUTPUT);
  analogWrite(9, 0);
  pinMode(10, OUTPUT);
  analogWrite(10, 0);
  pinMode(10, OUTPUT);
  analogWrite(11, 0);
  
  Serial.begin(9600);
//  Serial.println("Enter AT commands:");
//  BTSerial.begin(9600);  // HC-05 default speed in AT command more
                         // was 38400 but changed it to 9600
}

void loop() {
  
  char inputLine[200];
  int l;
  String argv[10];
  char* i;
  
  if(running) {
    digitalWrite(8,1);
      delay(7 0);
    digitalWrite(8,0);
    delay(80);
    if(param_dx>0) {
      analogWrite(6,63);
      delay(5);
      analogWrite(6,127);
      delay(5);
      analogWrite(6,191);
      delay(10);
      analogWrite(6,255);
      delay(param_dx);
      analogWrite(6,191);
      delay(10);
      analogWrite(6,127);
      delay(5);
      analogWrite(6,63);
      delay(5);
      analogWrite(6,0);
    }
    if(param_dx<0) {
      analogWrite(10,63);
      delay(5);
      analogWrite(10,127);
      delay(5);
      analogWrite(10,191);
      delay(10);
      analogWrite(10,255);
      delay(-param_dx);
      analogWrite(10,191);
      delay(10);
      analogWrite(10,127);
      delay(5);
      analogWrite(10,63);
      delay(5);
      analogWrite(10,0);
    }
    if(param_dy>0) {
      analogWrite(9,63);
      delay(5);
      analogWrite(9,127);
      delay(5);
      analogWrite(9,191);
      delay(10);
      analogWrite(9,255);
      delay(param_dy);
      analogWrite(9,191);
      delay(10);
      analogWrite(9,127);
      delay(5);
      analogWrite(9,63);
      delay(5);
      analogWrite(9,0);
    }
    if(param_dy<0) {
      analogWrite(11,63);
      delay(5);
      analogWrite(11,127);
      delay(5);
      analogWrite(11,191);
      delay(10);
      analogWrite(11,255);
      delay(-param_dy);
      analogWrite(11,191);
      delay(10);
      analogWrite(11,127);
      delay(5);
      analogWrite(11,63);
      delay(5);
      analogWrite(11,0);
    }
    delay(param_dt); 
  }

  if (Serial.available()) {
    // Serial.write(BTSerial.read());
    l=Serial.readBytesUntil('\n',inputLine,200);
    inputLine[l]=0;
    if(inputLine[l-1]=='\r') inputLine[l-1]=0;
    argv[0]=strtok_r(inputLine," ",&i);
    argv[1]=strtok_r(NULL," ",&i);
    
    if(argv[0]=="run") {
      running=1;
      
    } else if(argv[0]=="hello") {
      Serial.write("hi\r\n");
      
    } else if(argv[0]=="shoot") {
      digitalWrite(8,1);
      delay(70);
      digitalWrite(8,0);
      Serial.write("shoot\r\n");
      
    } else if(argv[0]=="dx") {
      param_dx=argv[1].toInt();
      Serial.write("dx\r\n");
      
    } else if(argv[0]=="dy") {
      param_dy=argv[1].toInt();
      Serial.write("dy\r\n");
      
    } else if(argv[0]=="dt") {
      param_dt=argv[1].toInt();
      Serial.write("dt\r\n");
      
    } else if(argv[0]=="left") {
      analogWrite(10,argv[1].toInt());
      Serial.write("left\r\n");
      
    } else if(argv[0]=="right") {
      analogWrite(6,argv[1].toInt());
      Serial.write("right\r\n");
      
    } else if(argv[0]=="up") {
      analogWrite(11,argv[1].toInt());
      Serial.write("up\r\n");
      
    } else if(argv[0]=="down") {
      analogWrite(9,argv[1].toInt());
      Serial.write("down\r\n");
      
    } else if(argv[0]=="stop") {
      running=0;
      analogWrite(6,0);
      analogWrite(9,0);
      analogWrite(10,0);
      analogWrite(11,0);
      Serial.write("stop\r\n");
      
    } else {
      Serial.write("bad command\r\n");
      
    }
  }

//  if (Serial.available())
//    BTSerial.write(Serial.read());
}
