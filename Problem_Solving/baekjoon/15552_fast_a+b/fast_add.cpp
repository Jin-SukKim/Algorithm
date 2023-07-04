#include <iostream>
int main()
{
    /*
        기본적으로 C++와 C의 standard stream은 동기화 되어 있다.
        즉, C++에서 C 스타일로 입출력을 받아도 두 스타일이 서로 동기화해 입/출력하고자 하는
        순서대로 결과를 얻을 수 있으나 동일한 버퍼를 공유해 성능이 저하된다.
        (C++의 iostream과 C의 stdio의 버퍼를 모두 사용하기 때문)

        std::sync_with_stdio(false)를 하게 되면 c++의 입출력 속도를 향상시킬 수 있다.
        하지만 c와 c++의 입출력 함수를 혼용하면 출력 순서를 보장할 수 없다.

        원래 cin과 cout은 서로 묶여 있다.
        입력 요청이 들어오면 출력 버퍼에 내용이 있을 경우 버퍼를 flush(비우기)해준다.
        결국 버퍼를 비우느라 시간이 더 걸리는데 cin.tie(nullptr)로 묶인 걸 풀어줄 수 있다.

        std::cin.tie(nullptr) std::cout.tie(nullptr)를 하게 되면 
        flush를 덜 자주 하기 때문에 입출력 속도를 향상시킬 수 있다.
        하지만 입출력의 순서를 보장받을 수 없다.(입력과 출력 각각의 순서는 
        보장받을 수 있다는 의미)

        */
    std::cin.tie(nullptr); // cin만 풀어줘 입력을 먼저 한 번에 다 받는다.
    std::ios::sync_with_stdio(false);
    int T, a, b;
    std::cin >> T;
    while (T--) {
        std::cin >> a >> b;
        /*
            endl은 새로운 줄로 개행해 줄 뿐만 아니라 출력 버퍼를 지워주기도 해 
            "\n"보다 시간이 더 걸린다. (cin.tie(nullptr)의 효과도 볼 수 없게 해준다.)
        */
        std::cout << a + b << "\n";
    }
    return 0;
}
