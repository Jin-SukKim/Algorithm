#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Position {
    int x, y;
};

Position SetDestination(Position start, char& dir, int dist)
{
    switch (dir)
    {
        case 'N':
            start.y -= dist;
            break;
        case 'S':
            start.y += dist;
            break;
        case 'W':
            start.x -= dist;
            break;
        case 'E':
            start.x += dist;
            break;
        default:
            break;
    }
    return start;
}

bool moveCheck(vector<string>& park, Position start, Position dest, string& s)
{
    if (dest.x < 0 || dest.x >= park[0].size() || dest.y < 0 || dest.y >= park.size())
        return false;
    
    Position move = start;
    do {
        move = SetDestination(move, s[0], 1);
        cout << "Move : " << move.y << " " << move.x << "\n";
        if (park[move.y][move.x] == 'X')
            return false;
    } while (dest.x != move.x || dest.y != move.y);
    
    return true;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    Position pos;
    bool find = false;
    for (int i = 0; i < park.size(); i++) {
        if (find)
            break;
        for (int j = 0; j < park[i].size(); j++) {
            if (park[i][j] == 'S')  {
                pos = {j, i}; 
                find = true;
                break;
            }
        }
    }
        
    for (string& s : routes)
    {
        Position dest = SetDestination(pos, s[0], s[2] - '0');
        cout << dest.y << " " << dest.x << "\n";
        if (moveCheck(park, pos, dest, s))
            pos = dest;
        cout << pos.y << " " << pos.x << "\n";
    }
    return {pos.y, pos.x};
}

int main()
{
    vector<string> park = {"OSO", "OOO", "OXO", "OOO"};
    vector<string> routes = {"E 2", "S 3", "W 1"};
    solution(park, routes);
}