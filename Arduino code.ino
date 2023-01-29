#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h> //includes the servo library


// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd (0x27, 20, 4);
LiquidCrystal_I2C lcd1(0x26, 16, 2);




Servo myservo;

char mtlb_data;
int ir_enter = 13;
int ir_back = 12;

int ir_car1 =11;
int ir_car2 =10;
int ir_car3 =9;
int ir_car4 =8;
int ir_car5 =7;
int ir_car6 =6;
int c2 =5;
int c1 =4;
int slot=7;
int flag1=0;
int flag2=0;
 int S1=0,S2=0,S3=0,S4=0,S5=0,S6=0,C1=0,C2=0;
 int row = 0;
int col = 0;

void setup(){
  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);
  pinMode(ir_car4, INPUT);
  pinMode(ir_car5, INPUT);
  pinMode(ir_car6, INPUT);
  pinMode(c1, INPUT);
  pinMode(c2, INPUT);
  pinMode(ir_enter,INPUT);
  pinMode(ir_back,INPUT);

  myservo.attach(2);
  myservo.write(90);
  lcd.begin();  
  lcd1.begin(); 
lcd.setCursor (5,1);
lcd.print("Car parking ");
lcd.setCursor (8,2);
lcd.print("System");
delay (2000);
lcd.clear();  
Read_Sensor();
int total =S1+S2+S3+S4+S5+S6;
slot=slot-total;

Serial.begin(9600);
  // Wire.setClock(10000);

}
//syntax :- lcd(RS,Enable,D4,D5,D6,D7);




void loop() {



  


Read_Sensor();
  lcd.setCursor (2,0);
if(S1==1){lcd.print("S1:FULL ");}
      else{lcd.print("S1:FREE");}

 lcd.setCursor (12,0);
 if(S2==1){lcd.print("S2:FULL");}
  else{lcd.print("S2:FREE");}
lcd.setCursor (2,1);
  if(S3==1){lcd.print("S3:FULL ");}
      else{lcd.print("S3:FREE");}

 lcd.setCursor (12,1);
 if(S4==1){lcd.print("S4:FULL");}
  else{lcd.print("S4:FREE");}
lcd.setCursor (2,2);
  if(S5==1){lcd.print("S5:FULL ");}
      else{lcd.print("S5:FREE");}

 lcd.setCursor (12,2);
 if(S6==1){lcd.print("S6:FULL");}
  else{lcd.print("S6:FREE");}

lcd.setCursor (2,3);
  if(C1==1){lcd.print("C1:FULL ");}
      else{lcd.print("C1:FREE");}

 lcd.setCursor (12,3);
 if(C2==1){lcd.print("C2:FULL");}
  else{lcd.print("C2:FREE");}

  if(digitalRead (ir_enter) == 0 && flag1==0){
  if (slot>0){
flag1=1;
if(flag2==0){
  myservo.write(180); 
  slot=slot-1;
}
}else{
lcd.clear();
lcd.print("No Parking Slot");  

delay(1500);
lcd.clear();
}  
}

if(digitalRead (ir_back) == 0 && flag2==0){flag2=1;
if(flag1==0){myservo.write(180);
slot=slot+1;
 }
 }

 if(flag1==1 && flag2==1){
 delay (1000);
 myservo.write(90);
 flag1=0, flag2=0;
 }

  if(Serial.available() > 0) //1st if open
  {
    while(Serial.available())
        {
          mtlb_data = Serial.read();
          if(mtlb_data == '#')
            {
              lcd1.clear();
              welcome();
              lcd1.setCursor(1,1);
              lcd1.print(' ');
              lcd1.setCursor(0,1);
            }
          else
            {
          
              col++;
              Serial.print(mtlb_data);
              

              lcd1.print(mtlb_data);
              
            }
        }
       
       lcd1.setCursor(--col,1);
       lcd1.print(' ');
       lcd1.setCursor(col,1);      
  }



}
void Read_Sensor(){
S1=0,S2=0,S3=0,S4=0,S5=0,S6=0,S6=0,C1=0,C2=0;

 if(digitalRead(ir_car1) == 0){S1=1;}
 if(digitalRead(ir_car2) == 0){S2=1;}
 if(digitalRead(ir_car3) == 0){S3=1;}
 if(digitalRead(ir_car4) == 0){S4=1;}
 if(digitalRead(ir_car5) == 0){S5=1;}
 if(digitalRead(ir_car6) == 0){S6=1;}
 if(digitalRead(c1) == 0){C1=1;}
 if(digitalRead(c2) == 0){C2=1;}


}

void welcome()
{
  col = 0; row = 0;
 
  lcd1.setCursor(col,++row);
}

