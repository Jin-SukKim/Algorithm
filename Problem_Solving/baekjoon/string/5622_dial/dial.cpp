#include <iostream>
#include <string>

// ASCII 테이블의 값을 활용, 7, 9, 0번을 제외한 나머지 번호는 3개의 문자가 들어가 있따.
int dialTime(char& c) {
    if (c == 'Z') {
        return 10;
    }
    else if (c == 'S') {
        return 8;
    }
    // 7번은 4개의 문자를 가지고 있어 ((c - 'A') / 3) + 3로 해준다.
    else if ((c - 'T') >= 0) { 
        // T = 124. T,U,V / 3 = 0. W,X,Y / 3 = 1
        return ((c - 'T') / 3) + 9; 
    }
    else {
        // A = 101, A,B,C / 3 = 0, D,E,F /3 = 1 ...
        return ((c - 'A') / 3) + 3; 
    }
    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::string word;
    int time =0;
    std::cin >> word;

    for (int i = 0; i < word.length(); i++) {
        time += dialTime(word[i]);
    }
    
    std::cout << time;

    return 0;
}


