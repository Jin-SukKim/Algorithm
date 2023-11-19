#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (const vector<int>& v : commands)
    {
        vector<int> sub(array.begin() + v[0] - 1, array.begin() + v[1]);
        sort(sub.begin(), sub.end());
        answer.push_back(sub[v[2]-1]);
    }
    
    return answer;
}