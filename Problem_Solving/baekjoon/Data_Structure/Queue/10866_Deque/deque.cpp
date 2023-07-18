#include <iostream>
#include <vector>

// 원형큐
class Deque
{
public:
	Deque(int n) : f(0), r(0)
	{
		length = n + 1;
		deque = new int[length];
	}

	void push_back(int n)
	{
		if (isFull())
			return;

		deque[r++] = n;
		// r이 맨 끝에 도달했을 때 다시 앞으로 돌아가야 원형으로 이어진다.
		r %= length;
	}

	void push_front(int n)
	{
		if (isFull())
			return;

		f = (f - 1 + length) % length;
		deque[f] = n;
	}

	int pop_front()
	{
		if (empty())
			return -1;

		int top = deque[f++];
		f %= length;
		return top;
	}

	int pop_back()
	{
		if (empty())
			return -1;
		
		r = (r - 1 + length) % length;
		int b = deque[r];
		return b;
	}

	int size()
	{
		if (f > r)
			return (r - f) + length;
		return r - f;
	}

	bool empty()
	{
		// 원형큐의 r의 위치는 빈자리가 되는데 r과 f가 같다면 비어있는 큐다.
		return (r == f);
	}

	bool isFull()
	{
		return ((r + 1) % length == f);
	}

	int front()
	{
		if (empty())
			return -1;

		return deque[f];
	}

	int back()
	{
		if (empty())
			return -1;

		return deque[(r - 1 + length) % length];
	}

private:
	int f;
	int r;
	int *deque;
	int length;
};

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;

	Deque deq(n);

	while (n--)
	{
		std::string cmd;
		std::cin >> cmd;

		if (cmd == "push_front")
		{
			int x;
			std::cin >> x;
			deq.push_front(x);
		}
		else if (cmd == "push_back")
		{
			int x;
			std::cin >> x;
			deq.push_back(x);
		}
		else if (cmd == "pop_front")
		{
			std::cout << deq.pop_front() << "\n";
		}
		else if (cmd == "pop_back")
		{
			std::cout << deq.pop_back() << "\n";
		}
		else if (cmd == "size")
		{
			std::cout << deq.size() << "\n";
		}
		else if (cmd == "empty")
		{
			std::cout << deq.empty() << "\n";
		}
		else if (cmd == "front")
		{
			std::cout << deq.front() << "\n";
		}
		else if (cmd == "back")
		{
			std::cout << deq.back() << "\n";
		}
	}
	return 0;
}