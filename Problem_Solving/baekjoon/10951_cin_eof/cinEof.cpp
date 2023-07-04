#include <iostream>
 
int main(int argc, const char *argv[]) {
 
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
 
	int a, b;
    /*
        EOF는 파일의 끝을 알리는 함수로 -1의 값을가지며 콘솔 창에서는 Ctrl+Z가
        EOF를 의미한다.
        bool 타입을 return하는 .eof()를 사용하면 EOF 값이 입력되면 끝낼 수 있다.

        while 문안에 std::cin을 넣어줘 정상적인 입력이 아닐 시에도 끝내도록 해주었다.
    */
    // while (!(std::cin >> a >> b).eof())
	while (std::cin >> a >> b) {
		std::cout << a + b << "\n";
	}
 
	return 0;
}