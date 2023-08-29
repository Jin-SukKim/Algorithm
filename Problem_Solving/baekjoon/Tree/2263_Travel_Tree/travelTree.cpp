#include <iostream>
#include <vector>

class Answer {
    std::vector<int> inOrder;
    std::vector<int> postOrder;
    std::vector<int> index;

public:
    Answer(int n)
        : inOrder(std::vector<int>(n + 1)), postOrder(std::vector<int>(n + 1)),
          index(std::vector<int>(n + 1)) {
        // tree의 inorder (자식인 왼쪽 노드, 부모 노드, 자식인 오른쪽 노드)
        for (int i = 1; i <= n; i++) {
            std::cin >> inOrder[i];
            // inOrder 숫자의 index 정보
            index[inOrder[i]] = i;  
        }
        // tree의 postOrder (자식인 왼쪽 노드, 자식인 오른쪽 노드, 부모 노드)
        for (int i = 1; i <= n; i++)
            std::cin >> postOrder[i];
    }

    void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd)
            return;
        // 루트(부모)의 위치
        int rootIndex = index[postOrder[postEnd]];
        // 루트의 index로 좌우 배열 사이즈
        int left = rootIndex - inStart;
        int right = inEnd - rootIndex;
        std::cout << inOrder[rootIndex] << ' '; 

        preOrder(inStart, rootIndex - 1, postStart, postStart + left - 1);
        // post에서 루트는 가장 끝에 있다.
        preOrder(rootIndex + 1, inEnd, postStart + left, postEnd - 1);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    Answer a(n);
    a.preOrder(1, n, 1, n);

    return 0;
}