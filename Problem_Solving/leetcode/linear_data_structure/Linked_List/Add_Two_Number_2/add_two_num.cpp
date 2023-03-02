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

ListNode *reverseList(ListNode *head)
{
    ListNode *next = head;
    ListNode *rev = nullptr;

    while (head)
    {
        next = head->next;
        head->next = rev;
        rev = head;
        head = next;
    }

    return rev;
}

int add(ListNode* head) {
    std::string num = "";

    while (head) {
        num.push_back(head->val);
        head = head->next;
    }

    return std::stoi(num);
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    std::string num = std::to_string(add(l1) + add(l2));

    ListNode* numList = l1;
    for ( std::string::iterator it=num.begin(); it!=num.end(); ++it)
    {
        numList->val += *it;
        numList = numList->next;
    }

    return l1;
}

int main()
{
    ListNode* head1 = new ListNode(2);
    addNode(head1, 4);
    addNode(head1, 3);
    ListNode* head2 = new ListNode(5);
    addNode(head2, 6);
    addNode(head2, 4);

    addTwoNumbers(head1, head2);
    return 0;
}