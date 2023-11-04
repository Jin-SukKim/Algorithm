#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;


int solution(int storey) {
    int answer = 0;
    
    while (storey)
    {
        int r = storey % 10;
        if (r == 5)
        {
            int front = storey / 10;
            // 만약 맨 뒷자리 수가 5일 때 앞 자리수가 5 이상이면 
            // 올리는 것이 좋고 아니라면 내리는 것이 더 좋다.
            if (front % 10 >= 5)
                storey += 5;
            answer += 5;
        }
        else if (r > 5) {
            answer += 10 - r;
            storey += 10;
        }
        else
            answer += r;
        
        storey /= 10;
    }
    
    return answer;
}