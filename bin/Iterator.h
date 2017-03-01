#pragma once

template <class T>
class Iterator {
    public:

        virtual Iterator<T> next() = 0;
        virtual Iterator<T> prev() = 0;

        virtual Iterator<T> hasNext() = 0;
        virtual Iterator<T> hasPrev() = 0;

        virtual Iterator<T>& operator*() = 0;

        virtual Iterator<T>& operator++() = 0;
        virtual Iterator<T>& operator++(int) = 0;
        virtual Iterator<T>& operator--() = 0;
        virtual Iterator<T>& operator--(int) =  0;
};
