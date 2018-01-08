
#include <iostream>
#include "headers/Fraction.h"
#include "headers/OnpCalculator.h"

using namespace std;

int main() {
    int choice = 0;
    std::string input;
    std::cout << "Welcome in ONP calculator, please select on which data would you like to work\n"
            "1. Int\n"
            "2. Double\n"
            "3. Fractions" << std::endl;
    std::cin >> choice;

    std::cout << "Enter fraze to calculate each symbol must be seperate by SPACEBAR \neg. 1 1 + if you enter 00 you "
            "exit from calculator" << endl;

    std::cin.ignore();

    getline(std::cin, input); // reading fraze from console

    if (choice == 1) {
        onpCalculator<int>(input);
    } else if (choice == 2) {
        onpCalculator<double>(input);
    } else if (choice == 3) {
        onpCalculator<Fraction>(input);
    }
    return 0;

}

/// operator i konstruktor przenoszący
// Nie ma potrzeby przeciążać operatora i konstruktora kopiującego gdyż może być defaulty (stworzony przez kompilator)
// taki operator/konstruktor wykona płytką kopię obiekty tzn. skopiuje pola klasy w naszym przypadku to jest wystarczające
// w programie nie mamy żadnych wskaźników

/// operator i konstruktor move
// to samo co copu

/// destruktor
// nie ma potrzeby deklarowania i implementowaia dekstruktora ponieważ nie alokujemy dynamicznie pamięci

/// operatory
// Moim zdaniem potrzebne jest przeciążenie wszystkich operatorów porównawczych dwa ułamki tj. <, <=, >, >=, ==, !=
// Przeciążyć należy również operatory wyj/wej w moim programie ułamki przy użyciu operatora wejścia
// wprowadza się w następujący sposób "1/2" gdy wprowadzimy mianownik równy 0 wtedy zgłosi się wyjątek,
// natomiast gdy mianownik będzie mniejszy od zera znak minus zostanie przeniesiony do licznika a mianownik stanie się
// dodatni, oraz wykona się metoda reduce która skróci ułamek. Nie dałem mianownika jako unsigned int by ograniczyć
// ilość konwersji i zwiększyć czytelność kodu.
// Operator wyjścia zwraca ułamek w następujący sposób, gdy mianownik będzie równy jeden wtedy zwrócony zostanie licznik
// w przeciwnym razie zwrócony wynik będzie w formacie a/b
// przeciążyłem również operator int oraz double gdyż może być potrzeba rzutowania wartości w klasach typu int jest
// jest zdeklarowany operator double

// Operatory matematyczne przeciążyłem następujące + - / * oraz ich wersje z przypisaniem. Nie widzę potrzeby
// przeciążać opratora potęgowania czy reszty z dzielenia (może zrobię wersję z potęgowaniem przez inta)
// niepotrzebne też wydaje mi się przeciążanie operatora post/pre inkrementacji/dekrementacji gdyż nie robi się
// pętli na ułamkach
