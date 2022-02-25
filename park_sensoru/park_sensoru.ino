#define echoPin 6 // devredeki pinlerin ataması yapılmaktadır.
#define trigPin 7
#define buzzerPin 8

int maximumRange = 50;//sensörün ölçüsüne göre max ve min mesafe belirledik.
int minimumRange = 0;

void setup() {
  pinMode(trigPin, OUTPUT);// giriş çıkış pin atamaları yapıldı.
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  
  int olcum = mesafe(maximumRange, minimumRange); 
  melodi(olcum * 10 );
}

int mesafe( int maxrange, int minrange)
{
  long duration, distance; // burada int tanımlasını aşan değerlere ulaşınca kullanılması için tanımladık.

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2); // arduıno bekleme süresi
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH); // echoPin'i HIGH oldugğuna kadar geçen süreyi hesaplıyor.
  distance = duration / 58.2; // geçen süreyi sesin hızına bölerek uzaklığı buluyoruz
  delay(50);// bekleme süresi koyarak gelen mesafeyi istedğimiz aralıkta olup olmadığını öğreniyoruz.

  if(distance >= maxrange || distance <= minrange)
  return 0; // gelen mesafe istediğimiz aralıkta değilse 0 döenecek yoksa distance dönecek
  return distance;
}
int melodi( int dly)
{
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
