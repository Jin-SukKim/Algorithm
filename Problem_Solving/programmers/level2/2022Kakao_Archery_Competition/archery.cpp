#include <string>
#include <vector>

using namespace std;

int GetDiff(vector<int>& apeach, vector<int>& ryan) {
    int aScore = 0, rScore = 0;
    for (int i = 0; i < 11; i++)
    {
        if (ryan[i] > apeach[i])
            rScore += 10 - i;
        else if (apeach[i] > 0)
            aScore += 10 - i;
    }
    return rScore - aScore;
}

bool cmp(vector<int>& ryan, vector<int>& result) {
    for (int i = 10; i > -1; i--)
    {
        // 낮은 점수에 맞힌 화살의 개수가 더 많은 경우
        if (ryan[i] > result[i])
            return false;
        else if (ryan[i] < result[i])
            return true;
    }
    return true;
}

void Shooting(vector<int>& apeach, vector<int>& ryan, vector<int>& result, int idx, int arrows, int& diff)
{
    if (arrows == 0 || idx == apeach.size() - 1) {
        ryan[10] = arrows;
        int d = GetDiff(apeach, ryan);
        // 기존의 점수차가 큰 경우
        // 점수 차가 여러 가지인 경우 낮은 점수를 많이 맞힌 경우가 정답
        if (diff > d || diff == d && cmp(ryan, result)) 
            return;
        
        result = ryan;
        diff = d;
        
        return;
    }
    
    Shooting(apeach, ryan, result, idx + 1, arrows, diff);
    if (apeach[idx] < arrows) {
        ryan[idx] = apeach[idx] + 1;
        Shooting(apeach, ryan, result, idx + 1, arrows - ryan[idx], diff);
        ryan[idx] -= apeach[idx] + 1;
    }
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer = { -1 };
    vector<int> ryan(11, 0);
    int diff = 0;
    Shooting(info, ryan, answer, 0, n, diff);
    return answer;
}