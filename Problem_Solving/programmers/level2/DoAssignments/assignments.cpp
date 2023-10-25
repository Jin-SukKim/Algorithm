#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

struct Assign {
    string Name;
    int Start;
    int PlayTime;
};

// 시간을 분으로 저장
int ConvertTime(const string& start)
{
    int time = stoi(start.substr(0, 2)) * 60;
    time += stoi(start.substr(3, 2));
    return time;
}

// 남은 시간
int RemainTime(const int& start, const int& playTime, const int& otherStart)
{
    return playTime - (otherStart - start);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    function<bool(const Assign& a, const Assign& b)> cmp = [] (const Assign& a, const Assign& b) { return a.Start > b.Start; };
    // decltype = parameter의 type을 알려준다.
    priority_queue<Assign, vector<Assign>, decltype(cmp)> q(cmp);
    
    for (auto v : plans)
    {
        Assign assignment = {v[0], ConvertTime(v[1]), stoi(v[2])};
        q.push(assignment);
    }
    
    stack<Assign> stop;
    // 현재 진행 중인 과제
    Assign current = q.top();
    q.pop();

    while (!q.empty())
    {
        Assign assign = q.top();
        q.pop();

        int remain = RemainTime(current.Start, current.PlayTime, assign.Start);

        // 하는 도중에 다른 과제를 시작해야 된다면
        if (0 < remain)
        {
            current.PlayTime = remain;
            
            // 아직 시작도 하지 않은 과제가 있다면
            if (!q.empty())
                stop.push(current);
            // 시작하지 않은 과제는 없지만 이전에 잠시 멈춘 과제가 남아 있다면
            else {
                current.Start = assign.Start + assign.PlayTime;
                q.push(current);
            }

            current = assign;
        }
        // 하던 과제를 끝냈는데 이전에 멈춘 과제가 있다면
        else if (!stop.empty()) {
            int endTime = current.Start + current.PlayTime;
            answer.push_back(current.Name);

            current = stop.top();
            stop.pop();
            
            current.Start = endTime;
            q.push(assign);
        }
        // 이전에 멈춤 과제가 없을 때
        else {
            answer.push_back(current.Name);
            current = assign;
            // 모든 과제를 끝냈으면
            if (q.empty())
                answer.push_back(current.Name);
        }
    }

    return answer;
}
int main()
{
    solution({{"science", "12:40", "50"}, {"music", "12:20", "40"}, {"history", "14:00", "30"}, {"computer", "12:30", "100"}});
    return 0;
}