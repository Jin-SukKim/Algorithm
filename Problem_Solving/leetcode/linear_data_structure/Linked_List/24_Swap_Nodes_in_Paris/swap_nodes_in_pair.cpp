/*
    Given a linked list, swap every two adjacent nodes and return its head.
    You must solve the problem without modifying the values in the list's nodes 
    (i.e., only nodes themselves may be changed.)

    Example 1:

    Input: head = [1,2,3,4]
    Output: [2,1,4,3]
    Example 2:

    Input: head = []
    Output: []
    Example 3:

    Input: head = [1]
    Output: [1]

    Constraints:

    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100
*/

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

inline void swapNode(ListNode* head, ListNode* next) {
    // 현재 노드로 부터 2번쨰 노드를 가리킨다.
    next = head->next;
    // 현재 노드의 다음 노드가 3번째 노드를 가리키게한다.
    head->next = next->next;
    // 2번째 노드의 다음 노드가 현재 노드가 된게한다.
    next->next = head;
}

ListNode *swapPairs(ListNode *head)
{   
    ListNode* root = new ListNode();
    ListNode* prev = root;
    prev->next = head;

    ListNode* next = nullptr;
    while (head && head->next) {
        next = head->next;
        head->next = next->next;
        next->next = head;

        prev->next = next;

        head= head->next;
        prev = prev->next->next;
    }

    head = root->next;
    delete root;

    return head;
}

int main() {
    ListNode *head = new ListNode(1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);

    head = swapPairs(head);
    return 0;
}