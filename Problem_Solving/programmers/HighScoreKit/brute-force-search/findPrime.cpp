#include <set>
#include <string>
#include <vector>

using namespace std;

bool checkPrime(int &n) {
    if (n == 0 || n == 1)
        return false;
    
    // 1과 자기 자신만을 가진 수를 소수라 하므로 2부터 n / 2까지 확인해준다.
    // 2 * (n / 2) = n이므로 n / 2까지만 확인해주는 것이다.
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}

void DFS(vector<int> &v, vector<bool> &visited, set<int> &ans, int depth,
         int &length, int num) {
    if (depth == length) {
        ans.insert(num);
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (visited[i])
            continue;

        visited[i] = true;
        DFS(v, visited, ans, depth + 1, length, num * 10 + v[i]);
        visited[i] = false;
    }
}

int solution(string numbers) {

    vector<int> v;
    // 각 숫자를 하나씩 나눈다.
    for (char& c : numbers)
        v.push_back(c - '0');
    vector<bool> visited(numbers.size());
    set<int> answer;
    int count = 0;
    // 나눈 숫자를 1 ~ n 길이까지의 숫자로 각각 변환
    for (int i = 1; i <= numbers.length(); i++) {
        DFS(v, visited, answer, 0, i, 0);
    }

    for (int i : answer)
        if (checkPrime(i))
            count++;

    return count;
}