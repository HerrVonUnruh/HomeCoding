#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <limits>

struct Gericht {
    std::string name;
    std::vector<std::string> zutaten;
};

class Essensplaner {
private:
    std::vector<Gericht> gerichte;
    std::random_device rd;
    std::mt19937 gen;

public:
    Essensplaner() : gen(rd()) {
        // Beispielgerichte initialisieren
        gerichte = {
            {"Spaghetti Bolognese",
             {"Spaghetti", "Hackfleisch", "Tomatensoße", "Zwiebeln", "Knoblauch", "Gewürze"}},
            {"Pizza Margherita",
             {"Pizzateig", "Tomatensoße", "Mozzarella", "Basilikum", "Olivenöl"}},
            {"Kartoffelsuppe",
             {"Kartoffeln", "Möhren", "Lauch", "Sellerie", "Brühe", "Gewürze"}},
            {"Schnitzel mit Pommes",
             {"Schweineschnitzel", "Kartoffeln", "Paniermehl", "Eier", "Zitrone", "Öl"}}
        };
    }

    void zeigeHauptmenu() {
        while (true) {
            std::cout << "\n=== Hauptmenü ===\n";
            std::cout << "1. Was esse ich heute?\n";
            std::cout << "2. Beenden\n";
            std::cout << "Ihre Wahl: ";

            int wahl;
            std::cin >> wahl;

            if (wahl == 2) {
                std::cout << "Auf Wiedersehen!\n";
                break;
            }
            else if (wahl == 1) {
                essensVorschlag();
            }
            else {
                std::cout << "Ungültige Eingabe!\n";
            }
        }
    }

private:
    void warteAufBenutzer() {
        std::cout << "\nDrücken Sie Enter, um fortzufahren...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    void essensVorschlag() {
        bool zufrieden = false;
        while (!zufrieden) {
            // Zufälliges Gericht auswählen
            std::uniform_int_distribution<> dis(0, gerichte.size() - 1);
            int index = dis(gen);

            std::cout << "\nVorschlag: " << gerichte[index].name << "\n\n";
            std::cout << "Sind Sie damit zufrieden?\n";
            std::cout << "1. Ja\n";
            std::cout << "2. Nein\n";
            std::cout << "Ihre Wahl: ";

            int wahl;
            std::cin >> wahl;

            if (wahl == 1) {
                zufrieden = true;
                std::cout << "\nZutaten für " << gerichte[index].name << ":\n";
                for (const auto& zutat : gerichte[index].zutaten) {
                    std::cout << "- " << zutat << "\n";
                }
                warteAufBenutzer(); // Neue Pausenfunktion
            }
        }
    }
};

int main() {
    Essensplaner planer;
    planer.zeigeHauptmenu();
    return 0;
}