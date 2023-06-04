/*
    743. Network Delay Time
        You are given a network of n nodes, labeled from 1 to n.
        You are also given times, a list of travel times as
        directed edges times[i] = (ui, vi, wi),
        where ui is the source node, vi is the target node,
        and wi is the time it takes for a signal to travel from
        source to target.

        We will send a signal from a given node k.
        Return the minimum time it takes for all the n nodes to
        receive the signal.
        If it is impossible for all the n nodes to receive the signal,
        return -1.

    Example 1:
        Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
        Output: 2
        Example 2:

        Input: times = [[1,2,1]], n = 2, k = 1
        Output: 1
        Example 3:

        Input: times = [[1,2,1]], n = 2, k = 2
        Output: -1

    Constraints:
        1 <= k <= n <= 100
        1 <= times.length <= 6000
        times[i].length == 3
        1 <= ui, vi <= n
        ui != vi
        0 <= wi <= 100
        All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

// 모든 노드가 신호를 받을 수 있는 시간을 계산하기 위해선
// 가장 오래 걸리는 노드까지의 최단 시간을 의마한다.
int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k)
{   
    // network[출발지] = (도착지, 소요시간)
    std::vector<std::vector<std::pair<int, int>>> network(n+1);

    // 그래프 생성
    for (auto net : times)
        network[net[0]].push_back(std::make_pair(net[1], net[2]));

    // 거리
    std::unordered_map<int, int> dist;
    // (time, node) = (소요 시간, 정점)
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int,int>>> q;
    // 맨 처음 출발지
    q.push(std::make_pair(0, k)); 
    std::pair<int, int> path;

    // 최단 경로 찾기
    while(q.size())
    {
        path = q.top();
        q.pop();
        
        if (dist.find(path.second) == dist.end())
        {
            dist[path.second] = path.first;
            // 현재 노드 주변의 노드들을 확인
            for (auto net : network[path.second])
            {   
                // 걸리는 시간을 계속 더해준다.
                int time = path.first + net.second;
                q.push(std::make_pair(time, net.first));
            }
        }
    }

    // 최단 경로 존재 여부 판별
    if (dist.size() == n)
        return std::max_element(dist.begin(), dist.end(), [](const auto &x, const auto &y) {
                    return x.second < y.second;
                })->second;

    return -1;
}

int main()
{
    std::vector<std::vector<int>> times =
    {
        {1,2,1},
        {2,3,2},
        {1,3,4}
    };

    networkDelayTime(times, 3,1);
    return 0;
}