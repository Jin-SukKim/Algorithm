#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Service {
    int Membership = 0;
    int Profit = 0;
};

// 멤버십 가입이 우선순위
struct cmp {
    bool operator()(const Service& a, const Service& b) {
        if (a.Membership == b.Membership)
        {
            return a.Profit < b.Profit;
        }
        return a.Membership < b.Membership;
    }
};

using Services = priority_queue<Service, vector<Service>, cmp>;

// 각 유저의 멤버십 가입과 이모티콘 가격 계산
Service CalPercentage(const vector<vector<int>>& users, const vector<int>& emoticons, const vector<int>& percentage) {
    
    Service s;
    for (const vector<int>& u : users)
    {
        int pay = 0;
        for (int i = 0; i < emoticons.size(); i++)
        {
            // 일정 비율 이상 할인하면 구매
            if (u[0] > percentage[i])
                continue;

            pay += emoticons[i] * (100 - percentage[i]) / 100;
        }
        
        // 서비스에 가입하지 않고 이모티콘 구매
        if (pay < u[1])
            s.Profit += pay;
        // 각 사용자의 기준 이상이면 구매 취소 후 서비스 가입
        else
            s.Membership++;
    }
    
    return s;
}

// 각 이모티콘의 모든 percentage 조건을 찾아본다.
void AllPercentage(const vector<vector<int>>& users, const vector<int>& emoticons, Services& services, vector<int>& percentage, int depth) {
    if (depth == emoticons.size())
    {
        services.push(CalPercentage(users, emoticons, percentage));
        return;
    }
    
    for (float i = 10; i < 50; i += 10)
    {
        percentage[depth] = i;
        AllPercentage(users, emoticons, services, percentage, depth + 1);
    }
}

// 할인율 10, 20, 30, 40
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> percentage(emoticons.size(), 0.0f);
    Services services;
    AllPercentage(users, emoticons, services, percentage, 0);
    
    Service best = services.top();
    
    return {best.Membership, best.Profit};
}

int main()
{
    solution({{40, 10000}, {25, 10000}}, {7000, 9000});
    return 0;
}