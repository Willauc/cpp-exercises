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

#include <stdexcept>


template<typename T>
class Link_List {
private:
    struct node {
        T value;
        node *next;


        explicit node(T p_value) : value(p_value), next(nullptr) {
        };
    };


    node *first;
    node *last;
    int count;

public:
    Link_List(): first(nullptr), last(nullptr), count(0) {
    }

    Link_List(const Link_List &other): first(nullptr), last(nullptr), count(0) {
        auto iter = other.first;
        while (iter != nullptr) {
            addLast(iter->value);
            iter = iter->next;
        }
    }

    ~Link_List() {
        while (first != nullptr) {
            deleteFirst();
        }
    }


    // O(1)
    void addFirst(T value) {
        auto to_Add = new node(value);

        if (isEmpty()) {
            first = last = to_Add;
            count++;
        } else {
            to_Add->next = first;
            first = to_Add;
            count++;
        }
    }

    // O(1)
    void addLast(T value) {
        auto to_Add = new node(value);

        if (isEmpty()) {
            first = last = to_Add;
            count++;
        } else {
            last->next = to_Add;
            last = to_Add;
            count++;
        }
    }

    // O(1)
    void deleteFirst() {
        if (isEmpty()) {
            throw std::runtime_error("Liste vide — suppression impossible");
        }
        auto to_Delete = first;
        first = to_Delete->next;

        if (first == nullptr) {
            last = nullptr;
        }

        delete to_Delete;
        count--;
    }

    // O(n)
    void deleteLast() {
        if (isEmpty()) {
            throw std::runtime_error("Liste vide — suppression impossible");
        }
        if (last != nullptr && first != last) {
            auto to_Delete = last;
            auto new_last = first;
            while (new_last->next != last) {
                new_last = new_last->next;
            }
            last = new_last;
            new_last->next = nullptr;
            delete to_Delete;
            count--;
        } else if (last != nullptr && first == last) {
            deleteFirst();
            count--;
        }
    }


    // O(n)
    bool contains(const T &value) const {
        return indexOf(value) != -1;
    }

    // O(n)
    int indexOf(const T &value) const {
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

    bool isEmpty() const {
        return first == nullptr;
    }

    // O(n)
    void reverse() {
        if (isEmpty() || first == last) return;

        node *precedent = nullptr;
        node *current = first;
        node *suivant = nullptr;

        last = first;

        while (current != nullptr) {
            suivant = current->next;
            current->next = precedent;
            precedent = current;
            current = suivant;
        }
        first = precedent;
    }

    T getKthFromTheEnd(int k) {
        if (isEmpty()) {
            throw std::out_of_range("List vide.");
        }
        if (k >= count || k < 0) {
            throw std::out_of_range("Valeur demandée hors liste.");
        }
        if (k == 0) {
            return last->value;
        }
        auto iter = first;
        auto iter2 = first;
        for (int i = 0; i < k; i++) {
            iter2 = iter2->next;
        }
        while (iter2 != last) {
            iter = iter->next;
            iter2 = iter2->next;
        }
        return iter->value;
    }

    const T getIndex(int index) const {
        if (isEmpty()) {
            throw std::out_of_range("List vide.");
        }
        if (index >= count || index < 0) {
            throw std::out_of_range("Valeur demandée hors liste.");
        }
        if (index == 0) {
            return first->value;
        }
        auto iter = first;
        for (int i = 0; i < index; i++) {
            iter = iter->next;
        }
        return iter->value;
    }

    void deleteIndex(int index) {
        if (isEmpty()) {
            throw std::out_of_range("List vide.");
        }
        if (index >= count || index < 0) {
            throw std::out_of_range("Valeur demandée hors liste.");
        }
        if (index == 0) {
            deleteFirst();
            return;
        }
        if (index == (count - 1)) {
            deleteLast();
            return;
        }
        auto courant = first->next;
        auto precedent = first;
        int i = 1;

        while (i != index) {
            courant = courant->next;
            precedent = precedent->next;
            i++;
        }

        precedent->next = courant->next;
        delete courant;
        count--;

    }
};


#endif //LINK_LIST_H
