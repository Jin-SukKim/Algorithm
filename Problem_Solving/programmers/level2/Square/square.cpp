using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    // 직선의 방정식 y = mx + n, 원점에서 시작하므로 n = 0
    // y = 높이 (칠해지는 블록의 높이)
    // 기울기 m = (y1 - y0) / (x1 - x0), (x0, y0) = (0, 0)인 원점
    // long double m = h / w; // 이 방식을 이진수의 소수점 오차범위로 인해 정답이 안나온다.
    for (int i = 1; i < w; i++) {
        // 그래서 최대한 나누기를 적게 해준다. 
        // m을 곱하면 w를 두 번 나눈것과 같은데 먼저 h * x를 해주면 한번만 나누면 된다.
        answer += int((double(h) * i) / w); // 소수점을 버리고 더해준다.
    }
    
    // 결국 삼각형 두개인 것과 같으므로 두배
    return answer * 2;
}