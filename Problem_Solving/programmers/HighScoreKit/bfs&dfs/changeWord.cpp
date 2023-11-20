#include <string>
#include <vector>
#include <map>

using namespace std;

// 한 번에 한 개의 알파벳만 바꿀 수 있으므로 두 단어의 알파벳 차이가 1이어야 한다.
bool CheckDiff(const string& a, const string& b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            cnt++;
        if (cnt > 1)
            return false;
    }
    
    if (cnt == 1)
        return true;
    return false;
}

void CountStep(vector<string>& words, vector<bool>& visited, string& cur, const string& target, int cnt, int& minStep)
{
    if (minStep < cnt)
        return;
    
    if (cur == target) {
        minStep = cnt;
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        // words[i] 는 다음 단계의 단어
        if (!visited[i] && CheckDiff(cur, words[i])) {
            visited[i] = true;
            CountStep(words, visited, words[i], target, cnt + 1, minStep);
            visited[i] = false;
        }    
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 51;
    vector<bool> visited(words.size(), false);
    CountStep(words, visited, begin, target, 0, answer);
    
    if (answer == 51)
        return 0;
    return answer;
}