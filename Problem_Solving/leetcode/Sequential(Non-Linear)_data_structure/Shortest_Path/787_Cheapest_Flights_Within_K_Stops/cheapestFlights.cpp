/*
    787. Cheapest Flights Within K Stops
        There are n cities connected by some number of flights.
        You are given an array flights where
        flights[i] = [fromi, toi, pricei] indicates that there is
        a flight from city fromi to city toi with cost pricei.

        You are also given three integers src, dst, and k,
        return the cheapest price from src to dst with at most k stops.
        If there is no such route, return -1.

    Example 1:
        Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
        Output: 700
        Explanation:
        The graph is shown above.
        The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
        Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
        Example 2:


        Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
        Output: 200
        Explanation:
        The graph is shown above.
        The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
        Example 3:


        Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
        Output: 500
        Explanation:
        The graph is shown above.
        The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

    Constraints:
        1 <= n <= 100
        0 <= flights.length <= (n * (n - 1) / 2)
        flights[i].length == 3
        0 <= fromi, toi < n
        fromi != toi
        1 <= pricei <= 104
        There will not be any multiple flights between two cities.
        0 <= src, dst, k < n
        src != dst
*/
#include <vector>
#include <queue>

// 47 testcase에 시간초과, 단축할 방법을 생각해봐야됨

// flights = [from, to, price]
// return cheapest price from src to fst with at most k stops
int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int k)
{
    std::vector<std::vector<std::pair<int, int>>> graph(n + 1);

    // 그래프 생성
    for (auto flight : flights)
    {
        graph[flight[0]].push_back(std::make_pair(flight[1], flight[2]));
    }

    // {price, vertex, 남은 경유지 수}
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> q;
    q.push({0, src, k});

    while (q.size())
    {
        auto node = q.top();
        q.pop();

        int price = node[0];
        int cur = node[1];
        int remain = node[2];

        if (cur == dst)
            return price;

        if (remain >= 0)
        {
            for (auto& [node, p] : graph[cur])
            {
                q.push({price + p, node, remain - 1});
            }
        }
    }

    return -1;
}
int main()
{
    std::vector<std::vector<int>> times =
        {
            {0, 1, 1},
            {0, 2, 5},
            {1, 2, 1},
            {2, 3, 1}};

    findCheapestPrice(4, times, 0, 3, 1);
    return 0;
}