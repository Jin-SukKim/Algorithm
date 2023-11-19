#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> combination;
    
    for (auto& c : clothes)
        combination[c[1]]++;
    
    int answer = 1;
    for (auto& [key, value] : combination) 
        answer = answer * (value + 1);
    
    answer--;

    
    return answer;
}