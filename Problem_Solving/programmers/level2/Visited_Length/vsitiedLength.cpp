#include <string>
#include <map>
using namespace std;

int solution(string dirs) {
    using Pos = pair<int, int>;
    using Edge = pair<Pos, Pos>;
    
    int answer = 0;
    Pos cur = {5, 5}; // 시작은 정중앙에서
    // 방향
    std::map<char, Pos> next = {{'U', {-1, 0}}, {'D', {1, 0}}, {'R', {0, 1}}, {'L', {0, -1}}};
    std::map<Edge, bool> edge;
    
    for (char& d : dirs) {
        auto [dirRow, dirCol] = next[d];
        int nRow = cur.first + dirRow, nCol = cur.second + dirCol;
        if (nRow < 0 || nCol < 0 || nRow > 10 || nCol > 10)
            continue;
        
        if (!edge[{{nRow, nCol}, cur}]) {
            edge[{{nRow, nCol}, cur}] = true;
            edge[{cur, {nRow, nCol}}] = true;
            answer++;
        }
        cur = {nRow, nCol};
    }
    
    return answer;
}