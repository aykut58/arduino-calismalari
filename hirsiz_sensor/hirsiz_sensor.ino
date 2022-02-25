int yesil=3; // devrede kullandığımız elemanların pin atamalarını yaptık
int kirmizi=4;
int pir_sensor=2;
int buzzer=10;
int dugme1=11;
int dugme2 =12;
bool alarm=false;

void setup() {
  pinMode(yesil,OUTPUT);// giriş çıkış birimlerini belirledik.
  pinMode(kirmizi,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(pir_sensor,INPUT);
  pinMode(dugme1,INPUT);
  pinMode(dugme1,INPUT);
  Serial.begin(9600);

}

void loop() {
if(digitalRead(dugme1)==HIGH) // devre aktif olması için basılması gereken düğme tanımlı
{
  alarm=true; delay(5000);  
}
if(digitalRead(dugme2)==HIGH)// devre kapatılması için gereken düğme tanımlı
{
  alarm=false;
}
if(alarm==true)
{
  digitalWrite(yesil,HIGH);// devrenin çalıştığını gösteriyor
  digitalWrite(kirmizi,LOW);// devrenin kapalı olduğunu gösteriyor.
  if(digitalRead(pir_sensor)==HIGH)// sensör hareketalgılarsa
  {
    while(digitalRead(dugme2)==LOW)// düğme2 kapalı olana kadar buzzer ses çıkarıyor.
    {
      digitalWrite(buzzer,HIGH);
      delay(250);
      digitalWrite(buzzer,LOW);
      delay(250);
    }
  }
}
else{
  digitalWrite(yesil,LOW); // devre kapatıldığında olması gereken konum
  digitalWrite(kirmizi,HIGH);
}
}
