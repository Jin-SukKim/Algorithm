import collections

def removeDuplicateLetters(s: str) -> str:
    # 각 char의 숫자, 집합, 스택
    counter, seen, stack = collections.Counter(s), set(), []
    
    for char in s:
        counter[char] -= 1
        
        if char in seen:
            continue
        # 뒤에 붙일 문자가 남아 있다면 스택에서 제거(char가 2개 이상일때)
        while stack and char < stack[-1] and counter[stack[-1]] > 0:
            r = char < stack[-1]
            c1 = char
            c2 = stack[-1]
            seen.remove(stack.pop())
            
        stack.append(char)
        seen.add(char)
        
    return ''.join(stack)

s = "cbacdcbc"
removeDuplicateLetters(s)