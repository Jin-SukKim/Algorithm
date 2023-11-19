#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    
    vector<int> answer;
    
    int before = -1;
    for (const int& i : arr)
    {
        if (before != i) {
            answer.push_back(i);
            before = i;
        }
    }

    return answer;
    
    /*
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return arr;
    */
}