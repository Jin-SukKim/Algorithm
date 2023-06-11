# 트라이를 저장할 노드
class TrieNode:
    def __init__(self):
        self.word = False
        self.children = {}


class Trie:
    # 딕셔너리를 이용해 간결한 트라이 구현
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        # 루트부터 자식 노드가 깊어지며 문자 단위의 다진 트리(m-ary Tree) 형태 생성
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        # 다음 문자를 키로 하는 자식 노드 형태로 단어가 완성되야 True가 된다.
        node.word = True

    # 단어가 존재하는지 여부를 판별
    def search(self, word: str) -> bool:
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]

        return node.word

    # 해당 문자열로 시작하는 단어가 존재하는지 여부를 판별
    def startsWith(self, prefix: str) -> bool:
        node = self.root
        # search 함수와 거의 동일
        for char in prefix:
            if char not in node.children:
                return False
            node= node.children[char]
            
        # node.word를 확인하지 않고 자식 노드가 존재하는지 여부만 판별
        return True
    
    
        # Your Trie object will be instantiated and called as such:
        # obj = Trie()
        # obj.insert(word)
        # param_2 = obj.search(word)
        # param_3 = obj.startsWith(prefix)
