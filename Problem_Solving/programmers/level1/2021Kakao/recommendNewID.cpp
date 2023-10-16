#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;

string solution(string new_id) {
    // 아이디에서 사용 가능한 문자를 제외하고 전부 삭제
    regex re("[^A-Za-z0-9._-]"); 
    new_id = regex_replace(new_id, re, ""); 
    
    // .은 임의의 문자로 해석되기에 \를 붙여주고 .이 1개 이상 반복될 때
    re = "\\.+";
    new_id = regex_replace(new_id, re, ".");
    
    if (new_id.front() == '.')
        new_id.erase(new_id.begin());
    if (new_id.back() == '.')
        new_id.pop_back();
    
    if (new_id.empty())
        new_id = 'a';
    
    if (new_id.length() > 15)
        new_id = new_id.substr(0, 15);
    
    if (new_id.back() == '.')
        new_id.pop_back();
    
    while (new_id.length() < 3)
        new_id += new_id.back();
    
    for (char& c : new_id)
        c = tolower(c);
    
    return new_id;
}