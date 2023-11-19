#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> stock;
    for (int i = 0; i < prices.size(); i++)
    {
        // 가격이 떨어지면
        while (!stock.empty() && prices[stock.top()] > prices[i])
        {
            answer[stock.top()] = i - stock.top();
            stock.pop();
        }
        
        stock.push(i);
    }
    
    // 끝까지 가격이 떨어지지 않은 시점
    while (!stock.empty())
    {
        answer[stock.top()] = prices.size() - stock.top() - 1;
        stock.pop();
    }
    
    return answer;
}