#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Travel(vector<vector<string>>& tickets, vector<bool>& used, string airport, vector<string>& answer, bool& connected) {
    answer.push_back(airport);
    // 티켓 숫자 + 출발한 공항(1) = 정답 배열 길이 
    if (answer.size() - 1 == tickets.size()) {
        connected = true;
        return;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (!used[i] && tickets[i][0] == airport) {
            used[i] = true;
            Travel(tickets, used, tickets[i][1], answer, connected);
            
            // 티켓을 다 사용한 경우
            if (connected)
                break;
            
            // 티켓을 다 사용하기 전에 루트가 끊겼으면
            used[i] = false;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    vector<bool> used(tickets.size(), 0);
    bool connected = false;
    Travel(tickets, used, "ICN", answer, connected);
    return answer;
}