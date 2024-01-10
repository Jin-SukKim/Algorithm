#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 플레이된 시간
int GetPlayTime(const string& begin, const string& end) {
    int bTime = stoi(begin) * 60 + stoi(begin.substr(3));
    int eTime = stoi(end) * 60 + stoi(end.substr(3));
    return eTime - bTime;
}

// 노래를 찾았는지
bool SameSong(const string& memory, const string& music) {
    int musicSize = music.length(), memorySize = memory.length(), idx;
    for (int i = 0; i < (musicSize - memorySize); ++i) {
        // i 위치에서부터 찾기 시작
        idx = music.find(memory, i);
        // "ABC"와 "ABC#"는 다르므로 맨 마지막을 확인해준다.
        if (idx != string::npos && music[idx + memorySize] != '#')
            return true;
    }
    
    for (int i = 0; i < memorySize; ++i) {
        // i 위치에서부터 찾기 시작
        idx = memory.find(music, i);
        if (idx != string::npos && memory[idx + musicSize] != '#')
            return true;
    }
    
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int time = 0;
    for (auto infos : musicinfos) {
        istringstream is(infos);
        vector<string> data;
        string temp;
        // ','를 기준으로 데이터 나누기
        while (getline(is, temp,  ',')) {
            data.push_back(temp);
        }
        
        // 시작시간, 끝난 시간의 차이로 음악 재생 시간 구하기
        int playedTime = GetPlayTime(data[0], data[1]);
        
        // 아예 재생 시간이 기억보다 짧으면 성립이 안된다.
        if (playedTime <= time) 
            continue;
        
        // 악보에 따른 음악시간
        int musicTime = 0;
        for (auto c : data[3])
            if (c != '#') // C#은 한 음
                ++musicTime;
        
        int tempTime = musicTime;
        
        // 반복 재생되었을 때
        while (tempTime < playedTime) { 
            temp += data[3];
            tempTime += musicTime;
        }
        
        // 라디오 플레이 시간에 맞게 잘라주기
        while (tempTime > playedTime) { 
            if (temp.back() == '#')
                temp.pop_back();
            temp.pop_back();
            --tempTime;
        }
        
        if (SameSong(m, temp)) {
            answer = data[2];
            time = playedTime;
        }
    }
    return answer;
}