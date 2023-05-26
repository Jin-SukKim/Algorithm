/*
    641. Design Circular Deque
        Design your implementation of the circular double-ended queue (deque).

    Implement the MyCircularDeque class:
        - MyCircularDeque(int k) Initializes the deque with a maximum size of k.
        - boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
        - boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
        - boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
        - boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
        - int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
        - int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
        - boolean isEmpty() Returns true if the deque is empty, or false otherwise.
        - boolean isFull() Returns true if the deque is full, or false otherwise.
        

    Example 1:

        Input
        ["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
        [[3], [1], [2], [3], [4], [], [], [], [4], []]
        Output
        [null, true, true, true, false, 2, true, true, true, 4]

    Explanation
        MyCircularDeque myCircularDeque = new MyCircularDeque(3);
        myCircularDeque.insertLast(1);  // return True
        myCircularDeque.insertLast(2);  // return True
        myCircularDeque.insertFront(3); // return True
        myCircularDeque.insertFront(4); // return False, the queue is full.
        myCircularDeque.getRear();      // return 2
        myCircularDeque.isFull();       // return True
        myCircularDeque.deleteLast();   // return True
        myCircularDeque.insertFront(4); // return True
        myCircularDeque.getFront();     // return 4
    

    Constraints:
        - 1 <= k <= 1000
        - 0 <= value <= 1000
        - At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
*/

// 이중 연결 리스트를 사용했지만 원형의 이점을 살리려면 배열을 사용해야된다.
#include <iostream>
class ListNode{
public:
    ListNode(int k, ListNode* left = nullptr, ListNode* right = nullptr) {
        val = k;
        this->left = left;
        this->right = right;
    }

    ~ListNode()
    {
        delete left;
        delete right;
    }

    ListNode* left;
    ListNode* right;
    int val;
};

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        // 왼쪽, 오른쪽 index 역할
        head = new ListNode(0);
        tail = new ListNode(0);
        // 최대 길이
        max = k;
        // 현재 길이
        len = 0;
        head->right = tail;
        tail->left = head;
    }
    
    void add(ListNode* node, ListNode* n) {
        ListNode* temp = node->right;
        node->right = n;
        n->left = node;
        n->right = temp;
        temp->left = n;
    }

    void del(ListNode* node) {
        ListNode* temp = node->right->right;
        node->right = temp;
        temp->left = node;
    }

    // 앞쪽에 노드 추가
    bool insertFront(int value) {
        if (len == max)
            return false;
        len++;
        add(head, new ListNode(value));
        return true;
    }
    
    bool insertLast(int value) {
        if (len == max)
            return false;
        len++;
        add(tail->left, new ListNode(value));
        return true;
    }
    
    bool deleteFront() {
        if (len == 0)
            return false;
        len--;
        del(head);
        return true;
    }
    
    bool deleteLast() {
        if (len == 0)
            return false;
        len--;
        del(tail->left->left);
        return true;
    }
    
    int getFront() {
        return len ? head->right->val : -1;
    }
    
    int getRear() {
        return len ? tail->left->val : -1;
    }
    
    bool isEmpty() {
        return !len;
    }
    
    bool isFull() {
        return len == max;
    }

private:
    ListNode* head;
    ListNode* tail;
    int max, len;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main() {
    MyCircularDeque* obj = new MyCircularDeque(5);
    std::cout << obj->insertFront(5) << std::endl;
    std::cout << obj->insertLast(0) << std::endl;
    std::cout << obj->getFront() << std::endl;
    std::cout << obj->insertLast(3) << std::endl;
    std::cout << obj->getFront() << std::endl;
    std::cout << obj->insertFront(9) << std::endl;
    std::cout << obj->getRear() << std::endl;
    std::cout << obj->getFront() << std::endl;
    std::cout << obj->getFront() << std::endl;
    std::cout << obj->deleteLast() << std::endl;
    std::cout << obj->getRear() << std::endl;
    return 0;
}