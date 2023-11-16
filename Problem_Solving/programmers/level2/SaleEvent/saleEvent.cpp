#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool Compare(map<string, int> w, const vector<string>& discount, int index)
{
    for (int i = 0; i < 10; i++) {
        if (w.count(discount[index + i]) && w[discount[index + i]])
            w[discount[index + i]]--;
        else 
            return false;
    }
    
    for (auto [want, cnt] : w) 
        if (cnt)
            return false;
    
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wants;
    for (int i = 0; i < want.size(); i++)
        wants[want[i]] = number[i]; 
    
    for (int i = 0; i < discount.size() - 9; i++)
        if (Compare(wants, discount, i))
            answer++;
    
    return answer;
}