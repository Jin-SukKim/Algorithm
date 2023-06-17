# 투 포인터, 슬라이딩 윈도우, Counter를 모두 이용
import collections


class Solution:
    
    # 최대 길이를 찾는 문제이르모, right는 클수록 좋고, left는 작을수록 좋다.
    def characterReplacement(self, s: str, k: int) -> int:
        # 최대 길이를 찾으므로 right는 클 수록 좋고 left는 작을수록 좋다
        left = right = 0
        counts = collections.Counter()
        for right in range(1, len(s) + 1):
            counts[s[right - 1]] += 1
            # 가장 흔하게 등장하는 문자 탐색
            max_char_n = counts.most_common(1)[0][1]
            
            # k 초과시 왼쪽 포인터 이동
            # 오른쪽 포인터에서 왼쪽 포인터 위치를 뺸 다음, 윈도우 내 출현 빈도가
            # 가장 높은 문자의 수를 뺀 값이 k와 같을 수 있는 수 중 가장 큰 최댓값이다
            if right - left - max_char_n > k:
                counts[s[left]] -= 1
                left += 1
                
        return right - left
        