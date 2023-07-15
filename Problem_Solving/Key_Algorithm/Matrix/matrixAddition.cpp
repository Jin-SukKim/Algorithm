#include <iostream>
#include <vector>

// 사용하는 행렬의 크기가 같다는 전제하에 만든 클래스
class Matrix
{
public:
    int row, col;

    Matrix(int N, int M, bool userInput = true)
    {
        col = N;
        row = M;
        if (!userInput)
        {
            constructMat(N, M);
            return;
        }

        for (int i = 0; i < N; i++)
        {
            std::vector<int> v;
            for (int j = 0; j < M; j++)
            {
                int value;
                std::cin >> value;
                v.push_back(value);
            }
            mat.push_back(v);
        }
    }

    // 유저의 입력이 없을 시
    void constructMat(int N, int M)
    {
        col = N;
        row = M;
        for (int i = 0; i < N; i++)
        {
            mat.push_back(std::vector<int>(M));
        }
    }
    std::vector<std::vector<int>> getMatrix() { return mat; }

    // + 오퍼레이터 오버로드
    Matrix operator+(const Matrix& m)
    {
        Matrix retMat(col, row, false);
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                retMat.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return retMat;
    }

    // += 오퍼레이터 오버로드
    Matrix& operator+=(const Matrix& m)
    {
        // 위에 오버로드한 + 오퍼레이터 함수 사용
        *this = *this + m;
        return *this;
    }

    void printMat()
    {
        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                std::cout << mat[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
private:
    std::vector<std::vector<int>> mat;
};

int main()
{
    std::ios_base::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;
    Matrix mat1(N, M), mat2(N, M);
    mat1 += mat2;
    mat1.printMat();

    return 0;
}
