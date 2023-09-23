#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    map<char, int> key;
    for (string& s : keymap)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (key.count(s[i]))
                key[s[i]] = min(key[s[i]], i + 1);
            else
                key[s[i]] = i + 1;
        }
    }
    
    for (string& s : targets)
    {
        int count = 0;
        for (char& c : s){
            if (!key.count(c))
            {
                count = -1;
                break;
            }
            count += key[c];   
        }
        answer.push_back(count);
    }
    
    return answer;
}