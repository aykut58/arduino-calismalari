#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD ekran pin tanımlaması yaptık

const int lm35= A3; //sensörün pin tanımlaması

float voltaj_deger=0; // kullanacağımız tanımlamalar
float sicaklik=0;
int gelen_veri=0;
void setup() {
  lcd.begin(16,2); // lcd erkan başlatıldı
}
void loop() {
  gelen_veri = analogRead(lm35); // sensörden veri okuduk
  voltaj_deger=(gelen_veri / 1023.0)* 5000; 
  sicaklik= voltaj_deger / 10.0;
  Serial.print(sicaklik);
  lcd.clear(); // ekran temizleme
  lcd.home(); //cursor başa alma
  lcd.print("sicaklik :"); 
  lcd.setCursor(0,1); // yazı koordinatı
  lcd.print(sicaklik); // degeri ekrana yazdırma
  Serial.print(sicaklik);
  delay(3000); // sonra ki veri girişi için bekleme süresi 
}
