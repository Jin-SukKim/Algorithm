/*
    23. Merge k Sorted Lists
        You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
        Merge all the linked-lists into one sorted linked-list and return it.

    Example 1:
        Input: lists = [[1,4,5],[1,3,4],[2,6]]
        Output: [1,1,2,3,4,4,5,6]
        Explanation: The linked-lists are:
        [
        1->4->5,
        1->3->4,
        2->6
        ]
        merging them into one sorted list:
        1->1->2->3->4->4->5->6
        Example 2:

        Input: lists = []
        Output: []
        Example 3:

        Input: lists = [[]]
        Output: []

    Constraints:
        - k == lists.length
        - 0 <= k <= 104
        - 0 <= lists[i].length <= 500
        - -104 <= lists[i][j] <= 104
        - lists[i] is sorted in ascending order.
        - The sum of lists[i].length will not exceed 104.
*/
#include <vector>
#include <queue>

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
struct compare{
    bool operator() (const ListNode* l, const ListNode* r) { return l->val > r->val; }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode* res;
    std::priority_queue<ListNode*, std::vector<ListNode*>, compare> pq;

    for (auto l : lists)
        if (l) pq.push(l);

    if (pq.empty())
        return NULL;

    res = pq.top();
    ListNode* t = res;
    pq.pop();
    if (t->next)
            pq.push(t->next);  

    while (!pq.empty()) {
        t->next = pq.top();
        pq.pop();
        t = t->next;
        if (t->next)
            pq.push(t->next);   
    }

    return res;
}

int main() {
    ListNode *head = new ListNode(1);
    addNode(head, 4);
    addNode(head, 5);

    ListNode *head2 = new ListNode(1);
    addNode(head2, 3);
    addNode(head2, 4);

    ListNode *head3 = new ListNode(2);
    addNode(head3, 6);

    std::vector<ListNode*> v = {head, head2, head3};
    mergeKLists(v);
    return 0;
}