#include <iostream>
#include <vector>

class Answer {
  private:
    std::vector<long long> nums;
    std::vector<long long> sorted;
    long long count;

  private:
    void merge(long long l, long long mid, long long r) {
        long long i = l;
        long long j = mid + 1;
        long long k = l;

        while (i <= mid && j <= r) {
            // 작은 수는 바꿔줄 필요가 없으니 그대로 넣어준다.
            // 중복값도 들어갈 수 있다.
            if (nums[i] <= nums[j])
                sorted[k++] = nums[i++];
            else {
                // 앞에 있던 수가 더 큰 수이니깐 뒤의 수와 바꿔준다.
                // 버블 정렬로 지면 j까지 j - k번 swap하는 것이다.
                count += j - k;
                sorted[k++] = nums[j++];
            }
        }

        while (i <= mid)
            sorted[k++] = nums[i++];

        while (j <= r)
            sorted[k++] = nums[j++];
        
        for (int i = l; i <= r; i++)
        {
            nums[i] = sorted[i];
        }
    }

  public:
    Answer(long long &N)
        : nums(std::vector<long long>(N)), sorted(std::vector<long long>(N)), count(0) {
        for (long long i = 0; i < N; i++) {
            std::cin >> nums[i];
        }
    }

    void sort(long long l, long long r) {
        if (l < r) {
            long long mid = l + (r - l) / 2;
            sort(l, mid);
            sort(mid + 1, r);
            merge(l, mid, r);
        }
    }

    void printAnswer() { std::cout << count; }
};

// 버블 정렬은 결국 자신보다 큰 값이 나올 때까지
// 계속 swap해주는 것이다.
// 즉, swap하는 횟수는 j - i, j = 자신보다 큰 값, i = 바꾸려는 index
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long long N;
    std::cin >> N;
    Answer a(N);
    a.sort(0, N - 1);
    a.printAnswer();

    return 0;
}