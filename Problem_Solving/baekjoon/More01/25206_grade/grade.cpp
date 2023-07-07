#include <iostream>
#include <string>
#include <vector>

// 전공이 3.3 이상
// 전공평점은 전공과목별 (학점 x 과목평점)의 합을 학점의 총합으로 나눈값
// A+ : 4.5, A0 : 4.0, B+ : 3.5, B0 : 3.0, C+ : 2.5, C0 : 2.0
// D+ : 1.5, D0 : 1.0, F : 0.0
// 등급이 P인 과목은 계산에서 제외

int main()
{
    std::ios_base::sync_with_stdio(false);

    double sum = 0;
    double res = 0;

    for (int i = 0; i < 20; i++)
    {
        std::string title, grade;
        double score;
        std::cin >> title >> score >> grade;

        // 등급이 P인 과목은 계산에서 제외
        if (grade == "P")
            continue;

        double rating = 0;

        
        // 학점의 총합
        sum += score;
        
        // F는 0점
        if (grade == "F")
            continue;

        if (grade[0] == 'A')
            rating = 4;
        else if (grade[0] == 'B')
            rating = 3;
        else if (grade[0] == 'C')
            rating = 2;
        else
            rating = 1;

        if (grade[1] == '+')
            rating += 0.5;

        // 전공과목별 (학점 x 과목평점)의 합
        res += score * rating;
    }

    std::cout << res / sum;
    return 0;
}
