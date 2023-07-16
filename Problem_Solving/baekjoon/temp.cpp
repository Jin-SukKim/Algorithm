#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

class Node{
public:
	int value;
	Node* next;
	Node() : next(nullptr) {};
	Node(int v) : value(v), next(nullptr) {};
	~Node() {};
};

class Stack {
public:
	Stack() : head(nullptr), tail(nullptr), length(0) {};
	~Stack() {
		while (!empty())
			pop();
	};

	void push(int val)
	{
		length++;
		Node* node = new Node(val);
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else 
		{
			tail->next = node;
			tail = tail->next;
		}
	}

	int pop()
	{
		if (empty())
			return -1;
		
		int value = tail->value;
		length--;
		if (head == tail)
		{
			delete(head);
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			Node* p = head;
			while (p->next->next)
			{
				p = p->next;
			}
			delete p->next;
			p->next = nullptr;
			tail = p;
		}

		return value;
	}

	int size()
	{
		return length;
	}

	int empty()
	{
		if (tail)
			return 0;
		return 1;
	}

	int top()
	{
		if (tail)
			return tail->value;
		return -1;
	}

private:
	Node* head;
	Node* tail;
	int length;
};

int main()
{
	std::ios_base::sync_with_stdio(0);
	// std::cin.tie(0);

	int n;
	std::cin >> n;

	Stack stack;
	while (n--)
	{
		std::string cmd;
		int num;
		std::cin >> cmd;

		if (cmd == "push")
		{
			std::cin >> num;
			stack.push(num);
		}
		else if (cmd == "pop")
		{
			std::cout << stack.pop() << "\n";
		}
		else if (cmd == "size")
		{
			std::cout << stack.size() << "\n";
		}
		else if (cmd == "empty")
		{
			std::cout << stack.empty() << "\n";
		}
		else if (cmd == "top")
		{
			std::cout << stack.top() << "\n";
		}
	}

	return 0;
}