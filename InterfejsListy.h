#pragma once

// Forward declaration, aby uniknac cyklicznych zaleznosci
template <typename T> class ListIterator;

/**
 * @file InterfejsListy.h
 * @brief Definicja szablonu abstrakcyjnego interfejsu listy.
 */

 /**
  * @brief Abstrakcyjny interfejs (klasa bazowa) dla listy.
  *
  * Definiuje publiczny kontrakt, jaki musi spelniac kazda implementacja listy.
  * Uzywany przez wzorzec fabryki.
  *
  * @tparam T Typ danych przechowywanych na liscie.
  */
template <typename T>
class IList {
public:
    /**
     * @brief Wirtualny destruktor.
     */
    virtual ~IList() {}

    /**
     * @brief Dodaje element na poczatek listy.
     * @param val Wartosc do dodania.
     */
    virtual void push_front(T val) = 0;

    /**
     * @brief Dodaje element na koniec listy.
     * @param val Wartosc do dodania.
     */
    virtual void push_back(T val) = 0;

    /**
     * @brief Wstawia element pod wskazany indeks.
     * @param val Wartosc do wstawienia.
     * @param index Indeks, pod którym element ma byc wstawiony.
     */
    virtual void insert(T val, size_t index) = 0;

    /**
     * @brief Usuwa element z poczatku listy.
     */
    virtual void pop_front() = 0;

    /**
     * @brief Usuwa element z konca listy.
     */
    virtual void pop_back() = 0;

    /**
     * @brief Usuwa element o wskazanym indeksie.
     * @param index Indeks elementu do usuniecia.
     */
    virtual void erase(size_t index) = 0;

    /**
     * @brief Wyswietla cala liste od poczatku do konca.
     */
    virtual void display_forward() const = 0;

    /**
     * @brief Wyswietla cala liste od konca do poczatku.
     */
    virtual void display_backward() const = 0;

    /**
     * @brief Usuwa wszystkie elementy z listy.
     */
    virtual void clear() = 0;

    /**
     * @brief Zwraca aktualna liczbe elementow na liscie.
     * @return Rozmiar listy (typu size_t).
     */
    virtual size_t get_size() const = 0;

    // --- Metody wzorca Iteratora ---

    /**
     * @brief Zwraca iterator wskazujacy na pocz¹tek listy.
     * @return ListIterator wskazujacy na pierwszy element.
     */
    virtual ListIterator<T> begin() = 0;

    /**
     * @brief Zwraca iterator wskazujacy na "koniec" listy (za ostatnim elementem).
     * @return ListIterator wskazujacy na nullptr.
     */
    virtual ListIterator<T> end() = 0;
};
