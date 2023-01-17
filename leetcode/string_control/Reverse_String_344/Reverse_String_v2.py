# Python 기본 기능 이용하기
# revserse() 는 리스트에만 제공된다.
# string 이었다면 [::-1] slicing을 이용하면 된다.
# 하지만 공간 복잡도로 인해 leetcode에선 문제가 생기는데 s[:] = s[::-1] 하면 해결된다.

def reverseString(self, s: List[str]) -> None:
    s.reverse()