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
#include <queue>

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
class Codec
{
public:
    // Encodes a tree to a single string.
    // DFS나 BFS 둘 다 구현 가능하다.
    std::string serialize(TreeNode *root)
    {
        // BFS 방식
        std::queue<TreeNode *> queue;
        queue.push(root);

        // 빈 nullptr인 경우 '#' 문자로 대채
        std::string res = "#";
        // 계산하기 쉽게 이진 트리의 노드 index를 1부터 시작
        while (queue.size())
        {
            TreeNode *node = queue.front();
            queue.pop();

            if (node)
            {
                queue.push(node->left);
                queue.push(node->right);

                res += std::to_string(node->val);
            }
            else
                res += "#";

            // 숫자가 한자리수가 아닌 경우를 위해 띄어쓰기
            res += " ";
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        // nullptr인 예외 처리
        if (data == "## ")
            return nullptr;

        // 숫자가 한자리가 아닌 10, 1000인 경우를 위해 " "로 구분
        int index = 1;
        int end = data.find(" ");
        std::string sub = data.substr(index, end);

        // string을 int로 convert해주는 함수
        TreeNode *root = new TreeNode(std::stoi(sub));
        std::queue<TreeNode *> queue;
        queue.push(root);

        while (queue.size())
        {
            TreeNode *node = queue.front();
            queue.pop();

            index = end + 1;
            end = data.find(" ", index);

            sub = data.substr(index, end - index);
            // 왼쪽 자식 노드가 배열에 먼저 들어가있다.
            if (sub != "#")
            {
                node->left = new TreeNode(std::stoi(sub));
                queue.push(node->left);
            }
            // 오른쪽 자식
            index = end + 1;
            end = data.find(" ", index);

            sub = data.substr(index, end - index);
            if (sub != "#")
            {
                node->right = new TreeNode(std::stoi(sub));
                queue.push(node->right);
            }
            // Null은 #으로 대체하므로 배열을 계속 진행
            index++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main()
{
    TreeNode *root = nullptr;

    Codec ser, deser;

    deser.deserialize(ser.serialize(root));
    return 0;
}