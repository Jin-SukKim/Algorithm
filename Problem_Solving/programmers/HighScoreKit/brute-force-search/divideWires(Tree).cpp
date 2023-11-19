#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int WireCnt(vector<vector<int>>& tree, vector<bool> visited, int i) {
    queue<int> q;
    q.push(i);
    
    int cnt = 1;
    while(!q.empty())
    {
        i = q.front();
        q.pop();
        
        // 연결된 node 탐색
        for (int& j : tree[i])
        {
            if (!visited[j]) {
                visited[j] = true;
                q.push(j);
                cnt++;
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int minCnt = n + 1;
    
    vector<vector<int>> tree(n + 1);
    for (vector<int>& v : wires)
    {
        tree[v[0]].push_back(v[1]);
        tree[v[1]].push_back(v[0]);
    }
    
    vector<bool> visited(n + 1, false);
    
    for (int i = 1; i< n + 1; i++)
    {
        // 절단의 의미로 i, j를 미리 true로 만들어 넘어갈 수 없게 한다.
        visited[i] = true;
        for (int& j : tree[i])
        {
            visited[j] = true;
            // 한 쪽의 wire 개수를 구했으면 전체 wire 개수에 빼 반대편 wire 개수를 구한다
            int l = WireCnt(tree, visited, i);
            int r = n - l;
            minCnt = min(minCnt, abs(r - l));
            visited[j] = false;
        }
        visited[i] = false;
    }
    
    
    return minCnt;
}