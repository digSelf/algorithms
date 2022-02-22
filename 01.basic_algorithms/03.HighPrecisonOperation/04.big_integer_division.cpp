#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> format_string_into_array(const string& str) {
    vector<int> result;
    for (int i = 0; i < str.length(); ++i) {
        result.push_back(str[i] - '0');
    }

    return result;
}

// q = quotient, rd = remainder
vector<int> div(const vector<int>& left, int right, int& rd) {
    vector<int> quotient;

    rd = 0; // 哨兵，假设上一轮的计算结果的余数为0
    for (int i = 0; i < left.size(); ++i) {
        // 这一轮的被除数应该为第i个数 + 余数 * 10，因为是10进制
        // 竖式运算时，相当于将余数乘以10后与被除数当前位置的数"落"下来
        rd = rd * 10 + left[i];

        quotient.push_back(rd / right);
        rd = rd % right;
    }

    // 由于是从高位开始算的，因此先进入vector中的是高位，所以需要逆置一下
    reverse(quotient.begin(), quotient.end());

    // 去除前导0
    while (quotient.size() > 1 && quotient.back() == 0) {
        quotient.pop_back();
    }

    return quotient;
}

int main() {
    string A;
    int right;
    cin >> A >> right;

    vector<int> left = format_string_into_array(A);
    // right >= 1 and right <= 1e4
    int r = 0;
    vector<int> quotient = div(left, right, r);

    for (int i = quotient.size() - 1; i >= 0; --i) {
        cout << quotient[i];
    }
    cout << endl << r << endl;;

    return 0;
}