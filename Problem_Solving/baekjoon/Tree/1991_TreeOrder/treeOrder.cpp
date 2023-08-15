#include <iostream>
#include <vector>
#include <queue>
#include <string>

void preorder(std::vector<std::pair<char, char>> &alpha, char& node)
{
    if (node == '.')
        return;
    
    std::cout << node;
    preorder(alpha, alpha[node - 'A'].first);
    preorder(alpha, alpha[node - 'A'].second);
}

void inorder(std::vector<std::pair<char, char>> &alpha, char& node)
{
    if (node == '.')
        return;
    
    inorder(alpha, alpha[node - 'A'].first);
    std::cout << node;
    inorder(alpha, alpha[node - 'A'].second);
}

void postorder(std::vector<std::pair<char, char>> &alpha, char& node)
{
    if (node == '.')
        return;
    
    postorder(alpha, alpha[node - 'A'].first);
    postorder(alpha, alpha[node - 'A'].second);
    std::cout << node;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<char, char>> alpha(N);

    for (int i = 0; i < N; i++)
    {
        char parent, left, right;
        std::cin >> parent >> left >> right;
        alpha[parent - 'A'] = {left, right};
    }

    char index = 'A';
    preorder(alpha, index);
    std::cout << '\n';
    inorder(alpha, index);
    std::cout << '\n';
    postorder(alpha, index);

    return 0;
}