/*
========================================================================
  Fichier     : My_Array.h
  Auteur      : William Turbide Auclair
  Date        : 30 juin 2025
  Description : Exercice du cours "The Ultimate Data Structures & Algorithms: Part 1" de Mosh.
                Le but est de créer une classe Array qui peut s'agrandir et rétrécir dynamiquement
                grâce à ses méthodes.
  Version     : 1.0
  ========================================================================
*/

#ifndef MY_ARRAY_H
#define MY_ARRAY_H


class My_Array {
private:
    int *m_array;
    int m_count;
    int m_capacity;

public:
    My_Array(int capacity);

    My_Array(const My_Array& other);

    ~My_Array();

    void insert(int value);

    void removeAt(int index);

    int get(int index) const;

    int get_capacity() const;

    int get_count() const ;

    int indexOf(int value) const ;

    void print() const ;

    int max() const ;

    My_Array intersect(const My_Array& second) const;

    void reverse();

    void insertAt();
};
#endif
