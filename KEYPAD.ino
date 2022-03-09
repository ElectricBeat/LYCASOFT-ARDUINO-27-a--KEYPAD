#include <LiquidCrystal.h> 
LiquidCrystal lcd(0,1,2, 3, 4, 5);

int row[]={6,7,8,9};
int col[]={10,11,12,13};

int i,j; 
int col_scan;

void setup()
{
  lcd.begin(16, 2);
    
  lcd.setCursor(0,0); 
  lcd.print("SRI ELECTRONIC & EMBEDDED SOLUTIONS");
  lcd.setCursor(0,1); 
  lcd.print("Keypressed:");  
  delay(1000);
    
  for(i=0;i<=3;i++)
  {
    pinMode(row[i],OUTPUT);
    pinMode(col[i],INPUT);
    digitalWrite(col[i],HIGH);
  } 
}

void loop()
{ 
  for(i=0; i<=3; i++)
  {
    digitalWrite(row[0],HIGH);
    digitalWrite(row[1],HIGH);
    digitalWrite(row[2],HIGH);
    digitalWrite(row[3],HIGH);
    digitalWrite(row[i],LOW);
    
    for(j=0; j<=3; j++)
    {
      col_scan=digitalRead(col[j]);
      if(col_scan==LOW)
      {
        lcd.setCursor(11,1);  
        keypress(i,j);  
        delay(300);
      }
    }
  }
}

void keypress(int i, int j)
{
  if(i==0&&j==0)
  lcd.print("D");
  if(i==0&&j==1)
  lcd.print("C");
  if(i==0&&j==2)
  lcd.print("B");
  if(i==0&&j==3)
  lcd.print("A");
  if(i==1&&j==0)
  lcd.print("#");
  if(i==1&&j==1)
  lcd.print("9");
  if(i==1&&j==2)
  lcd.print("6");
  if(i==1&&j==3)
  lcd.print("3");
  if(i==2&&j==0)
  lcd.print("0");
  if(i==2&&j==1)
  lcd.print("8");
  if(i==2&&j==2)
  lcd.print("5");
  if(i==2&&j==3)
  lcd.print("2");
  if(i==3&&j==0)
  lcd.print("*");
  if(i==3&&j==1)
  lcd.print("7");
  if(i==3&&j==2)
  lcd.print("4");
  if(i==3&&j==3)
  lcd.print("1");
}
