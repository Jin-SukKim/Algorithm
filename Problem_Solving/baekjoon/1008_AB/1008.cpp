#include <iostream>
#include <iomanip>
int main(){
    // 오차가 10^-9 이하여야 한다.
    // 1/3 등의 수는 무한의 수이기에 근사값을 표현하는데 float이 10^-7 전후이므로 double을 사용한다.
    double a, b;
    std::cin >> a >> b;

    // 소수점 숫자 개수 제한
    std::cout << std::setprecision(12) << a / b << std::endl;
    return 0;
}