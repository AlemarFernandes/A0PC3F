/*  ---->> A0PC3F <<----
 Projeto   RC_MASTER_TX v0.0
 
  -> Criada a funçâo Start 
  -> Criado as funções para os Puch-Button

  By A.Fernandes
  Junho de 2021.
*/

//                             ===>> Bibliotecas Auxiliares <<===

#include <Arduino.h>

//.....................................................................................................
//..................................  Mapeamento de Hardware ..........................................

#define LR_1 30                                   // led  vermelo   => R1 
#define LR_2 28                                   // led  vermelo   => R2
#define LR_3 26                                   // led  vermelo   => R3
#define LR_4 24                                   // led  vermelo   => R4

#define LG_1 31                                   // led  verde     => G1
#define LG_2 29                                   // led  verde     => G2
#define LG_3 27                                   // led  verde     => G3
#define LG_4 25                                   // led  verde     => G4

// Puch-Bottun
#define BT_A 2
#define BT_B 3
#define BT_C 4
#define BT_D 5
#define BT_E 6
#define BT_F 7

//------------------------------------------------------------------------------------------------------


//===>> Constantes do Projeto <<===// 

#define tempoDebounce 50                                         // tempo para eliminar o efeito Bounce 
#define tmp1 50
#define tmp2 500
#define tmp3 1000

//.....................................................................................................
//                                  ===>> Variáveis Globais  <<===//

bool ButtonPressed_A();
bool ButtonPressed_B();
bool ButtonPressed_C();
bool ButtonPressed_D();
bool ButtonPressed_E();
bool ButtonPressed_F();

//------------------------------------------------------------------------------------------------------

//===>> Protótipo das Funções<<===//

void Leds (bool R1,  bool R2, bool R3, bool R4, bool G1, bool G2,  bool G3,  bool G4);
void Leds ();
void Test_Button();

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

  pinMode(BT_A, INPUT);
  pinMode(BT_B, INPUT);
  pinMode(BT_C, INPUT);
  pinMode(BT_D, INPUT);
  pinMode(BT_E, INPUT);
  pinMode(BT_F, INPUT);

  
  Serial.println("starting");

} //end  setup

void loop()
{
   Test_Button();
  
  
} // end loop
//........................................  End of main program .....................................................







//===>> Desenvolvimento das Funções <<===//

// ---->> Funções para os leds <<----

void Leds (bool R1,  bool R2, bool R3, bool R4, bool G1, bool G2,  bool G3,  bool G4)
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

//.....................................................................................................

void Leds ()
{
  // Leds amarelos
  Leds(0,0,0,0,0,0,0,0);
  delay(tmp3);
  Leds(1,1,1,1,1,1,1,1);
  delay(tmp1);
  // loop direita
  Leds(0,1,1,1,0,1,1,1);
  delay(tmp1);
  Leds(1,1,1,1,1,1,1,1);
  delay(tmp1);
  Leds(1,0,1,1,1,0,1,1);
  delay(tmp1);
  Leds(1,1,1,1,1,1,1,1);
  delay(tmp1);
  Leds(1,1,0,1,1,1,0,1);
  delay(tmp1);
  Leds(1,1,1,1,1,1,1,1);
  delay(tmp1);
  Leds(1,1,1,0,1,1,1,0);
  delay(tmp1);
  Leds(1,1,1,1,1,1,1,1);
  delay(tmp1);


  Leds(1,1,1,1,1,1,1,1);
  delay(tmp1);
  Leds(1,1,0,1,1,1,0,1);
  delay(tmp1);
  Leds(1,1,1,1,1,1,1,1);
  delay(tmp1);
  Leds(1,0,1,1,1,0,1,1);
  delay(tmp1);
  Leds(1,1,1,1,1,1,1,1);
  delay(tmp1);
  Leds(0,1,1,1,0,1,1,1);
  delay(tmp1);
  Leds(1,1,1,1,1,1,1,1);
  delay(tmp1);

}// End Funções para os leds 

//.....................................................................................................

//---->> Função de controle para Puch-Button <<----




void Test_Button()
{
    if(ButtonPressed_A()) {                      // liga leds R1, R2, R3, R4
      Leds(0,0,0,0,1,1,1,1);
    } else {
      Leds(1,1,1,1,1,1,1,1);                     // leds OFF
    }

     if(ButtonPressed_B()) {                      // liga leds R1, R4
      Leds(0,1,1,0,1,1,1,1);
    } else {
      Leds(1,1,1,1,1,1,1,1);                     // leds OFF
    }

     if(ButtonPressed_C()) {                      // liga leds R2, R3
      Leds(1,0,0,1,1,1,1,1);
    } else {
      Leds(1,1,1,1,1,1,1,1);                     // leds OFF
    }

     if(ButtonPressed_D()) {                      // liga G1, G2, G3, G4
      Leds(1,1,1,1,1,0,0,1);
    } else {
      Leds(1,1,1,1,1,1,1,1);                     // leds OFF
    }

    if(ButtonPressed_E()) {                      // liga G1, G4
      Leds(1,1,1,1,0,1,1,0);
    } else {
      Leds(1,1,1,1,1,1,1,1);                     // leds OFF
    }

    if(ButtonPressed_F()) {                      // liga G2, G3
      Leds(1,1,1,1,0,0,0,0);
    } else {
      Leds(1,1,1,1,1,1,1,1);                     // leds OFF
    }

}// end Test_Button




























bool ButtonPressed_A() {

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = false;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(BT_A);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}


bool ButtonPressed_B() {

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = false;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(BT_B);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}

bool ButtonPressed_C() {

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = false;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(BT_C);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}


bool ButtonPressed_D() {

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = false;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(BT_D);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}


bool ButtonPressed_E() {

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = false;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(BT_E);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}

bool ButtonPressed_F() {

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = false;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(BT_F);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}

// End função de controle para Puch-Button 

//.....................................................................................................
