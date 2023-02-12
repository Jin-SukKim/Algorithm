// 49. Group Anagrams
/*
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
    typically using all the original letters exactly once.

    Example 1:

    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
    Example 2:

    Input: strs = [""]
    Output: [[""]]
    Example 3:

    Input: strs = ["a"]
    Output: [["a"]]

    Constraints:

    1 <= strs.length <= 104
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.

*/
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
        std::string w = s;
        std::stable_sort(s.begin(), s.end());
        if (!category.insert(std::make_pair(s, vectorType())).second);
            category[s].push_back(w);
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