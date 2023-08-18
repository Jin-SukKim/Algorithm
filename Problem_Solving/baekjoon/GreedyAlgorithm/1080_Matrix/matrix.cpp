#include <iostream>
#include <vector>
#include <string>
using Matrix = std::vector<std::vector<bool>>;

void convert(Matrix& m, int c, int r)
{
    for (int i = c; i < c + 3; i++)
    {
        for (int j = r; j < r + 3; j++)
        {
            m[i][j] = !m[i][j];
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    
    // 0과 1만 입력할 것이므로 bool로 해도 된다.
    // 간편하게 뒤집기위해 bool을 사용했다.
    Matrix matrixA(N, std::vector<bool>(M));
    Matrix matrixB(N, std::vector<bool>(M));
    
    for (int i = 0; i < N; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < M; j++)
        {
            matrixA[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < M; j++)
        {
            matrixB[i][j] = s[j] - '0';
        }
    }

    int count = 0;
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            if (matrixA[i][j] != matrixB[i][j])
            {
                convert(matrixA, i, j);
                count++;
            }
        }
    }

    // matrixA를 matrixB로 바꿀수 없다면
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matrixA[i][j] != matrixB[i][j])
            {
                std::cout << -1;
                return 0;
            }
        }
    }
    
    std::cout << count;

    return 0;
}