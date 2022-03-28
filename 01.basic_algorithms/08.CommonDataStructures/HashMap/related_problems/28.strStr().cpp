#include <string>
using std::string;

class Solution {
    const int P = 131;
    typedef unsigned long long ull;

public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;

        ull target = 0;
        ull base = 1;

        // 计算模式串的hash值，并计算出power(P, needle.length())的值用于后序对齐计算
        for (auto ch : needle) {
            target = target * P + ch;
            base = base * P;
        }

        ull source = 0;
        size_t n = haystack.length(), m = needle.length();
        for (int i = 0; i < n; ++i) {
            source = source * P + haystack[i];
            
            if (i < m - 1) continue;

            if (i >= m) {
                source = source - haystack[i - m] * base;
            }

            if (source == target)
                return i - m + 1; 
        }

        return -1;
    }
};