#include <vector>

// Linked-List가 아닌 vector를 사용
class MyHashMap {
    // 개별 체이닝 방법
	std::vector<std::vector<std::pair<int, int>>> map;
	const int size = 10000;
public:
	MyHashMap() {
		map.resize(size);
	}

	void put(int key, int value) {
        // 간단한 해싱 기법 (Modulo-Division Method)
		int index = key % size;
        auto &link = map[index];
        for(auto iter = link.begin(); iter != link.end(); iter++)
        {
            // 키가 같다면
            if(iter->first == key)
            {
                // 값 update
                iter->second = value;
                return;
            }
        }
        // 키가 없다면 새로운 pair 삽입
		link.push_back(std::make_pair(key, value));
	}

	int get(int key) {
		int index = key % size;
        auto &link = map[index];
		for (auto iter = link.begin(); iter != link.end(); iter++)
		{
			if (iter->first == key)
			{
				return iter->second;
			}
		}
		return -1;
	}

	void remove(int key) {
		int index = key % size;
        auto &link = map[index];
		for (auto iter = link.begin(); iter != link.end(); iter++)
		{
			if (iter->first == key)
			{
				link.erase(iter);
                return;
			}
		}
	}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */