#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& v, int& l, int& r, int& mid)
{
    int leftSize = mid - l + 1;
    int rightSize = r - mid;

    std::vector<int> left(leftSize);
    std::vector<int> right(rightSize);

    for (int i = 0; i < leftSize; i++)
        left[i] = v[l + i];
    
    for (int i = 0; i < rightSize; i++)
        right[i] = v[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < leftSize && j < rightSize)
    {
        if (left[i] < right[j])
            v[k++] = left[i++];
        else
            v[k++] = right[j++];
    }

    while (i < leftSize)
        v[k++] = left[i++];

    while (j < rightSize)
        v[k++] = right[j++];
}

void mergeSort(std::vector<int>& v, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(v, l, mid);
        mergeSort(v, mid + 1, r);
        merge(v, l, r, mid);
    }
}

int binary_search(std::vector<int>& v, int& target, int l, int r)
{
    while (l <= r)
    {
        int mid = l + (r - l);

        if (v[mid] == target)
        {
            l = mid;
            // 정렬된 배열에서 같은 target을 가진 가장 왼쪽 index를 찾는다.
            for (l = mid; l >= 0; l--)
                if (v[l - 1] != target)
                    break;

            // 정렬된 배열에서 같은 target을 가진 가장 오른쪽 index를 찾는다.
            for (r = mid; r < v.size(); r++)
                if (v[r + 1] != target)
                    break;

            // r - l에 자기 자신을 포함해야 되 + 1을 해준다.
            return r - l + 1;
        }

        // 중간에 있던 값보다 target이 크면 오른쪽 배열에서 검색하도록 한다.
        if (v[mid] < target)
            l = mid + 1;
        // 중간에 있던 값보다 target이 작으면 왼쪽 배열에서 검색한다.
        else if (v[mid] > target)
            r = mid - 1;
    }

    return 0;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<int> own(N);    
    for (int i = 0; i < N; i++)
        std::cin >> own[i];
    std::sort(own.begin(), own.end());

    int M;
    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int t;
        std::cin >> t;
        std::cout << std::upper_bound(own.begin(), own.end(), t) -
        std::lower_bound(own.begin(), own.end(), t) << ' ';
    }

    return 0;
}