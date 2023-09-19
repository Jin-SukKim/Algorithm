#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> calls;
    for (int i = 0; i < players.size(); i++)
    {
        calls[players[i]] = i;
    }
    
    for (string& s : callings)
    {
        int idx = calls[s]--;
        string temp = players[idx - 1];
        calls[temp]++;
        
        players[idx - 1] = players[idx];
        players[idx] = temp;
    }
    
    return players;
}