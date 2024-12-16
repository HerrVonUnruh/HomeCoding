// Hier werden verschiedene Bibliotheken eingebunden, die wir für das Programm brauchen:
#include <iostream>     // Für Ein- und Ausgabe (cout, cin)
#include <vector>       // Für dynamische Arrays (Listen)
#include <string>       // Für Text-Verarbeitung
#include <random>       // Für Zufallszahlen
#include <ctime>       // Für Zeitfunktionen
#include <limits>       // Für Grenzwerte von Datentypen
#include <locale>       // Für Spracheinstellungen (Umlaute etc.)

// Dieser Block ist speziell für Windows-Systeme
#ifdef _WIN32          // Wenn das Programm auf Windows läuft...
#include <windows.h>   // ...werden Windows-spezifische Funktionen eingebunden
#endif

// Definition einer Struktur (wie eine Schablone) für ein Gericht
struct Gericht {
    std::string name;                  // Name des Gerichts
    std::vector<std::string> zutaten;  // Liste der Zutaten
};

// Hauptklasse des Programms
class Essensplaner {
private:
    // Private Variablen (nur innerhalb der Klasse nutzbar):
    std::vector<Gericht> gerichte;     // Liste aller verfügbaren Gerichte
    std::random_device rd;             // Gerät für echte Zufallszahlen
    std::mt19937 gen;                  // Zufallszahlengenerator

public:
    // Konstruktor: Wird aufgerufen, wenn ein neuer Essensplaner erstellt wird
    Essensplaner() : gen(rd()) {
        // Windows-spezifische Einstellung für UTF-8 (Umlaute)
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
#endif

        // Lokale Spracheinstellungen für Deutsch
        setlocale(LC_ALL, "de_DE.UTF-8");

        // Hier werden alle Gerichte mit ihren Zutaten definiert
        // Format: {"Name des Gerichts", {"Zutat1", "Zutat2", ...}}
        gerichte = {
        {"Schnitzel mit Rotkohl und Klößen oder Spargel",
         {"Schweineschnitzel", "Rotkohl", "Kartoffelklöße", "Spargel", "Paniermehl", "Eier", "Öl"}},
        {"Nudeln mit Tomatensoße",
         {"Nudeln", "Tomaten", "Zwiebeln", "Knoblauch", "Basilikum", "Olivenöl"}},
        {"Wurstgulasch",
         {"Wurstaufschnitt", "Paprika", "Zwiebeln", "Tomatenmark", "Brühe", "Gewürze"}},
        {"Jägerschnitzel mit Pilzsoße",
         {"Schweineschnitzel", "Champignons", "Zwiebeln", "Sahne", "Petersilie", "Öl"}},
        {"Rindergulasch",
         {"Rindfleisch", "Zwiebeln", "Paprika", "Tomatenmark", "Brühe", "Gewürze"}},
          {"Leber",
         {"Leber", "Zwiebeln", "Kartoffeln", "Milch", "Butter", "Mischgemüse"}},
          {"Karottensuppe",
         {"Karotten", "Zwiebeln", "Kartoffeln", "Butter", "Brühe", "Knoblauch"}},
          {"Hähnchenherzen",
         {"Hähnchenherzen", "Zwiebeln", "Kartoffeln", "Milch", "Brühe", "Gewürze"}},
        {"Rinderrouladen",
         {"Rindfleisch", "Speck", "Zwiebeln", "Senf", "Gurken", "Bindfaden"}},
        {"Lachs-Sahne-Spinat mit Nudeln",
         {"Lachs", "Spinat", "Sahne", "Nudeln", "Knoblauch", "Zwiebeln"}},
        {"Kohlrouladen",
         {"Weißkohl", "Hackfleisch", "Reis", "Zwiebeln", "Brühe", "Gewürze"}},
        {"Paprikageschnetzeltes",
         {"Schweinefleisch", "Paprika", "Zwiebeln", "Sahne", "Paprikapulver", "Reis"}},
        {"Fischstäbchen mit Spinat",
         {"Fischstäbchen", "Spinat", "Sahne", "Kartoffeln", "Muskat", "Öl"}},
        {"Eierkuchen",
         {"Eier", "Mehl", "Milch", "Zucker", "Salz", "Öl"}},
        {"Bouletten mit Mischgemüse",
         {"Hackfleisch", "Zwiebeln", "Brötchen", "Eier", "Gemüsemischung", "Gewürze"}},
        {"Tomaten-Mozzarella-Minutenschnitzel",
         {"Schweineschnitzel", "Tomaten", "Mozzarella", "Basilikum", "Öl"}},
        {"Pellkartoffeln mit Quark",
         {"Kartoffeln", "Quark", "Kräuter", "Zwiebeln", "Leinöl"}},
        {"Flammkuchen Brötchen",
         {"Brötchen", "Schmand", "Zwiebeln", "Speck", "Schnittlauch"}},
        {"Selbstmachpizza",
         {"Pizzateig", "Tomatensoße", "Käse", "Salami", "Champignons", "Paprika"}},
        {"Chili con Carne",
         {"Hackfleisch", "Kidneybohnen", "Mais", "Tomaten", "Paprika", "Gewürze"}},
        {"Burger",
         {"Burgerbrötchen", "Hackfleisch", "Salat", "Tomaten", "Zwiebeln", "Käse"}},
        {"Hot Dogs",
         {"Hotdog-Brötchen", "Würstchen", "Senf", "Ketchup", "Röstzwiebeln"}},
        {"Brokkoli Sahnesoße",
         {"Brokkoli", "Sahne", "Nudeln", "Zwiebeln", "Knoblauch", "Gewürze"}},
        {"Königsberger Klopse",
         {"Hackfleisch", "Kapern", "Sardellen", "Zitrone", "Mehl", "Kartoffeln"}},
        {"Senfeier",
         {"Eier", "Senf", "Mehl", "Butter", "Brühe", "Kartoffeln"}},
        {"Senfnudeln",
         {"Nudeln", "Senf", "Sahne", "Zwiebeln", "Speck", "Gewürze"}},
        {"Hühnerfrikassee",
         {"Hühnerfleisch", "Champignons", "Erbsen", "Möhren", "Sahne", "Reis"}},
        {"Kasslerbraten mit Sauerkraut",
         {"Kassler", "Sauerkraut", "Kartoffeln", "Zwiebeln", "Kümmel"}},
        {"Krustenbraten",
         {"Schweinebraten", "Knoblauch", "Kümmel", "Salz", "Bier", "Kartoffeln"}},
        {"Bratkartoffeln",
         {"Kartoffeln", "Zwiebeln", "Speck", "Öl", "Paprikapulver"}},
        {"Omlette",
         {"Eier", "Milch", "Käse", "Schinken", "Tomaten", "Kräuter"}},
        {"Carbonara",
         {"Spaghetti", "Speck", "Eier", "Parmesan", "Sahne", "Pfeffer"}},
        {"Spezialauflauf",
         {"Nudeln", "Hackfleisch", "Gemüse", "Käse", "Sahne", "Gewürze"}},
        {"gefüllte Paprika",
         {"Paprika", "Hackfleisch", "Reis", "Zwiebeln", "Tomatensoße", "Käse"}},
        {"Schinken Hackröllchen",
         {"Hackfleisch", "Schinken", "Zwiebeln", "Senf", "Gewürze"}},
        {"Champies mit Sahnesoße",
         {"Champignons", "Sahne", "Zwiebeln", "Petersilie", "Nudeln"}},
        {"Bratwurst mit Bratkartoffeln",
         {"Bratwurst", "Kartoffeln", "Zwiebeln", "Öl", "Gewürze"}},
        {"Käse-Lauch Suppe",
         {"Lauch", "Schmelzkäse", "Brühe", "Sahne", "Kartoffeln", "Zwiebeln"}},
        {"Schmorkohl",
         {"Weißkohl", "Hackfleisch", "Zwiebeln", "Brühe", "Kartoffeln", "Gewürze"}},
        {"Gebackene Bohnen mit Speck",
         {"Bohnen", "Speck", "Zwiebeln", "Tomatensoße", "Gewürze"}},
        {"Reispfanne",
         {"Reis", "Gemüse", "Fleisch", "Zwiebeln", "Gewürze", "Öl"}},
        {"Nudelpfanne",
         {"Nudeln", "Gemüse", "Fleisch", "Zwiebeln", "Gewürze", "Öl"}},
        {"Brat Mi Nudeln",
         {"Mie-Nudeln", "Gemüse", "Fleisch", "Sojasoße", "Ingwer", "Knoblauch"}},
        {"Blätterteig gefüllt / im Schlafrock",
         {"Blätterteig", "Würstchen", "Schinken", "Käse", "Ei"}},
        {"Schaschlik",
         {"Schweinefleisch", "Paprika", "Zwiebeln", "Speck", "Schaschliksoße"}},
        {"Lecho mit Schnitzel",
         {"Schnitzel", "Paprika", "Tomaten", "Zwiebeln", "Knoblauch", "Paprikapulver"}}
        };
    }

