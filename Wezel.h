#pragma once

/**
 * @file Wezel.h
 * @brief Definicja szablonu struktury wezla dla listy dwukierunkowej.
 */

 /**
  * @brief Struktura reprezentuj¹ca pojedynczy wezel w liscie dwukierunkowej.
  * @tparam T Typ danych przechowywanych w wezle.
  */
template <typename T>
struct Node {
    T data;         ///< Dane przechowywane w wezle.
    Node<T>* next;  ///< Wskaznik na nastepny wezel na liscie.
    Node<T>* prev;  ///< Wskaznik na poprzedni wezel na liscie.

    /**
     * @brief Konstruktor wezla.
     * @param val Wartosc do przechowania w wezle.
     */
    Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};
