/*
    147. Insertion Sort List
        Given the head of a singly linked list,
        sort the list using insertion sort,
        and return the sorted list's head.

        The steps of the insertion sort algorithm:

        Insertion sort iterates, consuming one input element
        each repetition and growing a sorted output list.
        At each iteration, insertion sort removes one element from
        the input data, finds the location it belongs within
        the sorted list and inserts it there.
        It repeats until no input elements remain.
        The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

    Example 1:
        Input: head = [4,2,1,3]
        Output: [1,2,3,4]

    Example 2:
        Input: head = [-1,5,3,4,0]
        Output: [-1,0,3,4,5]

    Constraints:
        The number of nodes in the list is in the range [1, 5000].
        -5000 <= Node.val <= 5000
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 삽입 정렬로 정렬
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode* cur = new ListNode();
        ListNode* parent = cur;

        while (head)
        {
            // 정렬된 리스트 cur와 정렬안된 head 노드를 비교해
            // 스왑할 위치를 찾아 cur의 포인터를 옮겨준다.
            while (cur->next && cur->next->val < head->val)
                cur = cur->next;
            
            ListNode* temp = cur->next;
            cur->next = head;
            head = head->next;
            cur->next->next = temp;

            // 비교 조건 개선
            // 다음번 head도 cur보다 큰 상태라면 
            // 어차피 지금 위치나 지금 위치보다 더 앞으로 가야하므로
            // 굳이 맨 처음으로 돌아가지 않는다.
            if (head && cur->val > head->val)
                // 다시 맨 처음부터 시작
                cur = parent;
        }

        return parent->next;
    }
};