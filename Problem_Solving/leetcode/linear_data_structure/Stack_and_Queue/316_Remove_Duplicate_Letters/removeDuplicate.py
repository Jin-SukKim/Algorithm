# 재귀함수 이용
def removeDuplicateLetters(s: str) -> str:
    # 집합으로 정렬(중복 문자를 제외한 알파벳 순으로 정렬)
    for char in sorted(set(s)):
        # 가장 빠른 알파벳부터 접미사 suffix로 분리해 확인
        suffix = s[s.index(char):]
        # 전체 집합과 접미사 집합이 일치할 때 분리 진행
        # 분리 가능 여부는 전체 집합과 접미사 집합이 일치하는지 여부로 판별
        if set(s) == set(suffix):
           return char + removeDuplicateLetters(suffix.replace(char, ''))
    
    return ''