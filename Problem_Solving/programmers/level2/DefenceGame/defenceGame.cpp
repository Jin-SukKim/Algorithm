#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int> q;
    
    for (const int& e : enemy)
    {
        q.push(e);
        n -= e;
        
        if (n < 0){
            if (k-- > 0) {
                n += q.top();
                q.pop();
            }
            else
                break;
        } 
        
        answer++;
    }
    
    return answer;
}