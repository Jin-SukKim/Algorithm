# 비트 연산을 묻는 문제다.
# 문제에 이미 이진수라고 언급했고 설명을 보면 OR을 얘기하고 있따.
# 물론 문자열 비교로 풀이해도 문제는 없지만 오프라인 코딩 테스트였다면
# 의도와 빗나가기에 감점이 있을수도 있다.
def solution(n: int, arr1: List[int], arr2: List[int]) -> List[str]:
    maps = []
    for i in range(n):
        # OR 연산 후  이진수 변환
        maps.append(
            bin(arr1[i] | arr2[i])[2:]
            .zfill(n)
            .replace('1', '#')
            .replace('0', ' ')
        )
    return maps