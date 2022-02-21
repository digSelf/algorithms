class Solution {
    typedef long long llong;
public:
    int mySqrt(int x) {
        llong left = 0, right = x;

        while (left < right) {
            llong mid = (left + right + 1) / 2;

            if (mid * mid <= x) {
                left = mid;
            } else { 
                right = mid - 1;
            }
        }

        return left;
    }
};