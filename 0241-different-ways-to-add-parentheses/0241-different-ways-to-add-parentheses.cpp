class Solution {
public: 
    vector<int> rec(string &expression, int i, int j) {
        vector<int> temp;


        string subStr = expression.substr(i, j - i + 1);
        if (subStr.find_first_of("+-*") == string::npos) {
            temp.push_back(stoi(subStr));
            return temp;
        }

        for (int k = i; k <= j; ++k) {
            if (expression[k] == '+' || expression[k] == '-' || expression[k] == '*') {
                vector<int> leftPart = rec(expression, i, k - 1);
                vector<int> rightPart = rec(expression, k + 1, j);

                for (int a = 0; a < leftPart.size(); ++a) {
                    for (int b = 0; b < rightPart.size(); ++b) {
                        if (expression[k] == '-') {
                            temp.push_back(leftPart[a] - rightPart[b]);
                        } else if (expression[k] == '+') {
                            temp.push_back(leftPart[a] + rightPart[b]);
                        } else if (expression[k] == '*') {
                            temp.push_back(leftPart[a] * rightPart[b]);
                        }
                    }
                }
            }
        }

        return temp;
    }

    vector<int> diffWaysToCompute(string expression) {
        int n = expression.length();
        return rec(expression, 0, n - 1);
    }
};
