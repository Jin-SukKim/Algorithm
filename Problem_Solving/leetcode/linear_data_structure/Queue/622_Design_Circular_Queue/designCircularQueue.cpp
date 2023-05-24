/*
    622. Design Circular Queue
        Design your implementation of the circular queue. 
        The circular queue is a linear data structure in which the operations are performed based on FIFO 
        (First In First Out) principle, and the last position is connected back to the first position to make a circle. 
        It is also called "Ring Buffer".

        One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. 
        In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. 
        But using the circular queue, we can use the space to store new values.

    Implement the MyCircularQueue class:
        - MyCircularQueue(k) Initializes the object with the size of the queue to be k.
        - int Front() Gets the front item from the queue. If the queue is empty, return -1.
        - int Rear() Gets the last item from the queue. If the queue is empty, return -1.
        - boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
        - boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
        - boolean isEmpty() Checks whether the circular queue is empty or not.
        - boolean isFull() Checks whether the circular queue is full or not.
        - You must solve the problem without using the built-in queue data structure in your programming language. 

    Example 1:
        Input
        ["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
        [[3], [1], [2], [3], [4], [], [], [], [4], []]
        Output
        [null, true, true, true, false, 3, true, true, true, 4]

        Explanation
        MyCircularQueue myCircularQueue = new MyCircularQueue(3);
        myCircularQueue.enQueue(1); // return True
        myCircularQueue.enQueue(2); // return True
        myCircularQueue.enQueue(3); // return True
        myCircularQueue.enQueue(4); // return False
        myCircularQueue.Rear();     // return 3
        myCircularQueue.isFull();   // return True
        myCircularQueue.deQueue();  // return True
        myCircularQueue.enQueue(4); // return True
        myCircularQueue.Rear();     // return 4
        

    Constraints:
        - 1 <= k <= 1000
        - 0 <= value <= 1000
        - At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.
*/
#include <vector>
#include <iostream>
#include <algorithm>

// front와 rear을 하나로 합쳐서 index handle하나로도 가능하다.
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        v.resize(k);
        max = k;
        front = 0;
        rear = 0;
        count = 0;
    }
    
    // rear가 이동하며 value 삽입
    bool enQueue(int value) {
        if (isFull())
            return false;

        v[rear] = value;
        rear = (rear + 1) % max;
        count++;
        return true;
    }
    
    // front가 이동하며 value 삭제
    bool deQueue() {
        if (isEmpty())
            return false;

        front = (front + 1) % max;
        count--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : v[front];
    }
    
    int Rear() {
        return isEmpty() ? -1 : v[(front+count-1)%max];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==max;
    }

private:
    std::vector<int> v;
    int front, rear, max, count;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    MyCircularQueue* obj = new MyCircularQueue(3);
    std::cout << obj->enQueue(1) << std::endl;
    std::cout << obj->enQueue(2)<< std::endl;
    std::cout << obj->enQueue(3)<< std::endl;
    std::cout << obj->enQueue(4)<< std::endl;
    std::cout << obj->Rear()<< std::endl;
    std::cout << obj->isFull()<< std::endl;
    std::cout << obj->deQueue()<< std::endl;
    std::cout << obj->enQueue(4)<< std::endl;
    std::cout << obj->Rear()<< std::endl;
    std::cout << obj->deQueue()<< std::endl;
    std::cout << obj->deQueue()<< std::endl;
    std::cout << obj->deQueue()<< std::endl;
    std::cout << obj->Rear()<< std::endl;

    return 0;
}