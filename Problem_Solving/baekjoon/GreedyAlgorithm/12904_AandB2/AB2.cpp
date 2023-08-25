#include <iostream>
#include <string>
#include <algorithm>

void dfs(std::string& S, std::string& T)
{
    if (S == T)
    {
        std::cout << 1;
        exit(0);
    }

    if (S.size() >= T.size())
        return;

    if (T.back() == 'A')
    {
        std::string temp = T;
        temp.pop_back();
        dfs(S, temp);
    }

    if (T[0] == 'B')
    {
        std::string temp = T;
        temp.erase(temp.begin());
        std::reverse(temp.begin(), temp.end());
        dfs(S, temp);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string S, T;

    std::cin >> S >> T;
    dfs(S, T);
    std::cout << 0;
    return 0;
}