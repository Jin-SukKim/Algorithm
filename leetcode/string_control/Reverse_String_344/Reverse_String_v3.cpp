#include <vector>

// speed : 15ms, memory : 23.3
inline void swap(char &&a, char &&b)
{
    typename std::remove_reference<char &&>::type t = b;
    b = a;
    a = t;
}

void reverseString(std::vector<char> &s)
{
    int second = s.size();
    int first = 0;
    while (first < second)
    {
        swap(std::move(s[first++]), std::move(s[--second]));
    }
}
