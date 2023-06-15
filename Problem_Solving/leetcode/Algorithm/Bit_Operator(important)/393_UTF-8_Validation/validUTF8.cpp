/*
    393. UTF-8 Validation
        Given an integer array data representing the data,
        return whether it is a valid UTF-8 encoding
        (i.e. it translates to a sequence of valid UTF-8 encoded characters).

        A character in UTF8 can be from 1 to 4 bytes long,
        subjected to the following rules:

        For a 1-byte character, the first bit is a 0,
        followed by its Unicode code.
        For an n-bytes character, the first n bits are all one's,
        the n + 1 bit is 0, followed by n - 1 bytes with
        the most significant 2 bits being 10.
        This is how the UTF-8 encoding would work:

            Number of Bytes   |        UTF-8 Octet Sequence
                            |              (binary)
        --------------------+-----------------------------------------
                    1          |   0xxxxxxx
                    2          |   110xxxxx 10xxxxxx
                    3          |   1110xxxx 10xxxxxx 10xxxxxx
                    4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        x denotes a bit in the binary form of a byte that may be either 0 or 1.

        Note: The input is an array of integers.
        Only the least significant 8 bits of each integer is used
        to store the data.
        This means each integer represents only 1 byte of data.

    Example 1:
        Input: data = [197,130,1]
        Output: true
        Explanation: data represents the octet sequence:
            11000101 10000010 00000001.
        It is a valid utf-8 encoding for a 2-bytes character followed by
        a 1-byte character.

    Example 2:
        Input: data = [235,140,4]
        Output: false
        Explanation: data represented the octet sequence:
            11101011 10001100 00000100.
        The first 3 bits are all one's and the 4th bit is 0 means
        it is a 3-bytes character.
        The next byte is a continuation byte which starts with 10
        and that's correct.
        But the second continuation byte does not start with 10,
        so it is invalid.

    Constraints:
        1 <= data.length <= 2 * 104
        0 <= data[i] <= 255
*/
#include <vector>

// 첫 바이트를 기준으로 한 판별
/*
    UTF-8의 실제 조건을 묻는 문제이다.

    UTF-8 바이트 순서의 이진 포맷 인코딩 구조

    바이트 수    바이트 1     바이트 2    바이트 3     바이트 4
    1           0xxxxxxx
    2           110xxxxx    10xxxxx
    3           1110xxxx    10xxxxx     10xxxxx
    4           11110xxx    10xxxxx     10xxxxx     10xxxxxx

    표를 기준으로 첫 바이트가 1110으로 시작한다면 3바이트 문자이므로,
    첫 바이트를 제외하고 뒤따르는 2바이트는 모두 10으로 시작해야 유효한 UTF-8문자가 된다.
    아니라면 false return

    UTF-8 인코딩 ex)
        '한' = 11010101 01011100 -> 인코딩(16비트로 표현된 문자이기에 3바이트로 표현)
        ->  첫바이트는 1110 이후에 비트에 코드를 표현하고 나머지 바이트는 10 이후에 표현한다.
            11101101 10010101 10011100
*/
class Solution
{
public:
    bool check(std::vector<int> &data, int start, int size)
    {
        for (int i = start + 1; i < start + size + 1; i++)
        {
            // 나머지 바이트 시작이 0b10으로 시작하는지 확인
            if (i >= data.size() || (data[i] >> 6) != 0b10)
                return false;
        }
        return true;
    }
    bool validUtf8(std::vector<int> &data)
    {
        int start = 0;
        while (start < data.size())
        {
            // 첫 바이트
            int first = data[start];

            // 4 바이트 문자인지 확인(첫 바이트 비트가 11110으로 시작)
            if ((first >> 3) == 0b11110 && check(data, start, 3))
                start += 4;
            // 3바이트 문자인지 확인(첫 바이트 비트가 1110으로 시작)
            else if ((first >> 4) == 0b1110 && check(data, start, 2))
                start += 3;
            // 2바이트 문자인지 확인(첫 바이트 비트가 110으로 시작)
            else if ((first >> 5) == 0b110 && check(data, start, 1))
                start += 2;
            // 1바이트 문자인지 확인(첫 바이트 비트가 0으로 시작)
            else if ((first >> 7) == 0)
                start += 1;
            // UTF-8 인코딩 조건에 맞지 않는다면 false
            else
                return false;
        }

        return true;
    }
};

int main()
{
    std::vector<int> data = {237};
    Solution s;
    s.validUtf8(data);
    return 0;
}