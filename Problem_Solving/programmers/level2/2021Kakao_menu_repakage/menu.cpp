#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

// 많은 손님이 선택한 순서
struct cmp {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
    }
};

// 코스 조합
void SetCombo(string& order, map<string, int>& combo, string& foods, int idx, int depth) {
    if (depth == foods.length()) {
        combo[foods]++;
        return;
    }
    
    for (int i = idx; i < order.length(); i++)
    {
        foods[depth] = order[i];
        SetCombo(order, combo, foods, i + 1, depth + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    map<string, int> combo;
    for (string& o : orders) {
        sort(o.begin(), o.end());
        for (int& l : course) {
            string foods = "";
            foods.resize(l);
            SetCombo(o, combo, foods, 0, 0);
        }
    }
    
    map<int, priority_queue<pair<string, int>, vector<pair<string, int>>, cmp>> courses;
    for (auto& [key, value] : combo) 
        courses[key.length()].push({key, value});
    
    for (int& i : course) {
        if (!courses[i].empty()) {
            auto [c, max] = courses[i].top();
            // 2명 이상의 손님이 선택한 콤보
            if (max < 2)
                continue;
            
            answer.push_back(c);
            courses[i].pop();
            while (!courses[i].empty() && courses[i].top().second == max)
            {
                answer.push_back(courses[i].top().first);
                courses[i].pop();
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}