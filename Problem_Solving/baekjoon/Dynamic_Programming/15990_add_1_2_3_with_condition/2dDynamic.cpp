#include <iostream>
#include <vector>

// Bottom-Up
int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int t;
	std::cin >> t;

	// 1, 2, 3으로 숫자를 표시해야 되나 같은 수를 연속적으로 사용하면
	// 안된다는 조건이 붙어 2d array를 이용해야 표현이 가능했다.
	// 1, 2, 3으로 시작할 수 있는 표현식의 개수
	std::vector<std::vector<long long>> matrix(4, std::vector<long long>(4));
	
	// row(가로)는 각각 1, 2, 3으로 시작하는 표현식의 개수이다.
	// column(세로)는 1, 2, 3의 조합으로 표현해야 되는 정수이다.
	// ex) 	1은 1로 시작하는 1개, 2는 2로 시작하는 1개, 3은 
	//		각각 1, 2, 3으로 시작하는 표현식이 1개씩있다.
	// 표현의 편의성의 위해 row, column의 index 0은 0으로 나뒀다.
	matrix[1][1] = matrix[3][1] = 1;
	matrix[2][2] = matrix[3][2] = 1;
	matrix[3][3] = 1;

	int mod = 1000000009;
	while (t--)
	{
		int n;
		std::cin >> n;

		// 이미 계산해서 존재한다면
		if (n < matrix.size())
		{
			std::cout << (matrix[n][1] + matrix[n][2] + matrix[n][3]) % mod << '\n';
			continue;
		}

		int i = matrix.size();
		// 방법의 수를 1000000009로 나눈 나머지를 출력한다.
		for (; i <= n; i++)
		{
			std::vector<long long> row(4);
			/* 
				숫자는 연속적으로 나오면 안된다. 
				즉, 1로 시작하면 그 다음은 2와 3으로 시작해야 된다.
				표현해야 되는 수 - 1인(i - 1)을 2와 3으로 표현할 수 있는 수가 
				목표 정수(i)를 1로 시작할 수 있는 식의 개수
				ec) 목표가 4인 경우 4 - 1 = 3이고 3을 1을 제외한 2와 3으로
				표현할 수 있는 개수는 2개이다.
			*/ 		
			row[1] = (matrix[i - 1][2] + matrix[i - 1][3]) % mod; 
			// 목표 정수(i)를 2로 시작할 수 있는 식의 개수.
			// 즉, i - 2를 2가 아닌 1과 3으로 표현할 수 있는 식의 개수
			row[2] = (matrix[i - 2][1] + matrix[i - 2][3]) % mod;
			row[3] = (matrix[i - 3][1] + matrix[i - 3][2]) % mod;
			matrix.push_back(row);
		}
		std::cout << (matrix[n][1] + matrix[n][2] + matrix[n][3]) % mod << '\n';
	}

	return 0;
}