#include <iostream>
#include <vector>
#include <queue>

struct emoticon
{
    int emote;
    int clip;
    int sec;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int S;
    std::cin >> S;

    std::queue<emoticon> q;
    q.push({1, 0, 0});

    // a개의 이모티콘과 b개의 클립보드가 있을 때
    std::vector<std::vector<bool>> visited(2000, std::vector<bool>(2000, false));

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();

        if (f.emote == S)
        {
            std::cout << f.sec;
            break;
        }

        if (f.emote - 1 > 0 && !visited[f.emote - 1][f.clip])
        {
            visited[f.emote][f.clip] = true;
            q.push({f.emote - 1, f.clip, f.sec + 1});
        }

        if (f.clip && f.emote + f.clip < 2000 && !visited[f.emote + f.clip][f.clip])
        {
            visited[f.emote + f.clip][f.clip] = true;
            q.push({f.emote + f.clip, f.clip, f.sec + 1});
        }

        if (f.emote > 0 && f.emote <= 2000 && !visited[f.emote][f.emote])
        {
            visited[f.emote][f.emote] =true;
            q.push({f.emote, f.emote, f.sec + 1});
        }
    }

    return 0;
}