#include <iostream>
#include <string>

// 숫자 자체는 중요하지 않고 그 숫자가 있는지 없는지만 확인해주면 된다.
// 있는지 없는지의 확인은 1 bit만 사용하면 되므로 bit를 이용해준다.
// 숫자는 1 ~ 20까지 있을 수 있으므로 32bit 길이인 int를 사용해주자.
class BitSet
{
public:
    BitSet() : S(0) {};

    void add(int x)
    {   
        // or 연산자를 활용해 bit를 추가해준다.
        S |= (1 << x);
    }

    void remove(int x)
    {
        // 1을 x번째 비트까지 shift해준뒤 ~(NOT)을 사용해 0으로 바꿔
        // AND 연산을 통해 무조건 0으로 만들어준다.
        S &= ~(1 << x);
    }

    bool check(int x)
    {
        // x번째 비트가 1인지 확인
        return S & (1 << x);
    }

    void toggle (int x)
    {
        // XOR 연산으로 1이면 0으로 0이면 1로 바꿔준다.
        S ^= (1 << x);
    }

    void all() 
    {
        // 20번째 bit까지 모두 1로 채워주기
        S = (1 << 21) - 1;
    }

    void empty()
    {
        S = 0;
    }

private:
    int S;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int M;
    std::cin >> M;

    BitSet bitSet;
    while (M--)
    {
        std::string s;
        std::cin >> s;

        if (s == "add") {
            int x;
            std::cin >> x;
            bitSet.add(x);
        }
        else if (s == "remove") {
            int x;
            std::cin >> x;
            bitSet.remove(x);
        }
        else if (s == "check") {
            int x;
            std::cin >> x;
            std::cout << bitSet.check(x) << '\n';
        }
        else if (s == "toggle") {
            int x;
            std::cin >> x;
            bitSet.toggle(x);
        }
        else if (s == "all")
            bitSet.all();
        else if (s == "empty")
            bitSet.empty();
    }
  
    return 0;
}