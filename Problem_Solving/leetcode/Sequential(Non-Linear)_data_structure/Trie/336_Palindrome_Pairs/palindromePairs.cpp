/*
    336. Palindrome Pairs
        You are given a 0-indexed array of unique strings words.

        A palindrome pair is a pair of integers (i, j) such that:

        0 <= i, j < words.length,
        i != j, and words[i] + words[j]
        (the concatenation of the two strings) is a palindrome.

        Return an array of all the palindrome pairs of words.

    Example 1:
        Input: words = ["abcd","dcba","lls","s","sssll"]
        Output: [[0,1],[1,0],[3,2],[2,4]]
        Explanation: The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]

    Example 2:
        Input: words = ["bat","tab","cat"]
        Output: [[0,1],[1,0]]
        Explanation: The palindromes are ["battab","tabbat"]

    Example 3:
        Input: words = ["a",""]
        Output: [[0,1],[1,0]]
        Explanation: The palindromes are ["a","a"]

    Constraints:
        1 <= words.length <= 5000
        0 <= words[i].length <= 300
        words[i] consists of lowercase English letters.
*/

// brute-force로 문제를 푸는 경우 time-out 발생할 확률이 높다. (O(n^2))
// 그래서 문자열 탐색이 빠른 Trie 자료구조를 사용한다. (O(n))
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_map>

class TrieNode
{
public:
    int word_id;
    std::vector<int> palindrome_word_ids;
    // 다진 트리(m-ary Tree) 형태
    // TrieNode *children[26]; // 알파벳 개수
    // map<char, Trie*> children; 맵을 이용하는 경우
    std::unordered_map<char, TrieNode *> children;
    // vector<pair<char, Trie*>> children; 벡터를 이용하는 경우

    TrieNode()
    {
        word_id = -1;
    };

    ~TrieNode()
    {
        for (auto a : children)
        {
            delete a.second;
        }
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    bool is_palindrome(std::string word)
    {
        for (int i = 0, j = word.size() - 1; i < j; i++, j--)
        {
            if (word[i] != word[j])
                return false;
        }
        return true;
    }

    void insert(int index, std::string word)
    {
        TrieNode *node = root;
        // 팰린드롬 판별을 위해 단어를 뒤집어서 트리 구성
        for (int i = word.length() - 1; i >= 0; i--)
        {
            char idx = word[i];
            // 단어에서 팰린드롬인 부분
            if (is_palindrome(word.substr(0, i + 1)))
                node->palindrome_word_ids.push_back(index);

            node->children.insert(std::make_pair(idx, new TrieNode()));
            node = node->children[idx];
        }

        // 해당 단어의 인덱스
        node->word_id = index;
    }

    // 단어가 존재하는지 여부를 판별

    std::vector<std::vector<int>> search(int index, std::string word)
    {
        std::vector<std::vector<int>> results;
        TrieNode *node = root;

        //  탐색 중간에 word_id가 있고 나머지 문자가 팰린드롬인 경우
        while (!word.empty())
        {
            if (node->word_id >= 0)
                if (is_palindrome(word))
                    results.push_back({index, node->word_id});

            if (!node->children.count(word[0]))
                return results;

            node = node->children[word[0]];
            word = word.substr(1, word.length());
        }

        // 끝까지 탐색했을 때 word_id가 있는 경우
        if (node->word_id >= 0 && node->word_id != index)
            results.push_back({index, node->word_id});

        // 끝까지 탐색했을 때 palindrome_word_ids가 있는 경우
        for (int palindrome_word_id : node->palindrome_word_ids)
            results.push_back({index, palindrome_word_id});

        return results;
    }
};

class Solution
{
public:
    // 단어리스트에서 words[i] + words[j]가 팰린드롬이 되는 모든 인데스 조합 구하기
    std::vector<std::vector<int>> palindromePairs(std::vector<std::string> &words)
    {
        Trie trie;

        for (int i = 0; i < words.size(); i++)
            trie.insert(i, words[i]);

        std::vector<std::vector<int>> results;
        for (int i = 0; i < words.size(); i++)
        {
            std::vector<std::vector<int>> res = trie.search(i, words[i]);
            std::move(res.begin(), res.end(), std::back_inserter(results));
        }

        return results;
    }
};

int main()
{
    std::vector<std::string> words = {
        "abcd", "dcba", "lls", "s", "sssll"};

    Solution s;
    std::vector<std::vector<int>> res = s.palindromePairs(words);
    return 0;
}