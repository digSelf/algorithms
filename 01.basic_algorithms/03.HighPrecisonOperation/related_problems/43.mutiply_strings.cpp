#include <string>
#include <algorithm>

using namespace std;

class Solution {
    static string mul(string& left, char& right, int n) { // n为补偿0的个数
        // 先补偿0
        string result;
        while (n-- > 0) {
            result.push_back('0');
        }

        // 传入进来的left是正序的
        int carry = 0;
        for (int i = left.size() - 1; i >= 0 || carry; --i) {
            if (i >= 0) {
                carry += (left[i] - '0') * (right - '0');
            }

            result.push_back((carry % 10) + '0');
            carry /= 10;
        }

        // 无需去除前导0，此时result是逆序的
        return result;
    }

    static void add(const string& mul_result, string& result) { // 两数相加，并将结果写到result中
        // 如果result的长度比mul_result短，就加到平齐的位置
        for (int i = mul_result.length() - result.length(); i > 0; --i) {
            result.push_back('0');
        }

        int carry = 0;
        for (int i = 0; i < result.size(); ++i) {
            carry += (result[i] - '0');
            if (i < mul_result.size())
                carry += (mul_result[i] - '0');

            result[i] = (carry % 10) + '0';
            carry /= 10;
        }

        if (carry)
            result.push_back('1');

        return;
    }


public:
    // 目标：尽量减少内存的无效拷贝之类的
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        } // 去除掉特殊情况

        string result; // 上一轮的计算结果
        int len_of_num1 = num1.length();
        for (int i = num1.size() - 1; i >= 0; --i) {
            // 本轮的大数乘法后，加上上一轮的计算结果为本轮的结果
            // mul为逆序的
            add(mul(num2, num1[i], len_of_num1 - 1 - i), result);
        }

        // result也是逆序的
        reverse(result.begin(), result.end());
        return result;
    }
};