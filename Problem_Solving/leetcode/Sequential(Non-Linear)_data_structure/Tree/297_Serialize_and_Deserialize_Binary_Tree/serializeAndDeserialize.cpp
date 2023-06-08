/*
    297. Serialize and Deserialize Binary Tree
        Serialization is the process of converting a data structure 
        or object into a sequence of bits so that it can be stored in 
        a file or memory buffer, or transmitted across 
        a network connection link to be reconstructed later in the same 
        or another computer environment.

        Design an algorithm to serialize and deserialize a binary tree. 
        There is no restriction on how your serialization/deserialization 
        algorithm should work. 
        You just need to ensure that a binary tree can be serialized to 
        a string and this string can be deserialized to 
        the original tree structure.

        Clarification: The input/output format is the same as 
        how LeetCode serializes a binary tree. 
        You do not necessarily need to follow this format, 
        so please be creative and come up with different approaches yourself.

    Example 1:
        Input: root = [1,2,3,null,null,4,5]
        Output: [1,2,3,null,null,4,5]
    
    Example 2:
        Input: root = []
        Output: []

    Constraints:
        The number of nodes in the tree is in the range [0, 104].
        -1000 <= Node.val <= 1000
*/
#include <string>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 
// 
/*
    이진 트리 데이터 구조를 파일이나 디스크에 저장하기 위해서
    물리적인 형태로 바꿔주는 직렬화(Serialize)와 반대의 역직렬화(Deserialize)가 있다

    완전 이진 트리는 배열로 표현할 수 있는데 계산을 편히 하기위해 보통 index 1부터 사용한다.

    깊이는 1, 2, 4, 8 index 순으로 2배씩 증가하며, index는 1부터 시작했기에
    부모/자식 노드의 위치는 각각 부모 |i/2|, 왼쪽 자식 2i, 오른쪽 자식 2i+1로 계산할 수있다.

    완전 이진 형태가 아닌 비어 있는 위치는 Null로 표현해주면
    모든 트리는 배열로 표현이 가능하다.
*/
class Codec {
public:

    // Encodes a tree to a single string.
    // DFS나 BFS 둘 다 구현 가능하다.
    std::string serialize(TreeNode* root) {
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));