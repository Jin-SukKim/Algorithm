/*
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    Example 1:


    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
    Example 2:


    Input: head = [1,2]
    Output: [2,1]
    Example 3:

    Input: head = []
    Output: []
    

    Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000
    

    Follow up: A linked list can be reversed either iteratively or recursively. 
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
class Solution {
    
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    // 반복자 사용
    // 3ms, 8.3MB
    ListNode* reverseList(ListNode* head) {
        ListNode* rev = nullptr;
        ListNode* next = nullptr;
        while (head) {
            // 역순으로 바꾸기 전 리스트의 다음 노드
            next= head->next; 
            // 역순으로 바꿀 리스트의 다음 노드를 여태까지 
            // 역순으로 바꾼 리스트로 바꿔주기
            // 이러면 원래 리스트와의 연결이 끊긴다.
            head->next = rev; 
            // 역순 리스트 갱신
            rev = head;
            head = next;
        }

        return rev;
    }
};
