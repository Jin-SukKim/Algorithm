class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    // recursive 사용
    ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
        if (!head) {
            return prev;
        }
        ListNode* next = head->next;
        head->next = prev;
        prev = head;

        return reverseList(next, prev);

    }

    
};