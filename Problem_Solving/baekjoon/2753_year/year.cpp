#include <iostream>
int main()
{
    int year;
    std::cin >> year;
    bool correct = false;
    // 해당 년도가 4의 배수일 때 100의 배수가 아니거나 400의 배수이면 윤년이 맞다
    if (year % 4 == 0)
    {
        if ((year % 100) || (year % 400 == 0))
            correct = true;
    }

    std::cout << correct;
    return 0;
}