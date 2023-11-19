#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

// 각 자리수의 가중치 [5^4, 5^3, 5^2, 5^1, 5^0]
// ex) AAAAA = 6, 5^0 * 5(길이) + 1, A부터 시작 = A = 1
// ex) AAE = 1 + 1 + (5^2 + 5^1 + 5^0) * index(E), 1 + 1 
int PosWeight(int n)
{
    int w = 0;
    for (int i = 0; i < 5 - n; i++)
    {
        w += pow(5, i);
    }
    return w;
}

int solution(string word) {
    int answer = 0;
    map<char, int> alphabet = {{'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4}};
    
    int length = 0;
    for (char& c : word)
    {
        answer += PosWeight(length++) * alphabet[c] + 1;
    }
    
    return answer;
}