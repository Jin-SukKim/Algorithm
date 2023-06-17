/*
    406. Queue Reconstruction by Height
        You are given an array of people, people,
        which are the attributes of some people in a queue
        (not necessarily in order).
        Each people[i] = [hi, ki] represents the ith person of height hi
        with exactly ki other people in front who have a height greater
        than or equal to hi.

        Reconstruct and return the queue that is represented
        by the input array people.
        The returned queue should be formatted as an array queue,
        where queue[j] = [hj, kj] is the attributes of the jth person
        in the queue (queue[0] is the person at the front of the queue).

    Example 1:
        Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
        Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
        Explanation:
        Person 0 has height 5 with no other people taller or the same height in front.
        Person 1 has height 7 with no other people taller or the same height in front.
        Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
        Person 3 has height 6 with one person taller or the same height in front, which is person 1.
        Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
        Person 5 has height 7 with one person taller or the same height in front, which is person 1.
        Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

    Example 2:
        Input: people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
        Output: [[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]

    Constraints:
        1 <= people.length <= 2000
        0 <= hi <= 106
        0 <= ki < people.length
        It is guaranteed that the queue can be reconstructed.
*/
#include <vector>
#include <queue>
#include <algorithm>

class Solution
{
public:
    using pair = std::pair<int, int>;
    struct compare
    {
        bool operator()(const pair &a, const pair &b)
        {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        }
    };
    // 사람 : (h, k) = (키, 앞에 줄 선 사람들 중 자신의 키 이상인 사람들의 수)
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people)
    {

        // 우선순위 큐는 매번 그때그때의 최소 또는 최댓값을 추출하기에 그리디에 어울린다.
        // 키가 큰 순서대로 데이터를 저장한다.
        std::priority_queue<pair, std::vector<pair>, compare> q;
        for (auto p : people)
            q.push(std::make_pair(p[0], p[1]));

        std::vector<std::vector<int>> result;
        // 사람의 두번째 데이터인 앞에 키가 큰 사람 수를 index로 활용해 중간에 데이터를 업데이트 시킨다.
        while (!q.empty())
        {
            pair person = q.top();
            result.insert(result.begin() + person.second, {person.first, person.second});
            q.pop();
        }

        return result;
    }

    std::vector<std::vector<int>> reconstructQueue2(std::vector<std::vector<int>> &people)
    {

        // 우선순위 큐는 매번 그때그때의 최소 또는 최댓값을 추출하기에 그리디에 어울린다.
        // 키가 큰 순서대로 데이터를 저장한다.
        std::sort(people.begin(), people.end(), [](const auto &a, const auto &b)
                  { return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; });

        std::vector<std::vector<int>> result;
        // 사람의 두번째 데이터인 앞에 키가 큰 사람 수를 index로 활용해 중간에 데이터를 업데이트 시킨다.
        for (const auto& person : people)
            result.insert(result.begin() + person[1], person);

        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> people = {
        {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution s;
    s.reconstructQueue2(people);
    return 0;
}