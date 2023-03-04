/*
    Given the head of a singly linked list, return true if it is a palindrome
    or false otherwise.

    Example 1:

    Input: head = [1,2,2,1]
    Output: true
    Example 2:

    Input: head = [1,2]
    Output: false

    Constraints:

    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

    Follow up: Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
struct ListNode{
    int val;
    ListNode* next;
    // 기본 생성자
    ListNode() : val(0), next(nullptr) {};
    // int 값을 지정하는 생성자. 새로운 리스트 생성할 떄 유용
    ListNode(int x) : val(x), next(nullptr) {};
    // 노드 맨 앞이나 중간 부분에 삽입할 노드 생성에 주로 사용
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* addEnd(ListNode* head, int value) {
    ListNode* n = new ListNode(value);

    ListNode* extend = head;
    while(extend->next) {
        extend = extend->next;
    }

    extend->next = n;
    return head;
}

// 283ms, 133.4MB (too slow, too much usage of memory)
inline ListNode* addFront(ListNode* head, int value) {
    ListNode* n = new ListNode(value);

    n->next = head;
    return n;
}
/*
    런너(Runner)는 연결 리스트르 순회할 때 2개의 포인터를
    동시에 사용하는 기법이다.
    한 포인터가 다른 포인터보다 앞서게 하여 병합 지점이나
    중간 위치, 길이 등을 판별할 때 유용하게 사용할 수 있따.

    보통 fast runner는 두칸씩, slow runner는 한칸씩 이동해
    slow runner가 중간을 가르킬떄 fast runner는 끝에 도달한다.
*/
bool isPalindrome(ListNode *head)
{
    ListNode* reverse = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        reverse = addFront(reverse, slow->val);
        slow = slow->next;
    }

    if (fast)
        slow = slow->next;

    while (reverse && reverse->val == slow->val) {
        slow = slow->next;
        reverse = reverse->next;
    }

    return !reverse;
}

int main() {
    ListNode* head = new ListNode(1);
    head = addEnd(head, 2);
    head = addEnd(head, 2);
    head = addEnd(head, 1);

    std::cout << std::boolalpha << isPalindrome(head) << std::endl;

    return 0;
}