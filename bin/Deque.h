#pragma once

#include "Stack.h"
#include "Queue.h"

namespace BSL {

template <class T>
class Deque: public Stack<T>, Queue<T> {
    public:
        virtual ~Deque<T>() {}

		// Remove and return the back object
		virtual T popBack() = 0;

		// Look at the front object
		virtual T back() const = 0;
};

}

