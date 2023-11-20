#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>>& computers, vector<bool>& connect, int idx)
{
    for (int i = 0; i < computers[idx].size(); i++)
    {
        if (!connect[i] && computers[idx][i]) {
            connect[i] = true;
            dfs(computers, connect, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> connect(n, 0);
    
    for (int i = 0; i < n; i++)
    {
        if (!connect[i]) {
            answer++;
            connect[i] = true;
            dfs(computers, connect, i);
        }
    }
    
    return answer;
}