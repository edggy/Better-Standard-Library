/**
    XorDeque
    XorDeque.h

    A low memory Deque where each node only contains one pointer

    @author Ethan Gertler
    @version 1.1 4/10/16
*/

#pragma once

#include "SingleNode.h"
#include "Deque.h"
#include "EmptyException.h"
#include "FullException.h"

#define XOR(a, b) ((void*)((uintptr_t)(a) ^ (uintptr_t)(b)))
#define XORSN(a, b) ((SingleNode<T>*) XOR(a, b))

namespace BSL {

template <class T>
class XorDeque: public Deque<T> {
    protected:
        SingleNode<T>* head;
        SingleNode<T>* tail;
        unsigned int _size;
        unsigned int _maxSize;

    public:
        /**
            Default Constructor
            @bigO - 1
        */
        XorDeque<T>();
        XorDeque<T>(unsigned int maxSize);
        XorDeque<T>(const XorDeque<T> &other);

        /**
            Destructor
            @bigO - n
        */
        ~XorDeque<T>() {
            clear();
            delete head;
            delete tail;
        }

        XorDeque<T>& operator=(const XorDeque<T> &other);

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
                throw EmptyException("Deque is empty");
            }
            return XORSN(head->n, tail)->data;
        }

        /**
            back()
            Returns the item in the back of the Deque

            @return - The back item
            @throw EmptyException - There are no items
            @bigO - 1
        */
        T back() const {
            if(empty()) {
                throw EmptyException("Deque is empty");
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

        /**
            clear()
            Removes all the items from the Deque
            @bigO - n
        */
        void clear() { while(!empty()) popFront(); }
};

/**
    Default Constructor
    @bigO - 1
*/
template <class T>
XorDeque<T>::XorDeque() {
	head = new SingleNode<T>;
	tail = new SingleNode<T>;
	head->n = 0;
	tail->n = 0;
	_size = 0;
	_maxSize = -1;
}

/**
    Constructor

    @param maxSize - The maximum number of elements in the Deque
    @bigO - 1
*/
template <class T>
XorDeque<T>::XorDeque(unsigned int maxSize) {
	head = new SingleNode<T>;
	tail = new SingleNode<T>;
	head->n = 0;
	tail->n = 0;
	_size = 0;
	_maxSize = maxSize;
}

/**
    Copy Constructor
    @bigO - n
*/
template <class T>
XorDeque<T>::XorDeque(const XorDeque<T> &other) {
    head = new SingleNode<T>;
	tail = new SingleNode<T>;
	operator=(other);
}

/**
    operator=
    @bigO - n
*/
template <class T>
XorDeque<T>& XorDeque<T>::operator=(const XorDeque<T> &other) {
    // TODO: Implement operator=
    clear();
    _size = other._size;
    _maxSize = other._maxSize;
    if(!other.empty()) {
        SingleNode<T>* prev = tail;
        SingleNode<T>* cur = head;
        SingleNode<T>* next = tail;
        SingleNode<T>* oPrev = other.head;
        SingleNode<T>* oCur = XORSN(other.head->n, other.tail);

        while(oCur != other.tail) {
            // Make a new next node with data
            next = new SingleNode<T>(oCur->data);

            // Connect next node with current
            cur->n = XORSN(prev, next);

            // Move to the next node
            prev = cur;
            cur = next;

            // Swap oPrev and oCur
            oPrev = XORSN(oCur, oPrev);
            oCur = XORSN(oCur, oPrev);
            oPrev = XORSN(oCur, oPrev);

            // Calculate the next node
            oCur = XORSN(oCur, oPrev->n);

            /*
            SingleNode<T>* tmp = oCur;
            oCur = XORSN(oCur->n, oPrev);
            oPrev = tmp;
            */

        }

        next->n = XORSN(prev, tail);
        tail->n = XORSN(head, next);
    }
    return *this;
}

/**
    pushFront
    Adds an item to the front of the Deque

    @param data - The data to append to the front
    @throw FullException - There is no room to add the item
    @bigO - 1
*/
template <class T>
void XorDeque<T>::pushFront(const T& data) {
    if(full()) {
        throw FullException("Deque is full");
    }
    SingleNode<T>* firstNode = XORSN(head->n, tail);
    SingleNode<T>* secondNode = XORSN(firstNode->n, head);
    SingleNode<T>* newFirstNode = new SingleNode<T>(data, XORSN(head, firstNode));
    head->n = XORSN(tail, newFirstNode);
    firstNode->n = XORSN(newFirstNode, secondNode);
    _size++;
}

/**
    pushBack
    Adds an item to the end of the Deque

    @param data - The data to append to the end of the deque
    @throw FullException - There is no room to add the item
    @bigO - 1
*/
template <class T>
void XorDeque<T>::pushBack(const T& data) {
    if(full()) {
        throw FullException("Deque is full");
    }
    SingleNode<T>* lastNode = XORSN(tail->n, head);
    SingleNode<T>* secondLastNode = XORSN(lastNode->n, tail);
    SingleNode<T>* newLastNode = new SingleNode<T>(data, XORSN(tail, lastNode));
    tail->n = XORSN(head, newLastNode);
    lastNode->n = XORSN(newLastNode, secondLastNode);
    _size++;
}

/**
    popFront
    Removes and returns the front item of the Deque

    @return - The data at the front of the Deque
    @throw EmptyException - There is no item to pop
    @bigO - 1
*/
template <class T>
T XorDeque<T>::popFront() {
    if(empty()) {
        throw EmptyException("Deque is empty");
    }
    SingleNode<T>* firstNode = XORSN(head->n, tail);
    SingleNode<T>* secondNode = XORSN(firstNode->n, head);
    SingleNode<T>* thirdNode = XORSN(secondNode->n, firstNode);
    T data = firstNode->data;
    delete firstNode;
    head->n = XORSN(tail, secondNode);
    secondNode->n = XORSN(head, thirdNode);
    _size--;
    return data;
}

/**
    popBack
    Removes and returns the back item of the Deque

    @return - The data at the back of the Deque
    @throw EmptyException - There is no item to pop
    @bigO - 1
*/
template <class T>
T XorDeque<T>::popBack() {
    if(empty()) {
        throw EmptyException("Deque is empty");
    }
    SingleNode<T>* lastNode = XORSN(tail->n, head);
    SingleNode<T>* secondLastNode = XORSN(lastNode->n, tail);
    SingleNode<T>* thirdLastNode = XORSN(secondLastNode->n, lastNode);
    T data = lastNode->data;
    delete lastNode;
    tail->n = XORSN(head, secondLastNode);
    secondLastNode->n = XORSN(tail, thirdLastNode);
    _size--;
    return data;
}

}

