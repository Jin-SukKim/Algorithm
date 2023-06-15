/*
    191. Number of 1 Bits
        Write a function that takes the binary representation of
        an unsigned integer and returns the number of '1' bits it has
        (also known as the Hamming weight).

        Note:

        Note that in some languages, such as Java, there is
        no unsigned integer type.
        In this case, the input will be given as a signed integer type.
        It should not affect your implementation,
        as the integer's internal binary representation is the same,
         whether it is signed or unsigned.
        In Java, the compiler represents the signed integers
        using 2's complement notation.
        Therefore, in Example 3, the input represents the signed integer. -3.

    Example 1:
        Input: n = 00000000000000000000000000001011
        Output: 3
        Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

    Example 2:
        Input: n = 00000000000000000000000010000000
        Output: 1
        Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

    Example 3:
        Input: n = 11111111111111111111111111111101
        Output: 31
        Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

    Constraints:
        The input must be a binary string of length 32.

    Follow up: If this function is called many times,
    how would you optimize it?
*/

/*
    이 문제의 결과는 모두 0으로 구성된 비트들과의 해밍 거리로,
    이를 해밍 가중치라고 부른다.
*/
#include <cstdint>
class Solution
{
public:
    /*
        1000에서 1을 빼면 0111이 된다.
        이 값을 AND 연산하면 0이 된다.

        1010에서 1을 뺀 1001을 AND 연산하면 0b1000이 된다.

        이처럼 1을 뺀 값과 AND 연산을 할 때마다 비트가 1씩 빠지게 된다.
        그러면 0이 될 때까지 이 작업을 반복하면 저체 비트에서 1의 개수가 몇 개인지
        알 수 있다.
    */
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while (n)
        {
            /*
                if (n & 1)
                    count++;
                n >>= 1
            */
            // 1을 뺀 값과 AND 연산 횟수 측정
            n &= n -1;
            count++;
        }

        return count;
    }
};