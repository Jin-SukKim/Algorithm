/*
    461. Hamming Distance
        The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

        Given two integers x and y, return the Hamming distance between them.

    Example 1:
        Input: x = 1, y = 4
        Output: 2
        Explanation:
        1   (0 0 0 1)
        4   (0 1 0 0)
            ↑   ↑
        The above arrows point to positions where the corresponding bits are different.

    Example 2:
        Input: x = 3, y = 1
        Output: 1

    Constraints:
        0 <= x, y <= 231 - 1
*/

// 두 정수를 입력받아 몇 비트가 다른지 계산
/*
    자연어 처리에서도 널리 쓰이는 해밍 거리는 두 정수 또는 두 문자열의 차이를 말한다.
    ex) karolin과 kathrin의 차이는 3이고 1011101과 1001001은 2다.
    문자열의 경우 다른 자리의 문자 개수가 되며, 이진수의 경우 다른 위치의 비트 개수다.
*/
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        // XOR 연산으로 다른 위치의 비트를 찾는다.
        int result = x ^ y;
        int count = 0;
        while (result)
        {
            // 맨 오른쪽 비트가 1인지 확인
            if (result & 1) 
                count++;
            // 오른쪽으로 한칸씩 shift
            result >>= 1;
        }
        
        return count;
    }
};