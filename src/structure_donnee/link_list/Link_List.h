/*
========================================================================
  Fichier     : Link_List.h
  Auteur      : William Turbide Auclair
  Date        : 3 juillet 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe link list.

  Version     : 1.0
  ========================================================================
*/

#ifndef LINK_LIST_H
#define LINK_LIST_H

template<typename T>
struct node {
    T value;
    node<T> *next;
};


template<typename T>
class link_list {
private:
    node<T> *first;
    node<T> *last;

public:
    link_list(): first(nullptr), last(nullptr) {
    }

    link_list(const link_list &other) {
        first = nullptr;
        last = nullptr;
        auto iter = other.first;
        while (iter != nullptr) {
            addLast(iter->value);
            iter = iter->next;
        }
    }

    ~link_list() {
        while (first != nullptr) {
            deleteFirst();
        }
    }


    // O(1)
    void addFirst(T value) {
        auto to_Add = new node<T>{value, nullptr};

        if (first == nullptr) {
            first = last = to_Add;
        } else {
            to_Add->next = first;
            first = to_Add;
        }
    }

    // O(1)
    void addLast(T value) {
        auto to_Add = new node<T>{value, nullptr};

        if (last == nullptr) {
            first = last = to_Add;
        } else {
            last->next = to_Add;
            last = to_Add;
        }
    }

    // O(1)
    void deleteFirst() {
        if (first != nullptr) {
            auto to_Delete = first;
            first = to_Delete->next;

            if (first == nullptr) {
                last = nullptr;
            }

            delete to_Delete;
        }
    }

    // O(n)
    void deleteLast() {
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


    // O(n)
    bool contains(const T &value) const {
        auto iter = first;
        while (iter != nullptr) {
            if (iter->value == value) {
                return true;
            }
            iter = iter->next;
        }
        return false;
    }

    // O(n)
    int indexOf(const T &value) {
        auto iter = first;
        int index = 0;
        while (iter != nullptr) {
            if (iter->value == value) {
                return index;
            }
            iter = iter->next;
            index++;
        }
        return -1;
    }
};


#endif //LINK_LIST_H
