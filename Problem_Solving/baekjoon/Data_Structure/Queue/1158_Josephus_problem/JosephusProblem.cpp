#include <iostream>
#include <vector>

// 원형큐
class Queue {
public:
	Queue(int n) : f(0), r(0)
	{
		length = n + 1;
		queue = new int[length];
	}

	void push(int n)
	{
		if (isFull())
			return;
		
		queue[r++] = n;
		// queue의 맨 끝에 도달했을 때 다시 앞으로 돌아가야 원형으로 이어진다.
		r %= length;
	}

	int pop()
	{
		if (empty())
			return -1;
		
		int top = queue[f++];
		f %= length;
		return top;
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
		return r == f;
	}

	bool isFull()
	{
		return (r + 1) % length == f;
	}

private:
	int f;
	int r;
	int* queue;
	int length;
};

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;

	Queue q(n);
	for (int i = 1; i <= n; i++)
		q.push(i);

	Queue res(n);
	std::cout << '<';
	while (q.size() > 1)
	{
		// k 번째 사람을 제거한다 (ex: 3이면 3번째 사람인 3 -> 6을 먼저 제거한다.)
		// 제거하기 위해 뺀 앞의 사람은 다시 뒤에 넣어준다.
		for (int i = 1; i < k; i++)
			q.push(q.pop());	// 만든 원형큐 클래스의 pop()은 빼는 int를 return
		std::cout << q.pop() << ", ";
	}
	std::cout << q.pop() << '>';
	return 0;
}