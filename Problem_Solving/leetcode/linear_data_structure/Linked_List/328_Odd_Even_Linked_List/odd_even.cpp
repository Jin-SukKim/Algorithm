/*
    Given the head of a singly linked list, group all the nodes with odd indices together
    followed by the nodes with even indices, and return the reordered list.

    The first node is considered odd, and the second node is even, and so on.

    Note that the relative order inside both the even and odd groups should remain as it was in the input.

    You must solve the problem in O(1) extra space complexity and O(n) time complexity.

    Example 1:

    Input: head = [1,2,3,4,5]
    Output: [1,3,5,2,4]
    Example 2:

    Input: head = [2,1,3,5,6,4,7]
    Output: [2,3,6,7,1,5,4]

    Constraints:

    The number of nodes in the linked list is in the range [0, 104].
    -106 <= Node.val <= 106
*/
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void addNode(ListNode *head, int val)
{
    ListNode *n = new ListNode(val);

    while (head->next)
    {
        head = head->next;
    }

    head->next = n;
}

ListNode *oddEvenList(ListNode *head)
{
    if (head == nullptr)
        return head;

    ListNode* odd = head;
    ListNode* even = head->next;
    // even listnode의 시작 노드
    ListNode* even_begin = head->next;

    while (even && even->next) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    // odd listnode와 even listnode를 연결
    odd->next = even_begin;
    return head;
}


int main() {
    ListNode *head = new ListNode(1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);
    addNode(head, 6);

    head = oddEvenList(head);
    return 0;
}