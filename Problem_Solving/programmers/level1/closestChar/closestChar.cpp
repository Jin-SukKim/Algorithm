#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> idx;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (!idx.count(s[i]))
        {
            answer.push_back(-1);
            idx[s[i]] = i;
        }
        else {
            answer.push_back(i - idx[s[i]]);
            idx[s[i]] = i;
        }
    }
    
    return answer;
}