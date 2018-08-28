#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;
    
    public:
        Iterator();
        Iterator(Node<T>* node);
         
        Iterator<T> operator=(Iterator<T> node);
        bool operator!=(Iterator<T> cmp);
        Iterator<T> operator++();
        T operator*();
};

#endif