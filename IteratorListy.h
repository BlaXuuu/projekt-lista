#pragma once

#include "Wezel.h"
#include <iterator> // Dla bidirectional_iterator_tag

using namespace std; // przestrzen nazw standardowa

/**
 * @file IteratorListy.h
 * @brief Definicja szablonu klasy ListIterator.
 */

 /**
  * @brief Klasa iteratora dla listy dwukierunkowej.
  *
  * Implementuje wzorzec iteratora dwukierunkowego, umozliwiajac
  * iteracje po liscie w obu kierunkach.
  *
  * @tparam T Typ danych na liscie.
  */
template <typename T>
class ListIterator {
public:
    // Tzw. "iterator traits" - dobre praktyki C++
    using iterator_category = bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using reference = T&;

private:
    Node<T>* current; ///< Wskaznik na aktualny wezel.

public:
    /**
     * @brief Konstruktor iteratora.
     * @param node Wskaznik na wezel, od ktorego iterator ma zaczac.
     */
    explicit ListIterator(Node<T>* node) : current(node) {}

    /**
     * @brief Operator dereferencji.
     * @return Referencja do danych w biezacym wezle.
     */
    reference operator*() const {
        return current->data;
    }

    /**
     * @brief Operator strzalki (dostepu do skladowych).
     * @return Wskaznik do danych w biezacym wezle.
     */
    pointer operator->() const {
        return &(current->data);
    }

    /**
     * @brief Operator pre-inkrementacji (przesuwa do nastepnego elementu).
     * @return Referencja do iteratora (*this).
     */
    ListIterator& operator++() {
        if (current) current = current->next;
        return *this;
    }

    /**
     * @brief Operator pre-dekrementacji (przesuwa do poprzedniego elementu).
     * @return Referencja do iteratora (*this).
     */
    ListIterator& operator--() {
        if (current) current = current->prev;
        return *this;
    }

    /**
     * @brief Operator porownania (rownosci).
     * @param other Inny iterator do porownania.
     * @return true, jesli iteratory wskazuja na ten sam wezel.
     */
    bool operator==(const ListIterator& other) const {
        return current == other.current;
    }

    /**
     * @brief Operator porownania (nierownosci).
     * @param other Inny iterator do porownania.
     * @return true, jesli iteratory wskazuj¹ na rozne wezly.
     */
    bool operator!=(const ListIterator& other) const {
        return current != other.current;
    }
};