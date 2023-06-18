class Solution:
    # 복수 개의 계산 결과를 return
    # ex) 3-4*5는 [-17, -5]의 복수 개의 계산 결과를 갖는다.
    def diffWaysToCompute(self, expression: str) -> List[int]:
        def compute(left, right, op):
            results = []
            for l in left:
                for r in right:
                    results.append(eval(str(l) + op + str(r)))
            return results

        if input.isdigit():
            return [int(input)]

        results = []
        for index, value in enumerate(input):
            # *, -, + 연산자가 등장할 떄 좌/우 분할을 하고 각각 계산 결과를 return
            if value in "-+*":
                left = self.diffWaysToCompute(input[index])
                right = self.diffWaysToCompute(input[index + 1:])

                # 복수 개의 계산 결과를 갖게 되며 
                results.extend(compute(left, right, value))

        return results
