#include <string>
#include <vector>
#include <map>
#include <string_view>
#include <iostream>
using namespace std;

int HourToMin(string& time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int CalFees(int& time, vector<int>& fees) {
    time -= fees[0];
    // 기본 요금
    if (time < 1) 
        return fees[1];
    
    // 기본 요금 + 추가 요금
    if (time % fees[2])
        time += fees[2];
    return fees[1] + (time / fees[2]) * fees[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> cumulate;
    map<string, int> table;
    
    for (string& r : records) {
        // 입차
        if (r.find("IN") != string::npos) 
            table[r.substr(6, 4)] = HourToMin(r);
        // 출차
        else if (r.find("OUT") != string::npos) {
            string car = r.substr(6, 4);
            cumulate[car] += HourToMin(r) - table[car];
            table[car] = -1;
        }
    }
    
    for (auto [car, in] : table) {
        // 출차된 기록이 없다면 23:59에 출차된 것으로 간주
        if (in > -1) 
            // 23:59 - in
            cumulate[car] += 1439 - in;
    }
    
    for (auto [car, time] : cumulate) 
        answer.push_back(CalFees(time, fees));
    
    return answer;
}