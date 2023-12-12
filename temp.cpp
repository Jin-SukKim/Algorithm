#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

void SetCombo(string& order, map<string, int>& combo, string foods, int idx, int depth) {
    if (depth > 1)
        combo[foods]++;
    
    if (idx < order.length()) {
        SetCombo(order, combo, foods, idx + 1, depth);
        SetCombo(order, combo, foods + order[idx], idx + 1, depth + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    map<string, int> combo;
    for (string& o : orders)
        SetCombo(o, combo, "", 0, 0);
    
    using pQueue = priority_queue<pair<string, int>, vector<string, int> >;
    map<int, priority_queue<
    
    return answer;
}