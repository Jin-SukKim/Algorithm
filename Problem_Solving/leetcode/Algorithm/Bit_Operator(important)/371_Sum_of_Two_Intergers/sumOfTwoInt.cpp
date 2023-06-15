/*
    371. Sum of Two Integers
        Given two integers a and b, 
        return the sum of the two integers without using 
        the operators + and -.

    Example 1:
        Input: a = 1, b = 2
        Output: 3

    Example 2:
        Input: a = 2, b = 3
        Output: 5
    
    Constraints:
        -1000 <= a, b <= 1000
*/

// +, - 연산자를 사용하지 않고 두 정수의 합을 구해야 된다.

class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        while (b != 0)
        {
            // carry 값을 고려하지 않는 a와 b의 합
            sum = a ^ b; 
            // 자릿수를 올려가며 carry 값이 담기게 한다.
            // AND 연산으로 올림수를 확인하고 왼쪽으로 shift해준다.
            // ex) 101 & 001 = 001 -> 왼쪽 shift -> 010. 알맞은 자리로 간다.
            // carry에는 음수가 필요 없고 음수면 shift하지 못하기에 unsigned로 cast
            b = static_cast<unsigned>(a & b) << 1;
            a = sum;
        }

        return a;
    }
};