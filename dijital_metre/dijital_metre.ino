 #include <LiquidCrystal.h> // LCD ekran kullanımı için kütüphane ekledik 

int trigPin = 7;// sensör pinlerini tanımladık 
int echoPin = 6;
int sure; // ullandığımız değişken tanımı
int uzaklik;

int rs = 12, en=11, d4=5, d5=4 , d6=3, d7=2; // LCD ekran pinlerini tanımladık
LiquidCrystal lcd(rs, en , d4, d5, d6, d7);
void setup() {

  pinMode(trigPin, OUTPUT); // giriş çıkış pinleri tanımlandı
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);
  

}

void loop() {
  

  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin , HIGH, 11600);

  uzaklik= sure*0.0345/2; // sensörün veriyi alma süresini ve hızına göre mesafe ölçme formulu

  delay(250);

  lcd.clear();
  lcd.setCursor(0,0); //yazının koordinatını ayarlıyoruz
  lcd.print("Uzaklik : ");
  lcd.setCursor(0,1);
  lcd.print(uzaklik); // bulunan değeri yazdırıyoruz.
  lcd.print("cm");

}
