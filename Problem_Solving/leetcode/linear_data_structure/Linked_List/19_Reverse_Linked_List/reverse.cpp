/*
    92. Reverse Linked List II

    Given the head of a singly linked list and two integers left and right 
    where left <= right, reverse the nodes of the list from position left 
    to position right, and return the reversed list.

    Example 1:
        Input: head = [1,2,3,4,5], left = 2, right = 4
        Output: [1,4,3,2,5]
        Example 2:

        Input: head = [5], left = 1, right = 1
        Output: [5]
    
    Constraints:
        - The number of nodes in the list is n.
        - 1 <= n <= 500
        - -500 <= Node.val <= 500
        - 1 <= left <= right <= n
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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* root = head;

    if (head == nullptr || left == right)
        return head;

    for (int i = 1; i < left-1; ++i)
    {
        head = head->next;
    }

    // 시작 node와 끝 node 자체는 바뀌지 않으나 next로 연결되는 node가 바뀐다.
    // reverse list node의 시작위치
    ListNode* reverse = head;
    // 끝위치
    ListNode* end = reverse->next;
    ListNode* temp = new ListNode();

    for (int i = left; i < right; ++i)
    {
        temp = reverse->next;
        reverse->next = end->next;
        end->next = end->next->next;
        reverse->next->next = temp;
    }

    temp = nullptr;
    delete temp;
    return root;
}


int main() {
    ListNode *head = new ListNode(1);
    addNode(head, 2);

    head = reverseBetween(head, 1, 2);
    return 0;
}