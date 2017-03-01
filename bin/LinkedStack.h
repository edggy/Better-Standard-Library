#pragma once

#include "Stack.h"
#include "SingleNode.h"
#include "EmptyException.h"
#include "FullException.h"

namespace BSL {

template <class T>
class LinkedStack: public Stack<T> {
	private:
		SingleNode<T>* head;
		unsigned int _size;
		unsigned int _maxSize;
	public:
	    /**
            Default Constructor

            @bigO - 1
	    */
		LinkedStack<T>() {
            head = new SingleNode<T>;
            _size = 0;
            _maxSize = -1;
        }

        /**
            Constructor

            @param maxSize - The maximum number of items in the Stack
            @bigO - 1
	    */
        LinkedStack<T>(unsigned int maxSize) {
            head = new SingleNode<T>;
            _size = 0;
            _maxSize = maxSize;
        }

        /**
            Copy Constructor
            @bigO - n
	    */
        LinkedStack<T>(const LinkedStack<T> &other) {
            head = new SingleNode<T>;
            _size = 0;
            operator=(other);
        }

        /**
            Destructor
            @bigO - n
        */
		~LinkedStack<T>() {
		    clear();
            delete head;
		}

		/**
            Assignment Operator
            @bigO - n
	    */
		LinkedStack<T>& operator=(const LinkedStack<T> &other) {
		    clear();
		    _size = other._size;
            _maxSize = other._maxSize;
            head = new SingleNode<T>(other.head->data);
            SingleNode<T>* oCur = other.head->n;
            SingleNode<T>* cur = head;
            while(oCur) {
                SingleNode<T>* next = new SingleNode<T>(oCur->data);
                cur->n = next;
                oCur = oCur->n;
                cur = next;
            }
            return *this;
		}

		/**
            pushFront
            Add an object to the front of the stack

            @param data - Item to add to the stack
            @throw FullException - If there is no room to add another item
            @bigO - 1
		*/
		void pushFront(const T& data) {
		    if(full()) {
                throw FullException("Stack is full");
		    }
            SingleNode<T>* newHead = new SingleNode<T>(data, head);
            head = newHead;
            _size++;
        }

        /**
            popFront
            Remove and return the front object

            @return - The data from the front of the Stack
            @throw EmptyException - There are no items in the Stack
            @bigO - 1
        */
		T popFront() {
		    if(empty()) {
                throw EmptyException("Stack is empty");
		    }
            T data = this->head->data;
            SingleNode<T>* next = this->head->n;
            delete this->head;
            this->head = next;
            this->_size--;
            return data;
        }

        /**
            front
            Look at the front object

            @return - The data from the front of the Stack
            @throw EmptyException - There are no items in the Stack
            @bigO - 1
        */
		T front() const {
		    if(empty()) {
                throw EmptyException("Stack is empty");
		    }
            return head->data;
        }

        /**
            size

            @return - The number of items in the Stack
            @bigO - 1
        */
		int size() const {
		    return _size;
        }

		/**
            empty

            @return - True iff there are no objects in the Stack
            @bigO - 1
        */
		bool empty() const {
		    return _size == 0;
        }

		/**
            full

            @return - True iff there is no room to add an item the Stack
            @bigO - 1
        */
		bool full() const {
		    return _size >= _maxSize;
        }

		/**
            empty
            Removes all the items from the Stack

            @bigO - n
        */
		void clear() {
		    while(!empty())
                popFront();
		}
};

}

