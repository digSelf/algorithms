// 这里提供了另一种写法，只需要保证左侧的加法的是更长的那个数字，这样在加法时，只需要判断一次不需要判断两次了

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> reverse_format_string_into_array(const string& str) {
    vector<int> result;

    for (int i = str.length() - 1; i >= 0; --i) {
        result.push_back(str[i] - '0');
    }

    return result;
}

vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    
    int carry = 0;
    for (int i = 0; i < a.size(); ++i) {
        carry += a[i];
        if (i < b.size()) { // 由于a是更长的，所以只需要比较b是否更长
            carry += b[i];
        }

        result.push_back(carry % 10);
        carry = carry / 10;
    }

    if (carry) 
        result.push_back(carry); // 和的进位最大是1

    return result;
}

int main() {
    string A, B;
    cin >> A >> B;

    // 利用指针，将更大一些的数放在左侧
    auto left = &A, right = &B;
    if (left->length() < right->length()) { // 保证左侧的是更长的数
        std::swap(left, right);
    }

    // 转成vector的形式
    vector<int> a = reverse_format_string_into_array(*left);
    vector<int> b = reverse_format_string_into_array(*right);

    vector<int> result = add(a, b);

    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}