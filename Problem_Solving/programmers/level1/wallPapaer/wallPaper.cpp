#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Position {
    int x, y;
};

vector<int> solution(vector<string> wallpaper) {
    
    Position begin = {(int)wallpaper[0].length(), (int)wallpaper.size()}, end = {0, 0};
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].length(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                begin.x = min(begin.x, j);
                begin.y = min(begin.y, i);
                end.x = max(end.x, j);
                end.y = max(end.y, i);
            }
        }
    }
    
    
    return {begin.y, begin.x, end.y + 1, end.x + 1};
}