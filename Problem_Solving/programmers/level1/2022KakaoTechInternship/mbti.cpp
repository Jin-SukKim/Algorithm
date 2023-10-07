#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    string pair[4] = {"RT", "CF", "JM", "AN"};
    int score[8] = {0, 3, 2, 1, 0, 1, 2, 3};
    map<char, int> point;
    
    for (int i = 0; i < survey.size(); i++)
    {
        char type = choices[i] < 4 ? survey[i][0] : survey[i][1];
        point[type] += score[choices[i]];
    }

    for (string& s : pair)
        answer += point[s[0]] >= point[s[1]] ? s[0] : s[1];
    
    return answer;
}