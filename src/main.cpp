/*  ---->> A0PC3F <<----
 Projeto   RC_MASTER_TX v0.0
 



  By A.Fernandes
  Junho de 2021.
*/


#include <Arduino.h>
//===>> Mapeamento de Hardware <<===//

#define LG_1 31
#define LR_1 30

#define LG_2 29
#define LR_2 28

#define LG_3 27
#define LR_3 26

#define LG_4 25
#define LR_4 24

//------------------------------------------------------------------------------------------------------

#define Tenp_1 1000
#define Tenp_2 500
#define Tenp_3 250


void Led_RG_4();
void Led_RG_3();
void Led_RG_2();
void Led_RG_1();


void setup()
{
  Serial.begin(9600);
  
  pinMode(LG_1, OUTPUT);
  pinMode(LR_1, OUTPUT);
  
  pinMode(LG_2, OUTPUT);
  pinMode(LR_2, OUTPUT);
  
  pinMode(LG_3, OUTPUT);
  pinMode(LR_3, OUTPUT);

  pinMode(LG_4, OUTPUT);
  pinMode(LR_4, OUTPUT);

  Serial.println("starting");
  


}

void loop()
{
 
Led_RG_4();
Led_RG_3();
Led_RG_2();
Led_RG_1();


}


void Led_RG_4()
{
  Serial.println(".>.<.");
  Serial.println("Led_G4");
  digitalWrite(LG_4, HIGH);
  delay(Tenp_3);
  digitalWrite(LG_4, LOW);
  delay(Tenp_3);

  Serial.println("Led_R4");
  digitalWrite(LR_4, HIGH);
  delay(Tenp_3);
  digitalWrite(LR_4, LOW);
  delay(Tenp_3);

}


void Led_RG_3()
{
  Serial.println(".>.<.");
  Serial.println("Led_G3");
  digitalWrite(LG_3, HIGH);
  delay(Tenp_3);
  digitalWrite(LG_3, LOW);
  delay(Tenp_3);

  Serial.println("Led_R3");
  digitalWrite(LR_3, HIGH);
  delay(Tenp_3);
  digitalWrite(LR_3, LOW);
  delay(Tenp_3);

}
void Led_RG_2()
{
  Serial.println(".>.<.");
  Serial.println("Led_G2");
  digitalWrite(LG_2, HIGH);
  delay(Tenp_3);
  digitalWrite(LG_2, LOW);
  delay(Tenp_3);

  Serial.println("Led_R2");
  digitalWrite(LR_2, HIGH);
  delay(Tenp_3);
  digitalWrite(LR_2, LOW);
  delay(Tenp_3);

}


void Led_RG_1()
{
  Serial.println(".>.<.");
  Serial.println("Led_G1");
  digitalWrite(LG_1, HIGH);
  delay(Tenp_3);
  digitalWrite(LG_1, LOW);
  delay(Tenp_3);

  Serial.println("Led_R1");
  digitalWrite(LR_1, HIGH);
  delay(Tenp_3);
  digitalWrite(LR_1, LOW);
  delay(Tenp_3);

}