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
    node<T>* next;
};


template<typename T>
class link_list {
private:
    node<T>* first;
    node<T>* last;

public:
    link_list();
    link_list(const link_list& other);
    ~link_list();
    void addFirst(T value);
    void addLast(T value);
    void deleteFirst();
    void deleteLast();
    bool contains(const T& value) const;
    int indexOf();



};



#endif //LINK_LIST_H
