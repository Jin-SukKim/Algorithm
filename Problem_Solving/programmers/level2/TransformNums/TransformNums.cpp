#include <string>
#include <vector>
#include <iostream>
using namespace std;

void Calculation(int x, const int& y, const int& n, vector<int>& count)
{
    if (x == y) {
        return;
    }
    
    if (x + n <= y && (count[x + n] == -1 || count[x + n] > count[x] + 1)) {
        count[x + n] = count[x] + 1;
        Calculation(x + n, y, n, count);
    }
    if (x * 2 <= y && (count[x * 2] == -1 || count[x * 2] > count[x] + 1)) {
        count[x * 2] = count[x] + 1;
        Calculation(x * 2, y, n, count);
    }
    if (x * 3 <= y && (count[x * 3] == -1 || count[x * 3] > count[x] + 1)) {
        count[x * 3] = count[x] + 1;
        Calculation(x * 3, y, n, count);
    }
}

int solution(int x, int y, int n) {
    vector<int> count(y + 1, -1);
    count[x] = 0;
    Calculation(x, y, n, count);
    
    return count[y];
}