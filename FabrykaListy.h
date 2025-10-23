#pragma once

#include "InterfejsListy.h"
#include "ListaDwukierunkowa.h"

/**
 * @file FabrykaListy.h
 * @brief Definicja szablonu klasy ListFactory (wzorzec fabryki).
 */

 /**
  * @brief Fabryka do tworzenia obiektów list.
  *
  * Implementuje wzorzec prostej fabryki (Simple Factory).
  * Abstrakcjonizuje proces tworzenia konkretnej implementacji listy (ListaDwukierunkowa),
  * zwracaj¹c wskaŸnik do interfejsu (InterfejsListy).
  *
  * @tparam T Typ danych, jakie ma przechowywaæ lista.
  */
template <typename T>
class ListFactory {
public:
    /**
     * @brief Tworzy now¹ instancjê listy na stercie.
     * @return WskaŸnik do nowo utworzonej listy (typu IList<T>*).
     */
    static IList<T>* createList() {
        // Zwracamy wskaŸnik do nowej instancji konkretnej klasy,
        // ale "ukryty" za interfejsem IList.
        return new DoublyLinkedList<T>();
    }
};
