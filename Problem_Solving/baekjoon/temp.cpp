#include <iostream>
#include <queue>
/*
    음.. 빌딩의 시작 위치와 높이, 끝나는 위치와 높이 2개로
    queue를 만들어야 될 것 같다.
    정답 저장용 queue도 한개 만들어줘야 할 듯

*/
struct Building {
    int L;
    int H;
    int R;

    // L이 낮은 순서대로 가져온다.
    bool operator<(const Building& s) const {
        if (this->L == s.L)
            return this->H < s.H;
        return this->L > s.L;
    }

    bool operator!=(const Building& s) const {
        return this->L != s.L && this->H != s.H && this->R != s.R;
    }
};

struct cmp {
    bool operator()(const Building &a, const Building &b) { return a.H < b.H; }
};

class Answer {
    std::priority_queue<Building> build;

  public:
    Answer(int N) {
        for (int i = 0; i < N; i++) {
            Building b;
            std::cin >> b.L >> b.H >> b.R;
            build.push(b);
        }
    }

    void skyLine() {
        std::priority_queue<Building, std::vector<Building>, cmp> sky;
        sky.push(build.top());
        build.pop();

        Building line = sky.top();
        while (!build.empty()) {
            Building b = build.top();
            build.pop();

            Building s = sky.top();
            if (line != s)
            {
                std::cout << line.L << " " << line.H << " ";
                line = s;
            }
            if (b.L < s.R) {
                sky.push(b);
            }
            else {
                while (!sky.empty())
                {
                    s = sky.top();
                    if (b.L > s.R && line.R > b.R)
                    {

                    }
                    sky.pop();
                }
            }
        }
    }
};

// 버블 정렬은 결국 자신보다 큰 값이 나올 때까지
// 계속 swap해주는 것이다.
// 즉, swap하는 횟수는 j - i, j = 자신보다 큰 값, i = 바꾸려는 index
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;

    Answer a(N);
    a.skyLine();

    return 0;
}