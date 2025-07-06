/*
========================================================================
  Fichier     : Link_List.cpp
  Auteur      : William Turbide Auclair
  Date        : 3 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe link list.

  Version     : 1.0
  ========================================================================
*/

#include "Link_List.h"

template<typename T>
link_list<T>::link_list() {
    first = nullptr;
    last = nullptr;
}

template<typename T>
link_list<T>::link_list(const link_list &other) {
}

template<typename T>
link_list<T>::~link_list() {

}

template<typename T>
void link_list<T>::addFirst(T value) {
    auto to_Add = new node<T>{value, nullptr};

    if (first == nullptr) {
        first = last = to_Add;
    } else {
        to_Add->next = first;
        first = to_Add;
    }
}

template<typename T>
void link_list<T>::addLast(T value) {
    auto to_Add = new node<T>{value, nullptr};

    if (last == nullptr) {
        first = last = to_Add;
    } else {
        last->next = to_Add;
        last = to_Add;
    }
}

template<typename T>
void link_list<T>::deleteFirst() {
}

template<typename T>
void link_list<T>::deleteLast() {
}

template<typename T>
bool link_list<T>::contains(const T& value) const {
    return true;
}

template<typename T>
int link_list<T>::indexOf() {
}
