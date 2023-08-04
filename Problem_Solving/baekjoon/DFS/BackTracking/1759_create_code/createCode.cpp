#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

void backTracking(std::vector<char> &alpha, std::vector<bool> &visited,
                  std::vector<char> &ans, int &L, int &C, int index, int depth, int consonant, int vowels)
{
    if (depth == L && vowels > 0 && consonant > 1)
    {
        for (char& i : ans)
            std::cout << i;
        std::cout << '\n';
        return;
    }

    for (int i = index; i < C; i++)
    {
        if (!visited[i])
        {
            if (alpha[i] == 'a' || alpha[i] == 'e' || 
                alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
                vowels++;
            else
                consonant++;
            visited[i] = true;
            ans[depth] = alpha[i];
            backTracking(alpha, visited, ans, L, C, i, depth + 1, consonant, vowels);
            visited[i] = false;
            if (alpha[i] == 'a' || alpha[i] == 'e' || 
                alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
                vowels--;
            else
                consonant--;
        }
    }
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int L, C;
    std::cin >> L >> C;

    std::vector<char> alpha(C);
    for (int i = 0; i < C; i++)
        std::cin >> alpha[i];

    std::sort(alpha.begin(), alpha.end());
    std::vector<bool> visited(C, false);

    std::vector<char> ans(L);

    backTracking(alpha, visited, ans, L, C, 0, 0, 0, 0);
    return 0;
}