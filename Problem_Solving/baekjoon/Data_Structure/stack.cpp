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
        // 아무런 데이터가 없을 때
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
        // 데이터가 있을 때
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

        // stack에 데이터가 1개일 때
		if (head == tail)
		{
			delete(head);
			head = nullptr;
			tail = nullptr;
		}
        // 데이터가 여러개 있을 때 맨 뒤의 한 데이터만 삭제한다.
		else
		{
			Node* p = head;
            // Linked-List 구조로 되어 있어 Head부터 tail 이전까지 찾는다.
			while (p->next->next)
			{
				p = p->next;
			}
            // tail의 데이터를 삭제한다.
			delete p->next;
			p->next = nullptr;
            // tail을 앞 데이터를 가르키게 한다.
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

    // LIFO 구조로 tail의 data를 출력한다.
	int top()
	{
		if (tail)
			return tail->value;
		return -1;
	}

private:
	Node* head;
	Node* tail;
    // 스택의 길이
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