#include <vector>
#include <algorithm>

// heap 자료구조 사용해서 priority queue 처럼 사용
// priority queue도 make_heap을 사용해 생성됬다
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
}
ListNode* mergeKLists(std::vector<ListNode*>& lists) { //make_heap
    ListNode head(0);
    ListNode *curNode = &head;
    std::vector<ListNode*> v;   
    for(int i =0; i<lists.size(); i++){
        if(lists[i]) v.push_back(lists[i]);
    }
    std::make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

    while(v.size()>0){
        curNode->next=v.front();
        std::pop_heap(v.begin(), v.end(), heapComp); 
        v.pop_back(); 
        curNode = curNode->next;
        if(curNode->next) {
            v.push_back(curNode->next); 
            std::push_heap(v.begin(), v.end(), heapComp);
        }
    }
    return head.next;
}