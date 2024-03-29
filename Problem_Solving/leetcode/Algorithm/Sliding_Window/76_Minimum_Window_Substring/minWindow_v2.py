import collections


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # 필요한 문자 각각의 개수
        need = collections.Counter(t)
        # 필요한 문자의 전체 개수
        missing = len(t)
        left = start = end = 0
        
        # 오른쪽 포인터 이동, 슬라이딩 윈도우의 크기가 점점 더 커지는 형태
        # 파이썬은 s[n:n + 1] 형태로 슬라이싱하므로 1부터 시작
        for right, char in enumerate(s, 1): 
            # 현재 문자가 필요한 문자 need[char]에 포함되어 있다면
            # 필요한 문자의 전체 개수인 missing을 1 감소하고
            # 해당 문자의 필요한 개수 need[char]도 1감소한다.
            missing -= need[char] > 0
            need[char] -= 1
            
            # 필요 문자가 0이면 왼쪽 포인터 이동 판단
            if missing == 0:
                while left < right and need[s[left]] < 0:
                    need[s[left]] += 1
                    left += 1
                    
                if not end or right - left <= end - start:
                    start, end = left, right
                need[s[left]] += 1
                missing += 1
                left += 1
        
        return s[start:end]