# itertools 모듈 사용
# 이 모듈은 반복자 생성에쵲거화된 효율적인 기능들을 제공한다.
import itertools

def permute(nums: List[int]) -> List[List[int]]:
    return list(itertools.permutations(nums))