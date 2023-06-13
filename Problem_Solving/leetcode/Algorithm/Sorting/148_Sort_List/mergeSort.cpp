/*
    148. Sort List
        Given the head of a linked list,
        return the list after sorting it in ascending order.

    Example 1:
        Input: head = [4,2,1,3]
        Output: [1,2,3,4]

    Example 2:
        Input: head = [-1,5,3,4,0]
        Output: [-1,0,3,4,5]

    Example 3:
        Input: head = []
        Output: []

    Constraints:
        The number of nodes in the list is in the range [0, 5 * 104].
        -105 <= Node.val <= 105
*/
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 그냥 벡터로 변환한 뒤 std::sort로 정렬하는 것이 더 효율적이다.
// merge sort
/*
    연결 리스트는 특성상 pivot을 고정된 위치로 지정할 수밖에 없고
    입력값에 따라 성능의 편차가 심하므로 우선 병합 정렬을 사용한다.
*/
class Solution
{
public:
    // 재귀를 통해 list1의 포인터를 이동하면서 정렬하고 합친다.
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2)
    {
        if (list1 && list2)
        {
            // 정렬
            if (list1->val > list2->val)
            {
                ListNode* temp = list1;
                list1 = list2;
                list2 = temp;
            }
            // 리스트를 이어준다.
            list1->next = mergeTwoList(list1->next, list2);
        }

        return list1 ? list1 : list2;
    }
    /*
        병합 정렬의 분할 정복을 위해서는 중앙을 분할해야하는데
        연결리스트는 전체 길이를 모르기에 Runner 기법을 활용한다.
    */
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // Runner 기법
        /*
            slow는 한 칸씩, fast는 두 칸씩 앞으로 이동한다.
            fast가 맨 끝에 도달할 때 slow는 중앙에 도착한다.
        */
        ListNode *half = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            half = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 마지막에 half->next를 nullptr로 해 연결리스트를 분할해준다.
        half->next = nullptr;
        // 분할 재귀 호출
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(slow);

        // 최종적으로 단일 아이템으로 쪼개진걸 다시 합쳐준다.
        return mergeTwoList(list1, list2);
    }
};

/*
    ListNode* mergeList(ListNode* h1, ListNode* h2) {
        if(h2->val < h1->val) {
            ListNode*tmp = h1;
            h1 = h2;
            h2 = tmp;
        }
        ListNode*head = h1;
        while(h1 || h2) {
            if(!h2) break;
            if(!h1->next) {
                h1->next = h2;
                break;
            }
            if(h1->next->val > h2->val) {
                ListNode*tmp = h2;
                h2 = h2->next;
                tmp->next = h1->next;
                h1->next = tmp;
            }
            h1 = h1->next;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) 
            return head;

        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mergeList(sortList(head), sortList(mid));;
    }
*/
int main()
{   
    ListNode* node = new ListNode(4);
    node->next = new ListNode(2);
    node->next->next = new ListNode(1);
    node->next->next->next = new ListNode(3);

    Solution s;
    s.sortList(node);
    return 0;
}