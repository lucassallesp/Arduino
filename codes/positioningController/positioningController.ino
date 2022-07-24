#include <PID_v1.h>
#include <Encoder.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>

#define CLK 3 //PINO DE CLOCK
#define DT 2 //PINO DE DADOS
#define SW 4 //BOTÃO DO ENCODER
#define IN1 9 //ENTRADA 1 PONTE H
#define IN2 10 //ENTRADA 2 PONTE H

unsigned long AGORA = 0, DEPOIS = 0;
int endereco = 22;
double Kd =0.01, Ki = 1, Kp = 10, saida, posicao, ajuste = 0, setPoint = EEPROM.read(endereco);

LiquidCrystal lcd(11, 12, 5, 6, 7, 8);
Encoder myEnc(CLK, DT);
PID controle(&posicao, &saida, &setPoint, Kp, Ki, Kd, DIRECT);

void Forward(){ 
  if(saida > 0){
    analogWrite(IN1, saida);
    analogWrite(IN2, 0);
  }
  else{
    analogWrite(IN1, 0);
    analogWrite(IN2, abs(saida)); 
  }
} 


void setup(){
  pinMode(CLK, INPUT);   
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  lcd.begin(16, 2);

  controle.SetOutputLimits(-255, 255);
  controle.SetMode(AUTOMATIC);
}

void loop() {
  AGORA = millis();
  
  posicao = map(analogRead(A0), 38, 984, 0, 180);
  lcd.setCursor(11,0);
  lcd.print(setPoint);
  
  ajuste = myEnc.read();
  lcd.setCursor(0, 1);
  if (ajuste >=180){
    myEnc.write(180);
  }
  if (ajuste <=0){
    myEnc.write(0);
  }

  ajuste = myEnc.read();
  lcd.print(ajuste);
  lcd.setCursor(0,0);
  lcd.print(posicao);
  
  if(posicao >= 180){
    lcd.setCursor(0,0);
    lcd.print("180.00");
  }
  

      if((digitalRead(SW) == LOW) && (AGORA - DEPOIS >= 2000)){
        setPoint = ajuste;
        EEPROM.update(endereco, setPoint);
        
        lcd.setCursor(12, 1);
        lcd.print("Att.");
              
        lcd.setCursor(11, 0);
        lcd.print(setPoint);
        DEPOIS = AGORA;
      }
      if((digitalRead(SW) == LOW) && (AGORA - DEPOIS <= 2000)){
        lcd.setCursor(6, 1);
      }

        if((AGORA - DEPOIS) >= 2000){
          lcd.setCursor(0, 1);
          lcd.print("                 ");
          DEPOIS = AGORA;
        }        
      
      
  if(controle.Compute()){
      Forward(); 
  }
 
}
