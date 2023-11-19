#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> phone;
    sort(phone_book.begin(), phone_book.end());
    int min = 1000001;
    for (string& p : phone_book)
    {
        if (!phone.empty())
        {
            for (int i = min; i <= p.size(); i++)
            {
                string key = p.substr(0, i);
                if (phone.find(key) != phone.end())
                   return false;
            }
        }
        
        phone.insert(p);
        
        if (p.size() < min)
            min = p.size();
    }
    
    return true;
}