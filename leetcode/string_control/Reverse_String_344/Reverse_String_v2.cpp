#include <vector>

// speed : 29ms, memory : 23.3MB
void reverseString(std::vector<char> &s)
{
    int second = s.size() - 1;
    int first = 0;
    while (first < second)
    {
        std::swap(s.at(first), s.at(second));
        ++first;
        --second;
    }
}