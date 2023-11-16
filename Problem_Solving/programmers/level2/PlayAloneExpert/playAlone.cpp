#include <string>
#include <vector>
#include <iostream>

using namespace std;

int OpenBox(vector<int>& cards, int i)
{
    int cnt = 0;
    // 방문할 상자가 있다면
    while (cards[i])
    {
        int temp = cards[i] - 1;
        // 방문한 상자
        cards[i] = 0;
        i = temp;
        cnt++;
    }
    
    return cnt;
}

int solution(vector<int> cards) {
    // 상자를 방문하는 순서와 그룹을 결정짓는 것은 무관하다.
    // 하나의 그룹은 서로 이어져 있으므로 일정하게 유지된다.
    int group1 = OpenBox(cards, 0);
    
    int group2 = 0;
    for (int& i : cards)
    {
        if (i) {
            int g = OpenBox(cards, i - 1);
            if (g > group1 || g > group2) {
                // 최고 점수를 얻기 위해선 가장 많은 박스를 가진 그룹들을 찾아야한다.
                group1 = group2 > group1 ? group2 : group1;
                group2 = g;
            }
        }
    }
    
    return group1 * group2;
}