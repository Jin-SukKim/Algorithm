#include <string>
#include <vector>
#include <map>

using namespace std;

void Compression(vector<int>& answer, map<string, int>& dict, string& s, int& index) {
    string cur = "";
    for (int i = 0; i < s.length(); ++i) {
        cur += s[i];
        if (!dict.count(cur)) {
            dict[cur] = index++; // 사전에 등록
            
            cur.pop_back(); // 맨 마지막 제외
            answer.push_back(dict[cur]);
            cur = "";
            --i;
        }
    }
    answer.push_back(dict[cur]);
}

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    
    // 초기화
    int index = 1;
    for (char alphabet = 'A'; alphabet <= 'Z'; ++alphabet){
        string init = "";
        init += alphabet;
        dict[init] = index++;
    }
    
    Compression(answer, dict, msg, index);
    
    return answer;
}