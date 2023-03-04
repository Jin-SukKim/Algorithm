// 성능 비교를 위한 C 언어 코드
#include <stdio.h>
#include <stdbool.h>

bool isPalindrom(char *s) {
    int bias_left = 0;
    int bias_right = 0;

    int str_len = strlen(s);
    for (int i = 0; i < str_len; i++) {
        // skip pointer 처리
        while (!isalnum(s[i + bias_left])) {
            bias_left++;
            if(i + bias_left == str_len)
                return true;
        }
        while (!isalnum(s[str_len - i - bias_right]))
            bias_right++;

        if (i + bias_left >= str_len - i - bias_left)
            break;

        // Palindrome 비교
        if(tolower(s[i + bias_left]) != tolower(s[str_len - i - bias_right]))
            return false;
    }

    return true;
}