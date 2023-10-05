#include <string>
#include <vector>

using namespace std;


void dfs(vector<int>& num,  int index, int depth, int sum, int& answer)
{
    if (depth == 3)
    {
        if ((sum) == 0)
            answer++;
        return;
    }

    for (int i = index; i < num.size(); i++)
        dfs(num, i + 1, depth + 1, sum + num[i], answer);
}

int solution(vector<int> number) {
    int answer = 0;
    
    dfs(number, 0, 0, 0, answer);
    
    return answer;
}