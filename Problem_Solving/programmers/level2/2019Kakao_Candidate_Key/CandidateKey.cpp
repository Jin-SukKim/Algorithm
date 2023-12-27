#include <string>
#include <vector>
#include <set>

using namespace std;

// bitmask를 활용한 조합 구하기
int Combination(const vector<vector<string>>& relation, const int& b, const int& row, const int& col) {
    set<string> key;
    for (int i = 0; i < row; ++i) {
        string temp = "";
        for (int j = 0; j < col; ++j) {
            // 현재 조합에 맞는 col이라면 b = 0110일때 index 1, 2가 맞는 col이 된다.
            // (index 1, 2는 j와 같다.)
            if (b & (1 << j)) {
                temp += relation[i][j];
            }
        }
        key.insert(temp);
    }
    
    // set으로 인해 중복없는 값만 comb에 들어간다.
    return key.size();
}

// 최소성을 만족하기 위해선 해당 key조합에 보다 작은 key의 값이 전부 있으면 안된다.
// ex) key = (0, 1)가 있을때 key = (0, 1, 3)은 보다작은 키 조합이 있으므로 최소성을 만족하지 못함
bool Minimality(const vector<int>& answer, const int& key) {
    for (const int& unique : answer) {
        if ((unique & key) == unique) // ex) 101 & 111 = 101이므로 최소성을 확인할 수 있다.
            return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    vector<int> answer;
    
    int col = relation[0].size();
    int row = relation.size();
    
    // bitmask를 활용한 조합 구하기
    // ex) b = 0 (0000), 1(0001), 2(0010), 3(0011) ... 15(1111)
    for (int i = 1; i < (1 << col); ++i) {
        // 중복이없는 unique일때 최소성을 만족한다면
        if (Combination(relation, i, row, col) == row && Minimality(answer, i)) 
            answer.push_back(i);
    }
    
    return answer.size();
}