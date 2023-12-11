#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

// 주어진 info로 만들수 있는 16가지 key 조합 생성
void SetData(unordered_map<string, vector<int>>& database, string* keySet, string key, int idx) {
    if (idx == 4) {
        database[key].push_back(stoi(keySet[idx]));
        return;
    }
    
    SetData(database, keySet, key + "-", idx + 1);
    SetData(database, keySet, key + keySet[idx], idx + 1);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string keySet[5];
    
    // 조건에 따른 점수 배열
    unordered_map<string, vector<int>> database;
    for (string& i : info) {
        int idx = 0;
        stringstream ss(i);
        while (ss >> keySet[idx])
            ++idx;
        
        // 각 조합에 score 입력
        SetData(database, keySet, "", 0);
    }
    
    // 정렬
    for (auto& [key, value] : database) {
        sort(value.begin(), value.end());
    }
    
    for (string& q : query) {
        stringstream ss(q);
        string s, key = "";
        int idx = 0;
        while (ss >> s) {
            if (s != "and") {
                // lower_bound로 score 이상의 시작 위치 찾기
                if (idx == 4)  {
                    auto it = lower_bound(database[key].begin(), database[key].end(), stoi(s));
                    answer.push_back(database[key].size() - (it - database[key].begin()));
                }
                
                key += s;
                idx++;
            }
        }
    }
    
    return answer;
}