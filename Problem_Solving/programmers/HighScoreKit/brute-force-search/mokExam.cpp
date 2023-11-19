#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> person(3);
    
    int a[5] = {1, 2, 3, 4, 5};
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int c[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == a[i % 5])
            person[0]++;
        if (answers[i] == b[i % 8])
            person[1]++;
        if (answers[i] == c[i % 10])
            person[2]++;
    }
    
    auto max = max_element(person.begin(), person.end());
    if (*max == 0)
        return {};
    
    vector<int> result;
    result.push_back(max - person.begin() + 1);
    for (int i = 0; i < 3; i++)
        if (i + 1 != result[0] && person[i] == *max)
            result.push_back(i+1);
    sort(result.begin(), result.end());
    
    
    return result;
}