    // Zeigt das Hauptmenü an und verarbeitet Benutzereingaben
    void zeigeHauptmenu() {
        while (true) {  // Endlosschleife, bis der Benutzer das Programm beendet
            // Menüoptionen anzeigen
            std::cout << "\nEssensplaner ===\n";
            std::cout << "1. Zufaelliges Gericht vorschlagen\n";
            std::cout << "2. Programm beenden\n";
            std::cout << "Bitte waehlen Sie eine Option: ";

            int auswahl;  // Variable für die Benutzereingabe

            // Eingabeüberprüfung
            if (!(std::cin >> auswahl)) {
                // Wenn keine gültige Zahl eingegeben wurde:
                std::cout << "Ungültige Eingabe. Bitte geben Sie eine Zahl ein: ";
                std::cin.clear();                    // Fehlerflags zurücksetzen
                std::cin.ignore(10000, '\n');        // Eingabepuffer leeren
                continue;                            // Zurück zum Schleifenanfang
            }

            // Verarbeitung der Benutzereingabe
            switch (auswahl) {
            case 1:     // Wenn 1 eingegeben wurde
                system("cls");
                zufaelligesGerichtVorschlagen();
                break;
            case 2:     // Wenn 2 eingegeben wurde
                std::cout << "Programm wird beendet...\n";
                return;
            default:    // Bei allen anderen Eingaben
                std::cout << "Ungueltige Auswahl. Bitte versuchen Sie es erneut.\n";
                break;
            }
        }
    }

