/*
Baekjoon Stie에서 다른 사람의 답
#include <cstdio>

int S[20][2]{}, N, min = 1e9;
void dfs(int cnt, int curr, int sum) {
    if (curr == N) {
        if (cnt == 0 || cnt == N) return;
        if (sum < 0) sum = -sum;
        if (min > sum) min = sum;
        return;
    }

    dfs(cnt + 1, curr + 1, sum + S[curr][0]);
    dfs(cnt, curr + 1, sum - S[curr][1]);
}

int main(void) {
    int num; scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &num);
            S[i][0] += num;
            S[j][1] += num;
        }
    }
    dfs(0, 0, 0);
    printf("%d", min);
}
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

int teamStat(std::vector<std::vector<int>> &stat, int &i, int &j)
{
    return stat[i][j] + stat[j][i];
}

void backTracking(std::vector<std::vector<int>> &stat, std::vector<bool> &visited,
                  int &N, int index, int depth, int &diff, int people)
{
    if (depth == people)
    {
        int team1 = 0;
        int team2 = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i] && visited[j])
                    team1 += teamStat(stat, i, j);
                if (!visited[i] && !visited[j])
                    team2 += teamStat(stat, i, j);
            }
        }
        int temp = std::abs(team1 - team2);
        diff = std::min(diff, temp);
        return;
    }

    for (int i = index; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            backTracking(stat, visited, N, i + 1, depth + 1, diff, people);
            visited[i] = false;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> stat(N, std::vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            std::cin >> stat[i][j];

    std::vector<bool> visitied(N);

    int diff = INT_MAX;
    for (int i = 1; i < N - 1; i++)
        backTracking(stat, visitied, N, 0, 0, diff, i);
    std::cout << diff;
    return 0;
}