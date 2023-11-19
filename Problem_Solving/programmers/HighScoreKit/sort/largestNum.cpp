#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), [](const int& a, const int& b)
         {
             string n1 = to_string(a);
             string n2 = to_string(b);
             return n1 + n2 > n2 + n1;
         });

    int zeroCheck = 0;
    for (int& i : numbers) {
        answer += to_string(i);
        zeroCheck += i;
    }
    if (zeroCheck)
        return answer;
    return "0";
}