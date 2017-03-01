#pragma once

namespace BSL {

template <class T>
class Stack {
	public:
	    virtual ~Stack<T>() {}

	    //virtual Stack<T>& operator=(Stack<T> &) { return *this; };

		// Add an object to the front of the stack
		virtual void pushFront(const T&) = 0;

		// Remove and return the front object
		virtual T popFront() = 0;

		// Look at the front object
		virtual T front() const = 0;

		// Returns the number of objects in the stack
		virtual int size() const = 0;

		// Returns true iff there are no objects in the stack
		virtual bool empty() const = 0;

        // Returns true iff no more object can be added to the stack
		virtual bool full() const = 0;

        // Removes all items
		virtual void clear() = 0;
};

}

