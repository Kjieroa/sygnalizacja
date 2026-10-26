
const int czerwony1 = 2;
const int zielony1  = 3;
const int czerwony2 = 4;
const int zielony2  = 5;
const int czerwony3 = 6;
const int zielony3  = 7;
const int czerwony4 = 8;
const int zielony4  = 9;

const int czujniki[4] = {10, 11, 12, 13};

bool poprzedniStan[4] = {LOW, LOW, LOW, LOW};
bool wykryto[4] = {false, false, false, false};

unsigned long czasZielonego[4] = {0, 0, 0, 0};
const unsigned long dodatkowyCzas = 2000;

void setup() {
  pinMode(czerwony1, OUTPUT);
  pinMode(zielony1, OUTPUT);
  pinMode(czerwony2, OUTPUT);
  pinMode(zielony2, OUTPUT);
  pinMode(czerwony3, OUTPUT);
  pinMode(zielony3, OUTPUT);
  pinMode(czerwony4, OUTPUT);
  pinMode(zielony4, OUTPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(czujniki[i], INPUT);
    poprzedniStan[i] = digitalRead(czujniki[i]);
  }

  // Pocz¹tkowo wszystkie œwiat³a czerwone
  digitalWrite(czerwony1, HIGH);
  digitalWrite(zielony1, LOW);
  digitalWrite(czerwony2, HIGH);
  digitalWrite(zielony2, LOW);
  digitalWrite(czerwony3, HIGH);
  digitalWrite(zielony3, LOW);
  digitalWrite(czerwony4, HIGH);
  digitalWrite(zielony4, LOW);
}

void loop() {
  unsigned long teraz = millis();

  // Wykrywanie zmian na czujnikach
  for (int i = 0; i < 4; i++) {
    bool aktualnyStan = digitalRead(czujniki[i]);

    // CHANGE: nast¹pi³a zmiana stanu
    if (aktualnyStan != poprzedniStan[i]) {

      // RISING: LOW -> HIGH
      if (aktualnyStan == HIGH) {
        czasZielonego[i] = teraz;
        wykryto[i] = true;
      }

      // FALLING: HIGH -> LOW
      else {
        // Zbocze opadaj¹ce wykryte
      }

      poprzedniStan[i] = aktualnyStan;
    }
  }

  // Wyznaczenie kierunku, który ma dostaæ zielone
  int aktywny = -1;

  for (int i = 0; i < 4; i++) {
    if (wykryto[i] &&
        teraz - czasZielonego[i] < dodatkowyCzas) {
      aktywny = i;
      break;
    }
  }

  // Ustawienie wszystkich œwiate³
  digitalWrite(czerwony1, aktywny != 0);
  digitalWrite(zielony1, aktywny == 0);

  digitalWrite(czerwony2, aktywny != 1);
  digitalWrite(zielony2, aktywny == 1);

  digitalWrite(czerwony3, aktywny != 2);
  digitalWrite(zielony3, aktywny == 2);

  digitalWrite(czerwony4, aktywny != 3);
  digitalWrite(zielony4, aktywny == 3);

  // Po up³ywie 2 sekund koñczymy ¿¹danie
  for (int i = 0; i < 4; i++) {
    if (wykryto[i] &&
        teraz - czasZielonego[i] >= dodatkowyCzas) {
      wykryto[i] = false;
    }
  }
}
