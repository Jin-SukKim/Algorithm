import collections


class TrieNode:
    def __init__(self):
        self.word_id = -1
        # 단어 자체가 palindrome인 경우
        self.palindrome_word_ids = []
        self.children = collections.defaultdict(TrieNode)


class Trie:
    # 딕셔너리를 이용해 간결한 트라이 구현
    def __init__(self):
        self.root = TrieNode()

    @staticmethod
    def is_palindrome(word: str) -> bool:
        return word[::] == word[::-1]
    
    def insert(self, index: int, word: str) -> None:
        node = self.root
        # 팰린드롬 판별을 위해 뒤집어서 구성
        for i, char in enumerate(reversed(word)):
            temp = word[0:len(word) - i]
            if self.is_palindrome(word[0:len(word) - i]):
                # 단어 자체가 palindrome인 경우
                node.palindrome_word_ids.append(index)
            node = node.children[char]
        # 해당 단어의 인덱스
        node.word_id = index
        

    # 단어가 존재하는지 여부를 판별
    # 입력값을 각각 한 번씩만 대입하면 되기 때문에 O(n)으로 풀이 가능하다.
    # 좀 더 정확히는 단어의 최대 길이를 k로 했을 때 O(k^2n)이다.
    def search(self, index: int, word: str) -> list[list[int]]:
        results = []
        node = self.root
        
        while word:
            # 판별 로직
            # 탐색 중간에 word_id가 있고 나머지 문자가 팰린드롬인 경우
            
            # 단어를 뒤집어서 구축했기에 입력값은 순서대로 탐색하다가
            # word_id가 -1이 아니라면, 현재 index와 해당 word_id는 팰린드롬으로 판단할 수 있다.
            if node.word_id >= 0:
                if self.is_palindrome(word):
                    results.append([index, node.word_id])
            if not word[0] in node.children:
                return results
            node = node.children[word[0]]
            word = word[1:]
        
        # 판별 로직
        # 끝까지 탐색했을 때 word_id가 있는 경우
        if node.word_id >= 0 and node.word_id != index:
            results.append([index, node.word_id])
            
        # 판별 로직
        # 끝까지 탐색했을 때 palindrome_word_ids가 있는 경우
        for palindrome_word_id in node.palindrome_word_ids:
            results.append([index, palindrome_word_id])
            
        return results

class Solution:
    def palindromePairs(self, words: list[str]) -> list[list[int]]:
        trie = Trie()
        
        for i, word in enumerate(words):
            trie.insert(i, word)
            
        results = []
        for i, word in enumerate(words):
            results.extend(trie.search(i, word))
            
        return results

def main():
    words = ["abcd","dcba","lls","s","sssll"]
    s = Solution()
    s.palindromePairs(words)

if __name__ == '__main__':
    main()