#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <memory>
using namespace std;

enum class RecordType { Leave, Enter }; // 0, 1

struct History {
    int index;
    RecordType type;
};

struct Status {
    RecordType in;
    string name;
    vector<History> history;
};

vector<string> solution(vector<string> record) {
    map<string, Status> nameRecord;
    int length = 0;
    
    for (string& s : record) {
        istringstream istring(s);
        RecordType type = RecordType::Leave;
        string statusType, id, name;
        istring >> statusType >> id >> name;
        
        // 닉네임 변경
        if (nameRecord.count(id) && statusType == "Change") {
            nameRecord[id].name = name;
            continue;
        }

        if (statusType == "Enter") {
            nameRecord[id].name = name;
            type = RecordType::Enter;
        }
            
        nameRecord[id].in = type;
        nameRecord[id].history.push_back({length, type});

        ++length;
    }
    
    vector<string> answer(length);
    for (auto [id, status] : nameRecord) {
        for (History& h : status.history) {
            string text;

            if (h.type == RecordType::Enter)
                text = status.name + "님이 들어왔습니다.";
            else if (h.type == RecordType::Leave)
                text = status.name + "님이 나갔습니다.";

            answer[h.index] = text;
        }
    }
    
    return answer;
}