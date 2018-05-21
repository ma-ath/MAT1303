#ifndef STACK_H
#define STACK_H

struct Coord
{
	int si;
	int sj;
	int mi;
	int mj;
	int cpuCasa;
	char cor;
	bool halmaFlag;
};

struct Node
{
	Coord c;
	Node *next;
};

class Stack
{
private:
	Node *top;
public:
	Stack(void) { top = nullptr; }
	void push(Coord& d)
	{
		Node *new_top = new Node;
		new_top->c = d;
		new_top->next = top;
		top = new_top;
	}
	Coord pop(void)
	{
		Node *remove;
		Coord c = top->c;

		remove = top;
		top = top->next;
		delete remove;

		return c;
	}
	bool empty(void)
	{
		if (top == nullptr)
			return true;
		else
			return false;
	}
};

#endif
