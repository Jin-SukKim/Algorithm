#include <iostream>
#include <vector>
#include <string>

class Node
{
public:
	char data;
	Node *left;
	Node *right;
	Node() : left(nullptr), right(nullptr) {}
	Node(char c) : data(c), left(nullptr), right(nullptr) {}
};

// Doubly Linked-List(이중 연결 리스트)
// current 포인터를 중심으로 활용한다.
class LinkedList
{
public:
	LinkedList() : head(nullptr), tail(nullptr), current(nullptr) {}
	~LinkedList()
	{
		// 만약 head값이 있을 때 current가 head의 위치에 있다면
		// pop() 함수의 exception인 current == head에 막혀 지워지지 않는다.
		current = tail->right;
		while (!empty())
			pop();
	}

	void push(char c)
	{
		Node *node = new Node(c);

		if (head == nullptr)
		{
			head = node;
			tail = node;
			// current 노드의 왼쪽에 삽입하므로 '\0'을 진짜 마지막 노드로 만들고
			// current를 이것으로 해줘 current노드를 안 움직이고 삽입하면 뒤에 계속 값이 연달아 삽입되도록 한다.
			Node *end = new Node('\0');
			node->right = end;
			end->left = node;
			current = end;
		}
		else
		{
			// 리스트 중간이나 맨 뒤에 삽입할 때
			if (current->left)
			{
				Node *p = current->left;
				// 현재 위치 왼쪽에 추가
				node->right = current;
				node->left = p;
				// 삽입할 노드와 왼쪽 노드를 연결
				p->right = node;
				// 삽입할 노드의 오른쪽 노드는 current가 된다.
				current->left = node;

				// tail은 다시 마지막 값을 가르키도록한다.
				while (tail->right->data != '\0')
				{
					tail = tail->right;
				}
			}
			// current 포인터가 제일 앞에 있을 때
			else
			{
				// 새로운 노드를 맨 앞에 연결
				node->right = current;
				current->left = node;

				// head를 맨 앞으로 가져온다.
				while (head->left)
					head = head->left;
			}
		}
	}

	void pop()
	{
		if (empty())
			return;

		// 커서가 제일 앞에 있을 때
		if (current == head)
			return;
		else
		{
			// 맨 앞의 값을 삭제할 때
			if (current->left == head)
			{
				
				delete head;
				// 만약 current가 list의 맨 뒤에 있고 값이 1개 남아 있을 때
				// 전부 삭제하고 초기화
				if (current->data == '\0')
				{
					delete current;
					current = nullptr;
					head = nullptr;
					tail = nullptr;
				}
				// 맨 앞의 값을 삭제하나 아직 다른 값이 list에 있을 때
				else {
					head = current;
					head->left = nullptr;
				}
			}
			// 값이 여러개 일때
			else
			{
				// 지워야 하는 왼쪽 노드를 건너 뛰고 그 다음 왼쪽 노드를 가져온다.
				Node *node = current->left->left;
				// 왼쪽 노드 삭제
				delete node->right;
				// 끊긴 리스트를 다시 연결시켜준다.
				node->right = current;
				current->left = node;

				if (current->data == '\0')
					tail = current->left;
			}
		}
	}

	// current 포인터를 왼쪽으로 이동
	void left()
	{
		if (current == head)
			return;
		current = current->left;
	}

	// current 포인터를 오른쪽으로 이동
	void right()
	{
		if (current->data == '\0')
			return;
		current = current->right;
	}

	bool empty()
	{
		if (tail)
			return false;
		return true;
	}

	Node *begin()
	{
		return head;
	}

	Node *end()
	{
		return tail;
	}

	Node *CurrentIndex()
	{
		return current;
	}

	void print()
	{
		Node *p = head;
		while (p->right->data != '\0')
		{
			std::cout << p->data;
			p = p->right;
		}
		std::cout << p->data;
	}

private:
	Node *head;
	Node *tail;
	Node *current;
};

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;

	LinkedList list;
	for (int i = 0; i < s.length(); i++)
		list.push(s[i]);

	int n;
	std::cin >> n;
	while (n--)
	{
		std::string cmd;
		std::cin >> cmd;

		if (cmd == "P")
		{
			char c;
			std::cin >> c;
			list.push(c);
		}
		else if (cmd == "L")
		{
			list.left();
		}
		else if (cmd == "D")
		{
			list.right();
		}
		else if (cmd == "B")
		{
			list.pop();
		}
	}

	list.print();
	return 0;
}