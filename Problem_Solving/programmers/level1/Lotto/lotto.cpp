#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {

    int zero = 0;
    int match = 0;
    for (int& i : lottos)
    {
        if (i == 0)
            zero++;
        else {
            for (int& j : win_nums)
                if (j == i)
                    match++;
        }
    }
    cout << zero << ' ' << match;
    int last = 7 - match > 6 ? 6 : 7 - match;
    int first = 7 - match - zero > 6 ? 6 : 7 - match - zero;
    
    return {first, last};
}