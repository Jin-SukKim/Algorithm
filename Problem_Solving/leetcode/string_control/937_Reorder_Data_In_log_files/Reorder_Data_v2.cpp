#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

std::vector<std::string> reorderLogFiles(std::vector<std::string> &logs)
{
    std::stable_sort(logs.begin(), logs.end(), [] (const std::string& a, const std::string& b) {
        if (std::isdigit(a.back()))
            return false;
        if (std::isdigit(b.back()))
            return true;
        const std::string& a_sub = a.substr(a.find(' '));
        const std::string& b_sub = b.substr(b.find(' '));
        if (a_sub == b_sub) 
            return a < b;
        return a_sub < b_sub;
    });

    return logs;
}

int main() {
    std::vector<std::string> s{"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    s = reorderLogFiles(s);
    for (auto a : s) {
        std::cout << a << std::endl;
    }
    return 0;
}