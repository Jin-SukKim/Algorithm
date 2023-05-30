# 파이썬다운 방식
import collections

def topKFrequent(nums, k)->list:
    # most_common() : 빈도 수가 높은 순서대로 아이템을 추출하는 기능
    # zip() : 2개 이상의 시퀀스를 짧은 길이를 기준으로일대일 대응하는 새로운 튜플 생성
    # list() 로 zip()의 결과물인 제너레이터를 묶어준다.
    # 아스테리스크(*) : Swquence Unpacking Operator로 시퀀스를 풀어헤치는 연산자다
    return list(zip(*collections.Counter(nums).most_common(k)))[0]