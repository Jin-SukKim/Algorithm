#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0; 
    
    --col;
    auto cmp = [&col](const vector<int>& a, const vector<int>& b)
    {
        // 내림차순
        if (a[col] == b[col])
            return a[0] > b[0];
        // 오름차순
        return a[col] < b[col];
    };
    
    sort(data.begin(), data.end(), cmp);
    
    for (--row_begin; row_begin < row_end; row_begin++)
    {
        int S_i = 0;
        for (const int& d : data[row_begin]) 
            S_i += d % (row_begin + 1);
        
        answer ^= S_i;
    }

    return answer;
}