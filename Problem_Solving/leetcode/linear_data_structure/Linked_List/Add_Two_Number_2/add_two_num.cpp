/*
    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example 1:

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.
    Example 2:

    Input: l1 = [0], l2 = [0]
    Output: [0]
    Example 3:

    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]


    Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
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

// 29ms, 71.6MB (too slow, too much space)
#include <string>
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

ListNode* add(ListNode* l1, ListNode* l2) {
    int sum = 0, up = 0, s = 0;

    ListNode* head = new ListNode();
    ListNode* re = head;
    while (l1 || l2) {
        sum = 0;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += up;
        up = sum / 10;
        head->next = new ListNode(sum % 10);
        head = head->next;
    }

    if (up)
        head->next = new ListNode(up);

    head = re->next;
    delete re;
    return head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{   
    l1 = add(l1, l2);

    return l1;
}

int main()
{
    ListNode* head1 = new ListNode(2);
    addNode(head1, 4);
    addNode(head1, 9);
    ListNode* head2 = new ListNode(5);
    addNode(head2, 6);
    addNode(head2, 4);
    addNode(head2, 9);

    addTwoNumbers(head1, head2);
    return 0;
}