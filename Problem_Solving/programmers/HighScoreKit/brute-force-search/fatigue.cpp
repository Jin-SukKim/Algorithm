#include <string>
#include <vector>

using namespace std;


// 갈 수 있는 모든 방을 가야된다. (종료문 x)
void dfs(vector<vector<int>>& dungeons, vector<bool>& visited, int k, int& max, int cnt) {
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && dungeons[i][0] <= k) {
            visited[i] = true;
            dfs(dungeons, visited, k - dungeons[i][1], max, cnt + 1);
            visited[i] = false;
        }
    }
    
    max = max < cnt ? cnt : max;
}


int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    vector<bool> visited(dungeons.size(), false);
    dfs(dungeons, visited, k, answer, 0);
    
    return answer;
}