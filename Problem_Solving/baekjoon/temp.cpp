#include <iostream>
#include <vector>
#include <string>
#include <climits>

class Queue {
public:
	Queue(int n) : f(0), r(0)
	{
		if (n == INT_MAX)
		{
			std::cout << "INT Limit Exception Error! Size should be less than INT_MAX" << "\n";
			return;
		}

		length = n + 1;
		// rear의 위치는 빈 공간으로 둬야 queue가 꽉찼는지 아닌지 구분 가능하다.
		queue = new int[length];
	}
	~Queue()
	{
		delete queue;
	}

	void push(int x)
	{
		queue[r++] = x;
    }

	int pop()
	{
		if (empty())
			return -1;
		return queue[f++];
	}

	int size()
	{
		return r - f;
	}

	int empty()
	{
		// r의 위치를 비워두므로 front와 rear의 위치가 같다면 빈 queue다.
		return (f == r);
	}

	int front()
	{
		if (empty())
			return -1;
		return queue[f];
	}

	int back()
	{
		if (empty())
			return -1;
		return queue[r - 1];
	}
private:
	int* queue;
	int length;
	int f;
	int r;
};

int main()
{
	std::ios_base::sync_with_stdio(0);
	// std::cin.tie(0);

	int n;
	std::cin >> n;

	Queue q(100000);
	while (n--)
	{
		std::string cmd;
		std::cin >> cmd;

		if (cmd == "push")
		{
			int x;
			std::cin >> x;
			q.push(x);
		}
		else if (cmd == "pop")
		{
			std::cout << q.pop() << "\n";
		}
		else if (cmd == "size")
		{
			std::cout << q.size() << "\n";
		}
		else if (cmd == "empty")
		{
			std::cout << q.empty() << "\n";
		}
		else if (cmd == "front")
		{
			std::cout << q.front() << "\n";
		}
		else if (cmd == "back")
		{
			std::cout << q.back() << "\n";
		}
	}
	return 0;
}