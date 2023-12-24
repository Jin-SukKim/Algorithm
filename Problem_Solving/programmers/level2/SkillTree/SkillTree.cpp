#include <string>
#include <vector>

using namespace std;

// 이전 스킬 배우기 전 앞의 스킬을 먼저 배우는지 확인
bool Cheat(const string& skill, const char& curSkill,const int& idx) {
    for (int i = idx + 1; i < skill.length(); i++)
        if (curSkill == skill[i])
            return true;
    return false;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (string& skill_tree : skill_trees) {
        int idx = 0;
        bool order = true;
        for (char& s : skill_tree) {
            // 스킬을 배우는 순서에 맞게 배우고 있다면
            if (s == skill[idx])
                idx++;
            // 스킬을 순서대로 모두 배웠다면
            if (idx == skill.length())
                break;
            else if (Cheat(skill, s, idx)){   
                order = false;
                break;
            }
        }
        
        if (order)
            answer++;
    }
    return answer;
}