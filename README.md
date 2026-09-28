# 🚦 Sygnalizacja świetlna Arduino

Prosty projekt sygnalizacji świetlnej wykonany na Arduino.

Projekt składa się z **4 stron sygnalizacji**. Każda strona posiada:
- 🔴 czerwone światło
- 🟢 zielone światło

W danym momencie **tylko jedna strona ma zielone światło**, a pozostałe trzy mają czerwone.

---

## 🚦 Jak działa?

Światła zmieniają się w następującej kolejności:

```text
Strona 1 → Strona 2 → Strona 3 → Strona 4 → 🔄
