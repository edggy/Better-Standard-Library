#pragma once

namespace BSL {

template <class T>
class Queue
{
    public:
        virtual ~Queue<T>() {}

		// Add an object to the front of the stack
		virtual void pushBack(const T&) = 0;

		// Remove and return the front object
		virtual T popFront() = 0;

		// Look at the front object
		virtual T front() const = 0;

		// Returns the number of objects in the stack
		virtual int size() const = 0;

		// Returns true iff there are no objects in the stack
		virtual bool empty() const = 0;

		// Removes all items
		virtual void clear() = 0;
};

}

