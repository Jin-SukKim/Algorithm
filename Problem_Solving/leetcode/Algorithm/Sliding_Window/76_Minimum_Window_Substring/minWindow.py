class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # 문자 단위의 포함 여부를 판별하는 것은 반드시 일대일로 문자가
        # 대응되어야 한다는 점에서 전체를 한 번에 비교하기 어렵고 정렬해서 풀이도 어렵다.
        def contains(s_substr_lst: List, t_lst: List):
            for t_elem in t_lst:
                # t의 문자를 하나씩 비교하며 윈도우 내에 속한 문자를 
                # 제거하는 방식으로 포함 여부를 판단한다.
                if t_elem in s_substr_lst:
                    s_substr_lst.remove(t_elem)
                # 이미 제거됬거나 다른 이유로 문자가 없다면 False
                else:
                    return False
                
            return True
        
        if not s or not t:
            return ''
        
        window_size = len(t)
        
        for size in range(window_size, len(s) + 1):
            for left in range(len(s) - size + 1):
                s_substr = s[left:left + size]
                if contains(list(s_substr), list(t)):
                    return s_substr
                
        return ''