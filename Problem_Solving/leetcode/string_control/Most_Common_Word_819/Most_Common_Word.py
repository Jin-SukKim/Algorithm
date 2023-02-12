import collections
import re

def mostCommonWord(self, paragraph: str, banned: list[str]) -> str:
    # Data Cleansing : 입력값에 대한 전처리 작업
    # 정규식에서 \w는 단어 문자(Word Character)를 뜻하며, ^은 not을 의미한다.
    # 즉 단어 문자가 아닌 모든 문자를 공백으로 치환
    # List Comprehension에서 words에 소문자, 구두점, banned을 제외한 단어 목록을 저장
    words = [word for word in re.sub(r'[\w]', ' ', paragraph)
            .lower().split()
                if word not in banned]
    
    counts = collections.Counter(words)
    
    # 가장 흔하게 등장하는 단어의 첫 번쨰 인덱스 리턴
    # ex) [('ball', 2)]가 되면 [0][0]으로 첫번째 인덱스의 키를 추출
    return counts.most_common(1)[0][0]