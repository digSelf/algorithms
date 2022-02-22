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
    for (int i = 0; i < a.size() || i < b.size(); ++i) {
        if (i < a.size()) {
            carry += a[i];
        }

        if (i < b.size()) {
            carry += b[i];
        }

        result.push_back(carry % 10);
        carry = carry / 10;
    }

    if (carry) 
        result.push_back(carry);

    return result;
}

int main() {
    string A, B;
    cin >> A >> B;

    // 转成vector的形式
    vector<int> a = reverse_format_string_into_array(A);
    vector<int> b = reverse_format_string_into_array(B);

    vector<int> result = add(a, b);

    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}