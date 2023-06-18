/*
    134. Gas Station
        There are n gas stations along a circular route,
        where the amount of gas at the ith station is gas[i].

        You have a car with an unlimited gas tank and it costs cost[i]
        of gas to travel from the ith station to its next (i + 1)th station.
        You begin the journey with an empty tank at one of the gas stations.

        Given two integer arrays gas and cost,
        return the starting gas station's index if you can travel around
        the circuit once in the clockwise direction, otherwise return -1.
        If there exists a solution, it is guaranteed to be unique

    Example 1:
        Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
        Output: 3
        Explanation:
        Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
        Travel to station 4. Your tank = 4 - 1 + 5 = 8
        Travel to station 0. Your tank = 8 - 2 + 1 = 7
        Travel to station 1. Your tank = 7 - 3 + 2 = 6
        Travel to station 2. Your tank = 6 - 4 + 3 = 5
        Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
        Therefore, return 3 as the starting index.

    Example 2:
        Input: gas = [2,3,4], cost = [3,4,3]
        Output: -1
        Explanation:
        You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
        Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
        Travel to station 0. Your tank = 4 - 3 + 2 = 3
        Travel to station 1. Your tank = 3 - 3 + 3 = 3
        You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
        Therefore, you can't travel around the circuit once no matter where you start.

    Constraints:
        n == gas.length == cost.length
        1 <= n <= 105
        0 <= gas[i], cost[i] <= 104
*/
#include <vector>
#include <numeric>

class Solution
{
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        // 기름의 양
        int fuel = 0;
        // 출발지점
        int start = 0, check = 0;
        for (int i = 0; i < gas.size(); i++)
        {

            // 남은 기름의 양
            fuel += gas[i] - cost[i];
            // 기름이 충분하지 않아 출발점이 안되는 지점들
            // 기름이 충분하면 start 위치가 아마 고정될 것이다.
            if (gas[i] < cost[i] && fuel < 0 && fuel < check)
            {
                start = i + 1;
                check = fuel;
            }
        }

        return fuel < 0 ? -1 : start;
    }

    int canCompleteCircuit2(std::vector<int>& gas, std::vector<int>& cost) {

        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            sum1 += gas[i];
            sum2 += cost[i];
        }
        if (sum1 < sum2)
            return -1;

        int fuel = 0;
        int ans = 0;
        for(int i=0;i<gas.size();i++)
        {
            fuel += gas[i] - cost[i];

            if(fuel < 0) 
            {
                ans = i+1;
                fuel = 0;
            }
        }

        return ans;
    }


    int canCompleteCircuit3(std::vector<int> &gas, std::vector<int> &cost)
    {
        // 기름의 양
        int curFuel = 0;
        // 출발지점
        int start = 0, total = 0;
        for (int i = 0; i < gas.size(); i++)
        {

            // 남은 기름의 양
            curFuel += gas[i] - cost[i];
            // 기름이 충분하지 않아 출발점이 안되는 지점들
            // 기름이 충분하면 start 위치가 아마 고정될 것이다.
            if (curFuel < 0)
            {
                total += curFuel;
                start = i + 1;
                curFuel = 0;
            }
        }

        return total + curFuel < 0 ? -1 : start;
    }
};