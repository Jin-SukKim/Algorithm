#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct File {
    string Head;
    string Number;
    string Tail;
};

bool Compare(const File& a, const File& b) {
    string lowerA = a.Head, lowerB = b.Head;
    transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower); 
    transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower); 
    
    if (lowerA == lowerB) 
        return stoi(a.Number) < stoi(b.Number);
    
    return lowerA < lowerB;
}

File DivideFile(const string& f) {
    File file;
    
    // 0~9 중 가장 처음 나오는 index
    size_t nStart = f.find_first_of("0123456789");
    if (nStart == string::npos)
        nStart = f.length();
    file.Head = f.substr(0, nStart);
    
    size_t nLength = nStart;
    for (size_t i = nStart; i < f.length(); ++i) {
        if ((i - nStart) > 5 || f[i] < '0' || f[i] > '9')
            break;
        nLength = i;
    }
    nLength -= nStart - 1; // Number의 길이
    
    file.Number = f.substr(nStart, nLength);
    file.Tail = f.substr(nStart + nLength);    
    
    return file;
}

vector<string> solution(vector<string> files) {
    vector<File> f;
    for (string& s : files)
        f.push_back(DivideFile(s));
    
    // 동일한 값을 가지면 순서를 보장 (sort는 순서를 보장할 수 없다.)
    stable_sort(f.begin(), f.end(), Compare);
    
    vector<string> answer;
    for (const File& file : f) 
        answer.push_back(file.Head + file.Number + file.Tail);
    
    return answer;
}