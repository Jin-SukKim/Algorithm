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
    if (head == nullptr || left == right)
        return head;

    // 시작 node와 끝 node 자체는 바뀌지 않으나 next로 연결되는 node가 바뀐다.
    // rev : reverse list node의 시작위치, end : 끝위치
    ListNode* root = new ListNode(), *rev = root, *end;
    root->next = head;

    for (int i = 0; i < left-1; i++)
    {
        rev = rev->next;
    }
        
    end = rev->next;
    ListNode* temp = nullptr;

    for (int i = 0; i < right - left; i++)
    {
        temp = rev->next;
        rev->next = end->next;
        end->next = end->next->next;
        rev->next->next = temp;
    }

    return root->next;
}
        
int main() {
    ListNode *head = new ListNode(1);
    addNode(head, 2);
    addNode(head, 3);

    head = reverseBetween(head, 1, 2);
    return 0;
}