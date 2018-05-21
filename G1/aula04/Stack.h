#ifndef STACK_H
#define STACK_H

#include "window.h"
#include <cstdlib>

struct Node {
	window a;
	Node *next;
};

class Stack {
private:
	Node *top;
public:
	Stack(void) { top = nullptr; }
	void push(window& b)
	{
		Node *new_top = new Node;
		new_top->a = b;
		new_top->next = top;
		top = new_top;
	}
	window pop(void)
	{
		Node *remove;
		window a = top->a;

		remove = top;
		top = top->next;
		delete remove;

		return a;
	}
	bool empty(void)
	{
		if (top == nullptr)
			return true;
		else
			return false;
	}
	int size(void);
	window peek(void);
};

#endif