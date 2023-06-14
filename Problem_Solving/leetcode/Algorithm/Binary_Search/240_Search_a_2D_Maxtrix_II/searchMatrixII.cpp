/*
    240. Search a 2D Matrix II
        Write an efficient algorithm that searches for a value target 
        in an m x n integer matrix matrix. 
        This matrix has the following properties:

        Integers in each row are sorted in ascending from left to right.
        Integers in each column are sorted in ascending from top to bottom.

    Example 1:
        Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
        Output: true

    Example 2:
        Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
        Output: false

    Constraints:
        m == matrix.length
        n == matrix[i].length
        1 <= n, m <= 300
        -109 <= matrix[i][j] <= 109
        All the integers in each row are sorted in ascending order.
        All the integers in each column are sorted in ascending order.
        -109 <= target <= 109
*/
#include <vector>
class Solution {
public:
    // 행렬은 왼쪽에서 오른쪽, 위에서 아래 오름차순으로 정렬되어 있다.
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;

        int row = 0, col = matrix[0].size() - 1;

        // 첫 행의 맨 뒤에서 탐색 시작
        while (row <= matrix.size() - 1 && col >= 0)
        {   
            int val = matrix[row][col];
            if (target == val)
                return true;
            // 타겟이 작으면 왼쪽으로 이동
            else if (target < val)
                col--;
            // 타겟이 크면 아래로 이동
            else if (target > val)
                row++;
        }

        return false;
    }
};