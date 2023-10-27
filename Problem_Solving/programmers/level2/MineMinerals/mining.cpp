#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 각 광물 캘 때 소모하는 각 곡갱이 피로도
struct MineSet {
    int dia = 0;
    int iron = 0;
    int stone = 0;
    // weight이 클수록 캐야되는 다이아몬드의 개수가 많은 것
    int weight = 0;
};

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int maxSize = 0;
    for (const int& i : picks)
        maxSize += i * 5;
    maxSize = maxSize < minerals.size() ? maxSize : minerals.size();
    
    vector<MineSet> fiveMinerals;
    
    for (int i = 0; i < maxSize; i += 5)
    {
        MineSet mine;
        for (int j = i; j < i + 5; j++) {
            if (j >= maxSize)
                continue;
            // 광물마다 소모하는 각 곡괭이의 피로도
            if (minerals[j] == "diamond") {
                mine.dia += 1;
                mine.iron += 5;
                mine.stone += 25;
                mine.weight += 25;
            }
            else if (minerals[j] == "iron") {
                mine.dia += 1;
                mine.iron += 1;
                mine.stone += 5;
                mine.weight += 5;
            }
            else if (minerals[j] == "stone") {
                mine.dia += 1;
                mine.iron += 1;
                mine.stone += 1;
                mine.weight += 1;
            }
        }
        fiveMinerals.push_back(mine);
    }
    
    sort(fiveMinerals.begin(), fiveMinerals.end(), [](const MineSet& a, const MineSet& b) {
        return a.weight > b.weight;
    });
    
    for (const MineSet& mine : fiveMinerals)
    {
        if (picks[0])
        {
            picks[0]--;
            answer += mine.dia;
        }
        else if (picks[1])
        {
            picks[1]--;
            answer += mine.iron;
        }
        else if (picks[2])
        {
            picks[2]--;
            answer += mine.stone;
        }
    }
    return answer;
}