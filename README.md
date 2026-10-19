
# 🚦 Inteligentna sygnalizacja świetlna Arduino

## 📌 Opis projektu

Projekt przedstawia system sygnalizacji świetlnej oparty na platformie **Arduino**, obsługujący cztery kierunki ruchu. System wykorzystuje cztery czujniki do wykrywania sygnałów i steruje sygnalizatorami w zależności od ich aktywności.

Celem projektu jest stworzenie prostego modelu inteligentnej sygnalizacji świetlnej, która przydziela zielone światło jednemu kierunkowi w danym momencie.

## ⚙️ Funkcje

- Obsługa czterech kierunków ruchu.
- Obsługa czterech czujników cyfrowych.
- Sterowanie ośmioma diodami LED.
- Pomiar czasu za pomocą funkcji `millis()`.
- Dodatkowy czas wynoszący **2000 ms (2 sekundy)**.
- Kontrola stanów świateł czerwonych i zielonych.
- Odczyt czujników za pomocą `digitalRead()`.
- Sterowanie diodami za pomocą `digitalWrite()`.

## 🧰 Wykorzystane komponenty

- Arduino Uno lub kompatybilna płytka.
- 4 czerwone diody LED.
- 4 zielone diody LED.
- 4 czujniki cyfrowe.
- Rezystory ograniczające prąd diod LED.
- Płytka stykowa.
- Przewody połączeniowe.

## 🔌 Schemat połączeń

### Diody LED

| Kierunek | Czerwona dioda | Zielona dioda |
|---|---|---|
| 1 | Pin 2 | Pin 3 |
| 2 | Pin 4 | Pin 5 |
| 3 | Pin 6 | Pin 7 |
| 4 | Pin 8 | Pin 9 |

### Czujniki

| Czujnik | Pin Arduino |
|---|---|
| Czujnik 1 | Pin 10 |
| Czujnik 2 | Pin 11 |
| Czujnik 3 | Pin 12 |
| Czujnik 4 | Pin 13 |

**Uwaga:** Diody LED należy podłączyć przez rezystory. Sposób podłączenia czujników zależy od zastosowanych modułów.

## 🧠 Zasada działania

1. Arduino odczytuje stany wszystkich czterech czujników.
2. Po wykryciu stanu `HIGH` zapisywany jest aktualny czas dla danego czujnika.
3. Wszystkie światła czerwone zostają włączone, a zielone wyłączone.
4. Program sprawdza warunki czasowe dla każdego kierunku.
5. Jeżeli warunki zostaną spełnione, odpowiednie światło zielone zostaje włączone.
6. Pętla programu powtarza się z opóźnieniem 50 ms.

## 💻 Technologie

- **Język programowania:** C++
- **Platforma:** Arduino
- **Środowisko:** Arduino IDE
- **Biblioteki:** standardowe funkcje Arduino

## 🚀 Uruchomienie projektu

1. Pobierz repozytorium na komputer.
2. Otwórz plik `.ino` w Arduino IDE.
3. Podłącz elementy zgodnie z tabelami.
4. Wybierz odpowiednią płytkę Arduino i port.
5. Wgraj program na mikrokontroler.
6. Sprawdź działanie czujników oraz świateł.

## ⚠️ Ograniczenia

- Projekt ma charakter edukacyjny i demonstracyjny.
- Program nie obsługuje żółtych świateł ani faz przejściowych.
- Jednoczesne zgłoszenia z kilku czujników mogą wpływać na wybór kierunku.
- Przy stale aktywnym czujniku czas wykrycia jest ciągle aktualizowany, co może wpływać na działanie sygnalizacji.
- System nie jest przeznaczony do sterowania rzeczywistym ruchem drogowym.

## 🔮 Możliwe rozszerzenia

- Dodanie żółtych świateł.
- Wprowadzenie minimalnego i maksymalnego czasu zielonego.
- Obsługa kolejkowania zgłoszeń z czujników.
- Dodanie wyświetlacza pokazującego aktualny stan sygnalizacji.
- Przygotowanie wizualizacji w Tinkercad lub Wokwi.

## 👨‍💻 Autor

Projekt edukacyjny wykorzystujący platformę Arduino.

## 📄 Licencja

Projekt może zostać udostępniony na wybranej licencji open source, np. MIT.
