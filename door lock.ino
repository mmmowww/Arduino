#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для LCD 1602
#include <Keypad.h>
#include <Servo.h>
#include <SPI.h>
#include <SD.h>

File myFILE;

LiquidCrystal_I2C lcd(0x27,16,2); // присваиваем имя lcd для дисплея 20х2
Servo ser1; //////////////////////////////////////////////////////////////////////////////////////////

void setup() // процедура setup
{
  lcd.init(); // инициализация LCD дисплея
  lcd.backlight(); // включение подсветки дисплея
  lcd.setCursor(1,1); // ставим курсор на 1 символ первой строки
  lcd.print("D"); // печатаем сообщение на первой строке
  lcd.setCursor(2,1); 
  lcd.print("o"); 
  lcd.setCursor(3,1); 
  lcd.print("r");
  lcd.setCursor(4,1); 
  lcd.print("e");
  lcd.setCursor(5,1); 
  lcd.print(" "); 
  lcd.setCursor(6,1); 
  lcd.print("C");
  lcd.setCursor(7,1); 
  lcd.print("l");
  lcd.setCursor(8,1); 
  lcd.print("o");
  lcd.setCursor(9,1); 
  lcd.print("s");
  lcd.setCursor(10,1); 
  lcd.print("e");
  //////////////////////////////////////////////
  int BUT = 8; // Датчик закрытия , открытия двери
  pinMode(BUT, INPUT); // Проверяем закрыта ли дверь вообще
  /////////////////////////////////////////////
  int key; // Ключ пользователя
  int lock; // Замок
  
}

void loop() // процедура loop
{   int BUT = 8; // Датчик закрытия , открытия двери
    int key; // Ключ пользователя
    int lock; // Замок
  if(BUT != HIGH){
    // Пока дверца открыта
ser1.write(105);// Дверь открыта
  lcd.setCursor(1,1); 
  lcd.print("D"); 
  lcd.setCursor(2,1); 
  lcd.print("o"); 
  lcd.setCursor(3,1); 
  lcd.print("r");
  lcd.setCursor(4,1); 
  lcd.print("e");
  lcd.setCursor(5,1); 
  lcd.print(" "); 
  lcd.setCursor(6,1); 
  lcd.print("O");
  lcd.setCursor(7,1); 
  lcd.print("P");
  lcd.setCursor(8,1); 
  lcd.print("E");
  lcd.setCursor(9,1); 
  lcd.print("N");
  
    
}
else
{
  lcd.setCursor(1,1); 
  lcd.print("D"); 
  lcd.setCursor(2,1); 
  lcd.print("o"); 
  lcd.setCursor(3,1); 
  lcd.print("r");
  lcd.setCursor(4,1); 
  lcd.print("e");
  lcd.setCursor(5,1); 
  lcd.print(" "); 
  lcd.setCursor(6,1); 
  lcd.print("C");
  lcd.setCursor(7,1); 
  lcd.print("l");
  lcd.setCursor(8,1); 
  lcd.print("o");
  lcd.setCursor(9,1); 
  lcd.print("s");
  lcd.setCursor(10,1); 
  lcd.print("e"); 
    if(key!=lock)  // Попытка открыть замок при момощи шыфра
    {
    ser1.write(360); // Дверь закрыта
    delay(1500);
      
       
      
      }else{
        ser1.write(105);// Дверь открыта
        
        
        };
    
    
    }


}

// Подкрутить ввод кода при помощи клавиши
// Подкрутить считываение "Key" из памяти на флешки

