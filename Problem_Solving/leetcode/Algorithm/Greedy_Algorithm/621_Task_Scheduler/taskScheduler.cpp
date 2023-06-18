/*
    621. Task Scheduler
        Given a characters array tasks, 
        representing the tasks a CPU needs to do, 
        where each letter represents a different task. 
        Tasks could be done in any order. 
        Each task is done in one unit of time. 
        For each unit of time, the CPU could complete either one task 
        or just be idle.

        However, there is a non-negative integer n that 
        represents the cooldown period between two same tasks 
        (the same letter in the array), 
        that is that there must be at least n units of time between 
        any two same tasks.

        Return the least number of units of times that 
        the CPU will take to finish all the given tasks.

    Example 1:
        Input: tasks = ['A','A','A','B','B','B'], n = 2
        Output: 8
        Explanation: 
        A -> B -> idle -> A -> B -> idle -> A -> B
        There is at least 2 units of time between any two same tasks.
    
    Example 2:
        Input: tasks = ['A','A','A','B','B','B'], n = 0
        Output: 6
        Explanation: On this case any permutation of size 6 would work since n = 0.
        ['A','A','A','B','B','B']
        ['A','B','A','B','A','B']
        ['B','B','B','A','A','A']
        ...
        And so on.

    Example 3:
        Input: tasks = ['A','A','A','A','A','A','B','C','D','E','F','G'], n = 2
        Output: 16
        Explanation: 
        One possible solution is
        A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
    
    Constraints:
        1 <= task.length <= 104
        tasks[i] is upper-case English letter.
        The integer n is in the range [0, 100].
*/
#include <vector>
#include <unordered_map>
#include <queue>

/*
    A에서 Z로 표현된 Tasks가 있는데 각 간격마다 CPU는 한 번의 Task만 실행 가능하고,
    n번의 간격 내에는 동일한 Task를 실행할 수 없다.
    더 이상 Task를 실행할 수 없는 경우 idle(대기) 상태가 된다.
    모든 Taskㄹ르 실행하기 위한 최소 간격을 출력하라.
*/
class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        int result = 0;
        std::unordered_map<char, int> t;
        for (char& c : tasks)
            t[c]++;
        
        std::priority_queue<int> q;
        for (auto& m : t)
            q.push(m.second);

        while (true)
        {
            std::vector<int> remain;
            // n번의 간격 내에는 동일한 task를 실행할 수 없고 더 이상
            // task 실행할 수 없으면 idle 상태로 바뀐다.
            // ex) A -> B -> idle or A -> B -> C -> A ect
            int cycle = n + 1;

            // 가장 개수가 많은 아이템부터 하나씩 추출
            while (cycle && !q.empty())
            {
                int top = q.top() - 1;
                q.pop();
                result++;
                cycle--;

                if (top > 0)
                    remain.push_back(top);
            }

            for (int& count : remain)
                q.push(count);

            if (q.empty())
                break;

            // idle
            result += cycle;
        }

        return result;
    }
};

int main() {
    std::vector<char> tasks = {
        'A','A','A','B','B','B'
    };

    Solution s;
    s.leastInterval(tasks, 2);
    s.leastInterval(tasks, 0);

    tasks = 
    {
        'A','A','A','A','A','A','B','C','D','E','F','G'
    };
    s.leastInterval(tasks, 2);

    return 0;
}