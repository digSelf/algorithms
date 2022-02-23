#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length() - 1, n2 = num2.length() - 1;
        int carry = 0;

        string ans;
        while (n1 >= 0 || n2 >= 0) {
            if (n1 >= 0) carry += num1[n1--] - '0';
            if (n2 >= 0) carry += num2[n2--] - '0';

            ans.push_back((carry % 10) + '0');
            carry /= 10;
        }
        if (carry) ans.push_back(1 + '0');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};