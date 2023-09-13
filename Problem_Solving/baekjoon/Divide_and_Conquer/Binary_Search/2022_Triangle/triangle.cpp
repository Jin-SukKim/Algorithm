#include <cmath>
#include <iostream>

class Answer {
  public:
    Answer(double x, double y, double c) : x(x), y(y), c(c) {}

    void search() {
        double l = 0;
        // 삼각형의 법칙에 따라 밑변과 높이는 대각선의 변의 길이보다 클 수 없다.
        double r = std::min(x, y);
        double res = 0;
        // 소수점 여섯째 자리까지 누어질 수 있다.
        while (r - l > 1e-6) {
            double mid = l + (r - l) / 2.0;

            if (ratio(mid) < c)
                r = mid;
            else {
                res = mid;
                l = mid;
            }
        }
        
        printf("%.3lf\n", res);
    }

  private:
    double x, y, c;

    // 높이를 C로 한 삼각형과 각각 x와 y로 그려지는 삼각형을 그리면
    // 결국 비율로 계산할 수 있다.
    /*
        W = W1 + W2
        C / W1 = h2 / W (y 삼각형)
        W1 = (C * W) / h2
        C / W2 = h1 / W (x 삼각형)
        W2 = (C * W) / h1

        W = (C * W) / h2 + (C * W) / h1
        1 = C / h2 + C / h2 = (h1 + h2) * C / (h1 * h2)
        C = (h1 * h2) / (h1 + h2)

        이때 mid 값을 두 빌딩 사이의 거리라 생각하고 이분 탐색으로
        임의의 숫자를 넣어 C를 계산해 원래 C와 크거나 같은지 비교한다.
    */
    double ratio(double mid) {
        double h1 = std::sqrt(x * x - mid * mid);
        double h2 = std::sqrt(y * y - mid * mid);

        return (h1 * h2) / (h1 + h2);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    double x, y, c;
    std::cin >> x >> y >> c;
    Answer A(x, y, c);
    A.search();

    return 0;
}