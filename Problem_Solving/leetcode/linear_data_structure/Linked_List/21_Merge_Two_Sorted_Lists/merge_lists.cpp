/*
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list.
    The list should be made by splicing together the nodes of the first two lists.

    Return the head of the merged linked list.

    Example 1:

    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]
    Example 2:

    Input: list1 = [], list2 = []
    Output: []
    Example 3:

    Input: list1 = [], list2 = [0]
    Output: [0]

    Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 8ms, 14.7MB
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{   
    /*
        > 비교의 우선순위가 높아 먼저 비교하고 list1 존재유무
        and 그리고 or 순으로 비교한다.
        l1과 l2의 값을 비교해 작은 값이 왼쪽에 오게한다.
    */
    if (!list1 || (list2 && list1->val > list2->val)) {
        ListNode* temp = list1;
        list1 = list2;
        list2 = temp;
    }
    if (list1) {
        // 재귀호출로 다음 연결 리스트가 스왑될 수 있게 한다.
        list1->next = mergeTwoLists(list1->next, list2);
    }
    return list1;

}