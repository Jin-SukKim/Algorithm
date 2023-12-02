#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <climits>

using namespace std;

struct Pos {
    long long x;
    long long y;
};

// set에 struct를 사용하기 위한 비교 함수(set은 정렬을 해주는데 custum struct을 사용하기 위함)
inline bool operator<(const Pos& a, const Pos& b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

inline bool check(double& n) {
    return n - static_cast<long long>(n) == 0;
}

pair<double, double> FindInter(vector<int>& a, vector<int>& b, long long& denom) {
    double x, y;
    
    x = (double(a[1]) * b[2] - double(a[2]) * b[1]) / denom;
    y = (double(a[2]) * b[0] - double(a[0]) * b[2]) / denom;
    
    return {x, y};
}

vector<string> solution(vector<vector<int>> line) {
    set<Pos> intersection;
    
    for (int i = 0; i < line.size() - 1; i++) {
        for (int j = 0; j < line.size(); j++) {
            long long denom = static_cast<long long>(line[i][0]) * line[j][1] - static_cast<long long>(line[i][1]) * line[j][0];
            if (denom) {
                auto [x, y] = FindInter(line[i], line[j], denom);
                if (check(x) && check(y))
                    intersection.insert({static_cast<long long>(x), static_cast<long long>(y)});
            }
        }
    }
    
    long long minX = LLONG_MAX, maxX = LLONG_MIN, minY = LLONG_MAX, maxY = LLONG_MIN;
    
    for (auto& p : intersection) {
        minX = min(minX, p.x);
        maxX = max(maxX, p.x);
        minY = min(minY, p.y);
        maxY = max(maxY, p.y);
    }
    
    // '.' 으로 초기화
    vector<string> answer(maxY - minY + 1, string(maxX - minX + 1, '.'));
    
    for (const auto& p : intersection) 
        answer[maxY - p.y][p.x - minX] = '*';
    
    return answer;
}