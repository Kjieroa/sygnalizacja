const int czerwony1 = 2;
const int zielony1  = 3;
const int czerwony2 = 4;
const int zielony2  = 5;
const int czerwony3 = 6;
const int zielony3  = 7;
const int czerwony4 = 8;
const int zielony4  = 9;

const int czujnik1 = 10;
const int czujnik2 = 11;
const int czujnik3 = 12;
const int czujnik4 = 13;

unsigned long czasZielonego[4] = {0, 0, 0, 0};
const unsigned long dodatkowyCzas = 2000;

void setup()
{
  pinMode(czerwony1, OUTPUT);
  pinMode(zielony1, OUTPUT);
  pinMode(czerwony2, OUTPUT);
  pinMode(zielony2, OUTPUT);
  pinMode(czerwony3, OUTPUT);
  pinMode(zielony3, OUTPUT);
  pinMode(czerwony4, OUTPUT);
  pinMode(zielony4, OUTPUT);

  pinMode(czujnik1, INPUT);
  pinMode(czujnik2, INPUT);
  pinMode(czujnik3, INPUT);
  pinMode(czujnik4, INPUT);
}

void loop()
{
  unsigned long teraz = millis();

  if (digitalRead(czujnik1) == HIGH)
    czasZielonego[0] = teraz;

  if (digitalRead(czujnik2) == HIGH)
    czasZielonego[1] = teraz;

  if (digitalRead(czujnik3) == HIGH)
    czasZielonego[2] = teraz;

  if (digitalRead(czujnik4) == HIGH)
    czasZielonego[3] = teraz;

  // Najpierw wszystkie œwiat³a czerwone
  digitalWrite(czerwony1, HIGH);
  digitalWrite(zielony1, LOW);
  digitalWrite(czerwony2, HIGH);
  digitalWrite(zielony2, LOW);
  digitalWrite(czerwony3, HIGH);
  digitalWrite(zielony3, LOW);
  digitalWrite(czerwony4, HIGH);
  digitalWrite(zielony4, LOW);

  // Zielone tylko dla jednego kierunku

  if (czasZielonego[0] != 0 &&
      teraz - czasZielonego[0] < dodatkowyCzas &&
      teraz - czasZielonego[1] >= dodatkowyCzas &&
      teraz - czasZielonego[2] >= dodatkowyCzas &&
      teraz - czasZielonego[3] >= dodatkowyCzas)
  {
    digitalWrite(czerwony1, LOW);
    digitalWrite(zielony1, HIGH);
  }
  else if (czasZielonego[1] != 0 &&
           teraz - czasZielonego[1] < dodatkowyCzas &&
           teraz - czasZielonego[0] >= dodatkowyCzas &&
           teraz - czasZielonego[2] >= dodatkowyCzas &&
           teraz - czasZielonego[3] >= dodatkowyCzas)
  {
    digitalWrite(czerwony2, LOW);
    digitalWrite(zielony2, HIGH);
  }
  else if (czasZielonego[2] != 0 &&
           teraz - czasZielonego[2] < dodatkowyCzas &&
           teraz - czasZielonego[0] >= dodatkowyCzas &&
           teraz - czasZielonego[1] >= dodatkowyCzas &&
           teraz - czasZielonego[3] >= dodatkowyCzas)
  {
    digitalWrite(czerwony3, LOW);
    digitalWrite(zielony3, HIGH);
  }
  else if (czasZielonego[3] != 0 &&
           teraz - czasZielonego[3] < dodatkowyCzas &&
           teraz - czasZielonego[0] >= dodatkowyCzas &&
           teraz - czasZielonego[1] >= dodatkowyCzas &&
           teraz - czasZielonego[2] >= dodatkowyCzas)
  {
    digitalWrite(czerwony4, LOW);
    digitalWrite(zielony4, HIGH);
  }

  delay(50);
}
