#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int ToMin(const string& time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

struct cmp{
    bool operator()(const vector<int>& a, vector<int>& b) { return a[1] > b[1]; } 
};

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> rooms;
    rooms.push({-10, -10});
    
    for (const auto& book : book_time)
    {
        vector<int> room = rooms.top();
        int begin = ToMin(book[0]);
        
        if (begin >= room[1]) 
            rooms.pop();
        rooms.push({begin, ToMin(book[1]) + 10});
        
        answer = max(answer, (int)rooms.size());
    }
    
    return answer;
}

int main()
{
    solution({{"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}});
    return 0;
}