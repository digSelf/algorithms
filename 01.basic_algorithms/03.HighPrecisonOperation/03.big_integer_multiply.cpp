#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> reverse_format_string_into_array(const string& str) {
    vector<int> result;
    for (int i = str.length() - 1; i >= 0; --i) {
        result.push_back(str[i] - '0');
    }

    return result;
}

vector<int> mul(const vector<int>& left, int right) {
    vector<int> result;
    
    int carry = 0; // 初始状态计算后的结果无进位，类似于有一个哨兵节点0，0 * right = 0，无进位
    for (int i = 0; i < left.size() || carry; ++i) {
        if (i < left.size()) {
            carry += left[i] * right; // carry = left[i] * right + carry;
        }

        result.push_back(carry % 10);
        carry /= 10;
    }

    // 去除前导0
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}

int main() {
    string A;
    int right;
    cin >> A >> right;

    vector<int> left = reverse_format_string_into_array(A);
    // right >= 0 and right <= 1e4
    vector<int> result = mul(left, right);

    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}