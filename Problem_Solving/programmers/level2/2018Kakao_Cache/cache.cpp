#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    // 대소문자 구분 x
    for (string& city : cities) {
        for_each(city.begin(), city.end(), [](char& c) { c = tolower(c); });
    }
    
    list<string> cache; // STL의 양방향 Linked-List
    for (const string& city : cities) {
        auto it = find(cache.begin(), cache.end(), city);
        // cache안에 없다면 cache miss
        if (it == cache.end()) {
            answer += 5;
            if (cache.size() < cacheSize)
                cache.push_back(city);
            // Cache가 꽉찼으면
            else if (cacheSize && cache.size() == cacheSize)
            {
                cache.pop_front(); // 가장 오래된 페이지 제거
                cache.push_back(city);
            }
        }
        // Cache 내부에 있다면 cache hit
        else {
            answer += 1;
            // 가장 최신 페이지
            cache.erase(it);
            cache.push_back(city);
        }
    }
    
    return answer;
}