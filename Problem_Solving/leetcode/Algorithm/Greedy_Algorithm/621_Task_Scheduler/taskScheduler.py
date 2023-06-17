import collections


class Solution:
    
    # 우선순위 큐 활용
    # 아이템을 추출한 이후에 매번 아이템 개수를 업데이트 해준다.
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = collections.Counter(tasks)
        result = 0
        
        while True:
            sub_count = 0
            
            # 개수 순 추출, 가장 개수가 많은 아이템부터 하나씩 추출한다(최대 힙).
            # 하나만 추출하고 빠진 개수를 업데이트 해준다.
            for task, _ in counter.most_common(n + 1):
                sub_count += 1
                result += 1
                
                # pop()으로 빼준게 아니기에 직접 1개씩 줄여준다.
                counter.subtract(task)
                # 0 이하인 아이템을 목록에서 완전히 제거
                counter += collections.Counter()
                
            if not counter:
                break
            
            result += n - sub_count + 1
            
        return result