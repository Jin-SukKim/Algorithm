#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int main()
{
int answer = 0;
    set<string> speak = {"aya","woo", "ye", "ma" };
    vector<string> babbling = {"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
    for (string& s : babbling)
    {
        string prev;
        int index = 0;
        while (index < s.length())
        {
            
            if (!prev.empty() && prev == s.substr(index, prev.length()))
            {
                string sub = s.substr(index, prev.length());
                break;
            }
            if (speak.count(s.substr(index, 3))) {
                prev = s.substr(index, 3);
                index += 3;
            }
            else if (speak.count(s.substr(index, 2))) {
                prev = s.substr(index, 2);
                index += 2;
            }
            else
                break;
        }
        
        if (index == s.length())
            answer++;
        cout << s << ' ' << answer << ' ' << index << '\n';
    }
    return 0;
}