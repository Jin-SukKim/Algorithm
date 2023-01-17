# Python 내부 기능인 slicing 사용하기.
import re

def isPalindrome(self, s:str) -> bool:
    s = s.lower()
    # 정규식으로 불필요한 문자 필터링
    s = re.sub('[^a-z0-9]', '', s)
    
    # 슬라이싱으로 문자열 뒤집어서 비교하기
    # 내부적으로 C로 구현되어 있어 빠르다
    return s == s[::-1]
    