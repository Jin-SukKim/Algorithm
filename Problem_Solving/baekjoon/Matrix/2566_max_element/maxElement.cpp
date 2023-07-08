#include <iostream>
int main()
{
    std::ios_base::sync_with_stdio(false);

    int max = -1, indexC = -1, indexR = -1;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            int input;
            std::cin >> input;
            if (max < input)
            {
                max = input;
                indexC = i;
                indexR = j;
            }
        }
    }
    std::cout << max << "\n"
              << indexC << " " << indexR;

    return 0;
}
