#pragma once

#include "InterfejsListy.h"
#include "Wezel.h"
#include "IteratorListy.h"
#include <iostream>  // Dla metod display
#include <stdexcept> // Dla out_of_range

using namespace std; // przestrzen nazw standardowa

/**
 * @file ListaDwukierunkowa.h
 * @brief Definicja i implementacja szablonu klasy DoublyLinkedList.
 */

 /**
  * @brief Konkretna implementacja listy dwukierunkowej.
  *
  * Implementuje interfejs Listy, zarzadzajac wezlami na stercie.
  *
  * @tparam T Typ danych przechowywanych na liscie.
  */
template <typename T>
class DoublyLinkedList : public IList<T> {
private:
    Node<T>* head; ///< Wskaznik na pierwszy element (glowe) listy.
    Node<T>* tail; ///< Wskaznik na ostatni element (ogon) listy.
    size_t size;   ///< Liczba elementow na liscie.

    /**
     * @brief Prywatna metoda pomocnicza do pobierania wezla o zadanym indeksie.
     * * Zoptymalizowana: szuka od glowy lub ogona, w zaleznosci co jest blizej.
     *
     * @param index Indeks wezla do znalezienia.
     * @return Wskaznik do wezla o zadanym indeksie lub nullptr, jesli nie istnieje.
     */
    Node<T>* getNode(size_t index) const {
        if (index >= size) return nullptr;

        Node<T>* current;
        if (index < size / 2) {
            // Szukaj od poczatku
            current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
        }
        else {
            // Szukaj od konca
            current = tail;
            for (size_t i = 0; i < (size - 1 - index); ++i) {
                current = current->prev;
            }
        }
        return current;
    }

    /**
     * @brief Sprawdza, czy lista jest pusta.
     * @return true, jesli lista jest pusta.
     */
    bool isEmpty() const {
        return size == 0;
    }

public:
    /**
     * @brief Domyslny konstruktor. Inicjalizuje pusta liste.
     */
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    /**
     * @brief Destruktor. Zwalnia cala pamiec zajmowana przez liste.
     */
    virtual ~DoublyLinkedList() {
        clear();
    }

    // ----- Implementacja metod interfejsu IList -----

    void push_front(T val) override {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    void push_back(T val) override {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insert(T val, size_t index) override {
        if (index > size) {
            throw out_of_range("Indeks poza zakresem");
        }
        if (index == 0) {
            push_front(val);
        }
        else if (index == size) {
            push_back(val);
        }
        else {
            Node<T>* current = getNode(index); // Wezel, przed ktory wstawiamy
            Node<T>* newNode = new Node<T>(val);

            newNode->next = current;
            newNode->prev = current->prev;

            current->prev->next = newNode;
            current->prev = newNode;

            size++;
        }
    }

    void pop_front() override {
        if (isEmpty()) return;

        Node<T>* temp = head;
        if (size == 1) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    void pop_back() override {
        if (isEmpty()) return;

        Node<T>* temp = tail;
        if (size == 1) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void erase(size_t index) override {
        if (index >= size) {
            throw out_of_range("Indeks poza zakresem");
        }
        if (index == 0) {
            pop_front();
        }
        else if (index == size - 1) {
            pop_back();
        }
        else {
            Node<T>* toDelete = getNode(index);
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            delete toDelete;
            size--;
        }
    }

    void display_forward() const override {
        cout << "Lista (do przodu): ";
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    void display_backward() const override {
        cout << "Lista (do tylu):   ";
        Node<T>* current = tail;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->prev;
        }
        cout << "NULL\n";
    }

    void clear() override {
        while (!isEmpty()) {
            pop_front(); // Uzywamy istniejacej logiki
        }
    }

    size_t get_size() const override {
        return size;
    }

    // ----- Implementacja metod wzorca Iteratora -----

    ListIterator<T> begin() override {
        return ListIterator<T>(head);
    }

    ListIterator<T> end() override {
        return ListIterator<T>(nullptr); // end() to wskaznik za ostatnim elementem
    }
};
