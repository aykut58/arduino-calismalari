#include <LiquidCrystal.h> // lcd kütüphanesi belirlendi
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // lcd ekran pinleri ayarlandı
const int  trig = 6; // diğer pin tanımlamaları
const int   echo = 7;
const int kalibButon = 8;
const int olcmeButon  =9;
int sure = 0; // kullanılan değişken tanımlamaları
int mesafe = 0;
int ilkmesafe;

void setup() {
   lcd.begin(16, 2); // erkan tanımlandı
  pinMode(trig, OUTPUT); // giriş çkış pinleri belirlendi
  pinMode(echo, INPUT);
  pinMode(kalibButon, INPUT);
  pinMode(olcmeButon, INPUT);

  while (digitalRead(kalibButon) == LOW) // kalibrasyon butonuna basılmadığı zaman aşaıda yer alan kod çalışır
{
    lcd.setCursor(2, 0); // kalibrasyon yazısı e pozisyonu ayarlandı
    lcd.print("KALiBRASYON iCiN");
    lcd.setCursor(2, 1);
    lcd.print(" BUTONA BASINIZ ");
    delay(100);

    if (digitalRead(kalibButon) == HIGH) //kalibrasyon sonrası için
{
      delay(50);
      ilkmesafe = mesafeolc();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("KALiBRASYON");
      lcd.setCursor(0, 1);
      lcd.print("YAPILDI : ");
      lcd.print(ilkmesafe); // kalibrasyon mesafesi ekrana veriliyor
      delay(2000);
      lcd.clear();
      break;
    }
  }
}
void loop() 
{
  if (digitalRead(olcmeButon) == HIGH) // ölçüm butonuna basılırsa 
{
    lcd.setCursor(0, 0);
    lcd.print("BOYUNUZ");
    lcd.setCursor(0, 1);
    int boy = ilkmesafe - mesafeolc(); / tanımlı işlem yapılıyor
    lcd.print(boy); // by belirleniyor
    lcd.print("cm");
    lcd.setCursor(0, 2); // ekrana yazılan yazının pozisyonunu
    delay(2000);
    lcd.clear(); 
  }
    else 
{
      lcd.setCursor(0, 0); // ölçüm butonuna basılmazsa çalışan kod parçacığı
      lcd.print("   OLCUM iCiN   ");
      lcd.setCursor(0, 1);
      lcd.print(" BUTONA BASINIZ ");
      delay(100);
      lcd.clear();
    }
  }

  int mesafeolc() 
{
    digitalWrite(trig, HIGH);
    delay(1);
    digitalWrite(trig, LOW);
    sure = pulseIn(echo, HIGH);
    mesafe = (sure / 2) / 27.6;
    return mesafe;
  }
