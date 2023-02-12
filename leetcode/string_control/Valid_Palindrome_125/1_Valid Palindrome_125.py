def isPalinrome(sef, s:str) -> bool:
    strs = []
    for char in s:
        # 알파벳과 숫자인지 확인
        if char.isalnum():
            # 대소문자 구분하지 않는다
            strs.append(char.lower())
            
    # Palindrom 여부 판별
    while len(strs) > 1:
        # pop() 함수에서 인덱스 지정 가능해 0으로 맨처음 가져오기
        # pop(0)와 pop()으로 맨앞과 맨뒤 원소를 가져와 비교하기
        if strs.pop(0) != strs.pop():
            return False
        
    return True