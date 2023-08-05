#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

int teamStat(std::vector<std::vector<int>> &stat, int &i, int &j)
{
    return stat[i][j] + stat[j][i];
}

void backTracking(std::vector<std::vector<int>> &stat, std::vector<bool>& visited,
                  int &N, int index, int depth, int &diff)
{
    if (depth == (N / 2))
    {
        int team1 = 0;
        int team2 = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i] && visited[j])
                    team1 += stat[i][j];
                if (!visited[i] && !visited[j])
                    team2 += stat[i][j];
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
            backTracking(stat, visited, N, i + 1, depth + 1, diff);
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
    backTracking(stat, visitied, N, 0, 0, diff);
    std::cout << diff;
    return 0;
}