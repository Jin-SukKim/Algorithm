#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ways;

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            if (c == '-' || c == '+' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (auto &l : left) {
                    for (auto &r : right) {
                        switch(c) {
                            case '-' : ways.push_back(l - r); break;
                            case '+' : ways.push_back(l + r); break;
                            case '*' : ways.push_back(l * r); break;
                        }
                    }
                }
            }
        }

        if (ways.empty()) return vector<int> {stoi(expression)};
        return ways;
    }
};