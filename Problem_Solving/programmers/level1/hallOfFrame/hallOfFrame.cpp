#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int eq = 0, diff = 0;
    char& x = s[0];
    for (int i = 0; i < s.length(); i++)
    {
        if (eq == diff)
        {
            x = s[i];
            answer++;
            diff = 0;
            eq = 0;
        }
        
        if (x != s[i])
            diff++;
        else if (x == s[i])
            eq++;
    }
    
    return answer;
}