#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    map<int, int> c;
    set<int> b;
    
    // 모든 토핑을 한 사람이 가지고 있는다
    for (const int& i : topping)
        c[i]++;
    
    // 토핑을 하나씩 다른 사람에게 주면서 토핑 가지수를 비교
    for (const int& i : topping)
    {
        c[i]--;
        if (c[i] == 0)
            c.erase(i);
        b.insert(i);
        
        if (c.size() == b.size())
            answer++;
    }
    
    return answer;
}