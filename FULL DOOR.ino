#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_I2C.h> // подключаем библиотеку для LCD 1602
#include <Keypad.h>
#include <Servo.h>
#include <SPI.h>
#include <SD.h>
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; 
byte colPins[COLS] = {8, 7, 6}; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
// Подключение флеш памяти
//
// Pins
// 3.3 V
// MOSI - 11
// MISO - 12
// SCK  - 13
// CS   - 10
File myFile;
char key = keypad.getKey();// Переменная для считывания кода
Servo ser1; // Переменная контроля угла поворота серво привада
void setup() {
  Serial.begin(9600);
   while (!Serial) {
    ; //Ждём инициализации серийного порта. Нужно для Leonardo

}
Serial.print("Установка...");
  // Этот вывод должен быть настроен как выход.
  // Иначе, некоторые функции могут не работать.
  pinMode(10, OUTPUT);
  pinMode(8,INPUT); // Переменная на дачик
  myFile = SD.open("example1.txt", FILE_WRITE); // Открываем фаел с ключём для открытия двери
  lcd.init(); // инициализация LCD дисплея 
}
void loop() {
  char key = keypad.getKey();// Переменная для считывания кода
  int door=digitalRead(8); // Датчик закрытия , открытия двери. 
 // Датчик у двери должен быть под наприжением когда дверь закрыта 
  int key; // Ключ пользователя
  int lock; // Замок
  ////////////
 ///Приведствие пользователя
//////////////
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
  ser1.write(275);// Так серво привод закрывает дверь (Под таким углом)
  if(door!=0)
  {
    if(key=lock)
     {
ser1.write(105);// Дверь открыта передвиним серво привод так что бы он открыл дверь
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
   int i=0;
  for(0;10;i++) // Открыть то мы её открыли, теперь надо закрыть
    { delay(2000);                        // Задержка в 2 секунды
      if(door!=1)                         //  Ожыдание что на датчик подёт наприжение
      { ser1.write(105); }                //  Серво в открытом состоянии
      else { ser1.write(275);}  }         // Серво в закрытом состоянии выводим его сразуже через 20 секунд
    }
  return 0;
  }
    else
    {
lcd.setCursor(1,1);                      // 
  lcd.print("E");                        //Если ввели не правильный код
  lcd.setCursor(2,1);                    //
  lcd.print("R");                        //
  lcd.setCursor(3,1); 
  lcd.print("O");
  lcd.setCursor(4,1); 
  lcd.print("R");
  return 0;
  
  }
    
    
    
    
    } 

