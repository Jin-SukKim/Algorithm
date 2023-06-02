# intertools 모듈 사용
import itertools

def combine(n: int, k: int) -> List[List[int]]:
    return list(itertools.combinations(range(1, n+1), k))
