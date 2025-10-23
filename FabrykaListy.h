#pragma once

#include "InterfejsListy.h"
#include "ListaDwukierunkowa.h"

/**
 * @file FabrykaListy.h
 * @brief Definicja szablonu klasy ListFactory (wzorzec fabryki).
 */

 /**
  * @brief Fabryka do tworzenia obiekt�w list.
  *
  * Implementuje wzorzec prostej fabryki (Simple Factory).
  * Abstrakcjonizuje proces tworzenia konkretnej implementacji listy (ListaDwukierunkowa),
  * zwracaj�c wska�nik do interfejsu (InterfejsListy).
  *
  * @tparam T Typ danych, jakie ma przechowywa� lista.
  */
template <typename T>
class ListFactory {
public:
    /**
     * @brief Tworzy now� instancj� listy na stercie.
     * @return Wska�nik do nowo utworzonej listy (typu IList<T>*).
     */
    static IList<T>* createList() {
        // Zwracamy wska�nik do nowej instancji konkretnej klasy,
        // ale "ukryty" za interfejsem IList.
        return new DoublyLinkedList<T>();
    }
};
