int LP = A3;            // Latch Pin 8
int ClkP = 8;           // Clock Pin 12
int R1P = 2;          // R1 Pin 11 
int B1P = 4;          // B1 Pin 10
int G1P = 3;           // G1 Pin  9
int R2P = 5;           // R2 Pin 7
int B2P = 7;           // B2 Pin 6 
int G2P = 6;           // G2 Pin 5
int AP = A0;            // A Pin 2
int BP = A1;            // B Pin 3
int CP = A2;            // C Pin 4
int OEP = 9;          // OE Pin 14
int row = 0;

void setup() {
  
pinMode(LP, OUTPUT);
pinMode(ClkP, OUTPUT);
pinMode(R1P, OUTPUT);
pinMode(B1P, OUTPUT);
pinMode(G1P, OUTPUT);
pinMode(R2P, OUTPUT);
pinMode(B2P, OUTPUT);
pinMode(G2P, OUTPUT);
pinMode(AP,OUTPUT);
pinMode(BP,OUTPUT);
pinMode(CP,OUTPUT);
pinMode(OEP,OUTPUT);
pinMode(13,OUTPUT);
digitalWrite(AP, LOW);
digitalWrite(BP, LOW);
digitalWrite(CP, LOW);
digitalWrite(OEP, LOW);
digitalWrite(LP, LOW);
row=0;

}

void loop() {

digitalWrite(OEP, LOW);
digitalWrite(LP, HIGH);
digitalWrite(OEP, LOW);

row1(AP,BP, ClkP);
shiftOut1(R1P, ClkP);
shiftOut2(R1P, ClkP);
delay(1000);

}

void row1(uint8_t AP1, uint8_t BP1, uint8_t ClkP1){
  
  uint8_t i;    
  
  for(i=0;i<64;i++){
    digitalWrite(AP1, 1);                 
    delay(100);                                                      
    digitalWrite(ClkP1, HIGH);
    digitalWrite(ClkP1, LOW);
    delay(100);      
      for(i=0;i>64;++i){
        digitalWrite(AP1, 0);                 
        delay(100);  
        digitalWrite(ClkP1, HIGH);
        digitalWrite(ClkP1, LOW);
        delay(100);                                                           
      }
  }     
}

void shiftOut1(uint8_t R1P1, uint8_t ClkP1)
{
     uint8_t i;

        digitalWrite(R1P1, 1);                 
        delay(100);                                                 
        digitalWrite(ClkP1, HIGH);
        digitalWrite(ClkP1, LOW);
        delay(100);
                                             
}

void shiftOut2(uint8_t R1P1, uint8_t ClkP1)
{
     uint8_t i;

     for (i = 0; i < 64; i++)  {
          digitalWrite(R1P1, 0);                 
          delay(100);                                                                 
          digitalWrite(ClkP1, HIGH);
          digitalWrite(ClkP1, LOW);
          delay(100);
                                            
     }
}
