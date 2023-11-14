#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> S;

    int n = elements.size();

    for (int i = 0 ; i < n; ++i) {
        int sum = 0;
        // 각각 index 별로 구할 수 있는 부분을 다 구한다.
        // ex) 0 index의 1개, 2개, 3개, 4개 ... n개 부분 수열의 합을 구하고 
        //     그 다음 1 index의 부분 수열 합들을 구한다. ~> 끝까지 반복
        for (int j = i; j < i + n ; ++j) {
            sum += elements[j % n];
            S.insert(sum);
        }
    }

    return S.size();
}

int solution(vector<int> elements)
{
    int n = elements.size();
    vector<int> dp(elements.begin(), elements.end());
    
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int m = i + j - 1;
            if (m >= n)
                m %= n;
            dp.push_back(dp[(i - 2) * n + j] + dp[m]);
        }
    }
    set<int> answer(dp.begin(), dp.end());
    
    return answer.size();
}