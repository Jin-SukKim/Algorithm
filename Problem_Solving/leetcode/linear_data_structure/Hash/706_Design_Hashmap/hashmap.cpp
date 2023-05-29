/*
    706. Design HashMap
        Design a HashMap without using any built-in hash table libraries.

    Implement the MyHashMap class:
        MyHashMap() initializes the object with an empty map.
        void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
        int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
        void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
    

    Example 1:
        Input
        ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
        [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
        Output
        [null, null, null, 1, -1, null, 1, null, -1]

        Explanation
        MyHashMap myHashMap = new MyHashMap();
        myHashMap.put(1, 1); // The map is now [[1,1]]
        myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
        myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
        myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
        myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
        myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
        myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
        myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
        

    Constraints:
        - 0 <= key, value <= 106
        - At most 104 calls will be made to put, get, and remove.
*/

// working but not pass on testcase no.27 why? 
// 개별 체이닝 방법을 사용하는 해시맵
#include <unordered_map>
struct ListNode
{
    int key, val;
    ListNode *next;
    ListNode() : next(nullptr) {}
    ListNode(int x, int y) : key(x), val(y), next(nullptr) {}
    ListNode(int x, int y, ListNode*) : key(x), val(y), next(next) {}
};

class MyHashMap {
public:
    MyHashMap() {
        size = 1000;
    }
    
    void put(int key, int value) {
        // 간단한 정수형 해싱 기법인 Modulo-Division Method
        int index = key % size;

        // 인덱스에 노드가 없다면 삽입 후 종료
        if (map[index] == nullptr) {
            map[index] = new ListNode(key, value);
            return;
        }

        // 인덱스에 노드가 존재하는 경우 연결리스트 연결(개별 체이닝 방법)
        ListNode* p = map[index];
        while (p) {
            // 같은 Key가 있다면 value update
            if (p->key == key)
            {
                p->val = value;
                return;
            }
            // 다음 빈 노드가 있을때 까지 이동
            if (p->next == nullptr)
                break;
            p = p->next;
        }
        p->next = new ListNode(key, value);
    }
    
    int get(int key) {
        // 해싱
        int index = key % size;
        
        // 없다면 -1 return
        if (map[index] == nullptr)
            return -1;

        // 노드가 존재할 때 일치하는 key 탐색
        ListNode* p = map[index];
        while (p)
        {
            if (p->key == key)
                return p->val;
            p = p->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % size;
        if (map[index] == nullptr)
            return;

        // 인덱스의 첫 번째 노드일 때 삭제 처리
        ListNode* p = map[index];
        if (p->key == key)
        {
            // 유일한 노드면 nullptr, 아니라면 현재 노드 삭제
            if (p->next == nullptr) 
                map[index] = nullptr;
            else {
                ListNode* temp = p->next;
                p = nullptr;
                p = temp;
            }
            return;
        }

        // 노드 삭제
        ListNode* prev = p;
        while (p)
        {
            if (p->key == key)
            {
                // 이전 노드의 다음을 현재 노드의 다음과 연결해 현재 노드를 없애준다.
                prev->next = p->next;
                return;
            }

            prev = p;
            p = p->next;
        }
    }
private:
    int size;
    std::unordered_map<int, ListNode*> map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    MyHashMap *myHashMap = new MyHashMap();
    myHashMap->put(1, 1); // The map is now [[1,1]]
    myHashMap->put(2, 2); // The map is now [[1,1], [2,2]]
    myHashMap->get(1);    // return 1, The map is now [[1,1], [2,2]]
    myHashMap->get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap->put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    myHashMap->get(2);    // return 1, The map is now [[1,1], [2,1]]
    myHashMap->remove(2); // remove the mapping for 2, The map is now [[1,1]]
    myHashMap->get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
    myHashMap->put(2, 2);
    myHashMap->put(1, 2);
    myHashMap->remove(1);
    return 0;
}