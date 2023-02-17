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

bool isPalindrome(ListNode *head)
{

}