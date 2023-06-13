/*
    179. Largest Number
        Given a list of non-negative integers nums,
        arrange them such that they form the largest number and return it.

        Since the result may be very large, so you need to return
        a string instead of an integer.

    Example 1:
        Input: nums = [10,2]
        Output: "210"

    Example 2:
        Input: nums = [3,30,34,5,9]
        Output: "9534330"

    Constraints:
        1 <= nums.length <= 100
        0 <= nums[i] <= 109
*/
#include <vector>
#include <string>
#include <algorithm>
// 항목들을 조합해 만들수 있는 가장 큰 수를 출력
class Solution
{
public:
    bool compare(std::string& a, std::string& b)
    {
        // 9와 30을 비교해서 전체 조합 수는 만드는 것은
        // 앞 숫자 하나하나 비교하는 것 보다 930과 309 같이 비교하는 것이 더 편하다.
        return a + b < b + a;
    }
    // 삽입 정렬 구현
    std::string largestNumber(std::vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            int j = i;
            // 비교할 숫자의 포인터를 왼쪽(앞)으로 이동하며 스왑할 위치를 찾는다.

            while (j > 0 && compare(std::to_string(nums[j - 1]), std::to_string(nums[j])))
            {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
                j--;
            }

        }

        std::string res;
        for (const auto &s : nums)
            res += std::to_string(s);

        /*
        // std::sort 사용해서 푸는 법, 대신 속도는 빠르고 메모리를 더 많이 사용한다.
        std::vector<std::string> sort;
        for (int i : nums)
            sort.push_back(std::to_string(i));

        std::sort(sort.begin(), sort.end(), [](std::string &a, std::string &b)
                  { return a + b > b + a; });
        
        for (auto &s : sort)
            res += s;
        */

        // "00"인 경우 00이 아니라 0을 출력
        return res[0] == '0' ? "0" : res;
    }
};

int main()
{
    std::vector<int> nums =
        {
            3, 30, 34, 5, 9};
    Solution s;
    s.largestNumber(nums);
    return 0;
}