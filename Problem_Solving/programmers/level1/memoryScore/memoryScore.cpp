#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> memory;
    for (int i = 0; i < name.size(); i++)
        memory[name[i]] = yearning[i];
    
    for (int i = 0; i < photo.size(); i++)
    {
        int score = 0;
        for (string& s : photo[i])
        {
            if (memory.count(s))
                score += memory[s];
        }
        answer.push_back(score);
    }

    return answer;
}