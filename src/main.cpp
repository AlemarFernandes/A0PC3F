/*  ---->> A0PC3F <<----
 Projeto   RC_MASTER_TX v0.0
 
 -> Criada a funçao Stast 


  By A.Fernandes
  Junho de 2021.
*/


//===>> Bibliotecas Auxiliares <<===//


#include <Arduino.h>

//------------------------------------------------------------------------------------------------------


//===>> Mapeamento de Hardware <<===//

// Ld_A
#define LG_1 31
#define LR_1 30
// Ld_B
#define LG_2 29
#define LR_2 28
// Ld_C
#define LG_3 27
#define LR_3 26
// Ld_D
#define LG_4 25
#define LR_4 24


//------------------------------------------------------------------------------------------------------


//===>> Constantes do Projeto <<===//

#define tmp1 50
#define tmp2 500
#define tmp3 1000


//------------------------------------------------------------------------------------------------------

//===>> Protótipo das Funções<<===//

void LD_Start (bool R1, bool G1, bool R2, bool G2, bool R3, bool G3, bool R4, bool G4);
void LD_Start ();

//------------------------------------------------------------------------------------------------------





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
  LD_Start();
  
}

//===>> Desenvolvimento das Funções <<===//



void LD_Start ()
{
  // LD_Start amarelos
  LD_Start(0,0,0,0,0,0,0,0);
  delay(tmp3);
  LD_Start(1,1,1,1,1,1,1,1);
  delay(tmp1);
  // loop direita
  LD_Start(0,1,1,1,0,1,1,1);
  delay(tmp1);
  LD_Start(1,1,1,1,1,1,1,1);
  delay(tmp1);
  LD_Start(1,0,1,1,1,0,1,1);
  delay(tmp1);
  LD_Start(1,1,1,1,1,1,1,1);
  delay(tmp1);
  LD_Start(1,1,0,1,1,1,0,1);
  delay(tmp1);
  LD_Start(1,1,1,1,1,1,1,1);
  delay(tmp1);
  LD_Start(1,1,1,0,1,1,1,0);
  delay(tmp1);
  LD_Start(1,1,1,1,1,1,1,1);
  delay(tmp1);

  
  LD_Start(1,1,1,1,1,1,1,1);
  delay(tmp1);
  LD_Start(1,1,0,1,1,1,0,1);
  delay(tmp1);
  LD_Start(1,1,1,1,1,1,1,1);
  delay(tmp1);
  LD_Start(1,0,1,1,1,0,1,1);
  delay(tmp1);
  LD_Start(1,1,1,1,1,1,1,1);
  delay(tmp1);
  LD_Start(0,1,1,1,0,1,1,1);
  delay(tmp1);
  LD_Start(1,1,1,1,1,1,1,1);
  delay(tmp1);


}





void LD_Start (bool R1,  bool R2, bool R3, bool R4, bool G1, bool G2,  bool G3,  bool G4)
{
  digitalWrite(LR_1, R1);
  digitalWrite(LR_2, R2);
  digitalWrite(LR_3, R3);
  digitalWrite(LR_4, R4);
  digitalWrite(LG_1, G1);
  digitalWrite(LG_2, G2);
  digitalWrite(LG_3, G3);
  digitalWrite(LG_4, G4);
}

//------------------------------------------------------------------------------------------------------


