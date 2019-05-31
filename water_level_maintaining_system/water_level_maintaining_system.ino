    /*
    Water level maintaianing system 
    created by kavindu handapangoda
    2019:03:29
    For inovate sri lanka exhibition
    */
    
#define trig 2
#define echo 3
#define WrelayPin  4  //Water pump realy pin

void setup() {
  Serial.begin(9600);

  //ultrasound sensor pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // relay pins
  pinMode(WrelayPin, OUTPUT);

  // Led bar graph pins
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Loading animation
  for (int w = 6; w < 11; w++){
   digitalWrite(w, HIGH);
   digitalWrite(w-1, LOW);
   delay(200);
  } 
}

void loop() {

     cWater();
  }


//------------------------------------- Water leval checker ---------------------------------------------------
  

void cWater(){
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
long t=pulseIn(echo, HIGH);
long cm = (t/2)/29.1;

Serial.print(cm);
Serial.println("cm");


  if (cm < 25){
   Serial.println("water leval is good");
   digitalWrite(WrelayPin, LOW);
   good();

            if (cm < 15){
   Serial.println("water leval is overflow");
   digitalWrite(WrelayPin, LOW);
   over();

        }
    }
          if (cm > 25){
          Serial.println("water leval is normal");
          normal();

                if (cm > 50){
                Serial.println("water leval is low");
                low();

                      if (cm > 65){
                      Serial.println("Water pump on");
                      digitalWrite(WrelayPin , HIGH);
                      
                      pump();
  }
  } 
  }
  
  delay(100);
}


//------------------------------------------------------ Led bar graph---------------------------

void over(){
   digitalWrite(6, LOW);   
   digitalWrite(7, LOW);   
   digitalWrite(8, LOW);   
   digitalWrite(9, LOW);   
   digitalWrite(10, LOW); 
   
   
   digitalWrite(6, HIGH);   
   digitalWrite(7, HIGH);   
   digitalWrite(8, HIGH);   
   digitalWrite(9, HIGH);   
   digitalWrite(10, HIGH); 
  }
  
void good(){
   digitalWrite(6, LOW);   
   digitalWrite(7, LOW);   
   digitalWrite(8, LOW);   
   digitalWrite(9, LOW);   
   digitalWrite(10, LOW); 
   
   digitalWrite(7, HIGH);   
   digitalWrite(8, HIGH);   
   digitalWrite(9, HIGH);   
   digitalWrite(10, HIGH); 
  }


void normal(){

   digitalWrite(6, LOW);   
   digitalWrite(7, LOW);   
   digitalWrite(8, LOW);   
   digitalWrite(9, LOW);   
   digitalWrite(10, LOW); 
   
   digitalWrite(8, HIGH);
   digitalWrite(9, HIGH);
   digitalWrite(10, HIGH);   
  }


void low(){

   digitalWrite(6, LOW);   
   digitalWrite(7, LOW);   
   digitalWrite(8, LOW);   
   digitalWrite(9, LOW);   
   digitalWrite(10, LOW); 
   
   digitalWrite(9, HIGH);
   digitalWrite(10, HIGH);
  }


void pump(){
   digitalWrite(6, LOW);   
   digitalWrite(7, LOW);   
   digitalWrite(8, LOW);   
   digitalWrite(9, LOW);   
   digitalWrite(10, LOW); 
   
   digitalWrite(10, HIGH);
   
  }

  
