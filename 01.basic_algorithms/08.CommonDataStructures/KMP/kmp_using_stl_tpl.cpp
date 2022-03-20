#include <iostream>
#include <string.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const int kN = 1e5 + 5;

void get_next(vector<int>& next, const string& str) {
    int n = str.length();

    for (int i = 1, j = 0; i < n; ++i) {
        // i遍历整个模式串, j指向的是模式串中下一个要匹配的字符
        // 即：第j-1号字符相等，而j开始不相等时要回退。
        while (j && str[i] != str[j])
            j = next[j - 1];

        if (str[i] == str[j])
            ++j;
        next[i] = j;
    }
    return;
}

int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    string pat, str;
    int n, m;
    cin >> n >> pat >> m >> str;
    
    // 计算next数组
    vector<int> next(kN, 0);
    get_next(next, pat);
    
    // match
    for (int i = 0, j = 0; i < m; ++i) {
        while (j && str[i] != pat[j])
            j = next[j -  1];

        if (str[i] == pat[j])
            ++j;

        if (j == n) {
            cout << i - n + 1 << " ";

            // 此时模式串已经走完，要跟下一个字符进行匹配的话，需要进行回退回退到哪里呢？
            // 由于j是指向模式串中下一个待匹配的字符，因此假设str[i] != pat[j]，此时
            // 应该回退到 j = next[j - 1] 处再开始匹配
            j = next[j - 1];
        }
    }
    cout << endl;

    return 0;
}
