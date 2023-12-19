#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    // 앞에 있는 숫자일수록 집합 안에 더 자주 포함된다.
    map<int, int> nCount;
    string num = "";    
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num += s[i];
        } else if (num.length()) {
            nCount[stoi(num)]++;
            num.clear();   
        }
    }
    
    vector<pair<int, int>> order(nCount.begin(), nCount.end());
    sort(order.begin(), order.end(), cmp);
    
    for (auto [key, vluae] : order)
        answer.push_back(key);
    
    return answer;
}