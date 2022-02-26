#include <iostream>

using namespace std;

int lowbit(int x) {
    return x & -x;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    
    while (n --) {
        int x;
        cin >> x;
        
        int count = 0;
        for (int i = x; i != 0; i = i - lowbit(i)) { // 使用for循环代替while，这样可以在for的{}内写局部变量而不用暴露出来
            ++count;
        }
        
        cout << count << " \n"[n == 0];
    }
    
    return 0;
}