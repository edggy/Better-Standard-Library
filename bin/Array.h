#pragma once

namespace BSL {

template <class T>
class Array: public List<T> {
    private:
        T[] data;
    public:

        Array<T>();
        Array<T>(unsigned int maxSize);
        Array<T>(const Array<T> &maxSize);

        /**
            Destructor
            @bigO - n
        */
        virtual ~Array<T>() {
        }

        Array<T>& operator=(const Array<T> &other);

        void pushFront(const T& data);
        void pushBack(const T& data);
        T popFront();
        T popBack();

        /**
            front()
            Returns the item in the front of the Deque
            @return - The front item
            @throw EmptyException - There are no items
            @bigO - 1
        */
        T front() const {
            if(empty()) {
                throw EmptyException("Array is empty");
            }
            return XORSN(head->n, tail)->data;
        }

        /**
            back()
            Returns the item in the back of the Array

            @return - The back item
            @throw EmptyException - There are no items
            @bigO - 1
        */
        T back() const {
            if(empty()) {
                throw EmptyException("Array is empty");
            }
            return XORSN(tail->n, head)->data;
        }

        /**
            size()

            @return - The number of items
            @bigO - 1
        */
        int size() const { return _size; }

        /**
            empty()

            @return - True iff there are no items
            @bigO - 1
        */
        bool empty() const { return _size == 0; }

        /**
            full()

            @return - True iff there is no room to add another item
            @bigO - 1
        */
        bool full() const { return _size >= _maxSize; }

        Iterator begin() = 0;
        Iterator end() = 0;
        Iterator rbegin() = 0;
        Iterator rend() = 0;

        // Inserts a new element before the given position or index
        Iterator insert(Iterator position, const T& val) = 0;
        Iterator insert(int index, const T& val) = 0;

        // Removes the item at the given position or index
        Iterator remove(Iterator position) = 0;
        Iterator remove(int index) = 0;

        // Removes the first instance of item
        Iterator remove(T item) = 0;

        // Removes all items that satisfy the predicate
        Iterator remove(Predicate pred) = 0;

        // Swaps the items at the two positions or indexes
        Iterator swap (Iterator position1, Iterator position2) = 0;
        Iterator swap (int index1, int index2) = 0;

        // Applies the predicate to each item
        Iterator map(Predicate pred) = 0;

        // Applies the + operator on each item on the list
        T sum() = 0;

        T &operator[](int i) = 0;
};

}

