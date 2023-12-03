#include <string>
#include <vector>
#include <algorithm>
#define MAX 505

using namespace std;

struct Dir
{
    int x, y;
};

// 빛이 나가는 방향
Dir moveDir[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // UP, DOWN, LEFT, RIGHT

// 각 노드는 상하좌우, 4 방향으로 나갈 수 있고 이전에 나간 방향으로 나가면
// 같은 사이클이므로 확인해준다.
// 빛의 경로가 한 번도 겹치지 않아야 다른 사이클이다.
bool visited[MAX][MAX][4];

int getCycleLength(int y, int x, int dir, vector<string> &grid)
{
    int len = 0;

    while (1)
    {
        if (visited[y][x][dir])
            break;
        
        visited[y][x][dir] = true;
        len++;

        if (grid[y][x] == 'L')
            dir = dir ? dir - 1 : 3;

        else if (grid[y][x] == 'R')
            dir = dir == 3 ? 0 : dir + 1;

        // grid를 벗어나면 반대쪽 끝으로 다시 돌아오므로 mod 연산을 해 반대쪽으로 넘겨준다.
        x = (x + moveDir[dir].x + grid[0].size()) % grid[0].size();
        y = (y + moveDir[dir].y + grid.size()) % grid.size();
    }

    return len;
}

vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    for (int y = 0; y < grid.size(); y++)
    {
        for (int x = 0; x < grid[0].size(); x++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (visited[y][x][k])
                    continue;
                answer.push_back(getCycleLength(y, x, k, grid));
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}