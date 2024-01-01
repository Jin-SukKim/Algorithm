#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

enum class RecordType { Leave, Enter }; // 0, 1

struct History {
    int index;
    RecordType type;
};

struct Status {
    bool in;
    string name;
    vector<History> history;
};

vector<string> solution(vector<string> record) {
    map<string, shared_ptr<Status>> nameRecord;
    vector<pair<string, string>> changeList;
    int length = 0;
    
    for (string& s : record) {
        istringstream istring(s);
        RecordType type;
        string temp;

        istring >> temp;
        
        if (temp == "Change") {
            string before, after;
            istring >> before >> after;
            // 이전의 log가 있고 방에 들어와 있다면
            if (nameRecord.count(before) && nameRecord[before]->in) {
                changeList.push_back({before, after});
            }
            continue;
        }
        
        else if (temp == "Enter") 
            type = RecordType::Enter;
        else if (temp == "Leave")
            type = RecordType::Leave;
        
        while (istring >> temp) {
            if (nameRecord.count(temp)) {
              nameRecord[temp]->in = static_cast<bool>(type);
              nameRecord[temp]->history.push_back({length, type});
            } else {
              shared_ptr<Status> status = make_shared<Status>();
              status->in = static_cast<bool>(type);
              status->history.push_back({length, type});
              nameRecord[temp] = status;
            }
            ++length;
        }
    }

    // history의 id 변경
    for (auto [before, after] : changeList) {
        nameRecord[after] = nameRecord[before]; // 포인터를 옮기고
        nameRecord.erase(nameRecord.find(before)); // 이전 id 삭제
    }
    
    vector<string> answer(length);
    for (auto [id, status] : nameRecord) {
        for (History& h : status->history) {
            string text;
            if (h.type == RecordType::Enter)
                text = id + "님이 들어왔습니다.";
            else if (h.type == RecordType::Leave)
                text = id + "님이 나갔습니다.";
            answer[h.index] = text;
        }
    }
    
    
    return answer;
}

int main() {
  solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo",
    "Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});
  return 0;
}