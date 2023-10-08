#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    // 유저가 신고한 ID
    map<string, set<string>> reported;
    for (string& s : report)
    {
        int space = s.find(' ');
        reported[s.substr(0, space)].insert(s.substr(space));
    }
    
    // 유저가 신고당한 횟수
    map<string, int> reportCount;
    for (auto [key, value] : reported) 
        for (auto& s : value) 
            reportCount[s]++;
    
    // 신고당해서 정지된 결과
    for (string& id : id_list)
    {
        int count;
        if (reportCount[id] < k)
            count = 0;
        else 
            count = 1;
        
        // 신고한 인원 중 정지된 ID가 있다면 결과 메일 전송
        for (string reportID : reported[id])
            if (reportCount[reportID] >= k)
                count++;
        
        answer.push_back(count);
    }
    
    return answer;
}