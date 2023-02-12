// 49. Group Anagrams
// fastest & smallest
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using vectorType = std::vector<std::string>;

std::vector<vectorType> groupAnagrams(vectorType &strs)
{   
    if(strs.size() == 1)
        return {{strs}};

    std::vector<vectorType> anagrams;
    std::unordered_map<std::string, vectorType> category;
    
    for (auto &s : strs)
    {
        std::string key = s;
        std::sort(key.begin(), key.end());
        category[key].push_back(s);
    }

    for (auto& g : category) {
        anagrams.push_back(g.second);
    }

    return anagrams;
}

template<typename Iter>
void print(Iter begin, Iter end) {
    std::cout << "[ ";
    while (begin != end) {
        std::cout << *begin << ", ";
        begin++;
    }
    std::cout << " ]" << std::endl;
}

int main()
{
    vectorType strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<vectorType> res = groupAnagrams(strs);
    
    for (auto& a : res) {
        print(a.begin(), a.end());
    }
    

    return 0;
}