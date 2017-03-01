#pragma once

#include "Deque.h"
namespace BSL {

template <class T>
class List: public Deque<T> {
    public:
        virtual Iterator begin() = 0;
        virtual Iterator end() = 0;
        virtual Iterator rbegin() = 0;
        virtual Iterator rend() = 0;

        // Inserts a new element before the given position or index
        virtual Iterator insert(Iterator position, const T& val) = 0;
        virtual Iterator insert(int index, const T& val) = 0;

        // Removes the item at the given position or index
        virtual Iterator remove(Iterator position) = 0;
        virtual Iterator remove(int index) = 0;

        // Removes the first instance of item
        virtual Iterator remove(T item) = 0;

        // Removes all items that satisfy the predicate
        virtual Iterator remove(Predicate pred) = 0;

        // Swaps the items at the two positions or indexes
        virtual Iterator swap (Iterator position1, Iterator position2) = 0;
        virtual Iterator swap (int index1, int index2) = 0;

        // Applies the predicate to each item
        virtual Iterator map(Predicate pred) = 0;

        // Applies the + operator on each item on the list
        virtual T sum() = 0;

        virtual T &operator[](int i) = 0;
};

}

