#include <string>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    std::map<string, int> nums = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, 
        {"six", 6},  {"seven", 7}, {"eight", 8}, {"nine", 9}};
    
    string sub;
    for (char& c : s)
    {
        if ('0' <= c && c <= '9')
            answer = answer * 10 + (c - '0');
        else
        {
            sub += c;
            if (nums.count(sub))
            {
                answer = answer * 10 + nums[sub];
                sub = "";
            }
        }
    }
    
    return answer;
}