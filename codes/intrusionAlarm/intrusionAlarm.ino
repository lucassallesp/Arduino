unsigned long AGORA;
unsigned long ANTES = 0;
unsigned long DEPOIS = 1;
int estado = 0, state = 1;

#define ZONA1 7
#define ZONA2 8
#define INTERRUPTOR 12
#define LED 13
#define ALARME 3

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(ALARME, OUTPUT);
  pinMode(INTERRUPTOR, INPUT);
  pinMode(ZONA1, INPUT); //
  pinMode(ZONA2, INPUT);
  
    
  ANTES = 0;
  
  PORTB = 0b00000000;
}

void loop()
{
  AGORA = millis();

  switch(estado){
    case 0: 
    	digitalWrite(ALARME, LOW);
    	digitalWrite(LED, HIGH);
    	if(digitalRead(INTERRUPTOR) == HIGH){
        	estado = 1;   	
        }
    break;
    
    case 1:
    
    	digitalWrite(ALARME, LOW);
    
    	if((AGORA - ANTES) >= 1000){
    		PORTB = PORTB ^ 0b100000;
          	ANTES = AGORA;
    	}
    
        if(digitalRead(INTERRUPTOR) == LOW){
            estado = 0;
        }
    	    
   		else if((digitalRead(ZONA1) == HIGH) | (digitalRead(ZONA2) == HIGH)){
    		estado = 2;
    	}
    break;
    
    case 2:
    		rotina();
      		if (digitalRead(INTERRUPTOR) == LOW){
            	estado = 0;
            } else if ((digitalRead(INTERRUPTOR) == HIGH) & (digitalRead(ZONA2) == LOW) & (digitalRead(ZONA1) == LOW)){
              	estado = 1;
            }
    break;    
  }  
}
 

void rotina(){
  switch(state){
    case 1:    
      if ((((AGORA - DEPOIS) >= 2000))) {
        PORTD = PORTD ^ 0b0001000;
        DEPOIS = AGORA; 
      }

      if ((AGORA - ANTES) >= 1000) {
         PORTB = PORTB ^ 0b100000;
         ANTES = AGORA;
      }
    
      if (AGORA - DEPOIS >= 180000) { //achar condição pra esse IF
         state = 2;
      } 
    break;
    
    case 2:
    	digitalWrite(ALARME, LOW);
      	delay(30000);
    	state = 1;
    break;  
  }
}
