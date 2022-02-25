int lm35Pin = A0; // sıcaklık sensörü ve led lamba tanımlaması yapıldı.
int led = 8;
#define buzzer 9

int zaman = 100; // değişken tanımlamaları. sıcaklık kontrolü içi istenilen süre
int okunan_deger=0; 
float sicaklik_gerilim = 0;
float sicaklik = 0;
void setup() {
  pinMode(led,OUTPUT); // led ve buzzer için çıkış pinleri veriliyor.
  pinMode(buzzer,OUTPUT);
}

void loop() {
  okunan_deger=analogRead(lm35Pin); // sensörden veri okuma
  sicaklik_gerilim=(5000.0 / 1023.0) * okunan_deger; // sensörden gelen vseriyi sıcaklık gerilimine eşitliyoruz.
  sicaklik=sicaklik_gerilim/10.0;
  Serial.println(sicaklik);
  if(sicaklik >= 32){ // gelen sıcaklık değeri 32 ve üzerine ise buzzer ve led lamba çalışır.
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    delay(zaman); // led lamba ve buzzer çalışma süresi 
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
    delay(zaman);
  }
    else{
      digitalWrite(led,LOW);
      digitalWrite(buzzer,LOW);
      }
    

}
