#include <iostream>
#include <vector>

// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;

	// 1자리 수는 각각 1개씩 있다.
	std::vector<std::vector<int>> stairs(n+1, std::vector<int>(10));
	for (int i = 1; i <= 9; i++)
	{
		stairs[1][i] = 1;
	}

	int mod = 1000000000;
	// 계단 수는 인접한 모든 자리의 차이가 1이다.
	/*
		길이가 2일때는 21, 23, 32, 34...등 총 17개가 있다.
		길이가 3일때 맨 앞이 3이 오는 수는 321, 323, 343, 345가 올 수 있다.
	
		즉, 맨 앞에 오는 숫자(i)가 있을 때 i - 1의 조합 개수와 i + 1의 조합 개수를
		더해주면 길이 n의 수의 맨 앞에 i일 때의 조합의 개수를 알 수 있다.
		1부터 8까지는 이런식으로 계산이 가능한데 0과 9는 좀 특수하게 각각 이전 정수와
		이후 정수가 없으므로 두 가지의 경우가 아닌 한가지의 경우만 생각한다.
		
		ex) 길이가 3인 수일 때 맨 앞이 2인 수의 조합은 길이가 2인 수의 맨 앞 숫자가
			1과 3의 조합의 개수를 더해주면 나온다 = 10, 12 2개 + 32, 34 2개 ->
			2xx는 총 4개의 조합이 나온다.

			이렇게 1 ~ 9까지의 각각의 개수를 파악하고 더해주면 길이 n의 수의
			계단 수가 총 몇 개 있는지 알 수 있다.
	*/
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				stairs[i][j] = (stairs[i - 1][j + 1]) % mod;
			else if (j == 9)
				stairs[i][j] = (stairs[i - 1][j - 1]) % mod;
			else
				stairs[i][j] = (stairs[i - 1][j - 1] + stairs[i - 1][j + 1]) % mod;
		}
	}
	int count = 0;
	for (int i = 0; i <= 9; i++)
		count = (count + stairs[n][i]) % mod;

	std::cout << count;
	return 0;
}