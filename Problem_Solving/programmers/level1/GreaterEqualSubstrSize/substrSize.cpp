#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for (int i = 0; i + p.size() <= t.length(); i++)
    {
        // t의 비교하는 substr이 p보다 작거나 같을 떄
        if (t.compare(i, p.size(), p) <= 0) {
            answer++;
        }
    }
    
    return answer;
}