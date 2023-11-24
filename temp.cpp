#include <string>
#include <vector>
#include <stack>
#include <iostream>

int main()
{
    int n = 517;
    int five = n / 5;
    int three = n / 3;
    for (int i = 0; i <= three; i++)
    {
        int box = five * 5 + i * 3;
        while (box > n)
            box = --five * 5 + i * 3;
            
        if (box == n) {
            std::cout << "Answer!";
            return 0;
        }
    }

    std::cout << "Wrong!";
    return 0;
}