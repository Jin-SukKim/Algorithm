#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int i = 0, j = 0;
    
    for (string& s : goal)
    {
        if (s == cards1[i])
            i++;
        else if (s == cards2[j])
            j++;
        else
        {
            answer = "No";
            break;
        }
    }
    if (answer != "No")
        answer = "Yes";
    return answer;
}