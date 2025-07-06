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
    while (first != nullptr) {
        deleteFirst();
    }
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
    if (first != nullptr) {
        auto to_Delete = first;
        first = to_Delete->next;

        if (first == nullptr) {
            last = nullptr;
        }

        delete to_Delete;
    }
}

template<typename T>
void link_list<T>::deleteLast() {
    if (last != nullptr && first != last) {
        auto to_Delete = last;
        auto new_last = first;
        while (new_last->next != last) {
            new_last = new_last->next;
        }
        last = new_last;
        new_last->next = nullptr;
        delete to_Delete;
    } else if (last != nullptr && first == last) {
        deleteFirst();
    }
}

template<typename T>
bool link_list<T>::contains(const T &value) const {
    return true;
}

template<typename T>
int link_list<T>::indexOf() {
}
