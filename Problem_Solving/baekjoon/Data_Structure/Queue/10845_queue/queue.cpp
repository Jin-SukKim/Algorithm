#include <iostream>
#include <vector>
#include <string>
#include <climits>

// 원형큐
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
		queue = new int[n+1];
	}
	~Queue()
	{
		delete queue;
	}
	void push(int x)
	{
		if (length - 1 == size())
		{
			std::cout << "Queue is full." << "\n";
			return;
		}
		queue[r++] = x;
		r %= length; // 나머지로 만들어 끝에 도달하면 앞으로 돌아갈 수 있도록 한다.
	}

	int pop()
	{
		if (empty())
			return -1;
		int top = queue[f];
		f = (f + 1) % length;

		return top;
	}

	int size()
	{
		// front가 rear보다 크면 rear는 한바퀴 돌아서 list의 앞에 있으므로
		// 계산식이 달라진다.
		if (f > r)
			return (r - f) + length;
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
		int b = r - 1 < 0 ? length - r - 1 : r - 1;
		return queue[b];
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
	std::cin.tie(0);

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