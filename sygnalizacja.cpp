const int czerwony1 = 2;
const int zielony1  = 3;
const int czerwony2 = 4;
const int zielony2  = 5;
const int czerwony3 = 6;
const int zielony3  = 7;
const int czerwony4 = 8;
const int zielony4  = 9;

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
}

void loop()
{
  digitalWrite(zielony1, HIGH);
  digitalWrite(czerwony1, LOW);

  digitalWrite(zielony2, LOW);
  digitalWrite(czerwony2, HIGH);

  digitalWrite(zielony3, LOW);
  digitalWrite(czerwony3, HIGH);

  digitalWrite(zielony4, LOW);
  digitalWrite(czerwony4, HIGH);

  delay(3000);

  digitalWrite(zielony1, LOW);
  digitalWrite(czerwony1, HIGH);

  digitalWrite(zielony2, HIGH);
  digitalWrite(czerwony2, LOW);

  digitalWrite(zielony3, LOW);
  digitalWrite(czerwony3, HIGH);

  digitalWrite(zielony4, LOW);
  digitalWrite(czerwony4, HIGH);

  delay(3000);

  digitalWrite(zielony1, LOW);
  digitalWrite(czerwony1, HIGH);

  digitalWrite(zielony2, LOW);
  digitalWrite(czerwony2, HIGH);

  digitalWrite(zielony3, HIGH);
  digitalWrite(czerwony3, LOW);

  digitalWrite(zielony4, LOW);
  digitalWrite(czerwony4, HIGH);

  delay(3000);


  digitalWrite(zielony1, LOW);
  digitalWrite(czerwony1, HIGH);

  digitalWrite(zielony2, LOW);
  digitalWrite(czerwony2, HIGH);

  digitalWrite(zielony3, LOW);
  digitalWrite(czerwony3, HIGH);

  digitalWrite(zielony4, HIGH);
  digitalWrite(czerwony4, LOW);

  delay(3000);
}
