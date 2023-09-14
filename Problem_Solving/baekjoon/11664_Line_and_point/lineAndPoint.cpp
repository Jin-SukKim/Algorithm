
#include <array>
#include <cmath>
#include <iostream>

struct Vector {
    double x, y, z;

    Vector operator+(const Vector &v) {
        return Vector{x + v.x, y + v.y, z + v.z};
    }

    Vector operator-(const Vector &v) {
        return Vector{x - v.x, y - v.y, z - v.z};
    }

    Vector operator*(const double &scalar) {
        return Vector{x * scalar, y * scalar, z * scalar};
    }
    double distance() { return std::sqrt(x * x + y * y + z * z); }

    void normalize() {
        double dis = this->distance();
        this->x /= dis;
        this->y /= dis;
        this->z /= dis;
    }

    double dot(const Vector &v) {
        return this->x * v.x + this->y * v.y + this->z * v.z;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::array<Vector, 3> v;

    for (int i = 0; i < 3; i++)
        std::cin >> v[i].x >> v[i].y >> v[i].z;
    
    // A를 원점 0으로 맞춰준다.
    for (int i = 1; i < 3; i++)
        v[i] = v[i] - v[0];
    v[0] = {0.0, 0.0, 0.0};

    Vector line = v[1] - v[0];
    double lineDis = line.distance();
    line.normalize();

    Vector toPoint = v[2] - v[0];
    double projDis = toPoint.dot(line);

    // 선분의 범위 밖이라면 A점이나 B점에서 C점으로 이어지는 길이가 가장 짧다.
    if (projDis < 0 || projDis > lineDis) {
        Vector toPoint2 = v[2] - v[1];
        printf("%0.10lf", std::min(toPoint.distance(), toPoint2.distance()));
        return 0;
    }

    Vector proj = line * projDis;

    Vector n = v[2] - proj;
    double dis = n.distance();
    printf("%0.10lf", dis);
    return 0;
}