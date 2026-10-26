# Inteligentna sygnalizacja świetlna Arduino

## Opis projektu

Projekt przedstawia system sygnalizacji świetlnej oparty na Arduino. System wykorzystuje cztery czujniki, które sterują czterema kierunkami sygnalizacji świetlnej.

Po wykryciu sygnału z czujnika odpowiedni kierunek otrzymuje zielone światło, a pozostałe kierunki mają światło czerwone.

## Wykorzystane elementy

- Arduino
- 4 czerwone diody LED
- 4 zielone diody LED
- 4 czujniki cyfrowe
- Rezystory
- Przewody połączeniowe
- Płytka stykowa

## Podłączenie pinów

| Element | Pin Arduino |
|---|---|
| Czerwone światło 1 | 2 |
| Zielone światło 1 | 3 |
| Czerwone światło 2 | 4 |
| Zielone światło 2 | 5 |
| Czerwone światło 3 | 6 |
| Zielone światło 3 | 7 |
| Czerwone światło 4 | 8 |
| Zielone światło 4 | 9 |
| Czujnik 1 | 10 |
| Czujnik 2 | 11 |
| Czujnik 3 | 12 |
| Czujnik 4 | 13 |

## Zasada działania

1. Po uruchomieniu wszystkie światła ustawiane są na czerwone.
2. Arduino odczytuje stany czterech czujników.
3. Zmiana stanu czujnika z `LOW` na `HIGH` aktywuje żądanie zielonego światła.
4. Program zapisuje czas wykrycia za pomocą funkcji `millis()`.
5. Program wybiera pierwszy aktywny kierunek, którego żądanie nie przekroczyło 2 sekund.
6. Wybrany kierunek otrzymuje zielone światło, a pozostałe kierunki czerwone.
7. Po upływie 2 sekund żądanie zostaje wyłączone.

## Wykrywanie zmian stanu

Program wykrywa zmiany stanów czujników poprzez porównywanie aktualnego odczytu z poprzednim.

- `CHANGE` – dowolna zmiana stanu.
- `RISING` – przejście z `LOW` na `HIGH`.
- `FALLING` – przejście z `HIGH` na `LOW`.

Zmiany są wykrywane programowo w funkcji `loop()`. Program nie korzysta ze sprzętowych przerwań `attachInterrupt()`.

## Wykorzystane funkcje

- `pinMode()` – konfiguracja pinów Arduino.
- `digitalRead()` – odczyt stanu czujników.
- `digitalWrite()` – sterowanie światłami.
- `millis()` – pomiar czasu działania programu.

## Konfiguracja czasu

Czas działania żądania określa zmienna:

```cpp
const unsigned long dodatkowyCzas = 2000;
