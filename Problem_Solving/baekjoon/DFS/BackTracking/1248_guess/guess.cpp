#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

bool check(std::vector<std::vector<char>>& signs, std::vector<int>& ans, int& index)
{
    int sum = 0;
    for (int i = index; i >= 0; i--)
    {
        // index부터 i까지의 합
        sum += ans[i];

        // index부터 i까지의 합은 signs matrix의 index번째 Column의 모든
        // 부호를 만족시켜야 된다.
        if (signs[i][index] == '+' && sum <= 0) return false;
        if (signs[i][index] == '-' && sum >= 0) return false;
        if (signs[i][index] == '0' && sum != 0) return false;
    }

    return true;
}

void backTracking(std::vector<std::vector<char>>& signs, std::vector<int>& ans,
    int& n, int index)
{
    if (index == n)
    {
        for (int& i : ans)
            std::cout << i << ' ';
        exit(0);
    }

    // 넣을 수 있는 숫자의 범위는 -10부터 10까지다.
    for (int i = -10; i <= 10; i++)
    {
        ans[index] = i;
        if (check(signs, ans, index))
            backTracking(signs, ans, n, index + 1);
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<char>> signs(n, std::vector<char>(n));

    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            signs[i][j] = s[idx++];
    
    std::vector<int> ans(n);

    backTracking(signs, ans, n, 0);
  
    return 0;
}