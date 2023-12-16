#include <string>
#include <vector>

using namespace std;

void Quad(vector<vector<int>>& arr, vector<int>& answer, int sRow, int sCol, int size) {
    bool one = true, zero = true;
    for (int row = sRow; row < sRow + size; row++)
    {
        for (int col = sCol; col < sCol + size; col++)
        {
            if (arr[row][col] == 0)
                one = false;
            else if (arr[row][col] == 1)
                zero = false;
            // 해당 구역에 둘 다 있다면 더 작게 쪼개야 하므로 loop에서 나온다.
            if (!one && !zero)
                break;
        }
    }
    
    // 현재 구역에 1만 있다면
    if (one) {
        answer[1]++;
        return;
    }
    // 0만 있다면
    if (zero) {
        answer[0]++;
        return;
    }
    
    Quad(arr, answer, sRow, sCol, size / 2); // 왼쪽 위 구역
    Quad(arr, answer, sRow, sCol + size / 2, size / 2); // 오른쪽 위 구역
    Quad(arr, answer, sRow + size / 2, sCol, size / 2); // 왼쪽 아래 구역
    Quad(arr, answer, sRow + size / 2, sCol + size / 2, size / 2); // 오른쪽 아래 구역
}

vector<int> solution(vector<vector<int>> arr) {
    // 0과 1의 개수
    vector<int> answer(2, 0);

    // 정사각형 형태의 map이므로 한 변의 길이만 있으면 된다.
    Quad(arr, answer, 0, 0, arr.size());
    
    return answer;
}