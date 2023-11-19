#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct Stock {
    int Price = 0;
    int Index = 0;
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<Stock> stock;
    stock.push({prices[0], 0});
    for (int i = 1; i < prices.size(); i++)
    {
        if (stock.empty() || stock.top().Price < prices[i])
            stock.push({prices[i], i});
        else {
            // 가격이 떨어지면
            while (!stock.empty() && stock.top().Price > prices[i])
            {
                int idx = stock.top().Index;
                answer[idx] = i - idx;
                stock.pop();
            }
        }
    }
    
    // 끝까지 가격이 떨어지지 않은 시점
    for (int i = 0; i < answer.size(); i++)
        if (!answer[i])
            answer[i] = answer.size() - i - 1;
    
    return answer;
}


int main()
{
    solution({3, 2, 4, 1, 1});
    return 0;
}