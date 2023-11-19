#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

struct Songs
{
    int plays;
    int index;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> gen;
    map<string, vector<Songs>> order;
    for (int i = 0; i < genres.size(); i++)
    {
        gen[genres[i]] += plays[i];
        order[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<string, int>> v(gen.begin(), gen.end());
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
    
    for (auto& [key, value] : v)
    {
        sort(order[key].begin(), order[key].end(), [](const Songs& s1, const Songs& s2) { 
            if (s1.plays == s2.plays) 
                return s1.index < s2.index;
            return s1.plays > s2.plays; 
        });
        
        int size = 0;
        while (size < 2) 
            answer.push_back(order[key][size++].index);
        /*
        int size = 1;
        for (Songs& s : order[key])
        {
            if (size > 2)
                break;
            answer.push_back(s.index);
            size++;
        }
        */
    }
    
    return answer;
}