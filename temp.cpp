#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool Compare(map<string, int> w, const vector<string>& discount, int i)
{
    for (; i < i + 10; i++) {
        if (w.count(discount[i]) && w[discount[i]])
            w[discount[i]]--;
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


int main()
{
    solution({"banana", "apple", "rice", "pork", "pot"}, {3, 2, 2, 2, 1}, {"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"});
    return 0;
}