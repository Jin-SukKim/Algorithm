#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> cnt;
    for (const int& o : tangerine)
        cnt[o]++;
    
    vector<pair<int, int>> tangs(cnt.begin(), cnt.end());
    sort(tangs.begin(), tangs.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; });
    
    for (auto [o, cnt] : tangs)
    {
        answer++;
        k -= cnt;
        
        if (k < 1)
            break;
    }
    
    return answer;
}