#include <SD.h>;
//#include <write.h>;
// Pins
// 3.3 V
// MOSI - 11
// MISO - 12
// SCK  - 13
// CS   - 10
File myFile;
 
void setup()
{
  Serial.begin(9600);
   while (!Serial) {
    ; //Ждём инициализации серийного порта. Нужно для Leonardo
  }
 
  Serial.print("Установка...");
  // Магия. Этот вывод должен быть настроен как выход.
  // Иначе, некоторые функции могут не работать.
  pinMode(10, OUTPUT);
 
  if (!SD.begin(4)) {
    Serial.println("Нет подключения!");
    return;
  }
  Serial.println("Подключение умерло");
 
  if (SD.exists("example1.txt")) {
    Serial.println("example1.txt exists.");
  }
  else {
    Serial.println("example1.txt doesn't exist.");
  }
 
  //Откроем новый файл и сразу же закроем его:
  Serial.println("Открыли и закрыли фаел");
  myFile = SD.open("example1.txt", FILE_WRITE);
  myFile.close();
 
  //Проверяем, создан ли файл:
  if (SD.exists("Проверка есть ли он")) {
    Serial.println("example1.txt exists.");
  }
  else {
    Serial.println("Его нет");
  }
 /*
  //Удаляем файл:
  Serial.println("Удаляем фаел");
  SD.remove("example.txt");
 
  if (SD.exists("example.txt")){
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");
  }
*/
}

 
void loop()
{
  //Тут ничего не происходит
}
// Думаю как подключить клавиатуру, и как осмысленно видо изменить код но так чтобы он работал
