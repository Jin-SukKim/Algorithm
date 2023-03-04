# 전가산기 구현(Full Adder) : 논리 회로
# 이진법이 아닌 십진법이란 차이만 있을뿐 
# 자리올림수(Carry)를 구하는 것까지 가산기의 어ㅜㄴ리와 거의 동일하다
# 입력값 A, B, 이전의자리올림수 Carry in, 3가지 입력으로 합(Sum)과 다음자리 올림수 (Carry out) 결정

# 전가산기의 전체적인 구조만 참고했다
def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
    root = head = ListNode(0)
    
    carry = 0
    while l1 or l2 or carry:
        sum = 0
        
        # 두 입력값의 합 계산, 입력값 A, B와 비슷하다
        if l1:
            sum += l1.val
            l1 = l1.next
            
        if l2:
            sum += l2.val
            l2 = l2.next
            
        # 몫(자리올림수)과 나머지(값) 계산
        carry, val = divmod(sum + carry, 10)
        head.next= ListNode(val)
        head = head.next
        
    return root.next