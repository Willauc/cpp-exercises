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
class link_list {
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
    link_list(): first(nullptr), last(nullptr), count(0) {
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

    bool isEmpty() {
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
};


#endif //LINK_LIST_H
