#include <iostream>
#include "SingleNode.h"
#include "LinkedStack.h"
#include "XorDeque.h"

// Assisted by Avi
#define SWAP(a,b) (((a) != (b)) ? ((a) ^= (b) ^= (a) ^= (b)) : 0)

using namespace BSL;

int main() {

    uintptr_t a = (uintptr_t) new int(7);
    uintptr_t b = (uintptr_t) new int(3);

    std::cout << *(int*)a << " " << *(int*)b << std::endl;

    SWAP(a, b);

    std::cout << *(int*)a << " " << *(int*)b << std::endl;

    SingleNode<int> node1;

	node1.data = 24;

	//SingleNode<int> node2 = new SingleNode<int>;

	std::cout << node1.data << std::endl;

	LinkedStack<int> stack;

	//std::cout << stack.front() << std::endl;
	//LinkedStack<int> stack4;

	//LinkedStack<LinkedStack<int>> stack5;
	//{

        //LinkedStack<int> stack2 = stack;
        //stack2.pushFront(17);
        //LinkedStack<int> stack3 = stack2;
        //stack4 = stack3;
	//}

    //stack5.pushFront(stack);

    //std::cout << "Here" << std::endl;
    //LinkedStack<int> s5front = stack5.front();
    //std::cout << "Here1" << std::endl;
    //s5front.pushFront(56);
    //std::cout << "Here2" << std::endl;
	//std::cout << s5front.front() << std::endl;


	for(int i = 0; i < 5; i++) {
		stack.pushFront(i);
	}

	LinkedStack<int> stack2 = stack;
	stack2.pushFront(27);

	for(int i = 0; i < 3; i++) {
        int data = stack.popFront();
        int size = stack.size();
		std::cout << data << " " << size << std::endl;
	}
	std::cout << std::endl;

	for(int i = 0; i < 3; i++) {
        int data = stack2.popFront();
        int size = stack2.size();
		std::cout << data << " " << size << std::endl;
	}
	std::cout << std::endl;

	while(!stack.empty()) {
        int data = stack.popFront();
        int size = stack.size();
		std::cout << data << " " << size << std::endl;
	}
	std::cout << std::endl;


	XorDeque<int> deque = XorDeque<int>();
	XorDeque<int> deque2 = deque;
	for(int i = 0; i < 5; i++) {
		deque.pushFront((i+1));
		deque.pushBack(-(i+1));
	}
	XorDeque<int> deque3;
	deque3 = deque;

	while(!deque.empty()) {
		std::cout << deque.popFront() << std::endl;
	}

	std::cout << std::endl << "Deque2:" << std::endl;

    while(!deque2.empty()) {
		std::cout << deque2.popFront() << std::endl;
	}

	std::cout << std::endl << "Deque3:" << std::endl;

    while(!deque3.empty()) {
		std::cout << deque3.popBack() << std::endl;
	}
	return 0;

}

