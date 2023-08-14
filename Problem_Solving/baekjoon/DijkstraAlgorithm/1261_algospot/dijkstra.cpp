#include <iostream>
#include <vector>
#include <queue>
#include <string>

struct path
{
    int weight;
    std::pair<int, int> position;
};

struct cmp
{
    bool operator()(const path &a, const path &b) const
    {
        return a.weight > b.weight;
    }
};
/*
    1. 출발 노드 설정
    2. 방문하지 않은 노드 중 최단 거리가 가장 짧은 노드를 선택
    3. 해당 노드를 거쳐 다음 노드로 가는 비용을 계산해 최단 거리 테이블 갱신
        ㄴ 만약, 현재 테이블의 최단 거리보다, 해당 노드를 거쳐가는 비용이 더 적으면 교쳬
    4. 1~3 반복
*/
// 다익스트라 알고리즘으로 최단거리 노드를 선택해 시작 지점에서 목표지점까지의 최단거리를 찾는다.
void dijkstra(std::vector<std::vector<int>> &maze, int &N, int &M)
{
    // 한 칸씩 움직일 수 있는 방향
    int dirCol[4] = {0, 0, -1, 1};
    int dirRow[4] = {-1, 1, 0, 0};

    // 최단 거리를 측정하기 위한 변수로 최대한 큰(INT_MAX 등) 값으로 초기화
    std::vector<std::vector<int>> distance(N, std::vector<int>(M, 1e9));
    // 우선순위 큐로 거리(weight)이 짧은 노드를 먼저 비교할 수 있도록 한다.
    // 최단거리 노드 선택
    std::priority_queue<path, std::vector<path>, cmp> q;
    // start position
    q.push({0, std::make_pair(0, 0)});
    distance[0][0] = 0;

    while (!q.empty())
    {
        auto top = q.top();
        q.pop();

        int col = top.position.first;
        int row = top.position.second;
        int weight = top.weight;

        // 큐에 넣을 때 방문했던 곳인지 파악하지 않기 때문에 한 번 더 삽입될 수 있다.
        // 현재 노드까지 비용 처리가 되어 있고 더 적은 비용이 든다면
        // 큐에서 나온 노드의 거리가 최단거리 테이블보다 크면 이미 갱신된 것으로 판단
        if (distance[col][row] < weight)
            continue;

        // 현재 노드와 연결된 갈 수 있는 인접한 노드들 확인
        for (int i = 0; i < 4; i++)
        {
            int nCol = col + dirCol[i];
            int nRow = row + dirRow[i];

            // 미로 범위 밖이라면
            if (nCol < 0 || nCol >= N || nRow < 0 || nRow >= M)
                continue;

            // 현재 노드를 거쳐 다음 노드까지 갈 때의 비용
            int cost = weight + maze[nCol][nRow];
            // 이미 저장된 다음 노드까지 가는 비용이 더 비싼 경우
            if (cost < distance[nCol][nRow])
            {
                distance[nCol][nRow] = cost;
                q.push({cost, {nCol, nRow}});
            }
        }
    }

    std::cout << distance[N - 1][M - 1];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int M, N;
    std::cin >> M >> N;

    std::vector<std::vector<int>> maze(N, std::vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < M; j++)
        {
            maze[i][j] = s[j] - '0';
        }
    }
    dijkstra(maze, N, M);
    return 0;
}