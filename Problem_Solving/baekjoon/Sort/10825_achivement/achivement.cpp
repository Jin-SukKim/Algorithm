#include <iostream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int kor;
    int eng;
    int math;
};

class Answer {
  private:
    std::vector<Student> s;
    std::vector<Student> sorted;

    bool compare(const Student &s1, const Student &s2) const {
        if (s1.kor == s2.kor) {
            if (s1.eng == s2.eng) {
                if (s1.math == s2.math) {
                    return s1.name < s2.name;
                } else
                    return s1.math > s2.math;
            } else
                return s1.eng < s2.eng;
        } else
            return s1.kor > s2.kor;
    }

    void merge(int l, int mid, int r) {
        int i = l;
        int j = mid + 1;
        int k = l;

        while (i <= mid && j <= r) {
            if (compare(s[i], s[j]))
                sorted[k++] = s[i++];
            else
                sorted[k++] = s[j++];
        }

        while (i <= mid)
            sorted[k++] = s[i++];
        while (j <= r)
            sorted[k++] = s[j++];

        for (int i = l; i <= r; i++)
            s[i] = sorted[i];
    }

  public:
    Answer(int &N)
        : s(std::vector<Student>(N)), sorted(std::vector<Student>(N)) {
        for (int i = 0; i < N; i++)
            std::cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].math;
    }

    void sort(int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            sort(l, mid);
            sort(mid + 1, r);
            merge(l, mid, r);
        }
    }

    void print() {
        for (Student &student : sorted) {
            std::cout << student.name << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;
    Answer a(N);
    a.sort(0, N - 1);
    a.print();

    return 0;
}