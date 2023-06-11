/*
    208. Implement Trie (Prefix Tree)
        A trie (pronounced as "try") or prefix tree is
        a tree data structure used to efficiently store and
        retrieve keys in a dataset of strings.
        There are various applications of this data structure,
        such as autocomplete and spellchecker.

        Implement the Trie class:

        Trie() Initializes the trie object.
        void insert(String word) Inserts the string word into the trie.
        boolean search(String word) Returns true if the string word is
        in the trie (i.e., was inserted before), and false otherwise.
        boolean startsWith(String prefix) Returns true if there is
        a previously inserted string word that has the prefix prefix,
        and false otherwise.

    Example 1:
        Input
        ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
        [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
        Output
        [null, null, true, false, true, null, true]

        Explanation
        Trie trie = new Trie();
        trie.insert("apple");
        trie.search("apple");   // return True
        trie.search("app");     // return False
        trie.startsWith("app"); // return True
        trie.insert("app");
        trie.search("app");     // return True

    Constraints:
        1 <= word.length, prefix.length <= 2000
        word and prefix consist only of lowercase English letters.
        At most 3 * 104 calls in total will be made to insert, search, and startsWith.
*/
#include <string>
class TrieNode{
public:
    bool is_word;
    // 다진 트리(m-ary Tree) 형태
    TrieNode* children[26]; // 알파벳 개수

    TrieNode() {
        is_word = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    };
};
class Trie
{
public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(std::string word)
    {   
        TrieNode* node = root;
        // 루프부터 자식 노드가 깊어지며 문자 단위의 m-ary Tree 형태 생성
        for (char c : word)
        {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        // 단어가 완성되면 마지막 알파벳 node에 is_word를 true로 설정해준다.
        node->is_word = true;
    }

    // 단어가 존재하는지 여부를 판별
    bool search(std::string word)
    {
        TrieNode* node = root;
        for (char c : word)
        {
            int index = c - 'a';
            // 문자가 없으면 false
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->is_word;
    }

    // 해당 문자열로 시작하는 단어가 존재하는지 여부를 판별
    bool startsWith(std::string prefix)
    {
        TrieNode* node = root;
        // search 함수와 동일
        for (char c : prefix)
        {
            int index = c - 'a';
            // 문자가 없으면 false
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        // 단어가 존재하는지 is_word로 확인하지 않고 자식 노드가 있다면 true
        return true;   
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */