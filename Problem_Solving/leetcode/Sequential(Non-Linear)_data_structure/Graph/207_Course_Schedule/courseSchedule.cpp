/*
    207. Course Schedule
        There are a total of numCourses courses you have to take,
        labeled from 0 to numCourses - 1.
        You are given an array prerequisites where
        prerequisites[i] = [ai, bi] indicates that you must take course
        bi first if you want to take course ai.

        For example, the pair [0, 1], indicates that to take course 0
        you have to first take course 1.
        Return true if you can finish all courses.
        Otherwise, return false.

    Example 1:
        Input: numCourses = 2, prerequisites = [[1,0]]
        Output: true
        Explanation: There are a total of 2 courses to take.
        To take course 1 you should have finished course 0. So it is possible.
        Example 2:

        Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
        Output: false
        Explanation: There are a total of 2 courses to take.
        To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

    Constraints:

        1 <= numCourses <= 2000
        0 <= prerequisites.length <= 5000
        prerequisites[i].length == 2
        0 <= ai, bi < numCourses
        All the pairs prerequisites[i] are unique.
*/
#include <vector>

bool dfs(std::vector<std::vector<int>> &graph, std::vector<bool> &traced, std::vector<bool> &visited, int course)
{
    // 순환 구조인 경우
    if (traced[course])
        return false;
    // 중복 방문 방지
    if (visited[course])
        return true;

    traced[course] = true;
    // 순환 구조를 찾기위해 탐색
    for (int pre : graph[course])
    {
        if (!dfs(graph, traced, visited, pre))
            return false;
    }

    // 모든 탐색이 끝나면 방문했던 내역을 삭제해준다.
    // 삭제하지 않으면 Sibling(형제) 노드가 방문한 노드까지 남아
    // 자식 노드 입장에서 순환이 아닌데 순환이라 잘못 판단할 수 있다.
    // 탐색 종료 후 순환 노드 삭제
    traced[course] = false;
    // 탐색 종료 후 방문 노드 추가
    visited[course] = true;

    return true;
}

bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
{
    std::vector<std::vector<int>> graph(numCourses);
    // 그래프 생성
    for (auto c : prerequisites)
    {
        graph[c.front()].push_back(c.back());
    }

    // 순환 구조 판별을 위한 변수.
    // ex) [[0, 1], [1, 0]] = 순환 구조
    // 즉 0을 완료하기 위해 1을 끝내야 하지만 1을 완료하기 위해 0을 끝내야하는 경우 등
    std::vector<bool> traced(numCourses, false); // std::set()을 사용해도 된다.

    // 한 번 방문한 노드를 다시 방문하지 않도록 가지치기 해준다
    std::vector<bool> visited(numCourses, false);

    for (int i = 0; i < numCourses; i++)
    {
        if (!dfs(graph, traced, visited, i))
            return false;
    }

    return true;
}

bool canFinish2(int n, std::vector<std::vector<int>> &prerequisites)
{
    std::vector<std::vector<int>> G(n);
    std::vector<int> degree(n, 0), bfs;
    for (auto &e : prerequisites)
        G[e[1]].push_back(e[0]), degree[e[0]]++;
    for (int i = 0; i < n; ++i)
        if (!degree[i])
            bfs.push_back(i);
    for (int i = 0; i < bfs.size(); ++i)
        for (int j : G[bfs[i]])
            if (--degree[j] == 0)
                bfs.push_back(j);
    return bfs.size() == n;
}

int main()
{
    std::vector<std::vector<int>> pre =
        {
            {0, 1},
            {0, 2},
            {1, 2}
            };

    canFinish(3, pre);
    canFinish2(3, pre);

    return 0;
}