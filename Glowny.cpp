#include <iostream>
#include <stdexcept> // Do lapania wyjątkow

// Glowne pliki naglowkowe
#include "FabrykaListy.h"
#include "InterfejsListy.h"
#include "IteratorListy.h"

// przestrzen nazw standardowa
using namespace std; 

/**
 * @file Glowny.cpp
 * @brief Glowny plik programu, testujacy implementacje listy dwukierunkowej.
 */

int main() {
    // 1. Uzyj fabryki do stworzenia obiektu listy na stercie.
    //    Pracujemy na wskazniku do interfejsu IList.
    IList<int>* list = ListFactory<int>::createList();

    cout << "Testowanie dodawania (push_back, push_front)\n";
    list->push_back(10);
    list->push_back(20);
    list->push_front(5);
    // Lista powinna byc: 5 -> 10 -> 20
    list->display_forward(); // Oczekiwano: 5 -> 10 -> 20 -> NULL
    cout << "Rozmiar: " << list->get_size() << "\n\n";

    cout << "Testowanie wyswietlania w odwrotnej kolejnosci\n";
    list->display_backward(); // Oczekiwano: 20 -> 10 -> 5 -> NULL
    cout << "\n";

    cout << "Testowanie wstawiania (insert na indeks 1)\n";
    try {
        list->insert(8, 1); // Wstawia 8 przed 10
        // Lista powinna byc: 5 -> 8 -> 10 -> 20
        list->display_forward(); // Oczekiwano: 5 -> 8 -> 10 -> 20 -> NULL
    }
    catch (const out_of_range& e) {
        cout << "Wyjatek: " << e.what() << '\n';
    }
    cout << "Rozmiar: " << list->get_size() << "\n\n";

    cout << "Testowanie usuwania (pop_front, pop_back)\n";
    list->pop_front(); // Usuwa 5
    list->pop_back();  // Usuwa 20
    // Lista powinna byc: 8 -> 10
    list->display_forward(); // Oczekiwano: 8 -> 10 -> NULL
    cout << "Rozmiar: " << list->get_size() << "\n\n";

    cout << "Testowanie usuwania z indeksu (erase na indeks 0)\n";
    list->push_back(12); // Lista: 8 -> 10 -> 12
    cout << "Przed erase: ";
    list->display_forward();
    try {
        list->erase(0); // Usuwa 8
        // Lista powinna byc: 10 -> 12
        cout << "Po erase(0): ";
        list->display_forward(); // Oczekiwano: 10 -> 12 -> NULL
    }
    catch (const out_of_range& e) {
        cout << "Wyjatek: " << e.what() << '\n';
    }
    cout << "Rozmiar: " << list->get_size() << "\n\n";

    cout << "Testowanie Iteratora (punkty 9 i 10)\n";
    cout << "Iteracja do przodu (petla for-each-style):\n";
    for (ListIterator<int> it = list->begin(); it != list->end(); ++it) {
        cout << "Element: " << *it << "\n";
    }

    cout << "\nDemonstracja 'nastepny' i 'poprzedni' element:\n";
    ListIterator<int> it = list->begin(); // it wskazuje na 10
    if (it != list->end()) {
        cout << "Pierwszy element: " << *it << "\n";

        ++it; // Przejscie do nastepnego elementu (12)
        if (it != list->end()) {
            cout << "Nastepny element: " << *it << "\n";

            --it; // Przejscie do poprzedniego elementu (10)
            cout << "Poprzedni element: " << *it << "\n";
        }
    }
    cout << "\n";

    cout << "Testowanie czyszczenia listy (clear)\n";
    list->clear();
    cout << "Rozmiar listy po clear: " << list->get_size() << "\n";
    list->display_forward(); // Oczekiwano: NULL
    cout << "\n";

    // 2. Zwolnienie pamieci (kluczowe!)
    //    Poniewaz fabryka dala nam wskaznik, musimy go usunac.
    delete list;
    list = nullptr;

    cout << "Testy zakonczone. Pamiec zwolniona.\n";

    return 0;
}

