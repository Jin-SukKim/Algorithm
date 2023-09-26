#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int day (string s){
    double  dayNumber =0;
    dayNumber +=stoi(s.substr(0,4))*12*28;
    dayNumber += stoi(s.substr(5,2))*28;

    dayNumber += stoi(s.substr(8,2));

    return dayNumber;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> t;
    for (int i = 0; i < terms.size(); i++)
    {
        t[terms[i][0]] = stoi(terms[i].substr(2)) * 28;
    }
    
    int curDay = day(today);
    std::cout << curDay << '\n';
    for (int i = 0; i < privacies.size(); i++)
    {
        int expire = day(privacies[i]);
        char* category = &privacies[i][11];
        
        expire += t[*category];
        if (expire <= curDay)
            answer.push_back(i + 1);
    }
    
    return answer;
}