    // Wählt ein zufälliges Gericht aus und zeigt es an
    void zufaelligesGerichtVorschlagen() {
        // Erzeugt eine gleichmäßige Verteilung zwischen 0 und der Anzahl der Gerichte minus 1
        std::uniform_int_distribution<> dis(0, gerichte.size() - 1);
        int index = dis(gen);  // Wählt eine zufällige Position aus

        // Holt das Gericht an der zufälligen Position
        const Gericht& gericht = gerichte[index];

        // Zeigt das ausgewählte Gericht und seine Zutaten an
        std::cout << "Vorgeschlagenes Gericht: " << gericht.name << "\n";
        std::cout << "Zutaten:\n";
        for (const auto& zutat : gericht.zutaten) {  // Geht durch alle Zutaten
            std::cout << "- " << zutat << "\n";
        }

        warteAufBenutzer();  // Wartet auf Bestätigung durch den Benutzer
    }

private:
    // Wartet auf eine Benutzereingabe (Enter-Taste)
    void warteAufBenutzer() {
        std::cout << "\nDruecken Sie Enter, um fortzufahren...";
        std::string dummy;
        std::getline(std::cin, dummy);
    }
};

// Hauptfunktion des Programms (Startpunkt)
int main() {
    // Windows-spezifische Einstellung für UTF-8 (Umlaute)
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    // Lokale Spracheinstellungen für Deutsch
    setlocale(LC_ALL, "de_DE.UTF-8");

    // Erstellt einen neuen Essensplaner und startet das Hauptmenü
    Essensplaner essensplaner;
    essensplaner.zeigeHauptmenu();

    return 0;  // Programm erfolgreich beendet
}