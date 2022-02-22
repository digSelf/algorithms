#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> reverse_format_string_into_array(string& str) {
    vector<int> result;

    for (int i = str.length() - 1; i >= 0; --i) {
        result.push_back(str[i] - '0');
    }

    return result;
}

bool is_left_greater_or_equal_to_right(const vector<int>& left, const vector<int>& right) {
    if (left.size() != right.size()) {
        return left.size() >= right.size();
    }

    for (int i = left.size() - 1; i >= 0; --i) {
        if (left[i] == right[i]) continue;
        else return left[i] >= right[i];
    }

    // 此时left == right
    return true;
}

vector<int> sub(const vector<int>& left, const vector<int>& right) {
    vector<int> result;

    int carry = 0; // 状态机，上一轮做完减法的借位情况，初始时借位为0
    // 模板的重点是：先减掉上一轮的借位情况后，再做减法运算
    for (int i = 0; i < left.size(); ++i) {
        carry = left[i] - carry;
        
        if (i < right.size()) 
            carry = carry - right[i];
        
        // 这里利用了去摸的性质，将一个if分支结构归并了，当carry < 0时，加上借的10是正常运算
        // 如果carry > 0，由于10 % 10 = 0，不影响运算结果
        result.push_back((carry + 10) % 10);

        carry = (carry < 0 ? 1 : 0);
    }

    // 由于两数可能相等，导致结果中有一堆的前导0
    for (int i = result.size() - 1; i > 0; --i) { // 当只剩下1个0时停止
        if (result[i] != 0) break;

        result.pop_back();
    }

    return result;
}

int main() {
    string A, B;
    cin >> A >> B;

    vector<int> left = reverse_format_string_into_array(A);
    vector<int> right = reverse_format_string_into_array(B);

    vector<int> result;
    bool is_result_negative = false;
    if (is_left_greater_or_equal_to_right(left, right)) {
        result = sub(left, right);
    } else {
        result = sub(right, left);
        is_result_negative = true;
    }

    // 输出结果
    if (is_result_negative) cout << "-";
    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i];
    }
    cout << endl;

    return 0;
}