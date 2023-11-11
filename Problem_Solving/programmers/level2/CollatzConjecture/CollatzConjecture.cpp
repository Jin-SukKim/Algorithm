#include <string>
#include <vector>
#include <iostream>

using namespace std;

void LotharCollatz(vector<int>& lothar, int& n)
{
    if (n < 2)
        return;
    
    // 홀수라면 3을 곱하고 1을 더한다.
    if (n & 1)
        n = n * 3 + 1;
    // 짝수라면 2로 나눈다.
    else
         n /= 2;
    
    lothar.push_back(n);
    // 결과가 1보다 크다면 반복
    LotharCollatz(lothar, n);
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> lothar(1, k);
    LotharCollatz(lothar, k);
    
    // x2 - x1 = 1인 각 구간별 넓이
    vector<double> sizes(lothar.size(), 0);
    
    for (const auto& range : ranges)
    {
        int x = range[0];
        int xE = lothar.size() + range[1] - 1;
        
        // 시작점이 끝점보다 큰 경우
        if (x > xE) {
            answer.push_back(-1.0);
            continue;
        }
        
        double size = 0;
        for (; x < xE; x++)
        {
            if (!sizes[x])
                // 사다리꼴 면적 = (윗변 + 아랫변) * 높이 / 2
                sizes[x] = (double) (lothar[x] + lothar[x + 1]) / 2;
            size += sizes[x];
        }
        
        answer.push_back(size);
    }
    
    return answer;
}