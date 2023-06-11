class BinaryHeap(object):
    def __init__(self):
        # 인덱스 0은 사용하지 않기에 None으로 설정
        self.items = [None]
        
    def __len__(self):
        # 인덱스 1부터 시작해서 길이 - 1
        return len(self.items) - 1 
    
    # 삽입 시 실행, 반복 구조 구현
    def _percolate_up(self):
        i = len(self)
        # 힙 배열의 노드 레벨은 2의 배수
        parent = i // 2
        # 정렬
        while parent > 0:
            # 부모 값보다 작으면 위치 변경
            if self.items[i] < self.items[parent]:
                self.items[parent], self.items[i] = \
                    self.items[i], self.items[parent]
            i = parent
            parent = i // 2
            
    def insert(self, k):
        # 맨 마지막에 삽입
        self.items.append(k)
        # 정렬
        self._percolate_up()
        
    # 추출시 실행, 재귀 구조 구현
    def _percolate_down(self, idx):
        left = idx * 2
        right = idx * 2 + 1
        smallest = idx
        
        # 최소힙이기에 각각 왼쪽과 오른쪽 자식을 비교하고 더 작하면 해당 인덱스로 교쳬
        if left <= len(self) and self.items[left] < self.items[smallest]:
            smallest = left
            
        if right <= len(self) and self.items[right] < self.items[smallest]:
            smallest = right
        
        # 인덱스가 교체됬다면 서로 값을 스왑하고 다시 재귀 호출
        if smallest != idx:
            self.items[idx], self.items[smallest] = \
                self.items[smallest], self.items[idx]
            self._percolate_down(smallest)
            
    def extract(self):
        # 루트 추출
        extracted = self.items[1] 
        # 마지막 요소를 루트로 올려준다.
        self.items[1] = self.items[len(self)]
        self.items.pop()
        # 정렬
        self._percolate_down(1)
        return extracted