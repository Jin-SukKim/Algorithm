/*
    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock
    and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction.
    If you cannot achieve any profit, return 0.

    Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
    Example 2:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.

    Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104

*/
#include <vector>
#include <algorithm>

// 제일 낮은 저점 이후 높은 가격이 안 나올수도 있어 틀렸다.
int maxProfit(std::vector<int> &prices)
{   
    // 최대 이익을 얻기 위해 제일 낮은 최저점에서 시작한다.
    auto price = std::min_element(prices.begin(), prices.end()); ; 
    int min = *price, max = *price;
    for(; price != prices.end(); price++) {
        // 제일 저점을 찍은 후 제일 높은 가격에 팔기위해 최고점을 찾는다.
        max = std::max(max, *price);
    }

    return max - min;
}